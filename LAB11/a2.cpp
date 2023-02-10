#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<pair<int, pair<int, int> > > g;
vector<int> p;
long long mcost = 0;

int dsu(int v){
	if (v == p[v]) {
		return v;
	}else{
    return p[v] = dsu(p[v]);
    }
}

void dsuU(int x, int y) {
    x = dsu(x);
    y = dsu(y);
    p[x] = y;
}

int main() { 
    int n, m;
    cin >> n >> m;
    p.resize(n);
    for(int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        l--; r--;
        g.push_back(make_pair(c, make_pair(l, r)));
    }
    sort(g.begin(), g.end());
    for (int i = 0; i < n; ++i){
        p[i] = i;
    }
    for (int i = 0; i < g.size(); ++i) {
        int u = g[i].second.first;
        int v = g[i].second.second;
        int cost = g[i].first;
        for(int j = u + 1; j <= v; j++){
            if(dsu(u) != dsu(j)){
                dsuU(u, j);
                mcost += cost;
            }else{
                j = p[u];
            }
        }
    }
    cout << mcost;
}