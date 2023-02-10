#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN];
vector<int> d(MAXN);
vector<int> p(MAXN);

int main(){
    int n, m;
    cin >> n >> m;
    queue<int> q;
    q.push(n);
    for(int i = 0; i < MAXN; i++){
        d[i] = 1000000005;
    }
    d[n] = 0;
    p[n] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int x = v * 2;
        int y = v - 1;
        if(x > 0 and x <= MAXN){
            if(d[x] > d[v] + 1){
                d[x] = d[v] + 1;
                q.push(x);
                p[x] = v;
            }
        }
        if(y > 0 and y <= MAXN){
            if(d[y] > d[v] + 1){
                d[y] = d[v] + 1;
                q.push(y);
                p[y] = v;
            }
        }
    }   
    cout << d[m] << endl;;
    vector<int> v;
    for(int i = m; i != n; i = p[i]){
        v.push_back(i);
    }
    for(int i = v.size() -1; i >= 0; i--){
        cout << v[i] << " ";
    }
}

