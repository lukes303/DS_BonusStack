
#include <iostream>

using namespace std;

class MyStack {

private:

	int* stack; 

	int itop;

	int arraySize = 2;;

public:

	// This function pushes x into the stack. 
	// Push should always be successful even 
	// if the stack array is currently "full". 
	void push(int x);

	// This function removes the top element 
	// in the stack. It does nothing if the 
	// stack is empty.
	void pop();

	// This function returns the top element 
	// in the stack. It returns -1 if the stack 
	// is empty. 
	int top();

	// This function returns number of elements 
	// in the stack. Note this means it should 
	// return 0 if the stack is empty. 
	int Ssize();

	// This function is given to you. 
	// It initializes a small array. 
	// Do not modify it.  
	MyStack();
};

MyStack::MyStack() {
	stack = new int[2];
	itop = -1;
};

void MyStack::push(int x) {

	//push is always sucessful, so increment itop
	itop++;

	//if itop exceeds the current size of our array, create a new larger array, copy elements over from old array, and replace
	if(itop >= arraySize){
		int* stack_new = new int[arraySize + 10];

		for(int i = 0; i < arraySize; i++){
			stack_new[i] = stack[i];
		}

		arraySize = arraySize + 10;

		delete stack;

		stack = stack_new;
	}

	//add element at itop index
	stack[itop] = x;
	
	// if itop > size
	// stack_new = new int[longer size]
	// 
	// copy stack to stack_new
	// 
	// add x to the top of the stack 
};

void MyStack::pop(){
	if(itop != -1) itop--;
}

int MyStack::top(){
	if(itop == -1) return -1;
	else return stack[itop];
}

int MyStack::Ssize(){
	return itop + 1;
};

int main()
{
	MyStack x;

	int temp;

	while (cin >> temp) {
	
		x.push(temp);
	}

	int initialSize = x.Ssize();

	for (int i = 0; i < initialSize; i++) {
	
	  	cout << x.top() << '\n';

	  	x.pop();	
	}

	return 0;
}

