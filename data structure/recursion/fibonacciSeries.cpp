#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int fs(int n){
	if(n==1 || n==2)
	return 1;
	else
	return fs(n-1)+fs(n-2);
}
int main(){
	int n;
	cout<<"enterthe value of n :";
	cin>>n;
	cout<<fs(n);
return 0;
}
