#pragma once

typedef struct
{
	int reqID;
}Request;

class Handler
{
protected:
	Handler* _handler;

public:
	Handler() : _handler(nullptr) {}
	void basehandler(Handler* handler);
	virtual void handle(Request* request);
};

class ConcreteHandlerA : public Handler
{
public:
	void handle(Request* request) override;
};
class ConcreteHandlerB : public Handler
{
public:
	void handle(Request* request) override;
};
