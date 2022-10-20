#pragma once
#ifndef _LINEAR_LIST_
#define _LINEAR_LIST_

#include <iostream>
#include <string>

using namespace std;


//generic linear abstract data table.
template <typename T>
class ADT
{
private:
    int capacity = 0;
    T* adt;
    bool isOrdered = false;


    //sort the list using bubble sort.
    void ListSort_Bubble() {
        int unsorted_count = capacity - 1;
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int i = 0; i < unsorted_count; ++i) {
                if (adt[i] > adt[i + 1]) {
                    SwapElem(adt, i, i + 1);
                    sorted = false;
                }
            }
            --unsorted_count;
        }
    };

    void ListSort_Selection() {
        int mini_index = 0;
        for (int m = 0; m < capacity; ++m) {
            for (int i = m; i < capacity - 1; ++i) {
                if (adt[i] > adt[i + 1]) {
                    mini_index = i + 1;
                }
            }
            SwapElem(adt, m, mini_index);
        }
        isOrdered = true;
    };

    void ListSort_Insert_if() {
        for (int i = 1; i < capacity; ++i) {
            T temp = adt[i];
            for (int m = i; m > 0; --m) {
                if (adt[m - 1] > temp) {
                    adt[m] = adt[m - 1];
                    if (m == 1) {
                        adt[0] = temp;
                        break;
                    }
                }
                else {
                    adt[m] = temp;
                    break;
                }
            }

        }
    };

    void ListSort_Insert_while() {
        for (int i = 1; i < capacity; ++i) {
            T temp = adt[i];
            int m = i;
            while (adt[m - 1] > temp) {
                adt[m] = adt[m - 1];
                if (m == 1) {
                    adt[0] = temp;
                    break;
                }
                --m;
            }
            if (m != 1) {
                adt[m] = temp;
            }
        }
    }

    //only efficient and only can be used when the list is ordered.
    void ListSort_Binary() {
        if (isOrdered) {

        }
        else throw;
    };

    void ListSort_Quick(T* obj, int left_index, int right_index) {
        if (!(right_index - left_index <= 0)) {
            //每次返回的pivot_position都使该位置的元素排序完成（放在了正确的顺序位上）
            //pivot被放在了它的次序上，在它之前的元素都比它小，在它之后的元素都比它大,pivot就是第pivot_position大的元素（从0开始记序），Partition返回的值left_point就是元素pivot位置
            int pivot_position = Partition(obj, left_index, right_index);
            ListSort_Quick(obj, left_index, pivot_position - 1);
            ListSort_Quick(obj, pivot_position + 1, right_index);
        }
    };

    int Partition(T* obj, int left_point, int right_point) {
        int pivot_position = right_point;
        T pivot = obj[pivot_position];

        right_point = pivot_position - 1;

        while (1) {
            while (obj[left_point] < pivot) {
                ++left_point;
            }

            while (obj[right_point] > pivot) {
                --right_point;
            }

            if (left_point >= right_point) {
                SwapElem(obj, left_point, pivot_position);
                break;
            }
            else {
                SwapElem(obj, left_point, right_point);
            }
        }

        return left_point;
    }

    //!modifoed.
    T Quick_Choice(int kth, int left_index, int right_index) {
        if(right_index-left_index<=0)return adt[left_index];
        int pivot = Partition(adt, left_index, right_index);
        //pivot是该adt[pivot]元素的从0开始的次序，上一步代码代表从0开始记序的情况下，第pivot大的元素位于adt[pivot]的位置上
        if (pivot > kth) {
            Quick_Choice(kth, left_index, pivot - 1);
        }
        else if (pivot < kth) {
            Quick_Choice(kth, pivot + 1, right_index);
        }
        else {
            return adt[pivot];
        }
    }

public:
    //constructor
    ADT() = default;

    ADT(int size) {
        capacity = size;
        adt = new T[capacity]();
    };

    ADT(T* initPtr, int size) {
        capacity = size;
        adt = new T[size]();
        for (int i = 0; i < size; ++i) {
            adt[i] = initPtr[i];
        }
        return;
    };

    ADT(const ADT& copyADT) {
        adt = new T[capacity]();
        *adt = *copyADT.adt;
    }

    ~ADT() {
        delete[] adt;
        adt = NULL;
    };

    //use destructor.
    void DestroyList() {
        this->~ADT();
    };

    void ADTInit(int n) {
        capacity = n;
        delete[] adt;
        adt = new T[n]();
        return;
    };
    //reset the ADT to an empty list.
    void ClearList()
    {
        ADTInit(capacity);
    };

    //check if the list is empty.
    bool ListEmpty() {
        if (capacity == 0)
            return true;
        else return false;
    };

    //return the length of the list
    int ListLength() {
        return capacity;
    };

    //return the value of the nth element in the list.
    T GetElem(int n) {
        return adt[n];
    };

    //return the index of the elem argu in the list(if elem doesn't exist, throw an exception.)

    int LocateElem(const T& elem) {
        for (int i = 0; i < ListLength(); ++i) {
            if (elem == adt[i]) return i;
        }
        return -1;
    };

    //return if the elem is in the list.

    bool HasElem(const T& elem) {
        for (int i = 0; i < ListLength(); ++i) {
            if (elem == adt[i]) return true;
        }
        return false;
    };

    //check if the elem is in the list, if not, or if the element is the first in the list, throw an exception;
    //else return the index of the element.

    int PriorElem(const T& elem) {
        if (adt[0] == elem) {
            throw;
        }
        for (int i = 1; i < capacity; ++i) {
            if (adt[i] == elem) {
                return i;
            }
        }
        throw;
    };
    //check if the elem is in the list, if not, or if the element is the last of the list, throw an exception;
    //else return the index of the element.

    int NextElem(const T& elem) {
        if (adt[capacity] == elem) {
            throw;
        }
        for (int i = 1; i < capacity; ++i) {
            if (adt[i] == elem) {
                return i;
            }
        }
        throw;
    };
    //insert the elem in the front of the ith element(if the i is within the length of the list).i starts with 0.
    //the i indicates the sequence of the element(starts from 1).to visit it, you need to make index i minus 1.
    void ListInsert(const T& elem, int i) {
        if (0 < i && i <= capacity) {
            ADT<T> temp(++capacity);
            for (int m = 0; m < temp.capacity; ++m) {
                if (m == i - 1) {
                    temp.adt[m] = elem;
                }
                else if (m < i - 1)
                {
                    temp.adt[m] = adt[m];
                }
                else {
                    temp.adt[m] = adt[m - 1];
                }
            }
            this->adt = new T[capacity];
            for (int i = 0; i < capacity; ++i) {
                this->adt[i] = temp.adt[i];
            }

            return;
        }
        throw;

    };
    //insert the elem right at the end of the list. 
    void ListInsert(const T& elem) {
        ADT<T> temp(++capacity);
        for (int m = 0; m < temp.capacity - 1; ++m) {
            temp.adt[m] = adt[m];
        }
        temp.adt[temp.capacity - 1] = elem;
        this->adt = new T[capacity];
        for (int i = 0; i < capacity; ++i) {
            this->adt[i] = temp.adt[i];
        }
        return;
    };

    //delete the ith element in the list and return the deleted value (if i is within the range of the list).
    T ListDelete(int i) {
        if (0 <= i && i < capacity) {
            ADT<T> temp(--capacity);
            for (int m = 0; m < capacity; ++m) {
                if (m < i) {
                    temp.adt[m] = adt[m];
                }
                else if (m > i) {
                    temp.adt[m - 1] = adt[m];
                }
            }
            T tempValue = adt[i];
            return tempValue;
        }
        throw;
        
    };
    //find the given element in the list(if not exist,throw an exception),and delete it.
    void ListElemDelete(const T& elem) {
        for (int i = 0; i < capacity; ++i) {
            if (adt[i] == elem) {
                ADT<T> temp(--capacity);
                for (int m = 0; m < capacity; ++m) {
                    if (m < i) {
                        temp.adt[m] = adt[m];
                    }
                    else if (m > i) {
                        temp.adt[m - 1] = adt[m];
                    }
                }
                this->adt = new T[capacity];
                for (int i = 0; i < capacity; ++i) {
                    this->adt[i] = temp.adt[i];
                }
                return;
            }
        }
        throw;
    };

    //union the two lists(this and the passing list). this operation will union the common elements that both lists have.
    T* ListUnion(const ADT& u) {
        for (int i = 0; i < u.ListLength(); ++i) {
            if (!HasElem(u.adt[i])) {
                ListInsert(u.adt[i]);
            }
        }
        return adt;
    };

    void SwapElem(T* obj, int index_a, int index_b) {
        T temp = adt[index_b];
        adt[index_b] = adt[index_a];
        adt[index_a] = temp;
    };

    //change if the input reference is an ordered list.
    void IsOrdered(bool ifIs) {
        isOrdered = ifIs;
    };

    void Sort() {
        ListSort_Quick(adt, 0, capacity - 1);
    }

    //!modified.
    //based on partition and quick sort.
    //finds the kth small element of the adt and return the element.
    //starts with 0,ranging(0,capacity-1);
    T ChoiceKth_starts_with_0(int kth) {
        if (0 <= kth && kth < capacity) return Quick_Choice(kth, 0, capacity - 1);
        else throw;
    }
    //starts with 1,ranging(1,capacity);
    T ChoiceKth_starts_with_1(int kth) {
        --kth;
        if (0 <= kth && kth < capacity) return Quick_Choice(kth, 0, capacity - 1);
        else throw;
    }
};
#endif