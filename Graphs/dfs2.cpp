#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int NEW = 0;
int DURING = 1;
int ViSiTED = 2;
const int MAXN = 100005;
vector<int>g[MAXN];
bool used[MAXN];


void dfs(int v){
    if(used[v]){
        return;
    }
    used[v] = true;
    cout << v << " ";
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
    // cout << v << " ";
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1);
    return 0;
}
