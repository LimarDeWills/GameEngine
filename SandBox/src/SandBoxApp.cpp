#include <Engine.h>

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer() 
		:Layer("ExampleLayer")
	{}

	void OnUpdate() override
	{
		//EG_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Engine::Event& event) override
	{
		EG_TRACE("{0}", event);
	}

};

class SandBox : public Engine::Application
{
public:
	SandBox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Engine::ImGuiLayer());
	}
	~SandBox() {};

private:

};


Engine::Application* Engine::CreateApplication() {
	return new SandBox();
}