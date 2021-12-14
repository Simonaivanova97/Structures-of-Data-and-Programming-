//
//  main.cpp
//  Stack
//
//  Created by Simona Ivanova on 3.11.21.
//

#include <iostream>
#include "Stack.hpp"
#include "ResizingStack.hpp"
#include "LinkedStack.hpp"
#include "StackTasks.hpp"

/* Задача 1: Преобразуване на аритметичен израз в обратен полски запис.
   Задача 2: Намира стойсността на аритметичен израз представен в обратен полски запис.
 */

int main() {
    /*Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.push(5);
    s.print();
    cout<<endl;
    Stack<int> s1=s;
    s1.print();*/
    /*ResizingStack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
    s.print();
    cout<<"Top elem: "<<s.top()<<endl;*/
    /*LinkedStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Length of stack is: "<<s.length()<<endl;
    s.print();*/

    char expression[10]="(a-b/c)*m";
    /*infixedToReversePolishNotation(expression,result);
    cout<<"Reverse polish notation: "<<result<<endl;
    
    char expression1[8]="a^n*b^m";
    infixedToReversePolishNotation(expression1,result);
    cout<<"Reverse polish notation: "<<result<<endl;

    char expression2[12]="(a-b)*(a+b)";
    infixedToReversePolishNotation(expression2,result);
    cout<<"Reverse polish notation: "<<result<<endl;

    char expression3[16]="(a+b)*c-d*f+m^p";
    infixedToReversePolishNotation(expression3,result);
    cout<<"Reverse polish notation: "<<result<<endl;

    char expression4[12]="(a+b-c^4/5)";
    infixedToReversePolishNotation(expression4,result);
    cout<<"Reverse polish notation: "<<result<<endl;*/
    
    cout<<expression<<"\n"<<calculateAritmeticExpression(expression)<<endl;
    return 0;
}
