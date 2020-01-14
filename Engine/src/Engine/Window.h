#pragma once

#include "egpch.h"
#include "Engine/Core.h"
#include "Engine/Events/Event.h"

namespace Engine {
	struct WindowProbs
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProbs(const std::string& title = "Engine title",
			unsigned int width = 1280, unsigned int height = 720)
			:Title(title), Width(width), Height(height) {}
	};

	class ENGINE_API Window
	{
	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallBackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProbs& probs = WindowProbs());
	};
}
