#include <DuskDawn.h>

class Sandbox : public DuskDawn::Application
{
public:
	Sandbox()
	{
		DD_INFO("Sandbox app created with DuskDawn {}", DD_VERSION);
	}
	~Sandbox()
	{
		DD_INFO("Sandbox app terminated!");
	}
};


NS_DD_BEGIN

Application* CreateApplication()
{
	return new Sandbox();
}

NS_DD_END


