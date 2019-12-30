#pragma once

#ifdef EG_PLATFORM_WINDOWS
extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	Engine::Log::GetCoreLogger()->warn("Initialaized log!!");
	Engine::Log::GetClientLogger()->info("Hello Misha");
	Engine::Log::GetClientLogger()->error("Opana Misha");
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}

#endif
