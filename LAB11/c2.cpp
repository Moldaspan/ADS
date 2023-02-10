#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MXN = 1005;
bool used[MXN];
vector <pair <int, int>> g[MXN];

int main(){
    int n, m, big, small;
    cin >> n >> m >> big >> small;
    int both = min(big, small);
    for(int i = 1; i <= m; i++){
        string option;
        int a, b, c;
        cin >> option >> a >> b >> c;
        if(option == "big"){
            g[a].push_back(make_pair(b, c * big));
            g[b].push_back(make_pair(a, c * big));
        }
        else if(option == "small"){
            g[a].push_back(make_pair(b, c * small));
            g[b].push_back(make_pair(a, c * small));
        }
        else{
            g[a].push_back(make_pair(b, c * both));
            g[b].push_back(make_pair(a, c * both));
        }
    }

    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >,  greater<pair<int, int> > > q;
    q.push(make_pair(0, 1));
    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        int mst = p.first, v = p.second;
        if(used[v]){
            continue;
        }
        used[v] = true;
        sum += mst; 
        for (int i = 0; i < g[v].size(); i++) {
            int u = g[v][i].first, length = g[v][i].second;
            if (!used[u]){
                q.push(make_pair(length, u));
            }
        }
    }
    cout << sum;
}