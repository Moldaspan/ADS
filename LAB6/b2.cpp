#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int low, int hight){
    int pivot  = v[hight];
    int i = low-1;
    for(int j = low; j <= hight-1; j++){
        if(s[j] < pivot){
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[hight]);
    return (i+1);
}
void quickSort(vector<int> &v, int low, int hight){
    if(low < hight){
        int pi = partition(s, low, hight);

        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, hight);
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    vector <int> v1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    vector<int> v2;
    for(int i = 0; i < m; i++){
        int y;
        cin >> y;
        v2.push_back(y);
    }
    quickSort(v1, 0, n - 1);
    quickSort(v2, 0, m - 1);
    vector<int> v;
    int i = 0; 
    int j = 0;
    // int k = 0;
    while (i < n && j < m) {
        if(v1[i] == v2[j]){
            cout << v2[j] << " ";
            i++;
            j++;

        } else if(v1[i] > v2[j]){
            j++;
        } else i++;
    }
   
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " "; 
    } 
}