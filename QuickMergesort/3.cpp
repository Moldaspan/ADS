// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void print(int a[], int n){
    for(int i  = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int partition(int a[], int low, int hight){
    int pivot = a[hight];
    int i  = low-1;
    for(int j = low; j <= hight - 1; j++){
        if(a[j] < pivot){
            i++;
            cout << "Swapping" << a[i] << " " << a[j] << endl;
            swap(a[i], a[j]);
            print(a,10);
        }
    }
    cout << "Swapping" << a[i+1] << " " << a[hight] << endl;
    swap(a[i+1], a[hight]);
    print(a, 10);
    return(i+1);
}

void quickSort(int a[], int low, int hight){
    if(low < hight){
        int pi = partition(a, low, hight);

        quickSort(a, low, pi-1);
        cout << endl;
        quickSort(a,pi+1, hight);
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}