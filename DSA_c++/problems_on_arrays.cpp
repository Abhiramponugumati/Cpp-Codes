// // #include<iostream>     //  1) Unique element 
// // using namespace std;
// // int main(){
// //     int n;
// //     cout<<"ENTER THE SIZE OF AN ARRAY"<<endl;
// //     cin>>n;
// //     int arr[n];
// //     cout<<"ENTER THE ELEMENTS "<<endl;
// //      for(int i=0;i<n;i++){
// //         cin>>arr[i];
// //      }
// //       cout<<"Entered array"<<endl;
// //       for(int i=0;i<n;i++){
// //         cout<<arr[i]<<" ";
// //       }
// //       cout<<endl;
// //         for(int i=0;i<n;i++){
// //             for(int j=i+1;j<n;j++){
// //                 if(arr[i]==arr[j]){
// //                     arr[i]=arr[j]=0;
// //                 }
// //             }
// //         }
// //          for(int i=0;i<n;i++){
// //             if(arr[i]!=0){
// //         cout<<arr[i]<<" ";
// //       }
// //          }
// //         return 0;
// // }

// // #include<iostream>     //  2) Duplicate elements 
// // using namespace std;
// // int main(){
// //     int n;
// //     cout<<"ENTER THE SIZE OF AN ARRAY"<<endl;
// //     cin>>n;
// //     int arr[n];
// //     cout<<"ENTER THE ELEMENTS "<<endl;
// //      for(int i=0;i<n;i++){
// //         cin>>arr[i];
// //      }
// //       cout<<"Entered array"<<endl;
// //       for(int i=0;i<n;i++){
// //         cout<<arr[i]<<" ";
// //       }
// //       cout<<endl;
// //       for(int i=0;i<n;i++){
// //         int ans=1;
// //         for(int j=i+1;j<n;j++){
// //              if(arr[i]==arr[j]){
// //                 arr[j]=0;
// //                 ans++;
// //              }
// //         }
// //         if(arr[i]!=0) cout<<arr[i]<<"--- "<<ans<<endl;
// //       }
// //        return 0;
// // }

// //   #include<iostream>     //  3) Intersection of arrays 
// // using namespace std;
// // int main(){
// //     int n;
// //     cout<<"ENTER THE SIZE OF 1st ARRAY"<<endl;
// //     cin>>n;
// //     int a[n];
// //     cout<<"ENTER THE ELEMENTS "<<endl;
// //      for(int i=0;i<n;i++){
// //         cin>>a[i];
// //      }
// //       cout<<"Entered array"<<endl;
// //       for(int i=0;i<n;i++){
// //         cout<<a[i]<<" ";
// //       }
// //       cout<<endl;
// //       int m;
// //     cout<<"ENTER THE SIZE OF 2nd ARRAY"<<endl;
// //     cin>>m;
// //     int b[m];
// //     cout<<"ENTER THE ELEMENTS "<<endl;
// //      for(int i=0;i<m;i++){
// //         cin>>b[i];
// //      }
// //       cout<<"Entered array"<<endl;
// //       for(int i=0;i<m;i++){
// //         cout<<b[i]<<" ";
// //       }
// //       cout<<endl;
// //       int c=0;
// //        for(int i=0;i<n;i++){
// //         for(int j=0;j<m;j++){
// //             if(a[i]==b[j]){
// //                 cout<<a[i]<<" ";
// //                 a[i]=b[j]=0;
// //                 c=1;
// //             }
// //         }
// //        }
// //        if(c==0) cout<<"-1"<<endl;
// //       return 0;
// // }

// //   #include<iostream>  // 4) Duplets of an array  
// //                            // extra  for loop for triplet..
// //   using namespace std;
// //  int getmin(int a, int b) {
// //     if (a < b) {
// //         return a;
// //     } else {
// //         return b; // Handles the case where a >= b
// //     }
// // }
// //    int getmax(int a, int b) {
// //     if (a > b) {
// //         return a;
// //     } else {
// //         return b; // Handles the case where a <= b
// //     }
// // }
// //   int main(){
// //      int n;
// //      cout<<"ENTER THE SIZE OF 1st ARRAY"<<endl;
// //      cin>>n;
// //      int a[n];
// //      cout<<"ENTER THE ELEMENTS "<<endl;
// //      for(int i=0;i<n;i++){     
// //             cin>>a[i];
// //       }
// //    cout<<"Entered array"<<endl;
// //     for(int i=0;i<n;i++){
// //          cout<<a[i]<<" ";
// //        }
// //        cout<<endl;
// //        int sum;
// //        cout<<"Enter the value of sum"<<endl;
// //        cin>>sum;
// //        int x=sum;
// //        int k1,k2;
// //        for(int i=0;i<n;i++){
// //         for(int j=i+1;j<n;j++){
// //             if(x==a[i]+a[j]){
// //                k1=  getmin(a[i],a[j]);
// //                k2= getmax(a[i],a[j]);
// //                cout<<k1<<","<<k2<<endl;
// //                a[i]=a[j]=0;
// //             }
// //         }
// //        }
// //          return 0;
// //   }
//         //   //5) Sorting 0's & 1's
//         //    // best way is 2ptr apporach
//         //    #include<iostream>
//         //    using namespace std;
//         //   int main(){
//         //     int n;
//         //     cout<<"enter the size of an array"<<endl;
//         //     cin>>n;
//         //     int arr[n];
//         //                 cout<<"enter the  elemets of an array"<<endl;
//         //     for(int i=0;i<n;i++){
//         //         cin>>arr[i];// input is only 0's&1's;
//         //     }
//         //     cout<<"entered array is:"<<endl;
//         //     for(int i=0;i<n;i++){
//         //        cout<<arr[i];
//         //     }
//         //     cout<<endl;
//         //     int left=0;
//         //     int right=n-1;
//         //     while(left<right){
//         //         if(arr[left]==0) left++;
//         //         if(arr[right]==1) right--;
//         //         if(arr[left]==1 and arr[right]==0){
//         //             swap(arr[left],arr[right]);
//         //             left++;
//         //             right--;
//         //         }
//         //     }
//         //     cout<<"Sorted array is:";
//         //     for(int i=0;i<n;i++){
//         //         cout<<arr[i]<<" ";
//         //     }
//         //     return 0;
//         //   }
//         // 6) Sort 0's,1's& 2's  by  single traversal method
//           // i.e 3ptr approach
//          #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter the size of an array: ";
//     cin >> n;
//     int arr[n];
    
//     cout << "Enter the elements of the array (0's, 1's & 2's only):" << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     cout << "Entered array is: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     int low = 0, mid = 0, high = n - 1;

//     while (mid <= high) {
//         if (arr[mid] == 0) {
//             swap(arr[low], arr[mid]);
//             low++;
//             mid++;
//         } else if (arr[mid] == 1) {
//             mid++;
//         } else if (arr[mid] == 2) {
//             swap(arr[mid], arr[high]);
//             high--;
//         }
//     }

//     cout << "Sorted array is: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }
 // 7) reversing  array after mTH index
 #include<iostream>
 #include<vector>
 using namespace std;
 vector<int>reverse(vector<int>v,int m){
    int s=m+1,e=v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
 }
  void print(vector<int>v){
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
  }
 int main(){
    vector<int>v;
    int m;
    cin>>m;
    v.push_back(11);
     v.push_back(7);
         v.push_back(3);
          v.push_back(12);
      v.push_back(4);
       vector<int>ans= reverse(v,m);
     print(ans);

 }