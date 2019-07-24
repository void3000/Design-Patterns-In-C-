#pragma once

#include <vector>

class IObservable;
class IObserver;
class Observer;
class Observable;

class IObserver
{
public:
	virtual void update(Observable* observable) = 0;
};
class IObservable
{
public:
	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;
	virtual void notify() = 0;
};
class Observable : public IObservable
{
private:
	int state = 0;

protected:
	std::vector<IObserver*> observers;

public:
	Observable() {}
	void attach(IObserver* observer);
	void detach(IObserver* observer);
	void notify();
	void set_state(int state);
	int get_state();
};
class Observer : public IObserver
{
private:
	int state = 0;

public:
	Observer() {}
	void update(Observable* observable);
	int get_state();
};
