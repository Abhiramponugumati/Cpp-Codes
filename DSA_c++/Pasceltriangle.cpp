#include<iostream>
using namespace std;
  int fact(int x){
       int ans=1;
       for(int i=1;i<=x;i++){
        ans=ans*i;
       }
       return ans;
  }
  int combination(int n,int r){
    int a= (fact(n)/(fact(r)*fact(n-r)));
    return a;
  }
int main(){
    int n;
    cout<<"Enter the value of n"<<" ";
    cin>>n;
     for(int i=1;i<=n;i++){
         for(int k=0;k<n+1-i;k++){
            cout<<" ";
         }
        for(int j=0;j<=i;j++){
            if(i==1){
                cout<<combination(i,0);
                break;
            }
            cout<<combination(i,j)<<" ";
        }
        cout<<endl;
     }
}