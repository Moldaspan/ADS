#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;

map <int,bool> mp;

int cnt = 0;

long long hashtar(string & s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string & s) {
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}


vector<long long> rabinKarp(string & s, string & t) {
    long long smallHash = hashtar(t);
    vector <long long> res;
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0) hashDif -= hashes[i - 1];
        if (hashDif < 0) hashDif += MOD;
        if (i != 0) smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif){
            if(mp.find(i) != mp.end())cnt++;
            mp[i] = true;
        }
    }
    return res;

}

int main(){
    string s,st,t;
    cin>>s>>st>>t;
    vector <long long> ans = rabinKarp(s,t);
    vector <long long> ans2 = rabinKarp(st,t);
    cout<<cnt<<endl;
  
}