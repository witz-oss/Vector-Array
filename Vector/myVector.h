#ifndef myVector_h
#define myVector_h

#include "error.h"

template <class T>
class myVector
{
public:
	myVector<T>() :
		sz{ 0 }, elem{ new T[] {} }, space{ 0 }
	{}
	explicit myVector<T>(int i) :
		sz{ i }, elem{ new T[i] {} }, space{ i }
	{}
	myVector<T>(const myVector<T>&);							//Kopier-Konstruktor
	myVector<T>& operator=(const myVector<T>&);					//Zuweisungsoperator
	~myVector<T>();

	int size()const;
	int capacity()const;

	T& operator[](int);								//like set (nicht const) zb v.[position] = 4
	T& at(int);
	const T& operator[](int) const;					//like get (da const) zb std::cout << v[position];
	const T& at(int) const;

	void reserv(int);
	void resize(int, T = T{});						// T = T{} -  falls du in x Stelle .resize(1, x) nichts schreibst, dann wird T als 0(oder leer Stelle, Konstruktor()) ausgerufen
	void push_back(const T&);
private:
	int sz;
	T* elem;
	int space;
};

#endif // !myVector_h

template<class T>
inline myVector<T>::~myVector<T>()
{
	delete[] elem;
	elem = nullptr;
}

template<class T>
myVector<T>::myVector(const myVector<T>& other) :
	elem{ new T[other.sz]{} }, sz{ other.sz }
{
	for (int i{ 0 }; i < other.sz; i++)
		elem[i] = other.elem[i];
}

template<class T>
inline int myVector<T>::size() const
{
	return sz;
}

template<class T>
inline void myVector<T>::reserv(int newSpace)
{
	if (newSpace <= space)
		return;
	T* p{ new T[newSpace] };

	for (int i{}; i < sz; ++i)
		p[i] = elem[i];

	delete[] elem;
	elem = p;
	space = newSpace;
}

template<class T>
inline void myVector<T>::push_back(const T& d)
{
	if (space == 0)
		reserv(8);
	else
		if (space == sz)
			reserv(space * 2);
	elem[sz] = d;
	++sz;
}

template<class T>
inline void myVector<T>::resize(int newSize, T  variabel)
{
	reserv(newSize);
	for (int i{ sz }; i < newSize; ++i)
		elem[i] = T{ variabel };
	sz = newSize;
}

template<class T>
inline int myVector<T>::capacity() const
{
	return space;
}

template<class T>
inline T& myVector<T>::operator[](int position)
{
	return elem[position];
}

template<class T>
inline T& myVector<T>::at(int position)
{
	if (position >= sz || position < 0)
		error("ausser vector");
	return elem[position];
}

template<class T>
inline const T& myVector<T>::operator[](int position) const
{
	return elem[position];
}

template<class T>
inline const T& myVector<T>::at(int position) const
{
	if (position >= sz || position < 0)
		error("ausser vector");
	return elem[position];
}

template<class T>
inline myVector<T>& myVector<T>::operator=(const myVector<T>& other)
{
	if (this == &other)
		return *this;
	if (other.sz <= space)								//if genug platz
	{
		for (int i{}; i < other.sz; ++i)
			elem[i] = other.elem[i];
		sz = other.sz;
		return *this;
	}
	// copy und swap
	T* p{ new T[other.sz] };
	for (int i{}; i < other.sz; ++i)
		p[i] = other.elem[i];
	delete[] elem;
	elem = p;
	space = sz = other.sz;
	return *this;
}

void praktikum2()
{
	myVector<double> x;
	myVector<double> y;

	x.push_back(2.22);
	x.push_back(2.88);
	x.push_back(6.66);
	x.push_back(5.66);
	x.push_back(0.66);

	y = x;
	y.resize(10);

	for (int i{}; i < x.size(); ++i)
		std::cout << x.at(i) << " ";

	std::cout << '\n';

	for (int i{}; i < y.size(); ++i)
		std::cout << y[i] << " ";

	std::cout << '\n';

	y[5] = 150;
	x.at(1) = 100;

	for (int i{}; i < x.size(); ++i)
		std::cout << x.at(i) << " ";

	std::cout << '\n';

	for (int i{}; i < y.size(); ++i)
		std::cout << y[i] << " ";

	std::cout << '\n';
}
