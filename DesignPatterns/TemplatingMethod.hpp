#pragma once

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