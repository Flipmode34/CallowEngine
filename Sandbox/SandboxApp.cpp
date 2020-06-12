#include "Callow.h"

class Sandbox : public Callow::Application
{
	public:
		Sandbox() // Constructor
		{

		}

		~Sandbox() // Deconstructor
		{

		}
};

Callow::Application* Callow::CreateApplication()
{
	return new Sandbox();
}