#include <iostream>
#include<vector>
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

int kmp(string t, string s){
    string st = s + '#' + t;
    int cnt = 0;
    vector<int> p = prefix_function(st);
    for(int i = 0; i < st.size(); i++){
        if(p[i] == s.size()){
            return 1;
        }
    }
    return 0;
}

int main(){
    string t, s;
    cin >> t >> s;
    string d = t;
    while(t.size() < s.size()){
        t += d;
    }
    if(kmp(t, s) == 0){
        t += d;
        if(kmp(t, s) != 1){
            cout << -1;
        }else{
            cout << t.size()/d.size();
        }
    }
    else{
        cout << t.size()/d.size();
    }
}