
#include "Renderer.h" //glew.h, VertexArray.h, IndexBuffer.h, Shader.h
#include "Texture.h"
#include "VertexBufferLayout.h"

#include "TestRender.h"

namespace tests {

	TestRender::TestRender()
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
		IndexBuffer  ib(indices, 6);

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
	}

	TestRender::~TestRender()
	{
	}

	void TestRender::OnUpdate(float deltaTime)
	{
	}

	void TestRender::OnRender()
	{
	}

	void TestRender::OnImGUIRender()
	{
	}

}