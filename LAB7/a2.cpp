#include <iostream>
#include <vector>
using namespace std;

bool comp(string &s, string &d){
    return s.size() > d.size();
}
void merge(vector<string>, int l, int r, int mid){
    int i = l;
    int j = mid + 1;
    vector<string>vec;
    while(i <= mid and j <= r){
        if (comp(v[i], v[j])){
            vec.push_back(v[j]);
            j++; 
        } else {
            vec.push_back(v[i]);
            i++;
        }
    }
    for(; i <= mid; i++){
        vec.push_back(v[i]);
    }

    for(; j <= r; j++){
        vec.push_back([j]);
    }

    for(i = l; i <= r; i++){
        v[i] = vec[i - l];
    }

}

int c[1000005];

// void merge2(int a[], int b[], int n, int m){
//     int i, j, k;
//     i = j = k = 0;
//     while(i < n and j < m){
//         if(a[i] < b[j]){
//             c[k] = a[i];
//             k++; i++;
//         }else{
//             c[k] = b[j];
//             k++; j++;
//         }
//     }
//     for(; i < n; i++){
//         c[k] = a[i];
//         k++;
//     }
//     for(; j < m; j++){
//         c[k] = b[i];
//         k++;
//     }
// }


void mergeSort(vector<string> &v, int l, int r){
    if(l < r){
        int mid = l + (r-l)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);
        mergeSort(v,l,mid,r);
    }
}


int main() {
    int n; 
    cin >> n;
    for (int k = 1; k <= n; k++){
        string s;
        getline(cin >> ws, s);
        vector <string> v;
        string str = "";
        for (int i = 0; i < s.size(); i ++){
            if (s[i] == ' '){
                v.push_back(str);
                str = "";
                continue;
            }
            str += s[i];
        }
        v.push_back(str);
        
        mergesort(v, 0, v.size()-1);
        for (int i = 0; i < v.size(); i ++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}