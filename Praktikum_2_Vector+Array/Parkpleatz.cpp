// Parkpleatze.cpp 
// Ros 26.10.2021

#include <iostream>
#include <exception>
#include "myArray.h"
#include "belegungParkpleatze.h"

int main()try
{
    myArray<std::string, 10> myArr;// { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    parkplatz(&myArr);
    menu(&myArr);
    //myArr.data();

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