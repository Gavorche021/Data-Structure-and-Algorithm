#include <iostream>
#include "linear_list.h"

using namespace std;


int main(int argc, char *argv[])
{
	ADT<char> newchar(20);
	newchar.ClearList();
	newchar.ListInsert('s',4);
	cout<<newchar.adt[3]<<endl;

	ADT<int> s(8);
	int* ptr = s.ADTInit(5);
	int parray[4] = {1,2,3,4};
	int* ptr_array = s.ADTInit(parray,4);//初始化一个数组
	int i = s.ListLength();
	s.ClearList();
	s.ADTInit(0);
	bool tf = s.ListEmpty();
	cout<< ptr[0] <<endl;
	
	
	return 0;
}