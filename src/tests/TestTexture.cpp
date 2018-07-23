#include "TestTexture.h"

#include "iamgui\imgui.h"


#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "iamgui\imgui.h"
#include "iamgui\imgui_impl_glfw_gl3.h"

namespace tests {

	TestTexture::TestTexture()
	{
		
		float texturePosition[16] = {
			0.0f, 0.0f, 0.0f, 0.0f, //0
			50.0f, 0.0f, 1.0f, 0.0f, //1
			50.0f, 50.0f, 1.0f, 1.0f, //2
			0.0f, 50.0f, 0.0f, 1.0f  //3
		};
		unsigned int indices[6] = {
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glBlendFunc(GL_SRC_ALPHA,
			GL_ONE_MINUS_SRC_ALPHA));
		GLCall(glEnable(GL_BLEND));

		VertexBuffer vb(texturePosition, 4 * 4 * sizeof(float));
		IndexBuffer ib(indices, 6);

		VertexBufferLayout layout;

		layout.Push<float>(2);
		layout.Push<float>(2);
		m_Va.AddBuffer(vb, layout);

		m_Shader = Shader("res/shaders/Basic.shader");
		
		Texture texture("res/textures/soundub.jpg");
		texture.Bind();
		m_Shader.Bind();
		m_Shader.SetUniform1i("u_Texture", 0);

		m_Ib = ib;

		//Testing our binding stuff
		m_Va.Unbind();
		vb.Unbind();
		ib.Unbind();
		m_Shader.Unbind();

		m_Projection = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
		m_View = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
		m_Translation = glm::vec3(0, 0, 0);
	}

	TestTexture::~TestTexture()
	{
	}

	void TestTexture::OnUpdate(float deltaTime)
	{
	}

	void TestTexture::OnRender()
	{
		m_Render.Clear();

		
		m_Model = glm::translate(glm::mat4(1.0f), m_Translation);
		m_MVP = m_Projection * m_View * m_Model;

		m_Shader.Bind();
		m_Shader.SetUniformMat4("u_MVP", m_MVP);

		m_Render.Draw(m_Va, m_Ib, m_Shader);


	}

	void TestTexture::OnImGUIRender()
	{
		ImGui::SliderFloat3("Translation", &m_Translation.x, 0.0f, 960.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}

}