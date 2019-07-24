#pragma once

class Singleton
{
private:
	~Singleton();
	static Singleton *singleton;

public:
	static Singleton* getInstance();
	// doSomething
	static void logMessage();
};
