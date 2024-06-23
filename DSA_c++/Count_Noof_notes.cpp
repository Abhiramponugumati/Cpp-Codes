#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number "<<" ";
    cin>>n;
    int a=100;
    int b=50;
    int c=20;
    int d=1;
    switch(d){
        case 1: {
         int a1=n/a;
         cout<<a1<<endl;
         n=n%100;
        }
         case 2: {
         int a2=n/b;
         cout<<a2<<endl;
         n=n-(a2*b);
         }
         case 3:{
         int a3=n/c;
         cout<<a3<<endl;
         n= n-(a3*c);
         }
         case 4:{
         int a4=n;
         cout<<a4<<endl;
         break;
         }
         default:
         cout<<"INPUT INVALID";
         break;
    } 
}