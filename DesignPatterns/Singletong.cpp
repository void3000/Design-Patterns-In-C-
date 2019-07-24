#include "Singleton.hpp"
#include <iostream>

Singleton* Singleton::singleton = nullptr;

Singleton::~Singleton()
{
	if (singleton != nullptr)
	{
		Singleton* deleteSingleton = singleton;
		singleton = nullptr;

		delete deleteSingleton;
	}
}

Singleton* Singleton::getInstance()
{
	if (singleton == nullptr)
		singleton = new Singleton();

	return singleton;
}

void Singleton::logMessage()
{
	std::cout << "Log 2019.07.21.11.52] Logging message.\n";
}