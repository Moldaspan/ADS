#include <bits/stdc++.h> 
using namespace std; 

int result(vector<vector<int>> &v, int x){
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        bool ok = true;
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] > x){
                ok = false;
            }
        }
        if(ok){
            ans++;
        }
    }
    return ans;
}
 
int main() { 
    int n, k; 
    cin >> n >> k; 
    vector<vector<int>> v;

    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < 4; j++){
            int x; cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }

    int l = 0, r = INT_MAX; 
 
    while(l + 1 < r) { 
        int mid = (l + r)/2; 
        if(result(v, mid) >= k){
            r = mid;
        }
        else{
            l = mid;
        }
    } 
    cout << r;  
}