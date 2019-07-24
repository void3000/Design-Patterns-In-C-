#include "Iterator.hpp"

template<class T> 
Iterator<T>* Collection<T>::getIterator()
{
	return new CollectionIterator<T>(this);
}

template<class T>
int Collection<T>::getSize()
{
	return itemCollection.size();
}

template<class T>
T Collection<T>::getItem(int pos)
{
	// For example purpose, we omit error checking
	return itemCollection.at(pos);
}

template<class T>
void Collection<T>::putItem(T item)
{
	itemCollection.push_back(item);
}

template<class T>
CollectionIterator<T>::CollectionIterator(ICollection<T>* collection)
{
	refCollection = collection;
	currentIndex = 0;
}

template<class T>
CollectionIterator<T>::~CollectionIterator()
{
	refCollection = nullptr;
}

template<class T>
bool CollectionIterator<T>::hasNext()
{
	return (currentIndex < refCollection->getSize());
}

template<class T>
void CollectionIterator<T>::next()
{
	currentIndex++;
}

template<class T>
T CollectionIterator<T>::current()
{
	return refCollection->getItem(currentIndex);
}

template<class T>
IteratorPtr<T>::IteratorPtr(Iterator<T>* _iterator)
{
	iterator = _iterator;
}

template<class T>
IteratorPtr<T>::~IteratorPtr()
{
	if (iterator != nullptr)
		delete iterator;
}
