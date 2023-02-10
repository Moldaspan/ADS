#include <iostream>
using namespace std;

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
    int a[5] = {2,5,7,10,15};
    int b[4] = {1,3,8,13};

    merge(a,b,5,4);
    for(int i = 0; i < 9; i++){
        cout << c[i] << " ";
    }
}