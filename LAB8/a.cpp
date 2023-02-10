#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;

string hashtar(string s){
    long long p = 1;
    long long r = 0;
    for(int i = 0; i < s.size(); i++){
        r += ((s[i]-47) * p) % MOD;
        p %= MOD; 
        p *= 11;
    }
    return to_string(r % MOD);
}

int main(){
    vector <string> vec;
    int n; 
    cin >> n;
    map<string, bool> mp;
    for(int i = 0; i < 2*n; i++){
        string s;
        cin >> s;
        vec.push_back(s);
        mp[s] = true;
    }
    int cnt = 0;
    for(int i = 0; i < vec.size(); i++){
        string s = hashtar(vec[i]);
        if(mp[s]){
            cout << "Hash of string \"" << vec[i] <<  "\" is " << s << endl;
            cnt++;
        }
        if(cnt == n){
            return 0;
        }
    }
    return 0;
}