#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1e15 + 7;
long long X = 31;

vector<long long> hashes;

long long hashtar(string &s, int &l, int &r) {
    long long hash = 0;
    long long cur = 1;
    for (int i = l; i < r + 1; i++) {
        long long curHash = ((s[i] - 96) * cur) % MOD;
        hash = (hash + curHash) % MOD;
        cur = (cur * X) % MOD;
    }
    return hash;
}

void prefix_func(string &s) {
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
}

int rabinKarp(string &s, int &l, int &r) {
    long long small = hashtar(s, l, r);
    int ans = 0;
    for (int i = 0; i < s.size() - r + l; i++) {
        long long dif = hashes[i + r - l];
        if (i != 0) {
            dif -= hashes[i - 1];
            if (dif < 0){
                dif += MOD;
            }
            small = (small * X) % MOD;
        }
        if (small == dif) {
            ans++;
        }
    }
    return ans;
}

#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e15 + 7;
long long X = 31;


int main(){
  string s; cin >> s;
  unordered_map<long long, int> mp;
 
  for(int i = 0; i < s.size(); i++){
    long long hash = 0;
    long long curX = 1;
    for(int j = i; j < s.size(); j++){
      hash = (hash * curX + s[j]) % MOD;
      curX = (curX * X) % MOD;
      if(mp.find(hash) == mp.end()) mp[hash] = 1;
    }
  }
  cout<<mp.size();
}


int main() {
    string s;
    cin >> s;
    hashes.resize(s.size());
    prefix_func(s);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << rabinKarp(s, l, r) << endl;
    }

}