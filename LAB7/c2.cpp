#include <iostream>
using namespace std;

int c[10000005];

void merge(int a[], int l, int mid, int r){
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[r + 1];
    while(i <= mid && j <= r){
        if (a[i] < a[j]){
            b[k] = a[i];
            k++; i++; 
        } else {
            b[k] = a[j];
            k++; j++;
        }
    }
    for (; i <= mid; i++){
        b[k] = a[i];
        k++; 
    }

    for(; j <= r; j++){
        b[k] = a[j];
        k++;
    }

    for (i = l; i <= r; i++){
        a[i] = b[i];
    }
}


void mergesort(int a[], int l, int r){
    if (l < r){
        int mid = (l+r)/2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
    } 
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[m];
    for(int j = 0; j < m; j++){
        cin >> b[j]; 
    }
    mergesort(a, 0, n - 1);
    mergesort(b, 0, m - 1);
    int l = 0, l2 = 0;
    while(l < n and l2 < m){
         if(a[l] == b[l2]){
            cout << a[l] << " ";
            l++; l2++;
        }
        else if(a[l] < b[l2]){
            l++;
        }
        else{
            l2++;
        }
    }
    return 0;
}