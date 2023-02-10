#include <bits/stdc++.h>

using namespace std;

int main (){
    int queries;
    cin >> queries;
    int v[100005];
    int x;
    string command;
    int size = -1;
    int mx = INT_MIN;
    while(queries--){
        cin >> command;
        if(command == "add"){
            cin >> x;
            size++;
            v[size] = x;
        } else if(command == "delete"){
            size--;
            if(size < 0) size = -1;
        } else if(command == "getcur"){
            if(size > -1){
                cout << v[size] << endl;
            } else cout << "error" << endl;
        } else if(command == "getmax"){
            if(size != -1){
                for(int i = 0; i <=size; i++){
                    if(v[i] > mx){
                        mx = v[i]; 
                    }
                }
                cout << mx << endl;
            } else cout << "error" << endl;
        }
    }
}