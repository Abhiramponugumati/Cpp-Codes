#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the  number";
    cin>>n;
    int ans=0;
    while(n>0){
        if(ans>INT_MAX/10 || ans<INT_MIN/10){
            cout<<"0";
            return 0;
        }
       int digit=n%10;
       ans= (ans*10)+ digit;
       n=n/10;
    }
    cout<<ans<<endl;
    return 0;
}
