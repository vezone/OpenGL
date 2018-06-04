#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"

#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "iamgui\imgui.h"
#include "iamgui\imgui_impl_glfw_gl3.h"

#define log(x) std::cout << x << std::endl

int main(void)
{
	GLFWwindow* window;
	
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(960, 540, "OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	GLenum isOkey = glewInit();
	if (isOkey != GLEW_OK) {
		std::cout << "Error" << std::endl;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
	
	{
		float positions[] = {
			-50.0f, -50.0f, 0.0f, 0.0f, //0
			 50.0f, -50.0f, 1.0f, 0.0f, //1
			 50.0f,  50.0f, 1.0f, 1.0f, //2
			-50.0f,  50.0f, 0.0f, 1.0f  //3
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glBlendFunc(GL_SRC_ALPHA, 
			GL_ONE_MINUS_SRC_ALPHA));
		GLCall(glEnable(GL_BLEND));

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));
		IndexBuffer ib(indices, 6);
		
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);
		
		glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,0));
		

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		
		Texture texture("res/textures/soundub.jpg");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();
		
		Renderer render;

		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		float r = 0.0f, incriment = 0.05f;
		
		glm::vec3 translation1 = glm::vec3(0, 0, 0),
				  translation2 = glm::vec3(0, 0, 0);
		glm::mat4 model;
		glm::mat4 mvp;

		while (!glfwWindowShouldClose(window))
		{
			render.Clear();

			ImGui_ImplGlfwGL3_NewFrame();

			{
				model = glm::translate(glm::mat4(1.0f), translation1);
				mvp = proj * view * model;
				shader.Bind();
				shader.SetUniformMat4("u_MVP", mvp);
				render.Draw(va, ib, shader);
			}

			{
				model = glm::translate(glm::mat4(1.0f), translation2);
				mvp = proj * view * model;
				shader.SetUniformMat4("u_MVP", mvp);
				render.Draw(va, ib, shader);
			}

			if (r > 1.0f)
				incriment = -0.05f;
			else if (r < 0.0f)
				incriment = 0.05f;
			
			r += incriment;

			{
				ImGui::SliderFloat3("Translation1", &translation1.x, 0.0f, 960.0f);  
				ImGui::SliderFloat3("Translation2", &translation2.x, 0.0f, 960.0f);
				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			}

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}