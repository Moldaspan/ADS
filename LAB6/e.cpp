#include <iostream>
#include <vector>
using namespace std;

int partition(vector<vector<int>> &v, int low, int high, int column){
    int pivot = a[high][column];
    int i = low - 1;
    for(int j = low; j <= high-1; i++){
        if(v[j][column] < pivot){
            i++;
            swap(v[i][column], v[j][column]);
        }
    }
    swap(v[i+1][column], v[high][column]);
    return(i + 1);
}

void quickSort(vector<vector<int>> &v, int low, int high, int column){
    if(low < high){
        int pi = partition(v, low, high, column);
        quickSort(v, low, pi - 1, column);
        quickSort(v, pi + high, column);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            v.push_back([i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        quickSort(v, 0, n - 1, i);
    }
    // quickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}