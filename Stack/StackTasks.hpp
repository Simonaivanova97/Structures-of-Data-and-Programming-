//
//  StackTasks.hpp
//  Stack
//
//  Created by Simona Ivanova on 4.11.21.
//

#ifndef StackTasks_hpp
#define StackTasks_hpp

#include <stdio.h>
#include <vector>
#include "ResizingStack.hpp"

void findPriority(const char&,int&);
void infixedToReversePolishNotation(const char*, char*);
void vectorFromdDifferentOperands(const char*,vector<pair<char,double>>&);
double findValue(const vector<pair<char, double>> symbols, const char&);
double calculateAritmeticExpression(const char*);

#endif /* StackTasks_hpp */
