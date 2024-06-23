// #include <bits/stdc++.h>
// using namespace std;

// vector<int> function(vector<int>& a, vector<int>& b) {
//     // Use long long to handle large sums
//     long long x = 0, y = 0;

//     for (int i = 0; i < a.size(); i++) {
//         x = x * 10 + a[i];
//     }
    
//     for (int i = 0; i < b.size(); i++) {
//         y = y * 10 + b[i];
//     }

//     long long sum = x + y;
//     vector<int> res;

//     // Convert the sum back to a vector of digits
//     while (sum > 0) {
//         res.push_back(sum % 10);
//         sum /= 10;
//     }
//     reverse(res.begin(), res.end());

//     return res;
// }

// void print(const vector<int>& v) {
//     for (int i = 0; i < v.size(); i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     vector<int> a = {1, 2, 3, 4};
//     vector<int> b = {6};
//     vector<int> ans = function(a, b);
//     print(ans);
// }
