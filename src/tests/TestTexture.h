#pragma once

#include "Test.h"

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
		glm::vec3 m_TexturePosition;
	};

}