#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >>arr[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(arr[a-1][b-1] == 1 and arr[a-1][c-1] == 1 and arr[b-1][c-1] == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}