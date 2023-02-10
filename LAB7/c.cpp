#include <iostream>
#include <vector>
using namespace std;


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
        mergeSort(v,l,mid-1);
        merge(v,l,mid,r);
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<int>v(n);
    vector<int>v2(m);
    for(int i = 0; i <n; i++){
        cin >> v[i];
    }
    for(int j = 0; j < m; j++){
        cin >> v2[j];
    }

    mergeSort(v, 0, n-1);
    mergeSort(v2, 0, m-1);

    int l = 0, l2 = 0;
    while(l < v.size() and l2 < v2.size()){
         if(v[l] == v2[l2]){
            cout << v[l] << " ";
            l++; l2++;
        }
        else if(v[l] < v2[l2]){
            l++;
        }
        else{
            l2++;
        }
    }
    return 0;
}