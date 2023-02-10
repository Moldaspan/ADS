#include <iostream>
#include <vector>
using namespace std;

int partit(int a[], int low, int hight){
    int pivot  = a[hight];
    int i = low-1;
    for(int j = low; j <= hight-1; j++){
        if(a[j] > pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[hight]);
    return (i+1);
}
void quickSort(int a[], int low, int hight){
    if(low < hight){
        int pi = partit(a, low, hight);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, hight);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[m][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[j][i];
        }
    }
    for(int i = 0; i < m; i++){
        quickSort(a[i], 0, n - 1);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[j][i] << ' ';
        }
        cout << endl;
    }
}
