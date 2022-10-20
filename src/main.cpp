#include <iostream>
#include "linear_list.h"

using namespace std;


int main(int argc, char* argv[])
{
	ADT<char> newchar(20);
	newchar.ClearList();
	newchar.ListInsert('s', 4);
	cout << newchar.GetElem(3) << endl;

	int test_array[] = { 11,2,13,56,248,1,75,84,111,93 };

	// ADT<int> bubble_test_adt(test_array,14);
	// bubble_test_adt.ListSort_Bubble();
	// for(int i=0;i<bubble_test_adt.ListLength();++i){
	// 	cout<<bubble_test_adt.GetElem(i)<<endl;
	// }

	// ADT<int> insert_test_adt(test_array,2);
	// insert_test_adt.Sort();
	// for(int i=0;i<insert_test_adt.ListLength();++i){
	// 	cout<<insert_test_adt.GetElem(i)<<endl;
	// }
	ADT<int> quick_choice_test_adt(test_array, 10);
	cout << quick_choice_test_adt.ChoiceKth_starts_with_0(5) << endl;//6th
	cout << quick_choice_test_adt.ChoiceKth_starts_with_1(5) << endl;//5th

	return 0;
}