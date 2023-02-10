#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


bool cmp(int a, int b){
    return a < b;
}

int main(){
    vector<int>v;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(a, a+n, cmp);  //pointers - указатель
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(auto i : v){
        cout << i << " ";
    }
    return 0;
}