#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
 
int main (){
    long long n;
    cin >> n;
    stack<long long> st;
    vector <long long> v;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        v.clear();
        while(x != 0){
            v.push_back(x%2);
            x/=2;
        }
        reverse(v.begin(), v.end());
        for(long long i = 0; i < v.size(); i++){
            if(st.size() == 0){
                st.push(v[i]);
            } else if (st.top() == 1 and v[i] == 0){
                st.pop();
            } else {
                st.push(v[i]);
            }
        }
        if(st.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
        while (!st.empty()) {
            st.pop();
        }
    }     
}