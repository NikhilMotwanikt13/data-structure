#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

void factorise(int number,int i=2){
	if(number%i==0){
		number=number/i;
		cout<<i<<"\n";
		
	}
	else{
		i++;
	}
	if(number>1){
	factorise(number,i);
	return;
}
}
int main(){
	int number;
	cout<<"enter the no. \n";
	cin>>number;
	factorise(number);
	
	
	
	
	getch();
	return 0;
}
