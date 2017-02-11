#include "stdafx.h"

#include "App.h"

int main()
{
	std::unique_ptr<App::App> app = std::make_unique<App::App>();
	while (!app->Update());
	return 0;
}
