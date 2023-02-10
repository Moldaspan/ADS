#include <iostream> 
#include <vector> 
#include <set> 
using namespace std; 

int INF = 1000000000; 
const int MXN = 200005;
vector<pair<int,int>> g[MXN]; 
vector<int> vec(MXN, INF); 

int deikstra(int start, int end){ 
    vec.clear(); 
    for(int i = 0; i< MXN; i++){ 
        vec[i] = INF; 
    } 
    vec[start] = 0; 
    set< pair<int,int> > q; 
    q.insert(make_pair(vec[start],start)); 
    while(!q.empty()){ 
        int v = q.begin()->second; 
        q.erase(q.begin()); 
        for(int j = 0;j < g[v].size(); j++){ 
            int to = g[v][j].first; 
            int length = g[v][j].second; 
            if(vec[v] + length < vec[to]){ 
                q.erase(make_pair(vec[to], to)); 
                vec[to] = vec[v] + length; 
                q.insert(make_pair(vec[to], to)); 
            } 
        } 
    } 
    return vec[end]; 
} 
int main(){ 
    int n,m; 
    cin >> n >> m; 
    for (int i = 0; i < m; i++){ 
        int x, y, z; 
        cin >> x >> y >> z; 
        g[x].push_back({y, z}); 
        g[y].push_back({x, z}); 
    } 
    int s, t, r, w;
    cin >> s >> t >> r >> w; 
    int a, b; 
    a = deikstra(s,t) + deikstra(t,r) + deikstra(r,w); 
    b = deikstra(s,r) + deikstra(r,t) + deikstra(t,w);
   
    if(min(a,b) <= INF){ 
        cout << min(a,b); 
    }else{ 
        cout << -1; 
    } 
}