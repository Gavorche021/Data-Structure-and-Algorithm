#include <iostream>

#include "linear_list.h"

using namespace std;


int main(int argc, char *argv[])
{
	ADT<int> s(8);
	int* ptr = s.ADTInit();
	cout<< ptr[5] <<endl;
	
	
}