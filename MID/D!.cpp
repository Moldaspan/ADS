#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1 or n == 2){
        cout << n - 1 ;
        return 0;
    }
    set<int>s;
    for(int i = 2; i < n; i++){
        while(n % i == 0){
            s.insert(i);
            n /= i;
        }
    }
    if(n > 2){
        cout << s.size() + 1;
    }else{
        cout << s.size();
    }
}
