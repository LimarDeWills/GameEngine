#pragma once

#include "Engine/Window.h"

#include "GLFW/glfw3.h"
//#include "Engine/Log.h"

namespace Engine {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& probs);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//Window attributes
		inline void SetEventCallback(const EventCallBackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& probs);
		virtual void Shutdown();

		inline virtual void* GetNativeWindow() const { return m_Window; };
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallBackFn EventCallback;
		};

		WindowData m_Data;
	};
}
