#pragma once

#include <memory>

class IPrototype
{
public:
	virtual std::unique_ptr<IPrototype> clone() = 0;
	//virtual IPrototype* clone() = 0;
	virtual int getState() = 0;
	virtual void setState(int state) = 0;
};

class ConcretePrototype : public IPrototype
{
private:
	int _state;

public:
	ConcretePrototype(ConcretePrototype& object) : _state(object.getState()) {}
	ConcretePrototype(int state) : _state(state) {}

	int getState() override;
	void setState(int state) override;
	std::unique_ptr<IPrototype> clone() override;
	//IPrototype* clone() override;
};
