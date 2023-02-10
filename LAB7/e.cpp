#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> &v){
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum;
}

bool comp(vector<int> &v, vector<int> &v2){
    int s = sum(v);
    int s2 = sum(v1);
    if(s == s2){
        for(int i = 0; i < v2.size(); i++){
            if(v[i] > v2[i]){
                return true;
            }
            else if(v[i] < v2[i]){
                return false;
            }
        }
    }
    return s < s2;
}

void merge(vector<int> &v, int l, int r, int mid){
    int i = l;
    int j = mid + 1;
    int k = l;
    vector<int> vec(r+1);
    while(i <= mid and j <= r){
        if(v[i] < v[j]){
            vec[k] = v[i];
            k++; i++;
        }else{
            vec[k] = v[j];
            k++; j++;
        }
    }
    for(; i <= mid; i++){
        vec[k]= v[i];
        k++;
    }

    for(; j <= r; j++){
        vec[k] = v[j];
    }

    for(i = l; i <= r; i++){
        v[i] = vec[i];
    }

}

// int c[1000005];

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


void mergeSort(vector<int> &v, int l, int r){
    if(l < r){
        int mid = l + r/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);
        merge(v,l,mid,r);
    }
}


int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < n; i++){
        vector<int>vec(n);
        for(int j = 0; j < m; j++){
            cin >> vec[j];
        }
        v.push_back(vec);
    }
    v = mergeSort(v);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}