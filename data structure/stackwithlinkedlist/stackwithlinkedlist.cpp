#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *link;
};
struct node *top=NULL;
int isEmpty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}
void push(int data){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL){
		cout<<"satck overflow";
		return;
	}
	p->data=data;
	p->link=top;
	top=p;	
}
int pop(){
	if(isEmpty()){
		cout<<"stack underflow";
		exit(1);
	}
	int data=top->data;
	struct node*p=top;
	top=top->link;
	free(p);
	return data;
}
int peek(){
	if(isEmpty()){
		cout<<"stack underflow";
		exit(1);
	}
	int data=top->data;
	return data;	
}
void display(){
	if(isEmpty()){
		cout<<"stack underflow";
		exit(1);
	}
	for(struct node *p=top;p!=NULL;p=p->link){
		cout<<p->data;
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
			data=peek();
			cout<<data;
			break;
		case 4:
			display();
			break;
		case 5:
			exit(1);
			break;
		default :
			cout<<"wrong choice";
			break;
	}
}
return 0;
}
