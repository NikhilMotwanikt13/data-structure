#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int fact(int a){
	if(a>0){
		a=a*fact(a-1);
	}
	else{
		return a+1;
	}
}

int main(){
	int a,b;
	cout<<"enter the number";
	cin>>a;
	b=fact(a);
	cout<<b;
	return 0;
}

