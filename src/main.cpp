#include <iostream>
#include "linear_list.h"

using namespace std;


int main(int argc, char *argv[])
{
	int* a = new int[5]{1,2,3,4,5};
	int* b = new int[5] {6,7,8,9,10};
	int* c = new int[5] {11,12,13,14,15};

	int* arr[] = { a,b,c };

	ADT<int*> arr_adt(arr, 3);
	cout<<arr_adt.HasElem(a)<<endl;

	int ai = 2;
	int bi = 3;
	int ci = 4;
	
	int arr_val[] = { ai,bi,ci };

	ADT<int> val_adt(arr_val,3);
	cout << val_adt.HasElem(ai) << endl;

	
	return 0;
}
