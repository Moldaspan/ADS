#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, big, small, y, sum = 0, a, b, c, i, j, count; 
    cin >> n >> m >> big >> small;
    int both = min(big, small);
    int graph[n][m];
    for(i = 0; i < n; i++) for(int j = 0; j < n; j++) graph[i][j] = INT_MAX;
    string option;
    while(m--){
        cin >> option >> a >> b >> c;
        if(option == "big") graph[b-1][a-1] = graph[a-1][b-1] = c * big;
        else if (option == "small") graph[b-1][a-1] = graph[a-1][b-1] = c * small;
        else graph[b-1][a-1] = graph[a-1][b-1] = c * both;
    }
    bool mstSet[n];
    for(i = 1; i < n; i++) mstSet[i] = false;
    mstSet[0] = true;
    for (count = 0; count < n - 1; count++) {
        int min = INT_MAX;
        for(i = 0; i < n; i++){
            if(mstSet[i]){
               for(j = 0; j < n; j++) if(min > graph[i][j] && !mstSet[j]) {
                min = graph[i][j];
                y = j;
            } 
            }
        }
        sum += min;
        mstSet[y] = true;
    }
    cout << sum;
    
    
    return 0;
}