#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MXN = 100005;
bool used[MXN];
vector <pair <int, int>> g[MXN];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(i != j){
                g[i].push_back(make_pair(j, x));
            }
        }
    }
    int weight = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> q;
    q.push(make_pair(0, 1));
    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        int mst = p.first, v = p.second;
        if(used[v]){
            continue;
        }
        used[v] = true;
        weight += mst; 
        for (int i = 0; i < g[v].size(); i++) {
            int u = g[v][i].first, length = g[v][i].second;
            if (!used[u]){
                q.push(make_pair(length, u));
            }
        }
    }
    cout << weight << endl;
}