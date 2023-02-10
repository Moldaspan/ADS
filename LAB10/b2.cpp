#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 105;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> p(MAXN);
vector<int> d(MAXN);

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int a;
            cin >> a;
            if(a == 1)
            g[i].push_back(j);
        }
    }
    int x, y;
    cin >> x >> y;
    queue<int> q;
    q.push(x);
    used[x] = true;
    p[x] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(used[to] == false){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    if(used[y] == true){
        cout << d[y];
    }
    else{
        cout << -1;
    }
}