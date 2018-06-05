#include "Menu.h"

#include "iamgui\imgui_impl_glfw_gl3.h"

//Somehow del obj {TestClearColor m_TClearColor;}

namespace tests {

	Menu::Menu(GLFWwindow *window) :
		m_Window(window)
	{
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		m_IsMenuActive = true;
		m_Canvas = 0;

		//Tests
		//TestClearColor m_TClearColor;
		
		m_CurrentTest = 0;
		m_TestNames[3] = new char[3];
		m_TestNames[0] = "None";
		m_TestNames[1] = "ClearColor";
		m_TestNames[2] = "Texture";

		//Editor
		m_Io = ImGui::GetIO();
		m_Font =
			m_Io.Fonts->AddFontFromFileTTF("fonts\\TimesNewRomanMTStd.otf", 16.0f);
		m_Font =
			m_Io.Fonts->AddFontFromFileTTF("fonts\\TimesNewRomanMTStd.otf", 14.0f);
		m_Font =
			m_Io.Fonts->AddFontFromFileTTF("fonts\\TimesNewRomanMTStd.otf", 18.0f);
		m_Font =
			m_Io.Fonts->AddFontFromFileTTF("fonts\\\\Baskerville.ttf", 16.0f);
		m_Font = 
			m_Io.Fonts->AddFontFromFileTTF("fonts\\English_Wd.ttf", 16.0f);
		m_CurrentTheme = 0;
		m_TextColor = ImVec4(0.2f, 0.4f, 1, 1);
		m_ThemeNames[3] = new char[3];
		m_ThemeNames[0] = "Dark";
		m_ThemeNames[1] = "Light";
		m_ThemeNames[2] = "Classic";

	}

	Menu::~Menu()
	{
		ImGui_ImplGlfwGL3_Shutdown();
		ImGui::DestroyContext();
	}

	void Menu::OnUpdate(float deltaTime)
	{
		ImGui_ImplGlfwGL3_NewFrame();
	}

	void Menu::OnRender()
	{
		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void Menu::OnImGUIRender()
	{
		ImGui::Begin("Windor for debug stuff", &m_IsMenuActive, ImGuiWindowFlags_MenuBar);
		ImGui::SetWindowSize(ImVec2(500, 300), 0);
		if (ImGui::BeginMenuBar())
		{

			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open", "Ctrl+O"))
				{
					m_Canvas = 0;
				}
				if (ImGui::MenuItem("Save", "Ctrl+S"))
				{
					//Saving stuff
				}
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Editor"))
			{

				if (ImGui::MenuItem("Theme"))
				{
					m_Canvas = 1;
				}
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}


		switch (m_Canvas)
		{
			case 0:
				Open();
				break;
			case 1:
				Editor();
				break;
			//..

		}


		ImGui::End();
	}

	void Menu::Open()
	{
		ImGui::TextColored(m_TextColor, "Choose ur test");
		ImGui::Combo("Tests", &m_CurrentTest, m_TestNames, 3);
		
		if (m_CurrentTest == 0)
		{
			//
		}
		if (m_CurrentTest == 1)
		{
			m_TClearColor.OnUpdate(0.0f);
			m_TClearColor.OnRender();
			m_TClearColor.OnImGUIRender();
		}

	}

	void Menu::Editor()
	{
		ImGui::TextColored(m_TextColor, "Editor parametrs");
		ImGui::TextColored(m_TextColor, "");

		ImGui::TextColored(m_TextColor, "Font");
		ImGui::ShowFontSelector("Font selector");

		ImGui::TextColored(m_TextColor, "");
		ImGui::TextColored(m_TextColor, "Choose color to ur text");
		ImGui::ColorEdit3("Text color", &m_TextColor.x);

		ImGui::TextColored(m_TextColor, "");
		ImGui::TextColored(m_TextColor, "Choose theme to menu");
		ImGui::Combo("Themes", &m_CurrentTheme, m_ThemeNames, 3);

		if (m_CurrentTheme == 0)
		{
			ImGui::StyleColorsDark();
		}
		if (m_CurrentTheme == 1)
		{
			ImGui::StyleColorsLight();
		}
		if (m_CurrentTheme == 2)
		{
			ImGui::StyleColorsClassic();
		}

		
	}

	void Menu::OpenColorTest()
	{
		
	}

}