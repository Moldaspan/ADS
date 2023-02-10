#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>g[105];
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    for(int i = 1; i <= n; i++){
        cout << g[i].size() << " ";
    }
    // for(int i = 1; i <= n; i++){
    //     cout << "u = " << i << endl;
    //     for(int j = 0; j < g[i].size(); j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}