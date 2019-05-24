#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
int data;
struct node *link;
};
void display(struct node *start){
	if(start==NULL){
		cout<<"list is empty";
		return;	
	}
	cout<<"list is:";
	while(start!=NULL){
		cout<<start->data;
		start=start->link;
		
	}
	
}
int count(struct node *start){
	int count=0;
	if(start==NULL){
		cout<<"list is empty";
		return 0;
	}
	while(start!=NULL){
		start=start->link;
		count++;
	}
	return count;
}
void search(struct node *start,int item){
	int pos=0;
	if(start==NULL){
		cout<<"list is empty";
		return;
	}
	while(start!=NULL){
		if(start->data==item){
			cout<<pos+1;
			return;
		}
		start=start->link;
		pos++;		
	}
	cout<<"data not found";
}
struct node * addatbeg(struct node *start, int data){
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->link=start;
	start=p;
	p->data=data;
	return start;
}
void addatend(struct node * start,int data){
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	while(start->link!=NULL){
		start=start->link;
	}
	start->link=p;
	p->link=NULL;
	p->data=data;
}
void addafternode(int data,struct node *start,int item){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	while(start->data!=item){
		start=start->link;
	}
	if(start->link==NULL){
		cout<<"element not found";
		return;
	}
	p->link=start->link;
	start->link=p;
	p->data=data;
	return;	
}
void addbeforenode(int data,struct node *start,int item){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	while(start->data!=item){
		start=start->link;
	}
	
	if(start->link==NULL){
		cout<<"element not found";
		return;
	}
	p->link=start->link;
	start->link=p;
	p->data=data;
	return;	
}
struct node * addatpos(int data,struct node *start,int pos){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=data;\
	struct node *temp=start;
	for(int a=1;a<pos && start->link!=NULL;a++){
		start=start->link;
		
	}
	p->link=start;
	start=p;
	if(pos==1){
		return start;
	}
	else{
		return temp;
	}
	
}
struct node * del(struct node* start,int item){
	struct node * temp=start;
	
	while(start->link!=NULL && start->data!=item){
		start=start->link;
	}
	if(start->data==item){
		if(start==temp){
			struct node *p=start;
		start=start->link;
		cout<<"element has been deleted ";
		free(p);
		return start;
	}
		else{
		start=start->link;
		struct node *p=start;
		cout<<"element has been deleted ";
		free(p);
		return temp;
			
		}
		}
	
	if(start->link==NULL){
		cout<<"element not found";
	}
	
}
struct node * reverse(struct node * start){
	struct node *p,*q,*n;
	p=NULL;
	q=start;
	
	while(q->link!=NULL){
		n=q->link;
		q->link=p;
		p=q;
		q=n;
			
	}
	start=p;
}
struct node * createlist(struct node *start){
	int num,data;
	struct node *q;
	cout<<"enter the no. of element to be inserted";
	cin>>num;
	if(num>0){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	start=p;
	cout<<"enter the data";
	cin>>data;
	p->data=data;
	p->link=NULL;
	}
	for(int i=1;i<num;i++){
		cout<<"enter the data";
		cin>>data;
		addatend(start,data);
	}
	return start;
}


int main(){
int choice=1,data,item,position;
struct node * start=NULL;
while(1){
cout<<"enter the choice \n";
cout<<"1.creating linked list\n";
cout<<"2.display \n";
cout<<"3.count the element \n";
cout<<"4.search \n";
cout<<"5.add to empty list \n";
cout<<"6.add at end \n";
cout<<"7.add after node \n";
cout<<"8.add before node\n";
cout<<"9.add at position \n";
cout<<"10.delete \n";
cout<<"11.reverse \n";
cout<<"12.Quit \n";
cin>>choice;
switch(choice){
case 1:
start=createlist(start);
break;
case 2:
display(start);
break;
case 3:
position=count(start);
cout<<position;
break;
case 4:
cout<<"enter the element to be searched";
cin>>item;
search(start,item);
break;
case 5:
cout<<"enter the data to be inserted";
cin>>data;
addatbeg(start,data);
break;
case 6:
cout<<"enter the data to be inserted";
cin>>data;
addatend(start,data);
break;
case 7:
cout<<"enter the data to be inserted";
cin>>data;
cout<<"enter the value after which the data is to be inserted";
cin>>item;
addafternode(data,start,item);
break;
case 8:
cout<<"enter the data to be inserted";
cin>>data;
cout<<"enter the item after which data is to be inserted";
cin>>item;
addbeforenode(data,start,item);
break;
case 9:
cout<<"enter the data to be inserted";
cin>>data;
cout<<"enter the position at which data is to be inserted";
cin>>position;
start=addatpos(data,start,position);
break;
case 10:
cout<<"enter the element to be deleted";
cin>>item;
start=del(start,item);
break;
case 11:
start=reverse(start);
break;
case 12:
exit(1);
default:
	cout<<"incorrect option seleted";
	
}
}
getch();
return 0;
}
