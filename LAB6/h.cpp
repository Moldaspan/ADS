#include <iostream>
#include <vector>
using namespace std;

int partition (vector<char> &v, int low, int high){
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}


void quickSort(vector<char> &v, int low, int high){
    if (low < high){
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}
char check(vector<char>v, char c, int size){
    int l = 0, r = size - 1, mid;
    char ans;
    while(l <= r){
        mid = l + (r-l)/2;
        if(c > v[mid]){
            l = mid + 1;
        }
        if(c < v[mid]){
            ans = v[mid];
            r = mid - 1;
        }else{
            if(v[mid] != v[mid+1]){
                return v[mid+1];
            }else{
                return v[mid+2];
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<char> v(n);
    char c, c1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> c1;
    v.push_back(c1);
    quickSort(v, 0, v.size()-1);
    if(v[v.size()-1] == c1){
        cout << v[0] << endl;
    }else{
        cout << check(v, c1, v.size());
    }
    return 0;
}


// int main(){
//     vector<char> v;
//     int n;
//     cin >> n;
//     char c, c1;
//     for(int i = 0; i < n; i++){
//         cin >> c;
//         v.push_back(c);
//     }
//     cin >> c1;
//     if(v[v.size()-1] == c1){
//         cout << v[0] << endl;
    
//     }
//     else 
//     {
//     int l = 0, r = v.size() - 1, mid;
//     char ans;
//     while(l <= r)
//     {
//         mid = l + (r - l)/2;
//         if(v[mid] > c1)
//         {
//             ans = v[mid];
//             r = mid - 1;
        
//         }else if(c1>v[mid])
//         { 
//             l = mid + 1;
//         }
//         else 
//         {
//             if(v[mid]!=v[mid+1]) cout<<v[mid];
//             else cout<<v[mid+2];
//         }
//     }

//     }
// }