#pragma once

#include "Test.h" 


namespace tests {

	class TestRender : Test
	{
	public:
		TestRender();
		~TestRender();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGUIRender() override;

	private:
		VertexArray m_Va;
		IndexBuffer m_Ib;

		Shader m_Shader;
		Texture m_Texture;
		Renderer m_Render;

	};

}