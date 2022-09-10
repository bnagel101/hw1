#include<iostream>
#include "split.h"
using namespace std;

int main(){
	Node* a = new Node(1, nullptr);
	Node* b = new Node(2, nullptr);
	Node* c = new Node(3, nullptr);
	Node* d = new Node(4, nullptr);
	Node* e = new Node(5, nullptr);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = new Node(6, new Node(7, new Node(8, new Node(9, nullptr))));
	Node* even = nullptr;
	Node* odd = nullptr;
	cout << "HI" << endl;
	split(a,odd,even);
	while(odd != nullptr){
		//cout << del->value <<endl;
		Node* del = odd;
		odd = odd->next;
		delete del;
	}
	while(even != nullptr){
		//cout << del->value <<endl;
		Node* del = even;
		even = even->next;
		delete del;
	}
	
}