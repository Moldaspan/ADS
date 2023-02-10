#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, long long>>> g;

int bfs(long long p, int n){
    queue<int> q;
    vector<bool> vec(n);
    q.push(0);
    vec[0] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == n - 1){
            return 1;
        }
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i].first;
            long long cost = g[v][i].second;
            if(!vec[to] && p >= cost){
                vec[to] = true;
                q.push(to);
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    vector<pair<long long, long long>> c;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        c.push_back(make_pair(x, y));
    }
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < c.size(); i++){
        for(int j = i + 1; j < c.size(); j++){
            g[i].push_back(make_pair(j, (abs(c[i].first - c[j].first) + abs(c[i].second - c[j].second))));
            g[j].push_back(make_pair(i, (abs(c[i].first - c[j].first) + abs(c[i].second - c[j].second))));
        }
    }
    long long ans = -1; 
    long long mid, l = 1, r = 2 * 1e9;
    while(l <= r){
        mid = (r + l) / 2;
        if(bfs(mid, n)){
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
}