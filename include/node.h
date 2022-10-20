#pragma once
#ifndef _NODE_
#define _NODE_

using namespace std;

template <typename T>
class Node{

private:
    int capacity;
    T elem;
    T lastNode;

public:
    T firstNode = nullptr;
    T lastNode;

    Node()=default;

    //初始化一个节点（链表） modified. 
    Node(T _elem){
        if(firstNode == nullptr){
            firstNode = _elem;
            lastNode = _elem;
            elem = _elem;
            capacity = 1;
        }
        else{
            throw;
        }
    };

    ~Node(){

    };

    Node(const Node &copy){

    };

    void InsertElem(T value,int index){
       
    }
    




};


#endif 


