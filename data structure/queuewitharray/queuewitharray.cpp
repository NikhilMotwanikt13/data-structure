#include<iostream>
#define max 10
using namespace std;

int queue[10];
int front=-1;
int rear=-1;
int isFull(){
	if(rear==front-1 || (rear==max-1 && front==0)){
		return 1;
	}
	else 
		return 0;
}
int isEmpty(){
	if(rear==-1 && front==-1){
		return 1;
	}
	else
		return 0;
}
void insert(int data){
	if(isFull()){
		cout<<"queue is full\n";
		return;
	}
	else{
	
	if(rear==-1){
		rear=rear+1;
		queue[rear]=data;
		front=front+1;
		return;
	}
	if(rear==max-1){
		rear=0;
		queue[rear]=data;
	}
	rear=rear+1;
	queue[rear]=data;
}
}
int del(){
	if(isEmpty()){
		cout<<"queue is empty\n";
		exit(1);
	}
	if(rear==front){
		int data=queue[rear];
		rear=-1;
		front=-1;
		return data;
	}
	if(front==max-1){
		int data=queue[front];
		front=0;
		return data;
	}
	else{
	int data=queue[front];
	front++;
	return data;
}
}
void peek(){
	if(isEmpty()){
		cout<<"queue is empty\n";
		exit(1);
	}
	else{
		cout<<queue[front];
	}
}
void display(){
	if(isEmpty()){
		cout<<"queue is empty\n";
		exit(1);
	}
	if(front<rear){
		for(int q=front;q<=rear;q++){
			cout<<queue[q];
		}
	}
	if(front>rear){
		for(int q=front;q<=max-1;q++){
			cout<<queue[q];
		}
		for(int q=0;q<=rear;q++){
			cout<<queue[q];
		}
	}
}

int main(){
	int choice,data;
	while(1){
	
	cout<<"1.insert\n";
	cout<<"2.delete\n";
	cout<<"3.display front element\n";
	cout<<"4.display all element\n";
	cout<<"5.quit\n";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"enter the data\n";
			cin>>data;
			insert(data);
			break;
		case 2:
			data=del();
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
			cout<<"wrong choice\n";
	}
}
return 0;
	
}
