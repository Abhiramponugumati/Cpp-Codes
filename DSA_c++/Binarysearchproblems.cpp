// // // // 1)Find pivot element in asorted array
// // //    #include<iostream>
// // //    using namespace std;
// // //    int getpivot(int arr[],int n){
// // //     int s=0;
// // //     int e=n-1;
// // //     int mid=s+(e-s)/2;
// // //     while(s<e){
// // //         if(arr[mid]>=arr[0]){
// // //             s=mid+1;
// // //         } 
// // //         else{
// // //             e=mid;
// // //         }
// // //         mid=s+(e-s)/2;
// // //     }
// // //     return s;
// // //    }
// // //     int main(){
// // //         int arr[5]={7,9,3,4,5};
// // //         cout<<"Pivot is "<< getpivot(arr,5)<<endl;
// // //         return 0;
// // //     }

// // // 2) Finding squareroot of an interger using Binary search
// // #include<iostream>
// // using namespace std;
// // int binarySearch(int n){
// //     int s=0;
// //     int e=n;
// //     long long int ans=-1;
// //     long long int mid= s+(e-s)/2;
// //     while(s<=e){
// //         long long int square=mid*mid;
// //         if(square==n) return mid;
// //         if(square<n){
// //                 ans=mid;
// //                 s=mid+1;
// //         }
// //         else{
// //             e=mid-1;
// //         }
// //         mid=s+(e-s)/2;
// //     }
// //    return ans;
// // }
// // double moreprecise(int n,int precision,int tempsoln){
// //     double factor=1;
// //     double ans=tempsoln;
// //     for(int i=0;i<precision;i++){
// //         factor=factor/10;
// //         for(double j=ans;j*j<n;j=j+factor){
// //             ans=j;
// //         }
// //     }
// //     return ans;
// // }
// // int main(){
// //     int x;
// //     cout<<"Enter the value of x"<<endl;
// //     cin>>x;
// //   int   tempsoln=binarySearch(x);
// //   cout<<tempsoln<<endl;
// //   cout<<"Square root of "<<x<<" is:"<<moreprecise(x,3,tempsoln);
// // }

//  // 3) Book allocation problem
//    #include<iostream>
//    using namespace std;
//    bool ispossible(int arr[],int n,int m,int mid){
//     int studentcount=1;
//     int pagesum=0;
//     for(int i=0;i<n;i++){
//         if(pagesum+arr[i]<=mid){
//             pagesum+=arr[i];
//         }
//         else{
//             studentcount++;
//             if(studentcount>m || arr[i]>mid){
//                 return false;
//             }
//             pagesum=arr[i];
//         }
//     }
//     return true;
//    }
//    int main(){
//     int n;
//     cout<<"Enter the no of books in an array"<<endl;
//     cin>>n;
//     int m;
//     cout<<"Enter the  no of students"<<endl;
//     cin>>m;
//     int arr[n];
//     cout<<"Enter the elements in the array"<<endl;
//      for(int i=0;i<n;i++){
//         cin>>arr[i];
//      }
//       cout<<"Enterted array"<<endl;
//       for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//       }
//       cout<<endl;
//       // search space  is used as binary search algorith
//       int s=0;
//       int sum=0;
//       for(int i=0;i<n;i++){
//         sum+=arr[i];
//       }
//       int e=sum;
//       int mid=s+(e-s)/2;
//       int ans=-1;
//       while(s<=e){
//         if(ispossible(arr,n,m,mid)){
//              ans=mid;
//              e=mid-1;
//         }
//         else{
//             s=mid+1;
//         }
//         mid=s+(e-s)/2;
//       }
//        cout<<ans<<endl;
// //    
//      // 4) Aggresive COws alloaction 
   #include<iostream>
using namespace std;

bool ispossible(int arr[], int n, int k, int mid) {
    int Cowcount = 1;
    int lastpos = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastpos >= mid) {
            Cowcount++;
            lastpos = arr[i];
            if (Cowcount == k) return true;
        }
    }
    return false;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    int k;
    cout << "Enter the number of COWS: ";
    cin >> k;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Entered array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array
    bubbleSort(arr, n);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Binary search for the largest minimum distance
    int s = 0;
    int e = arr[n - 1] - arr[0];
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (ispossible(arr, n, k, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    cout << "The largest minimum distance is: " << ans << endl;

    return 0;
}
