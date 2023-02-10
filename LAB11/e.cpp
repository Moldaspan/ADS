#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > g;
vector<int> p;
int dsu(int v) {
	if (v == p[v]) {
		return v;
	}
    return p[v] = dsu(p[v]);
}

bool dsuU(int x, int y) {
	x = dsu(x);
	y = dsu(y);
	if (x != y){
		p[x] = y;
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    p.resize(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    for(int i = n - 1; i >= 0; i--){
        ans.push_back(cnt);
        cnt++;
        for(int j = 0; j < g[i].size(); j++){
            int to = g[i][j];
            if(i < to){
                if(dsuU(i, to)){
                    cnt--;
                }
            }
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << endl;
    }
}