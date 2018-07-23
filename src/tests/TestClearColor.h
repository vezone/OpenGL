#pragma once

#include "Test.h"

namespace tests {

	class TestClearColor : Test
	{
	public:
		TestClearColor();
		~TestClearColor();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGUIRender() override;

	private:
		float m_ClearColor[4];
		bool m_Animation = false;
		float m_RedIncriment, m_Red;
	};

}