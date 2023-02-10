#include<iostream>
#include<vector>
using namespace std;


int a, b, c;
bool check;
vector<bool> vis;
vector<vector<int> > arr;
void dfs(int v) {
	if (v == b) {
		check = true;
		return;
	}
	vis[v] = true;
	for (int i = 0; i < arr[v].size(); i++) {
		int to = arr[v][i];
		if (!vis[to]) {
			dfs(to);
		}
	}
}

int main(){
    int n, oper;
    cin >> n >> oper;
    for(int i = 0; i < n; i++){
        vector<int> v;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        arr.push_back(v);
    }
    while(oper--){
        int a, b, c;
        cin >> a >> b >> c;
        if(arr[a - 1][b - 1] && arr[a - 1][c - 1] && arr[b - 1][c - 1]){
            cout<< "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }   
    }
}