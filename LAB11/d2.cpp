#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MXN = 100005;
bool used[MXN];
vector <pair <int, int>> g[MXN];

int main(){
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (i != j) {
                g[i].push_back(make_pair(j, x));
            }
        }
    }
    int wid = 0; 
    priority_queue <pair<int, int>, vector <pair <int, int >>, greater <pair <int, int>>> q;
    q.push (make_pair(0, 1));
    while (!q.empty()){
        pair <int, int> a = q.top();
        q.pop();
        int mst = a.first, v = a.second;
        if(used[v]) continue;

        used[v] = true;
        wid += mst;

        for (int i = 0; i < g[v].size(); i++) {
            int u = g[v][i].first, len = g[v][i].second;
            if (!used[u]) q.push(make_pair(len, u));
        }
    }

    cout << wid;
}
    