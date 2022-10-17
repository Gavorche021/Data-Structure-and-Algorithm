#pragma once
#ifndef _LINEAR_LIST_
#define _LINEAR_LIST_

#include <iostream>

using namespace std;
//generic linear data table
template <typename T> 
class ADT
{
    private:
    int capacity=0;
    int currentElemCount=0;


    public:
    T* adt;

    //constructor
    ADT() = default;

    ADT(int n){
        ADTInit(n);
    };
    
    T* ADTInit(int n){
        capacity = n;
        adt = new T[n]();
        return adt;
        
    };
    

    T* ADTInit(T* initArray,int size){
        capacity=size;
        adt = initArray;
        return adt;
    };
    
    ~ADT(){
        delete adt;
    };
    //use destructor.
    void DestroyList(){
        this->~ADT();
    };
    //reset the ADT to an empty list.
    void ClearList()
    {
        this->adt = ADTInit(capacity);
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
    //!
    int LocateElem(const T elem){
        for(int i=0;i<ListLength();++i){
            if(elem == this->adt[i]) return i;
        }
        return -1;
    };

    //return if the elem is in the list.
    //!
    bool HasElem(const T elem){
        for(int i=0;i<ListLength();++i){
            if(elem == this->adt[i]) return true;
        }
        return false;
    };

    //check if the elem is in the list, if not, or if the element is the first in the list, throw an exception;
    //else return the index of the element.
    int PriorElem(T elem){
        if(adt[0]==elem){
            throw "first element, no element priors.";
        }
        for(int i = 1;i<capacity;++i){
            if(adt[i]==elem){
                return i;
            }
        }
        throw "element doesn't in the list.";
    };
    //check if the elem is in the list, if not, or if the element is the last of the list, throw an exception;
    //else return the index of the element.
    int NextElem(T elem){
        if(adt[capacity]==elem){
            throw "last element, no elements behind it.";
        }
        for(int i = 1;i<capacity;++i){
            if(adt[i]==elem){
                return i;
            }
        }
        throw "element doesn't in the list.";
    };
    //insert the elem in the front of the ith element(if the i is within the length of the list).i starts with 0.
    void ListInsert(T elem,int i){
        if(0<=i && i<capacity){
            ADT<T> temp(++capacity);
            for(int m=0;m<temp.ListLength();++m){
                if(m==i){
                    temp.adt[m]=elem;
                }
                else if (m<i)
                {
                    temp.adt[m]=adt[m];
                }
                else{
                    temp.adt[m]=adt[m-1];
                }
            }
            this->capacity = temp.ListLength();
            this->adt =temp.adt;
        }
        throw "i exceeds the range of the list.";
    };
    //insert the elem right at the end of the list. 
    void ListInsert(T elem){
        ADT<T> temp(++capacity);
        for(int m=0;m<temp.capacity-1;++m){
            temp.adt[m]=adt[m];
        }
        temp.adt[temp.capacity-1]=elem;
        this->capacity = temp.capacity;
        this->adt =temp.adt;
    };

    //delete the ith element in the list(starts from 0) and return the deleted value (if i is within the range of the list).
    T ListDelete(int i){
        if(0<=i && i<capacity){
            ADT<T> temp(--capacity);
            for(int m=0;m<capacity;++m){
                if(m<i){
                    temp.adt[m]=adt[m];
                }
                else if(m>i){
                    temp.adt[m-1]=adt[m];
                }
            }
            T tempValue = adt[i];
            return tempValue;
        }
        throw "i is out of range.";
    };
    //find the given element in the list(if not exist,throw an exception),and delete it.
    void ListElemDelete(T elem){
        for(int i=0;i<capacity;++i){
            if(adt[i]==elem){
                ADT<T> temp(--capacity);
                for(int m=0;m<capacity;++m){
                    if(m<i){
                        temp.adt[m]=adt[m];
                    }
                    else if(m>i){
                        temp.adt[m-1]=adt[m];
                    }
                }
                this->adt = temp.adt;
                this->capacity = temp.capacity;
            }
        }
        throw "elem not found in the list.";
    };
    //!
    //union the two lists(this and the passing list). this operation will union the common elements that both lists have.
    T* ListUnion(const ADT &u){
        for(int i = 0;i<u.ListLength();++i){
            if(!HasElem(u.adt[i])){
                ListInsert(u.adt[i]);
            }
        }
        return adt;
        // bool breakSignal = false;
        // for(int i =0;i<u.ListLength();++i){
        //     breakSignal=false;
        //     for(int m = 0;m<ListLength();++m){
        //         if(u.adt[i]==adt[m]){
        //             breakSignal = true;
        //             break;
        //         }
        //     }
        //     if(!breakSignal){
        //         ListInsert(u.adt[i]);
        //     }
        // }
        // return adt;
    };  

    void SwapElem(int index_a,int index_b){
        T temp = adt[index_b];
        adt[index_b]=adt[index_a];
        adt[index_a]=temp;
    };

    //! sort practice.
    //sort the list using bubble sort.
    void ListSort_Bubble(){
        
        for(int m = 0;m<capacity;++m){
            int i = m;
            while(i<capacity-1){
                if(adt[i]>adt[i+1]){
                    SwapElem(i,i+1);
                    ++i;
                }
            }
        }
    };

    void ListSort_Choose(){

    };

    void ListSort_Binary(){

    };

    void ListSort_Quick(){
        
    };
};

#endif