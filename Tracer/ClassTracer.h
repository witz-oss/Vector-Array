#pragma once
#include <istream>


template<class T>
class ClassTracer
{
public:
	ClassTracer<T>(T);
	ClassTracer<T>(T*);
	ClassTracer<T>(const ClassTracer<T>&);								// KopieKonstruktor
	ClassTracer<T>& operator=(const ClassTracer<T>&);					// Zuweisungoperator
	~ClassTracer<T>();

	int getCounter()const;
	T getElem()const;
private:
	static int counter;
	T elem;
};

template<class T>
int ClassTracer<T>::counter = 0;										// muss da ohne static sein, keine Ahnung warum, sonst Fehler - C2720 

template<class T>
inline ClassTracer<T>::ClassTracer(T elem)
{
	std::cout << "Konstruktor - " << elem << '\n';
	counter++;
	this->elem = elem;
}

template<class T>
inline ClassTracer<T>::ClassTracer(T* elem)
{
	counter++;
	this->elem = *elem;
	std::cout << "Konstruktor with Pointer - " << elem << " - " << this->elem << '\n';
}

template<class T>
inline ClassTracer<T>::ClassTracer(const ClassTracer<T>& other)
{
	counter++;
	this->elem = other.elem;
	std::cout << "Kopiekonstrutor - " << elem << '\n';
}

template<class T>
inline ClassTracer<T>::~ClassTracer()
{
	std::cout << "Destruktor - " << elem << '\n';
}

template<class T>
inline ClassTracer<T>& ClassTracer<T>::operator=(const ClassTracer<T>& other)
{
	if (this == &other)
		return *this;
	this->elem = other.elem;
	std::cout << "Zuweisungoperator" << '\n';
}

template<class T>
inline int ClassTracer<T>::getCounter() const
{
	return counter;
}

template<class T>
inline T ClassTracer<T>::getElem() const
{
	return elem;
}


