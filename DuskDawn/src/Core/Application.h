#pragma once

#include "Macros.h"

NS_DD_BEGIN

class DD_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
     
protected:
	virtual bool Init();
};

Application* CreateApplication();

NS_DD_END
