#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN];
bool used[MAXN];
int cnt = 0;

void dfs(int v) {
    if (used[v]){
        return;
    }
    used[v] = false;
    for (int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (g[to].size() > g[v].size()){
            cnt++;
        }
        dfs(to);
    }
    return;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u , v;
        cin >> u >> v;
        u--; v--; 
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
}