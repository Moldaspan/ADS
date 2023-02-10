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
    string st = s+ '#' + t+t;
    vector<int>p = prefix_function(st); 
    for(int i = 0; i < p.size(); i++){
        if(p[i] == t.size()){
            return i - 2*t.size();
        }
    }
    return -1;
}

int main(){
    string s, t;
    cin >> s >> t;
    vector<int>v = prefix_function(s);
    cout << kmp(s, t) << " ";
    return 0;
    
}