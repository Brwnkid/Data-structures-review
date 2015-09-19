#ifndef ASTACK_H_
#define ASTACK_H_

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> class Astack{
public:
	Astack(int capacity = 100){
		cap = capacity;
		mySize = 0;
		stack = new T[cap];
	}

	~Astack(){
		delete[] stack;
	}

	void push(T& t){
		if(mySize == cap){
			increase_capacity();
		}
		stack[mySize] = t;
		mySize++;
	}

	void pop(){
		if(empty()){
			throw logic_error("Stack is empty");
		}
		mySize--;
	}

	T top() const{
		if (mySize == 0){
			throw logic_error("Stack is empty");
		}
		return stack[mySize-1];
	}

	void increase_capacity(){
		cap *= 2;
		T* newStack = new T[cap];
		for(int i = 0;i < mySize; i++){
			newStack[i] = stack[i];
		}
		delete[] stack;
		stack = newStack;
	}

	bool empty(){
		return (mySize == 0);
	}

	int size(){
		return mySize;
	}

private:
	T* stack;
	int cap;
	int mySize;
};


#endif
