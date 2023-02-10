#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> vec;
    int mn = 1000000000;
    int index = -1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
        if(x < mn){
            mn = x;
            index = i;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(i != index){
            cnt += vec[i] + mn;
        }
    }
    cout << cnt << endl;
}