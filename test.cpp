#include <iostream>

using namespace std;

#include "Linkedlist.h"

int main(){
	Linkedlist<int> a;

	for(int i = 0; i < 5; i++){
		a.push_back(i);
		a.insert(i,i);
	}
	cout << a.size() << endl;
	for(int i = 0; i < 10; i++){
		cout << a.top() << endl;
		//a.remove_back();
		a.removeAt(a.size());
	}
	cout << endl;
	return 0;
}
