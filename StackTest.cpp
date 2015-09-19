#include <iostream>
#include "Astack.h"
#include "LinkedStack.h"

using namespace std;

int main(){

	//Astack<int> a(10);
	LinkedStack<int> a;

	for(int i = 0; i < 10000; i++){
		a.push(i);
		cout << a.top() << " ";
		//a.pop();
	}

	cout << "size:" << a.size() << endl;
	cout << endl;
	return 0;
}
