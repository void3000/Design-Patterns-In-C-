#include "Decorator.hpp"
#include <iostream>

Decorator::Decorator(IComponent* component)
{
	_component = component;
}
void Decorator::draw()
{
	_component->draw();
}

void Component::draw()
{
	std::cout << "Drawing] Component\n";
}
DecoratorA::DecoratorA(IComponent* component) : Decorator(component)
{
	_component = component;
}
void DecoratorA::draw()
{
	Decorator::draw();
	std::cout << "Drawing] Decorator A\n";
}
DecoratorB::DecoratorB(IComponent* component) : Decorator(component)
{
	_component = component;
}
void DecoratorB::draw()
{
	Decorator::draw();
	std::cout << "Drawing] Decorator B\n";
}