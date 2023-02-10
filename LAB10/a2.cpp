#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 1005;
int a[MAXN][MAXN];
queue<pair<int, int>> q;
int n, m;
int ans = 0;

void eat(int i, int j){
    if(i + 1 <= n && i + 1 >= 1 && a[i + 1][j] == 1){
        a[i + 1][j] = 2;
        q.push(make_pair(i + 1, j));
    }
    if(i - 1 >= 1 && i - 1 <= n && a[i - 1][j] == 1){
        a[i - 1][j] = 2;
        q.push(make_pair(i - 1, j));
    }
    if(j + 1 >= 1 && j + 1 <= m && a[i][j + 1] == 1){
        a[i][j + 1] = 2;
        q.push(make_pair(i, j + 1));
    }
    if(j - 1 >= 1 && j - 1 <= m && a[i][j - 1] == 1){
        a[i][j - 1] = 2;
        q.push(make_pair(i, j - 1));
    }
}

int main(){
    cin >> n >> m;
    int numOfOnes = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                q.push(make_pair(i, j));
            }
            else if(a[i][j] == 1){
                numOfOnes++;
            }
        }
    }
    int sz = q.size();
    int cntMarios = 0;
    while(!q.empty()){
        pair<int, int> p = q.front();
        if(sz == 0){
            ans++;
            cntMarios += q.size();
            sz = q.size();
        }
        q.pop();
        sz--;
        eat(p.first, p.second);
    }
    if(cntMarios == numOfOnes){
        cout << ans;
    }else{
        cout << -1;
    }
}