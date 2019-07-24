#include "Observer.hpp"

void Observable::attach(IObserver* observer)
{
	observers.push_back(observer);
}
void Observable::detach(IObserver* observer)
{
	//observers.remove(observer);
}
void Observable::notify()
{
	for (auto& observer : observers)
	{
		observer->update(this);
	}
}
void Observable::set_state(int state)
{
	this->state = state;
}
int Observable::get_state()
{
	return state;
}
void Observer::update(Observable* observable)
{
	state += observable->get_state();
}
int Observer::get_state()
{
	return state;
}
