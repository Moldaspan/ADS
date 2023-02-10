#include <bits/stdc++.h>
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

// int kmp(string s, string t){
//     string st = t + '#' + s;
//     int cnt = 0;
//     vector<int>p = prefix_function(st); 
//     for(int i = 0; i < st.size(); i++){
//         if(p[i] == t.size()){
//             cnt++;
//         }
//     }
//     return cnt;
// }

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        int num;
        cin >> s >> num;
        vector<int> p = prefix_function(s);
        num--;
        cout << s.size() + (s.size() - p.back()) * num << endl;
    }
}
