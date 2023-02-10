#include <iostream>
using namespace std;


void merge(int a[], int b[], int l, int r, int mid){
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[r+1];
    while(i <= mid and j <= r){
        if(a[i] < a[j]){
            b[k] = a[i];
            k++; i++;
        }else{
            b[k] = a[j];
            k++; j++;
        }
    }
    for(; i <= mid; i++){
        b[k]= a[i];
        k++;
    }

    for(; j <= r; j++){
        b[k] = a[j];
    }

    for(i = l; i <= r; i++){
        a[i] = b[i];
    }

}

int c[1000005];

void merge2(int a[], int b[], int n, int m){
    int i, j, k;
    i = j = k = 0;
    while(i < n and j < m){
        if(a[i] < b[j]){
            c[k] = a[i];
            k++; i++;
        }else{
            c[k] = b[j];
            k++; j++;
        }
    }
    for(; i < n; i++){
        c[k] = a[i];
        k++;
    }
    for(; j < m; j++){
        c[k] = b[i];
        k++;
    }
}


int main(){
    int a[8] = {2,5,8,6,7,9,10,12};
    merge(a,0,7,2);

    for(int i = 0; i < 8; i++){
        cout << a[i] << " ";
    }
}