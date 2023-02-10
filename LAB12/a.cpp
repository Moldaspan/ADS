#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    unordered_map<int, bool> mp;
    for(int i = 0; i < n; i++) {
        mp[i] = true;
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }   
    for(int s = 0; s < n; s++){
        int x;
        cin >> x;
        x--;
        mp[x] = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][x] + a[x][j] < a[i][j]){
                    a[i][j] = a[i][x] + a[x][j];
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < n; i++){
            if(!mp[i]){
                for(int j = 0; j < n; j++){
                    if(!mp[j]){
                        if(a[i][j] > mx){
                            mx = a[i][j];
                        }
                    }
                }
            }
        }
        cout << mx << endl;
    }
}