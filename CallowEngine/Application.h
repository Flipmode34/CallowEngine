#pragma once

#include "Core.h"

namespace Callow {

	class CALLOW_API Application
	{
	public:
		Application(); // Constructor
		virtual ~Application(); // Destructor

		void Run();
	};

	// To be DEFINED in Client
	Application* CreateApplication();

}