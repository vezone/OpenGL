#pragma once


#include "Test.h"

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

namespace tests {

	class TestTexture : Test
	{
	public:
		TestTexture();
		~TestTexture();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGUIRender() override;

	private:

		VertexArray m_Va;
		IndexBuffer m_Ib;

		Shader m_Shader;
		Texture m_Texture;
		Renderer m_Render;

		glm::mat4 m_Projection;
		glm::mat4 m_View;
		glm::mat4 m_Model;
		glm::mat4 m_MVP;

		glm::vec3 m_Translation;

		GLFWwindow* m_Window;
	};

}