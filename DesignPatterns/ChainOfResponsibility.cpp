#include <iostream>
#include "ChainOfResponsible.hpp"

void Handler::basehandler(Handler* handler)
{
	_handler = handler;
}
void Handler::handle(Request* request)
{
	if (_handler == nullptr)
		return;
	_handler->handle(request);
}

void ConcreteHandlerA::handle(Request* request)
{
	if (request->reqID  < 5)
		std::cout << "ConcereteHanlderA handling request\n";
	else
		Handler::handle(request);
}

void ConcreteHandlerB::handle(Request* request)
{
	if (request->reqID > 5)
		std::cout << "ConcereteHanlderB handling request\n";
	else
		Handler::handle(request);
}
