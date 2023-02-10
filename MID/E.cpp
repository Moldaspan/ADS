#include <bits/stdc++.h>
using namespace std;

void func(int &mx, stack<int>st){
    int mx2 = INT_MIN;
    while(!st.empty()){
        if(st.top() > mx2){
            mx2 = st.top();
        }
        st.pop();
    }
    mx = mx2;
}

int main(){
    int n;
    cin >> n;
    int mx = INT_MIN;
    stack<int> st;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x;
            st.push(x);
            if(x > mx){
                mx = x;
            }
        }
        if(s == "delete"){
            if(st.empty()){
                cout<<"error"<<endl;
            }
            else{
                if(st.top() == mx){
                    st.pop();  
                    func(mx, st); 
                    }else{
                        st.pop();
                    }
                }
        }
        if(s == "getmax"){
            if(st.empty()){
                cout << "error" << endl;
            }else{
                cout << mx << endl;
            }
        }
        if(s == "getcur"){
            if(st.empty()){
                cout << "error" << endl;
            }else{
                cout << st.top() << endl;
            }
        }
    }
}
