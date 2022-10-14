#pragma once
#ifndef _LINEAR_LIST_
#define _LINEAR_LIST_

#include "array";

//generic linear data table
template <typename T> 
class ADT
{
    private:
    T* adt;
    //use destructor.
    void DestroyList(){

    };
    //reset the ADT to an empty list.
    void ClearList();
    //check if the list is empty.
    bool ListEmpty();
    //return the length of the list
    int ListLength();
    //return the value of the nth element in the list.
    T GetElem(int n);
    //return the index of the elem argu in the list(if elem doesn't exist, throw an exception.)
    int LocateElem(const T elem);
    //check if the elem is in the list, if not, or if the element is the first in the list, throw an exception;
    //else return the index of the element.
    int PriorElem(T elem);
    //check if the elem is in the list, if not, or if the element is the last of the list, throw an exception;
    //else return the index of the element.
    int NextElem(T elem);
    //insert the elem in the front of the ith element(if the i is within the length of the list).
    void ListInsert(int i,T elem);
    //delete the ith element in the list and return the deleted value (if i is within the range of the list).
    T ListDelete(int i);
    //find the given element in the list(if not exist,return 0),and delete it.
    void ListElemDelete(T elem);
    //check every element in the list(print it out if exist and throw an exception if not exist).
    void ListTraverse();

    public:
    
    //constructor
    ADT(int n){
        adt = new T[n]();
    };

    T* ADTInit(){
        return adt;
    };

    ~ADT(){
        delete[] adt;
    };
    
    
};

#endif