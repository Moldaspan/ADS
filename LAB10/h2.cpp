#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 105;
char a[MAXN][MAXN];
bool used[MAXN][MAXN];
int n, m;

void dfs(int i, int j){
    if(i < 1 or j < 1 or i > n or j > m){
        return;
    }
    if(used[i][j]){
        return;
    }
    if(a[i][j] == '0'){
        return;
    }
    used[i][j] = true;
    dfs(i, j + 1); 
    dfs(i, j - 1);
    dfs(i - 1, j); 
    dfs(i + 1, j); 
}

int main(){
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j]; 
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '1' and !used[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;
}
