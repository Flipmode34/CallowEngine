#pragma once

#ifdef CW_PLATFORM_WINDOWS

extern Callow::Application* Callow::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Callow::CreateApplication();
	app->Run();
	delete app;
}

#endif