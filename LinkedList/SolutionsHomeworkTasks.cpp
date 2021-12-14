//
//  main.cpp
//  HomeworkTasksLinkedList
//
//  Created by Simona Ivanova on 14.12.21.
//

#include <iostream>
using namespace std;

template <typename T>
struct node{
    T inf;
    node<T>* link;
};

//Функция, която извежда елементите на списък с първи елемент start.
template <typename T>
void print(node<T>* start){
    if(start!=NULL){
        while(start){
            if(start->link){
                cout<<start->inf<<" -> ";
            }
            else{
                cout<<start->inf<<endl;
            }
            start=start->link;
        }
    }
    else{
        cout<<"Empty list!"<<endl;
    }
}

//1. Фунцкия, която преброява колко пъти елементът elem се среща в списъка с първи елемент start.
int count(int elem, node<int>* start){
    int c=0;
    while(start){
        if(start->inf==elem){
            c++;
        }
        start=start->link;
    }
    return c;
}

//2. Функция, която създава и връща първия елемет на списък с елементи х, х+1, ..., у, като х<=у.
node<int>* range(int x, int y){
    node<int>* start=NULL;
    if(x>y){
        cout<<"Invalid data!"<<endl;
    }
    else{
        node<int>* previousNode=NULL,* newNode=NULL;
        start=new node<int>;
        assert(start!=NULL);
        start->inf=x;
        start->link=NULL;
        previousNode=start;
        x++;
        while(x<=y){
            newNode=new node<int>;
            assert(newNode!=NULL);
            newNode->inf=x;
            newNode->link=NULL;
            previousNode->link=newNode;
            previousNode=newNode;
            x++;
        }
        newNode=NULL;
        delete newNode;
        previousNode=NULL;
        delete previousNode;
    }
    return start;
}

//3. Фунцкия, която изтрива всички срещания на елемента elem от списъка start
void removeAll(node<int>*& start, int elem){
    if(start){
        node<int>* toDelete=NULL;
        while(start && start->inf==elem){
            toDelete=start;
            start=start->link;
            toDelete=NULL;
            delete toDelete;
        }
        if(start){
            node<int>* copyStart=start, *previousNode=copyStart;
            while(copyStart->link){
                if(copyStart->link->inf==elem){
                    toDelete=copyStart->link;
                    previousNode->link=toDelete->link;
                    toDelete=NULL;
                    delete toDelete;
                }
                else{
                    copyStart=copyStart->link;
                    previousNode=copyStart;
                }
            }
            copyStart=NULL;
            delete copyStart;
            previousNode=NULL;
            delete previousNode;
        }
    }
}

//4. Фунцкия, която добавя към края на списъла l1 всички елементи на списъка l2.
template <typename T>
void append(node<T>*& l1, node<T>* l2){
    if(l2){
        if(l1){
            node<T>* copyL1=l1;
            while(copyL1->link){
                copyL1=copyL1->link;
            }
            node<T>* previousNode=copyL1, * newNode=NULL;
            while(l2){
                newNode=new node<T>;
                assert(newNode!=NULL);
                newNode->inf=l2->inf;
                newNode->link=NULL;
                previousNode->link=newNode;
                previousNode=newNode;
                l2=l2->link;
            }
            copyL1=NULL;
            delete copyL1;
            previousNode=NULL;
            delete previousNode;
            newNode=NULL;
            delete newNode;
        }
        else{
            l1=l2;
        }
    }
}

//5. Фунцкия, която съединява два списъка в нов, трети списък.
template <typename T>
node<T>* concat(node<T>* l1, node<T>* l2){
    node<T>* start=NULL;
    if(l1){
        node<T>* previousNode=NULL,* newNode=NULL;
        start=new node<T>;
        assert(start!=NULL);
        start->inf=l1->inf;
        start->link=NULL;
        previousNode=start;
        l1=l1->link;
        while(l1){
            newNode=new node<T>;
            assert(newNode!=NULL);
            newNode->inf=l1->inf;
            newNode->link=NULL;
            previousNode->link=newNode;
            previousNode=newNode;
            l1=l1->link;
        }
        while(l2){
            newNode=new node<T>;
            assert(newNode!=NULL);
            newNode->inf=l2->inf;
            newNode->link=NULL;
            previousNode->link=newNode;
            previousNode=newNode;
            l2=l2->link;
        }
        previousNode=NULL;
        delete previousNode;
        newNode=NULL;
        delete newNode;
    }
    else{
        start=l2;
    }
    return start;
}

//6. Функция, която прилага егноаргументна функция f:int->int към всеки от елементите на списъка с първи елемент start.
int addFive(int& x){
    x+=5;
    return x;
}
void map(node<int>*& start,int (*f)(int&)){
    if(start){
        node<int>* copyStart=start;
        while(copyStart){
            (*f)(copyStart->inf);
            copyStart=copyStart->link;
        }
    }
}

//7. Функция, която обръща реда на елеметите на списъка с първи елемент start.
template <typename T>
void reverse(node<T>*& start){
    if(start && start->link){
        node<T>* copyStart=start,*previousNode=NULL;
        start=new node<T>;
        assert(start!=NULL);
        start->inf=copyStart->inf;
        start->link=NULL;
        previousNode=start;
        copyStart=copyStart->link;
        while(copyStart){
            start=new node<T>;
            assert(start!=NULL);
            start->inf=copyStart->inf;
            start->link=previousNode;
            previousNode=start;
            copyStart=copyStart->link;
        }
        delete copyStart;
        previousNode=NULL;
        delete previousNode;
    }
}

//8. Фунцкия, която проверява дали в списък има дублиращи се елементи.
template <typename T>
bool hasElement(const T& elem, node<T>* start){
    if(start){
        while(start){
            if(start->inf==elem){
                return true;
                break;
            }
            start=start->link;
        }
    }
    return false;
}
template <typename T>
bool duplicates(node<T>* start){
    if(start){
        while(start){
            if(hasElement(start->inf, start->link)){
                return true;
                break;
            }
            start=start->link;
        }
    }
    return false;
}

//9. Фунцкия, която изтрива всички дублиращи се елементо от списък.
template <typename T>
void removeDuplicates(node<T>*& start){
    if(start && start->link){
        node<T>* toDelete=NULL;
        while(start->link && hasElement(start->inf, start->link)){
            toDelete=start;
            start=start->link;
            toDelete=NULL;
            delete toDelete;
        }
        if(start->link){
            node<T>* copyStart=start->link,*previousNode=start;
            while(copyStart->link && copyStart){
                if(hasElement(copyStart->inf, copyStart->link)){
                    toDelete=copyStart;
                    copyStart=copyStart->link;
                    previousNode->link=toDelete->link;
                    toDelete=NULL;
                    delete toDelete;
                }
                else{
                    previousNode=copyStart;
                    copyStart=copyStart->link;
                }
            }
            previousNode=NULL;
            delete previousNode;
            copyStart=NULL;
            delete copyStart;
        }
    }
}

//10. Фунцкия, която проверява дали даден списък е подреден в нарастваш или в намаляващ ред.
bool isSorted(node<int>* start){
    bool ascendingOrder=true, descendingOrder=true;
    if(start){
        while(start->link){
            if(start->inf>start->link->inf){
                ascendingOrder=false;
            }
            if(start->inf<start->link->inf){
                descendingOrder=false;
            }
            start=start->link;
        }
    }
    return ascendingOrder || descendingOrder;
}

//10. Фунцкия, която проверява дали даден списък е полиндром.
template <typename T>
int length(node<T>* start){
    int len=0;
    while(start){
        len++;
        start=start->link;
    }
    return len;
}
template <typename T>
bool palindrom(node<T>* start){
    int len=length(start);
    int splitLen=len/2;
    bool isPalindrome=true;
    if(splitLen>=1){
        node<T>* firstPart=NULL, *secondPart=NULL, *previousNode=NULL, *newNode=NULL;
        int countLen=0;
        firstPart=new node<T>;
        assert(firstPart!=NULL);
        firstPart->inf=start->inf;
        firstPart->link=NULL;
        previousNode=firstPart;
        start=start->link;
        countLen++;
        while(countLen<splitLen){
            newNode=new node<T>;
            assert(newNode!=NULL);
            newNode->inf=start->inf;
            newNode->link=NULL;
            previousNode->link=newNode;
            previousNode=newNode;
            start=start->link;
            countLen++;
        }
        if(len%2==1){
            start=start->link;
        }
        countLen=0;
        secondPart=new node<T>;
        assert(secondPart!=NULL);
        secondPart->inf=start->inf;
        secondPart->link=NULL;
        previousNode=secondPart;
        start=start->link;
        countLen++;
        while(countLen<splitLen){
            newNode=new node<T>;
            assert(newNode!=NULL);
            newNode->inf=start->inf;
            newNode->link=NULL;
            previousNode->link=newNode;
            previousNode=newNode;
            start=start->link;
            countLen++;
        }
        reverse(secondPart);
        while(firstPart){
            if(firstPart->inf!=secondPart->inf){
                isPalindrome=false;
                break;
            }
            firstPart=firstPart->link;
            secondPart=secondPart->link;
        }
        delete firstPart;
        delete secondPart;
        previousNode=NULL;
        delete previousNode;
        newNode=NULL;
        delete newNode;
    }
    return isPalindrome;
}
int main() {
    
    node<int>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL, *fourth=NULL, *fifth=NULL, *sixth=NULL;
    start=new node<int>;
    assert(start!=NULL);
    first=new node<int>;
    assert(first!=NULL);
    second=new node<int>;
    assert(second!=NULL);
    thirth=new node<int>;
    assert(thirth!=NULL);
    fourth=new node<int>;
    assert(fourth!=NULL);
    fifth=new node<int>;
    assert(fifth!=NULL);
    sixth=new node<int>;
    assert(sixth!=NULL);
    start->inf=1;
    start->link=first;
    first->inf=1;
    first->link=second;
    second->inf=2;
    second->link=thirth;
    thirth->inf=2;
    thirth->link=fourth;
    fourth->inf=3;
    fourth->link=fifth;
    fifth->inf=2;
    fifth->link=sixth;
    sixth->inf=5;
    sixth->link=NULL;
    
    node<int>* start2=NULL, *first2=NULL, *second2=NULL, *thirth2=NULL, *fourth2=NULL;
    start2=new node<int>;
    assert(start2!=NULL);
    first2=new node<int>;
    assert(first2!=NULL);
    second2=new node<int>;
    assert(second2!=NULL);
    thirth2=new node<int>;
    assert(thirth2!=NULL);
    fourth2=new node<int>;
    assert(fourth2!=NULL);
    start2->inf=1;
    start2->link=first2;
    first2->inf=2;
    first2->link=second2;
    second2->inf=3;
    second2->link=thirth2;
    thirth2->inf=2;
    thirth2->link=fourth2;
    fourth2->inf=1;
    fourth2->link=NULL;
        
    cout<<"---Print list---"<<endl;
    print(start);
    
    cout<<"\nElem 2: "<<count(2,start)<<endl;
    cout<<"\nElem 9: "<<count(9,start)<<endl;
    
    cout<<"\nRange 2 - 9"<<endl;
    print(range(2, 9));

    cout<<"\nRange 2 - 1"<<endl;
    print(range(2, 1));
    
    cout<<"\n---Remove element 2 from list---"<<endl;
    removeAll(start, 2);
    print(start);
    
    cout<<"\n---Append---"<<endl;
    append(start, start2);
    print(start);
    
    cout<<"\n---Concat---"<<endl;
    print(concat(start, start2));
    
    cout<<"\n---Map---"<<endl;
    map(start, &addFive);
    print(start);
    
    cout<<"\n---Reverse---"<<endl;
    reverse(start);
    print(start);
    
    cout<<"\nHas duplicates? ";
    if(duplicates(start2)){
        cout<<"> Yes"<<endl;
    }
    else{
        cout<<"> No"<<endl;
    }
    
    cout<<"\n---Remove duplicates---"<<endl;
    removeDuplicates(start);
    print(start);
    
    cout<<"\n---Ascending order or Descending order? ";
    if(isSorted(start2)){
        cout<<"> Yes"<<endl;
    }
    else{
        cout<<"> No"<<endl;
    }
    
    cout<<"\nPalinrome ";
    print(start2);
    if(palindrom(start2)){
        cout<<"> Yes"<<endl;
    }
    else{
        cout<<"> No"<<endl;
    }
    return 0;
}
