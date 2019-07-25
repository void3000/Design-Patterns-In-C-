#pragma once

#include <iostream>

class TravelTemplate
{
public:
	TravelTemplate(){}

	void trevel();
	virtual void schedule() = 0;
	virtual void buy_ticket() = 0;
	virtual void have_fun() = 0;
};
void TravelTemplate::trevel()
{
	schedule();
	buy_ticket();
	have_fun();
}

class ConcreteTravel : public TravelTemplate
{
public:
	ConcreteTravel() : TravelTemplate() {}
	void schedule() override;
	void buy_ticket() override;
	void have_fun() override;
};

void ConcreteTravel::schedule()
{
	std::cout << "Scheduling...\n";
}
void ConcreteTravel::buy_ticket()
{
	std::cout << "Buy ticket...\n";
}
void ConcreteTravel::have_fun()
{
	std::cout << "Have fun...\n";
}
