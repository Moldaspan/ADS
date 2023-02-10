#include<iostream>
#include<queue>
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n][n];
    queue <int> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    int a, b;
    cin >> a >> b;
    a = a - 1;
    b = b - 1;
    q.push(a);
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        cnt++;
        q.pop();
        for(int i = 0; i < n; i++){
            if(arr[front][i] == 1){
                if(i == b){
                    cout << cnt;
                    return 0;
                }
                q.push(i);
                arr[front][i] = 0;
                arr[i][front] = 0;
            }
        }
    }
    cout << - 1;
}