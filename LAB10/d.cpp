#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 5005;
vector<int> g[MAXN];
vector<long long> d(MAXN);
bool redtenbaskasy = false;
int n, m, q;
int state[MAXN];
int red = 1;

void bfs(int v){
    state[v] = red;
    queue<int> q;
    q.push(v);
    d[v] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(d[to] > d[v] + 1){
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        d[i] = 1000000005;
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < q; i++){
        int type, num;
        cin >> type >> num;
        if(type == 1){
            if(state[num] != red){
                bfs(num);
            }
        }
        else{
            if(d[num] == 1000000005){
                cout << -1 << endl;
            }
            else{
                cout << d[num] << endl;
            }
        }
    }
}