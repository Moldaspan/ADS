#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 

const int MXN = 1005;
vector<int>g[1005]; 
vector<int>g2[1005]; 
int a[1005][1005]; 

//g -roadways
//g2 - airlanes 
 

int main(){ 
    int n,m; 
    cin >> n >> m; 
    for(int i=0; i<m; i++){ 
        int x, y; 
        cin >> x >> y; 
        x--; y--; 
        g[x].push_back(y); 
        g[y].push_back(x); 
        a[x][y] = 1; 
        a[y][x] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (a[i][j] == 0 and i != j){ 
                g2[i].push_back(j); 
            } 
        } 
    } 
    queue<int>q; 
    vector<int>vec(n+1); 
    vector<bool>used(n+1); 
    q.push(0); 
    used[0] = true; 
    while(!q.empty()){ 
        int v = q.front(); 
        q.pop(); 
        for(int i = 0; i <g[v].size(); i++){ 
            int to = g[v][i]; 
            if(!used[to]){ 
                used[to] = true; 
                q.push(to); 
                vec[to] = vec[v]+1; 
            } 
        } 
    } 
    queue<int>q2; 
    vector<int>vec2(n+1); 
    vector<bool>used2(n+1); 
    q2.push(0); 
    used2[0] = true; 
    while(!q2.empty()){ 
        int v = q2.front(); 
        q2.pop(); 
        for(int i = 0; i < g2[v].size(); i++){ 
            int to = g2[v][i]; 
            if(!used2[to]){ 
                used2[to] = true; 
                q2.push(to); 
                vec2[to] = vec2[v]+1; 
            } 
        } 
    } 
    if (!used[n-1] || !used2[n-1]){ 
        cout << -1; 
    } 
    else { 
        cout << max(vec[n-1], vec2[n-1]); 
    } 
}