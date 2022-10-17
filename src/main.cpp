#include <iostream>
#include "linear_list.h"

using namespace std;


int main(int argc, char *argv[])
{
	ADT<char> newchar(20);
	newchar.ClearList();
	newchar.ListInsert('s',4);
	cout<<newchar.adt[3]<<endl;

	return 0;
}