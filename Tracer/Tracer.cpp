// Tracer.cpp 
// Ros 01.11.2021

#include <iostream>
#include <exception>
#include "ClassTracer.h"

extern int globalInt{ 6 };

int main()try
{
    int* pointerInt = { new int {5} };
    ClassTracer<int> a1(1);
    ClassTracer<int> a2(2);
    ClassTracer<int> a3(a2);                                                          // KopieKonstruktor
    ClassTracer<int> a4 = a1;                                                         // KopieKonstruktor
    a4 = a2;
    ClassTracer<int> a5(pointerInt);
    ClassTracer<int> a6(globalInt);

    std::cout << "\na1 - " << a1.getElem();
    std::cout << "\na2 - " << a2.getElem();
    std::cout << "\na3 - " << a3.getElem();
    std::cout << "\na4 - " << a4.getElem();
    std::cout << "\na5 - " << a5.getElem();
    std::cout << "\na6 (global) - " << a6.getElem();
    std::cout << "\ncounter - " << a1.getCounter() << '\n\n';


    return 0;
}
catch (std::exception& e)
{
    std::cerr << e.what();
    return -1;
}
catch (...)
{
    std::cerr << "some wrong";
    return -2;
}