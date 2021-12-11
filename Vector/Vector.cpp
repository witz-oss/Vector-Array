// Vector.cpp 
// Ros 25.20.2021

#include <iostream>
#include <exception>
#include "myRangeVec.h"

int main()try
{
    //praktikum2();

    myRangeVec<int> vec1(-1, 7);
    myRangeVec<int> vec2(-1, 7);

    for (int i{ vec1.low() }; i < vec1.high(); ++i)
    {
        vec1[i] = i;
        vec2[i] = i * 2;
    }

    for (int i{ vec1.low() }; i < vec1.high(); ++i)
    {
        std::cout << "i - " << i << ", vec1 - " << vec1[i] << " / ";
        std::cout << "i - " << i << ", vec1 - " << vec2[i] << " / ";
    }

    tf(vec1, vec2);

    return 0;
}
catch (const std::exception& e)
{
    std::cerr << e.what();
    return -1;
}
catch (...)
{
    std::cerr << "some wrong";
    return -2;
}