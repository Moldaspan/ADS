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
int kmp(string s, string t){
    string st = t + '#' + s;
    int cnt = 0;
    vector<int>p = prefix_function(st); 
    for(int i = 0; i < st.size(); i++){
        if(p[i] == t.size()){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string s, t;
    int d;
    cin >> s >> d >> t;
    if(kmp(t, s) >= d){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}