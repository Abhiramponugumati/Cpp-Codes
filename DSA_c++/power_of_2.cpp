#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number"<<" ";
    cin>>n;
    int x=0;
    for(int i=0;i<n;i++){
        if(n==pow(2,i)){
            x=1;
            break;
        }
    }
    if(x==0) cout<<"false";
    if(x==1) cout<<"True";
    return 0;
}