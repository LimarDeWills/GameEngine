#include "Application.h"

#include "Engine/Events/ApplicationEvent.h" 
#include "Engine/Log.h"
namespace Engine {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(640, 480);
		EG_TRACE(e);
		while (true);
	}
}