/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;
#include "ulliststr.h"

int main(int argc, char* argv[])
{


	ULListStr *a = new ULListStr();

	//testing push_front(), push_back()
	for(int i = 0; i < 50; i++){
		if(i%2 == 0){
			a->push_front("A");
		}else{
			a->push_back("B");
		}
	}
	//Testing front and back functions
	if(a->front() != "A" || a->back() != "B"){
		cout << "Error" << endl;
	}

	//Testing getValAtLoc function by using get function
	for(int i = 0; i < 50; i++){
		if(i < 25 && a->get(i) != "A"){
			cout << "Error" << endl;
		}else if(i >= 25 && i < 50 && a->get(i) != "B"){
			cout << "Error" << endl;
		}
	}
	//Testing pop_back(), pop_front()
	for(int i = 0; i < 50; i++){
		if(i%2 == 0){
			a->pop_front();
		}else{
			a->pop_back();
		}
	}
	//checking size function
	if(a->size() != 0){
		cout << "Error" << endl;
	}
	//testing pop_back/front on empty list to show they do nothing
	a->pop_back(); 
	a->pop_front();
	//Unclear if assignment wanted to test for front() and back() functions when
	//head and tail nodes are set to null, but my code throws an invalid argument

	a->clear();
	delete a;
	cout << "Everything works" << endl;
  return 0;
}
