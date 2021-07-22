#include <iostream>
using namespace std;

class ArrayStack {

private:
	int* A;
	int size;
	int length;

public:
	void Stack();
	void Stack(int user_size);
	void ~Stack();
	bool isFull();
	bool isEmpty();
	void display();
	void Pop(); // removes top
	void Push(int x); //return top value;
	void peek(); // returns top value



};