#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> d(MAXN);

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int x, y;
    cin >> x >> y;
    queue<int> q;
    q.push(x);
    used[x] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
            }
        }
    }
    if(used[y] == true){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}