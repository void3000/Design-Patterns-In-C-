#include <iostream>
#include "Singleton.hpp"
#include "Iterator.hpp"
#include "Decorator.hpp"
#include "Prototype.hpp"
#include "Observer.hpp"
#include "TemplatingMethod.hpp"
#include "ChainOfResponsible.hpp"

Singleton* logger = Singleton::getInstance();

int main(int argc, char *argv[])
{
	logger->logMessage();

	Collection<double> arrayList;
	arrayList.putItem(5.1);
	arrayList.putItem(2.2);
	arrayList.putItem(1.5);
	arrayList.putItem(3.7);
	IteratorPtr<double> itrptr = arrayList.getIterator();
	for (; itrptr->hasNext(); itrptr->next())
		std::cout << itrptr->current() << std::endl;

	Component component;
	DecoratorA decoratorA(&component);
	DecoratorB decoratorB(&decoratorA);
	decoratorB.draw();

	ConcretePrototype originalObject(5);
	std::unique_ptr<IPrototype> clonedObject = originalObject.clone();
	clonedObject->setState(3);
	std::cout << "ClonedObject   = " << clonedObject->getState() << std::endl;
	std::cout << "OriginalObject = " << originalObject.getState() << std::endl;

	ConcreteHandlerA concreteA;
	ConcreteHandlerB concreteB;
	concreteA.basehandler(&concreteB);
	Request req;
	req.reqID = 7;
	concreteA.handle(&req);

	Observer observerA;
	Observer observerB;
	Observer observerC;
	Observable observable;
	observable.attach(&observerA);
	observable.attach(&observerB);
	observable.attach(&observerC);
	observable.set_state(5);
	observable.notify();
	std::cout << "Observer A's state = " << observerA.get_state() << "\n";
	std::cout << "Observer B's state = " << observerB.get_state() << "\n";
	std::cout << "Observer C's state = " << observerC.get_state() << "\n";

	ConcreteTravel travel;
	travel.trevel();

	return 0;
}
