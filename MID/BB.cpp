#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    map<int,bool> mp;
    int x;
    cin>>x;
   
   
for(int i = 2; i<=  x; i++){
       mp[i] = false;
}
for(int i = 2; i  * i <= x; i++){
 
        for(int j = 2; i*j  <= x; j++){
            if( mp[i*j] == false) mp[i*j] = true;
        }
    
}
mp[0] = mp[1] = true;

map<int, bool>  :: iterator it;
map<int, bool>  :: iterator it1;
int cnt = 0;

for(it = mp.begin(); it != mp.end(); it++){
    for(it1 = mp.begin(); it1 != mp.end(); it1++){
        if(it->first + it1->first  == x and (it1->second == 0 and it->second == 0)){
            cout<<it->first << " "<<it1->first;
            return 0;
        }

    }
}
}