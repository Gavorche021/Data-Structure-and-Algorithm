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
    int capacity=0;

    public:
    //constructor
    ADT(int n){
        ADTInit(n);
    };
    
    T* ADTInit(int n){
        capacity = n;
        adt = new T[n]();
        return adt;
    };

    T* ADTInit(T* initArray){
        capacity=sizeof(initArray)/sizeof(T);
        adt = initArray;
        return adt;
    };
    
    ~ADT(){
        delete[] adt;
    };
    //use destructor.
    void DestroyList(){
        this->~ADT();
    };
    //reset the ADT to an empty list.
    T* ClearList()
    {
        this->~ADT();
        ADTInit(capacity);

        return adt;
    };
    //check if the list is empty.
    bool ListEmpty(){
        if(capacity==0)
            return true;
        else return false;
    };

    //return the length of the list
    int ListLength(){
        return capacity;
    };
    //return the value of the nth element in the list.
    T GetElem(int n){
        return adt[n];
    };
    //return the index of the elem argu in the list(if elem doesn't exist, throw an exception.)
    int LocateElem(const T elem){

        for(int i=0;i<ListLength();++i){
            if(elem == atd[i]) return i;
        }
        throw "Element doesn't exist.";
        return 0;
        
    };
    //check if the elem is in the list, if not, or if the element is the first in the list, throw an exception;
    //else return the index of the element.
    int PriorElem(T elem);
    //check if the elem is in the list, if not, or if the element is the last of the list, throw an exception;
    //else return the index of the element.
    int NextElem(T elem);
    //insert the elem in the front of the ith element(if the i is within the length of the list).i starts with 0.
    void ListInsert(T elem,int i){
        if(0<=i && i<=capacity){
            ADT<T> temp(++capacity);
            for(int m=0;m<temp.capacity;++m){
                if(m==i){
                    temp.adt[m]=elem;
                }
                else if (m<i)
                {
                    temp.adt[m]=adt[m]
                }
                else{
                    temp.adt[m]=adt[m-1];
                }
            }
            return;
        }
        throw "i exceeds the range of the list.";
        return;
    };
    //insert the elem right in the next index, if the range is exceeded, expand the adt. 
    void ListInsert(T elem);

    //delete the ith element in the list and return the deleted value (if i is within the range of the list).
    T ListDelete(int i);
    //find the given element in the list(if not exist,return 0),and delete it.
    void ListElemDelete(T elem);
    //check every element in the list(print it out if exist and throw an exception if not exist).
    void ListTraverse();
    
    
};

#endif