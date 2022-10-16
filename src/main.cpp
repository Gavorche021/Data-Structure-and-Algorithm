#include <iostream>
#include "linear_list.h"

using namespace std;


int main(int argc, char *argv[])
{
	
	char* newchar = new char[5] {'a', 'b', 'c', 'd'};
	char* charptr = new char[5];
	char* charArrayptr = charptr;
	const int& charArrayRef = 1;
	int* newI = new int[5] {1, 2, 3, 4, 5};
	int Bint[] = {1,2,3,4,5,6};
	ADT<int> newint0(Bint, 6);
	ADT<char> refint(charArrayptr,5);
	ADT<int> newint(newI,5);
	newint.ClearList();
	newint.ListInsert(5,5);
	cout<< newint.GetElem(4) << endl;

	ADT<int> s(8);
	s.ADTInit(5);
	int parray[4] = {1,2,3,4};
	ADT<int> s_ary(parray,4);//初始化一个数组
	int i = s.ListLength();
	s.ClearList();
	s.ADTInit(0);
	bool tf = s.ListEmpty();

	return 0;
}