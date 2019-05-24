#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void convert(int num,int base){
	if(num>base-1){
	convert(num/base,base);
	cout<<num%base;
}
	else{
		cout<<num;
		return; 
	}
}
int main(){
	int num,base;
	cout<<"enter the num to be converted";
	cin>>num;
	cout<<"enter the base to which it is to be converted";
	cin>>base;
	convert(num,base);
	return 0;
}
