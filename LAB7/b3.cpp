#include <iostream>
#include <vector>
using namespace std;

int main (){
    int n;
    cin >> n;
    int a[n];
    vector<int> v1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    int m;
    cin >> m;
    vector<int> v2;
    for(int i = 0; i < m; i++){
        int y;
        cin >> y;
        v2.push_back(y);
    }
    vector<int> v;
    int i = 0; 
    int j = 0;
    int k = 0;
    while(i < n && j < m){
        if(v1[i] <= v2[j]){
            v.push_back(v1[i]);
            i++;
        } else {
            v.push_back(v2[j]);
            j++;
        }
        k++;
    }
    while(i < n){
        v.push_back(v1[i]);
        i++;
        k++;
    }
    while(j < m){
        v.push_back(v2[j]);
        j++;
        k++;
    }
}