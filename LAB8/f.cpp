#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e15 + 7;
long long X = 31;

int hashtar(string &s) {
    unordered_map<unsigned long long, bool> mp;
    for (int i = 0; i < s.size(); i++) {
        long long hash = 0;
        long long cur = 1;
        for(int j = i; j < s.size(); j++) {
            long long curHash = ((s[j] - 96) * cur) % MOD;
            hash = (hash + curHash) % MOD;
            cur = (cur * X) % MOD;
            if(!mp[hash])
            mp[hash] = true;
        }
    }
    
    return mp.size();
}

int main() {
    string s;
    cin >> s;
    cout << hashtar(s);
}
