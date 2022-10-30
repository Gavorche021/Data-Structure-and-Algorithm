#pragma once

#ifndef _NODE_
#define _NODE_

using namespace std;

template<typename T>
struct Node {
    T element;
    struct Node<T>* nextNode;
};

template<typename T>
class LinkList
{
private:
    struct Node<T>* head;

public:
    LinkList() { head = nullptr; };

    LinkList(const Node<T>& node) {
        head = new struct Node<T>;
        head->element = node.element;
        head->nextNode = node.nextNode;
    };

    LinkList(const T& t) { 
        head = new struct Node<T>;
        head->element = t;
        head->nextNode = nullptr;
    };

    ~LinkList() {
        Node<T>* temp = head;
        while (head != nullptr) {
            temp = head;
            head = head->nextNode;
            delete temp;
        }
    };

    LinkList(const LinkList<T>& copylink) {
        head = new struct Node<T>;
        *head = *copylink.head;
    };

    bool Clear() {
        Node<T>* temp = head;
        while (head != nullptr) {
            temp = head;
            head = head->nextNode;
            delete temp;
        }
    };

    bool isEmpty() { return head == nullptr; }

    //返回链表长度
    int Length() {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            ++count;
            temp = temp->nextNode;
        }
        return count;
    };

    //通过下标返回元素
    T GetElem(int i) {
        Node<T>* temp = head;
        if (head != nullptr) {
            while (i != 0 && temp != nullptr) {
                --i;
                temp = temp->nextNode;
            }
            return temp->element;
        }
        return nullptr;
    };

    //通过元素返回下标
    int LocateElem(const T& elem) {
        Node<T>* temp = head;
        int index = 0;
        while (temp->element != elem && temp!=nullptr) {
            temp = temp->nextNode;
            ++index;
        }
        if (temp != nullptr) return index;
        else return nullptr;
    };

    //通过元素返回前一个元素
    T PriorElem(const T& elem) {
        Node<T>* temp = head;
        Node<T>* pretemp = head;
        while (temp->element != elem && temp != nullptr) {
            pretemp = temp;
            temp = temp->nextNode;
        }
        return pretemp->element;

    };


    T NextElem(const T& elem) {
        Node<T>* temp = head;
        Node<T>* nextTemp = head->nextNode;
        while (temp->element != elem && nextTemp != nullptr) {
            temp = temp->nextNode;
            nextTemp = temp->nextNode;
        }
        if (nextTemp == nullptr) return nullptr;
        else return nextTemp->element;
    };

    void Insert(int index, const Node<T> &node) {
        Node<T>* curNode = head;
        Node<T>* lastNode = head;
        while (index != 0 && curNode != nullptr) {
            --index;
            lastNode = curNode;
            curNode = head->nextNode;
        }

        lastNode->nextNode = &node;
        node->nextNode = curNode;
    };
    //输入index为linkList最后一位元素下标时，在队尾插入。
    void AddNode(const Node<T>& node) {
        int length = Length();
        if (length == 0) {
            *head = node;
        }
    };

    //按index删除，并返回删除的元素（指针）
    T Delete(int index) {
        Node<T>* temp = head;
        Node<T>* lastNode = head;
        while (index != 0 && temp != nullptr) {
            --index;
            lastNode = temp;
            temp = temp->nextNode;
        }
        Node<T>* nextNode = temp->nextNode;
        lastNode->nextNode = nextNode;
        T ret = temp->element;
        delete temp;
        return ret;
    };

    struct Node<T>* Reverse() {
        int length = Length();
        int i = length;
        Node<T>* temp = head;
        Node<T>* temp_reverse = head;
        Node<T>* lastNode = head;
        while (i-1 != 0 && temp != nullptr) {
            --i;
            if (i == length - 1) {
                temp = temp->nextNode;
                lastNode->nextNode = nullptr;
            }
            else {
                temp_reverse = lastNode;
                lastNode = temp;
                temp = temp->nextNode;
                lastNode->nextNode = temp_reverse;
            }
        }
    };

};

#endif 
