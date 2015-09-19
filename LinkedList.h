#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <stdexcept>

using namespace std;

template <class G> class Node{
public:
	G value;
	Node<G>* next;
};

template <class T> class Linkedlist{
public:
	Linkedlist(){
		head = NULL;
		tail = NULL;
		mySize = 0;
	}

	virtual ~Linkedlist(){
		Node<T>* cur_node = head;
		Node<T>* next_node = NULL;
		while(cur_node != NULL){
			next_node = cur_node->next;
			delete cur_node;
			cur_node = next_node;
		}
		head = NULL;
		tail = NULL;
		mySize = 0;
	}

	void push_back(T &t){
		Node<T>* newNode = new Node<T>;
		newNode->value = t;
		if(head == NULL){
			head = newNode;
		}else{
			tail->next = newNode;
		}
		tail = newNode;
		mySize++;
	}

	void prepend(T &t){
		Node<T>* newNode = new Node<T>;
		newNode-> value = t;
		newNode->next = head;
		head = newNode;
		if(tail == NULL){
			tail = newNode;
		}
		mySize++;
	}

	void insert(int loc, T& t){
		if(loc > mySize){
			throw logic_error("location is not within the list");
		}
		while(loc < 0){
			loc += mySize;
		}
		if (loc == 0){
			prepend(t);
		}else if(loc == mySize){
			push_back(t);
		}else{
			Node<T>* cur = head;
			for(int i = 1; i < loc; i++){
				cur=cur->next;
			}
			Node<T>* newNode = new Node<T>;
			newNode->value = t;
			newNode->next = cur->next;
			cur->next = newNode;
			mySize++;
		}
	}



	T top() const{
		if (empty()){
			throw logic_error("Location out of bounds.");;
		}
		return tail->value;
	}

	void remove_back(){
		if (empty()){
			throw logic_error("List is empty");
		}else if(head == tail){
			delete head;
			head = NULL;
			tail = NULL;
		}else{
			Node<T>* cur = head;
			while(cur->next != tail){
				cur = cur->next;
			}
			delete tail;
			tail = cur;
		}
		mySize--;
	}

	void remove_front(){
		if (empty()){
			throw logic_error("List is empty");
		}else if(head == tail){
			delete head;
			head = NULL;
			tail = NULL;
		}else{
			Node<T>* curhead = head;
			head = head->next;
			delete curhead;
		}
		mySize--;
	}

	void removeAt(int loc){
		if(loc > mySize){
			throw logic_error("location is not within the list");
		}
		while(loc < 0){
			loc += mySize;
		}
		if (loc == 0){
			remove_front();
		}else if(loc == mySize){
			remove_back();
		}else{
			Node<T>* cur = head;
			for(int i = 1; i < loc; i++){
				cur = cur->next;
			}
			Node<T>* temp = cur->next;
			cur->next = temp->next;
			delete temp;
		}
	}

	unsigned int size() const{
		return mySize;
	}

	bool empty() const{
		if (mySize == 0){
			return true;
		}
		return false;
	} 

private:
	Node<T>* head;
	Node<T>* tail;
	unsigned int mySize;
};

#endif
