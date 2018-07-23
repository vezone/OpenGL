#pragma once

#include "Test.h"
#include "TestClearColor.h"
#include "TestTexture.h"

#include "GLFW\glfw3.h"
#include "iamgui\imgui.h"

namespace tests {

	class Menu : Test
	{
	public:
		Menu(GLFWwindow *window);
		~Menu();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGUIRender() override;

	private:
		GLFWwindow *m_Window;
		
		bool m_IsMenuActive;
		int m_Canvas;

		//Tests
		TestClearColor m_TClearColor;
		//TestTexture m_TTexture;

		//Test (Open)
		int m_CurrentTest;
		const char *m_TestNames[3];

		//Editor
		ImGuiIO m_Io;
		ImFont *m_Font;
		int m_CurrentTheme;
		const char *m_ThemeNames[3];
		ImVec4 m_TextColor;

		void Open();
		void Editor();
		
		//Tests 
		void OpenColorTest();

	};

}