#include<iostream>
#define max 10
using namespace std;

int stack[max];
int top=-1;
int isFull(){
	if(top==max-1){
		return 0;
	}
	else{
		return 1;
	}
}
int isEmpty(){
	if(top==-1)
		return 0;
	else
		return 1;
}
void push(int data){
	if(isFull()){
		top=top+1;
		stack[top]=data;
		cout<<"data inserted successfully\n";
	}
	else{
		cout<<"stack is full data cannot be inserted\n";
	}
}
int pop(){
	if(isEmpty()){
		int element=stack[top];
		top=top-1;
		return element;
	}
	else{
		exit(1);
	}
}

void peek(){
	if(isEmpty()){
		cout<<stack[top];
	}
	else{
		cout<<"stack is empty\n";
	}
	
}
void display(){
	if(isEmpty()==0){
		cout<<"stack is empty\n";
		return;
	}
	for(int i=top;i>-1;i--){
		cout<<stack[i];
	}
}
int main(){
	int choice,data;
	while(1){
	
	cout<<"1.push\n";
	cout<<"2.pop\n";
	cout<<"3.display top element\n";
	cout<<"4.display all element\n";
	cout<<"5.quit\n";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"enter the data";
			cin>>data;
			push(data);
			break;
		case 2:
			data=pop();
			cout<<data;
			break;
		case 3: 
			peek();
			break;
		case 4:
			display();
			break;
		case 5:
			exit(1);
			break;
		default :
			cout<<"wrong choice";
	}
}
return 0;
}
