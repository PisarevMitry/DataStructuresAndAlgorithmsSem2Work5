#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <string>
#include "ArrayQueue.h"
#include "ListQueue.h"

using namespace std;

bool isOperation(string token);
string calculate(string var1, string sign, string var2);
string calculate_array(string input);
string calculate_list(string input);

#endif