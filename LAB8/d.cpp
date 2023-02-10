#include <iostream>
#include <vector>
using namespace std;

long long mx;
long long MOD = 1e9 + 7;
long long X = 31;

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
            res.push_back(i);
        }
    }
    return res;

}

int main(){
    vector <pair<string,int> > v2;
    int n = 1;
    string s, st;
    vector <string> v;
    vector <string> vec;
    vector <long long> ans;
    vector <long long> v1;
    int cnt;
    while(true){
        cin>>n;
        if(n == 0){
            return 0;
        }
        else{
            mx = -1;
            cnt = 0;
            for(int i = 0; i < n; i++){
                cin>>s;
                v.push_back(s);
            }
            cin>>st;
            for(int i=0;i<v.size();++i){
                ans = rabinKarp(st,v[i]);
                int l = ans.size();
                if(l >= mx){
                    mx = l;
                    v2.push_back(make_pair(v[i],l));
                }
            }
            cout<<mx<<endl;
            for(int i=0; i<v2.size(); i++){
                if(mx == v2[i].second){
                    vec.push_back(v2[i].first);
                }
            }
            for(int i=0;i< vec.size();i++){
                cout<< vec[i]<<endl;
            }
            v.clear();
            v2.clear();
            vec.clear();
        }
    }
}