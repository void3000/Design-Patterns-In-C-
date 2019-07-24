#pragma once

class IComponent
{
public:
	virtual void draw() = 0;

};
class Component : public IComponent
{
public:
	void draw();
};

///
// Decorator is just an extension of Chain of Responsibility
class Decorator : public IComponent
{
protected:
	IComponent* _component;

public:
	Decorator(IComponent* component);
	void draw();
};

class DecoratorA : public Decorator
{
public:
	DecoratorA(IComponent* component);
	void draw();
};

class DecoratorB : public Decorator
{
public:
	DecoratorB(IComponent* component);
	void draw();
};
