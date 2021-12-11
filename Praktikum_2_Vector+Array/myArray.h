#pragma once
#include <initializer_list>
#include <iostream>
#include "error.h"

template <class T, int N>
class myArray
{
public:
	myArray() :
		myArray<T, N>{ T{} }
	{}
	explicit myArray(const T&);
	myArray(const myArray<T, N>&);								// Kopier-Konstruktor
	myArray(std::initializer_list<T>);							// когда видит он список, то он автоматически конвертирует его в обьект (zb {1,2,3,4})
	~myArray();

	myArray<T, N>& operator=(const myArray<T, N>&);				// Zuweisungsoperator / оператор присваивания
	T& operator[](int);											// set									
	const T& operator[](int)const;								// Zugriff (std::cout << myArray[int];
	T& at(int);													// set
	const T& at(int)const;										// Zugriff
	T* data(int = 0);											// Zeiger auf ein element
	//const T* data(int = 0);//( int = 0);
	void fill(const T&);
	int size()const;
	void printAll()const;
private:
	T elem[N];
};

template<class T, int N>
inline myArray<T, N>& myArray<T, N>::operator=(const myArray<T, N>& other)
{
	if (this == &other) // (*this == other)
		return *this;
	for (int i{}; i < N; ++i)
		elem[i] = other[i];
	return *this;
}

template<class T, int N>
inline T& myArray<T, N>::operator[](int position)
{
	return elem[position];
}

template<class T, int N>
inline T& myArray<T, N>::at(int position)
{
	if (position >= N || position < 0)
		error("ausser array");
	return elem[position];
}

template<class T, int N>
inline const T& myArray<T, N>::at(int position) const
{
	if (position >= N || position < 0)
		error("außer array");
	return elem[position];
}

template<class T, int N>
inline T* myArray<T, N>::data(int position)
{
	return &(elem[position]);
}

template<class T, int N>
inline void myArray<T, N>::fill(const T& val)
{
	for (int i{}; i < N; ++i)
		elem[i] = val;
}

template<class T, int N>
inline int myArray<T, N>::size() const
{
	return N;
}

template<class T, int N>
inline void myArray<T, N>::printAll() const
{
	for (int i{}; i < N; ++i)
		std::cout << elem[i] << " ";
	std::cout << '\n';
}

template<class T, int N>
inline myArray<T, N>::myArray(const T& t)
{
	for (int i{}; i < N; ++i)
		elem[i] = t;
}

template<class T, int N>
inline myArray<T, N>::myArray(const myArray<T, N>& newArray)
{
	*this = newArray;
}

template<class T, int N>
inline myArray<T, N>::myArray(std::initializer_list<T> in)
{
	//myArray myArr(in.size());
	//for (int i{ in.begin() }; i != in.end(); ++i)			// for(auto const& i : in)
	//	myArr[i] = in;

	std::copy(in.begin(), in.end(), elem);					// он же типа просто вывoдит даные ??
}

template<class T, int N>
inline myArray<T, N>::~myArray()
{
	T{};
}
