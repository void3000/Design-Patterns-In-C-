#pragma once

#include <vector>

template<class T>
class Iterator
{
protected:
	int currentIndex;

public:
	virtual bool hasNext() = 0;
	virtual void next() = 0;
	virtual T current() = 0;
};

template<class T>
class IteratorPtr
{
private:
	Iterator<T>* iterator;
public:
	IteratorPtr(Iterator<T>* _iterator);
	~IteratorPtr();

	IteratorPtr<T>& operator=(Iterator<T>* _iterator)
	{
		iterator = _iterator;
		return *this;
	}
	Iterator<T>* operator->()
	{
		return iterator;
	}
};

template<class T>
class ICollection
{
public:
	virtual Iterator<T>* getIterator() = 0;
	virtual int getSize() = 0;
	virtual T getItem(int pos) = 0;
};

template<class T>
class Collection : public ICollection<T>
{
private:
	std::vector<T> itemCollection;

public:
	Iterator<T>* getIterator();
	int getSize();
	void putItem(T item);
	T getItem(int pos);
};

template<class T>
class CollectionIterator : public Iterator<T>
{
private:
	ICollection<T>* refCollection;

public:
	CollectionIterator(ICollection<T>* collection);
	~CollectionIterator();

	bool hasNext();
	void next();
	T current();
};

template class IteratorPtr<int>;
template class Collection<int>;
template class CollectionIterator<int>;

template class IteratorPtr<double>;
template class Collection<double>;
template class CollectionIterator<double>;
