//
//  main.cpp
//  LinkedList
//
//  Created by Simona Ivanova on 11.12.21.
//

#include <iostream>
#include "LinkedList.hpp"

int main() {
    node<int>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL, *start2=NULL, *first2=NULL;
    start=new node<int>;
    assert(start!=NULL);
    first=new node<int>;
    assert(first!=NULL);
    second=new node<int>;
    assert(second!=NULL);
    thirth=new node<int>;
    assert(thirth!=NULL);
    start->inf=4;
    start->link=first;
    first->inf=6;
    first->link=second;
    second->inf=10;
    second->link=thirth;
    thirth->inf=11;
    thirth->link=NULL;
    
    start2=new node<int>;
    assert(start2!=NULL);
    first2=new node<int>;
    assert(first2!=NULL);
    start2->inf=56;
    start2->link=first2;
    first2->inf=23;
    first2->link=NULL;
    
    LinkedList<int> l(start,thirth);
    l.print();
    cout<<endl;
    
    LinkedList<int> l2(start2,first2);
    l2.print();
    
    cout<<"\n---Add element to end---"<<endl;
    l.toEnd(100);
    l.print();
    
    cout<<"\n---Insert after---"<<endl;
    l.insertAfter(first, 8);
    l.print();
    
    cout<<"\n---Insert before---"<<endl;
    l.insertBefore(start, 22);
    l.print();
    
    cout<<"\n---Delete after---"<<endl;
    l.deleteAfter(second);
    l.print();
    
    cout<<"\n---Delete before---"<<endl;
    l.deleteBefore(second);
    l.print();
    
    cout<<"\n---Delete element---"<<endl;
    l.deleteElem(start);
    l.print();
    
    cout<<"\n---Length of list---"<<endl;
    cout<<l.length()<<endl;
    
    cout<<"\n---Concatenation of lists---"<<endl;
    l.concat(l2);
    l.print();
    
    cout<<"\n---Reverse list---"<<endl;
    l.reverse();
    l.print();
    
    return 0;
}
