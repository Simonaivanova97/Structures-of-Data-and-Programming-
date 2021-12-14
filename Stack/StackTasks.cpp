//
//  StackTasks.cpp
//  Stack
//
//  Created by Simona Ivanova on 4.11.21.
//

#include "StackTasks.hpp"

void findPriority(const char& operation, int& priority){
    switch (operation) {
        case '+':
            priority=1;
            break;
        case '-':
            priority=1;
            break;
        case '*':
            priority=2;
            break;
        case '/':
            priority=2;
            break;
        case '^':
            priority=3;
            break;
    }
}

void infixedToReversePolishNotation(const char* expression, char* result){
    ResizingStack<char> operations;
    //char result[100];
    int i=0,j=0;
    while(expression[i]){
        // Ако текущият символ е буква или цифра, го добавяме към резулатат.
        if((expression[i]>='0' && expression[i]<='9') || (expression[i]>='a' && expression[i]<='z')){
            result[j]=expression[i];
            j++;
        }
        // Ако текущият символ е ( я добавяме в стека с операциите.
        else if(expression[i]=='('){
            operations.push(expression[i]);
        }
        // Ако текущият символ е ), от стека с операции вадим всяка от операциите и я добавяме към резулатата. След като достигне (, излиза от while цикъла. Премахваме от спека с операции ( до която е достигнато.
        else if(expression[i]==')'){
            while(operations.top()!='('){
                result[j]=operations.top();
                operations.pop();
                j++;
            }
            operations.pop();
        }
        // Ако текущия символ е някоя от операциите:
        else if(expression[i]=='+' || expression[i]=='-' ||
                expression[i]=='*' || expression[i]=='/' || expression[i]=='^'){
            // Ако стекът с операциите е все още празен, просто добавяме операцията.
            if(operations.empty()){
                operations.push(expression[i]);
            }
            // Ако стекът не е празен:
            else{
                // priorityCurrentOperation е приоритета на текущата операция, а priorityOperationTopElem е приоритета на операцията, която се намира на върха на стека. Ако в стекът операцията която е на върха на стека е с >= приоритет от текущата операция, то я изваждаме и я прибавяме към резулатата. След това отново проверяваме приоритета на операцията на върха на стека, и правим същото ако е отново с >= приоритет от текущатата операция и т.нататък. След като вече операцията, която е на върха на стека е с по-малък приоритет от текущата операция, добавяме текущатата операция в стека.
                int priorityCurrentOperation, priorityOperationTopElem;
                findPriority(expression[i], priorityCurrentOperation);
                findPriority(operations.top(), priorityOperationTopElem);
                while(priorityCurrentOperation<=priorityOperationTopElem && operations.top()!='(' && !operations.empty()){
                    result[j]=operations.top();
                    j++;
                    operations.pop();
                    findPriority(operations.top(), priorityOperationTopElem);
                }
                operations.push(expression[i]);
            }
        }
        i++;
    }
    // Ако стекът не е празен (има операции в него) ги изваждаме последователно всички, и ги добавяме към резулатата.
    while(!operations.empty() && operations.top()!='('){
        result[j]=operations.top();
        j++;
        operations.pop();
    }
    result[j]='\0';
    //cout<<"Reverse polish notation: "<<result<<endl;
}

void vectorFromdDifferentOperands(const char* expression,vector<pair<char,double>>& symbols){
    for(int i=0;i<strlen(expression);i++){
        bool hasSymbolI=false;
        if(expression[i]>='a' && expression[i]<='z'){
            for(int j=i+1;j<strlen(expression);j++){
                if(expression[i]==expression[j]){
                    hasSymbolI=true;
                    break;
                }
            }
            if(!hasSymbolI){
                pair<char, double> tempPair;
                tempPair.first=expression[i];
                cout<<"Enter value for symbol "<<expression[i]<<": ";
                cin>>tempPair.second;
                symbols.push_back(tempPair);
            }
        }
    }
}
double findValue(const vector<pair<char, double>> symbols, const char& s){
    for(int i=0;i<symbols.size();i++){
        if(symbols[i].first==s){
            return symbols[i].second;
            break;
        }
    }
    return -1;
}
double calculateAritmeticExpression(const char* expression){
    char reversePolishNotation[100];
    infixedToReversePolishNotation(expression, reversePolishNotation);
    vector<pair<char, double>> symbols;
    vectorFromdDifferentOperands(expression, symbols);
    ResizingStack<double> value;
    int i=0;
    while(reversePolishNotation[i]){
        if(reversePolishNotation[i]>='a' && reversePolishNotation[i]<='z'){
            value.push(findValue(symbols, reversePolishNotation[i]));
        }
        else if(reversePolishNotation[i]>='0' && reversePolishNotation[i]<='9'){
            value.push(reversePolishNotation[i]-48);
        }
        else if (reversePolishNotation[i]=='+' || reversePolishNotation[i]=='-' ||
                 reversePolishNotation[i]=='*' || reversePolishNotation[i]=='/' || reversePolishNotation[i]=='^'){
            double second=value.top();
            value.pop();
            double first=value.top();
            value.pop();
            if(reversePolishNotation[i]=='+'){
                value.push(first+second);
            }
            else if(reversePolishNotation[i]=='-'){
                value.push(first-second);
            }
            else if(reversePolishNotation[i]=='*'){
                value.push(first*second);
            }
            else if(reversePolishNotation[i]=='/'){
                value.push(first/second);
            }
            else if(reversePolishNotation[i]=='^'){
                value.push(pow(first,second));
            }
        }
        i++;
    }
    return value.top();
}
