#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int low, int high){
    int pivot  = v[high];
    int i = low-1;
    for(int j = low; j <= high-1; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return (i+1);
}
void quickSort(vector<int> &v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);

        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
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
    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }

    quickSort(v, 0, n - 1);
    quickSort(v2, 0, m - 1);

    int l = 0, l2 = 0;
    while(l < v.size() and l2 < v2.size()){
        if(v[l] < v2[l2]){
            l++;
        }
        if(v[l] > v2[l2]){
            l2++;
        }
        if(v[l] == v2[l2]){
            cout << v[l] << " ";
            l++; l2++;
        }
    }
    return 0;
}