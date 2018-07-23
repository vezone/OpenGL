#include "TestClearColor.h"

#include "iamgui\imgui.h"
#include "Renderer.h" 

namespace tests {

	

	TestClearColor::TestClearColor()
		: m_ClearColor {0.8f, 0.0f, 0.0f, 1.0f}, m_RedIncriment(0.0f)
	{
		//0.2f, 0.3f, 0.8f, 1.0f
	}

	TestClearColor::~TestClearColor()
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void TestClearColor::OnUpdate(float deltaTime)
	{
	}

	void TestClearColor::OnRender()
	{
		if (m_Animation)
		{
			if (m_ClearColor[0] < .5f)
				m_RedIncriment += 0.0005f;
			else if (m_ClearColor[0] > 0.0f)
				m_RedIncriment -= 0.0005f;
			m_ClearColor[0] += m_RedIncriment;
			m_ClearColor[1] += m_RedIncriment;
			m_ClearColor[2] = m_ClearColor[0]* m_ClearColor[0] 
				+ m_ClearColor[1] * m_ClearColor[1];
		}
		
		GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
		
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void TestClearColor::OnImGUIRender()
	{
		if (ImGui::Button("Manual"))
		{
			m_Animation = false;
		}
		if (ImGui::Button("Animation"))
		{
			m_Animation = true;
		}
		ImGui::ColorEdit4("Clear color", m_ClearColor);
		
	}

}