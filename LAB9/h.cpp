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
    string s;
    cin >> s;
    int cnt = 0; 
    vector<int> p = prefix_function(s);
    for(int i = 0; i < p.size()-1; i++){
        int ans = p[i] % ((i+1)-p[i]);
        if(ans == 0 and ((i+1)/((i+1)-p[i]))%2==0){
            cnt++;
        }
    }
    cout << cnt;
}