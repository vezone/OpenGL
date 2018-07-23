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

#include "tests\TestClearColor.h" //Test 1
#include "tests\Menu.h" //Test menu

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
		Renderer render;

		tests::Menu menu(window);

		while (!glfwWindowShouldClose(window))
		{
			render.Clear();
			
			menu.OnUpdate(0.0f);
			menu.OnImGUIRender();
			menu.OnRender();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}