#include <iostream>
#include "Astack.h"

using namespace std;

int main(){

	Astack<int> a(10);

	for(int i = 0; i < 1000000; i++){
		a.push(i);
		//cout << a.top() << " ";
		//a.pop();
	}

	cout << "size:" << a.size() << endl;
	cout << endl;
	return 0;
}
