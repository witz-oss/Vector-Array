#pragma once
#include "myVector.h"

template<class T>
class myRangeVec : public myVector<T>
{
public:
	myRangeVec() = delete;
	myRangeVec<T>(int, int);

	int low()const;
	int high()const;

	T& operator[](int);
	const T& operator[](int)const;
private:
	int lb;
	myVector<T> mv;
};

template<class T>
myRangeVec<T>::myRangeVec(int lo, int hi)
{
	myVector<T> v(hi - lo + 1);
	mv = v;
	lb = lo ;
}

template<class T>
int myRangeVec<T>::low()const
{
	return lb;
}

template<class T>
int myRangeVec<T>::high()const
{
	return lb + mv.size() - 1;//myVector<T>::size() - 1;
}

template<class T>
T& myRangeVec<T>::operator[](int position)
{
	return mv.operator[](position - lb);//myVector<T>::operator[](position - lb);
}

template<class T>
const T& myRangeVec<T>::operator[](int position)const
{
	return mv.operator[](position - lb);//myVector<T>::operator[](position - lb);
}


template<class T>
void tf(const myRangeVec<T>& rcmv, myRangeVec<T>& rmv) {
	//rcmv[6] = 4; // Fehler, wie es auch sein soll
	T d1{ rcmv[6] }; // die const-Version []
	rmv[6] = 7; // die nicht-const-Version []
	T d2{ rmv[6] }; // die nicht-const-Version []
}