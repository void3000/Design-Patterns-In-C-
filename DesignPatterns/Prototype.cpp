#include "Prototype.hpp"

int ConcretePrototype::getState()
{
	return _state;
}
void ConcretePrototype::setState(int state)
{
	_state = state;
}

std::unique_ptr<IPrototype> ConcretePrototype::clone()
{
	return std::make_unique<ConcretePrototype>(*this);
}

//IPrototype* ConcretePrototype::clone()
//{
//	return new ConcretePrototype(*this);
//}
