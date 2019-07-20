#include<iostream>
#include<conio.h>

using namespace std;

class stack{
	private: 
		int block[50];
		int top;
	public:
		stack(){
			top=-1;
		}
		bool isFull();
		bool isEmpty();
		void push(int);
		void pop();
		int peek();
		int depth();
};

bool stack::isFull(){
	if(top==49)
		return true;
	else
		return false;
}

bool stack::isEmpty(){
	if(top==-1)
		return true;
	else
		return false;
}

void stack::push(int key){
	if(isFull()){
		cout<<"Stack Full! Overflow!";
		getch();
	}
	else{
		top++;
		block[top] = key;
	}
}

void stack::pop(){
	if(isEmpty()){
		cout<<"Stack Empty! Underflow!";
		getch();
	}
	else{
		int temp = block[top];
		top--;
		cout<<endl<<temp<<"  popped!\n";
	}
}

int stack::peek(){
	if(!isEmpty()){
		cout<<"\nElement on top: "<<block[top]<<"\t";
		cout<<endl;
	}
	else{
		cout<<"\nStack Empty!";
	}
}

int stack::depth(){
	return top+1;
}

int main(){
	stack s;
	cout<<"\t\t\tStack"<<endl;
	//MENU HERE
	return 0;
}
