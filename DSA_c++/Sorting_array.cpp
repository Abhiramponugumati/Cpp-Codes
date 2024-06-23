// // 1) Binary search 
// #include<iostream>
// using namespace std;
//  int binarySearch(int arr[],int size,int key){
//     int start=0;
//     int end=size-1;
//     int mid= (start+end)/2;
//     while(start<=end){
//         if(arr[mid]==key){
//             return mid;
//         }
//         if(key>arr[mid]){
//             start=mid+1;
//         }
//     else{  
//         end=mid-1;
//     }
//     mid=(start+end)/2;
//     }
//     return -1;
//  }
// int main(){
//     int even[6]={2,4,6,8,12,18};
//     int index= binarySearch(even,6,12);
//     cout<<"Index of 12 is "<<index<<endl;
// }
//  //2)  Selection sort
//  // pseudo code
// //    for(int i=0;i<n;i++){
// //     int min=i;
// //     for(int j=i+1;j<n;j++){
// //         if(arr[j]<min) min=j;
// //     }
// //     if(min!=i) swap (a[i],a[min]);
// //    }
    
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> m;  // Correct declaration with std:: prefix
    m[4] = "dsa";
    m[1] = "abhi";
    m[3] = "loves";

    for (auto i : m) {
        std::cout << i.first << " "<<i.second<<" ";  // Use std:: prefix or using namespace std;
    }
    std::cout << std::endl;

    return 0;
}
