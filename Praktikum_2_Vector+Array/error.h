#pragma once
#ifndef error_h
#define error_h

#include <exception>
#include <iostream>
#include <string>

void error(const std::string&);
void error(const std::string&, const std::string&);

#endif // !error_h

