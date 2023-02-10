#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s){
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i-1];
        while(j > 0 and s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main(){
    string s, t;
    cin >> s >> t;
    string st = t + '#' + s;
    vector<int>p = prefix_function(st); 
    vector<int> v;
    for(int i = t.size() + 1; i < st.size(); i++){
        if(p[i] == t.size()){
            v.push_back(i - 2*t.size() + 1);
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
}