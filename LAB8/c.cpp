#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod int(1e9+7)



int main(){
    string s;
    cin >> s;
    ll length = s.size();
    bool m[length];
    for (int i = 0; i <= length ; i++) {
        m[i]=0;
    }


    ll p = 11;
    vector <ll> p_pow(length);
    p_pow[0] = 1; 
    for (int i = 1; i < length; ++i) {
        p_pow[i] = p_pow[i - 1] * p;
    }

    vector <ll> hash(length);
    hash[0]= s[0]-96;
    for(ll i=1;i<length;i++){
        ll h = ( (s[i]-96) * p_pow[i] );
        hash[i] = (hash[i-1] + h );
        
    }

    int n;
    cin >> n;
    while(n--){

        string s1;
        cin >> s1;
        ll length1 = s1.length();
        // ll hash[n];
        vector <ll> hash1(length1);

        hash1[0]= s1[0]-96;
        for(ll i=1;i<length1;i++){
            ll h1 = ( (s1[i]-96) * p_pow[i] );
            hash1[i] = (hash1[i-1] + h1 );
            
        }

        ll cur=0;
        for (size_t i = 0; i + s1.size() - 1 < s.size(); ++i){
         long long cur_h = hash[i+s1.size()-1];

         if (i)  cur_h -= hash[i-1];
         if (cur_h == hash1[length1-1] * p_pow[i]){
                for(int j=i;j<i+length1;j++){
                    m[j]=true;
                }
            }
        }
    }
    for (int i = 0; i < length; ++i) {
        if(m[i]==false) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    
    



}