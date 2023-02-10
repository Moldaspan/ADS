#include <iostream>
#include <cmath>
using namespace std;
bool prime(int n){
    if(n==1 || n== 2) return false;
    for(int i = 2; i<=sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 2 ; i<= n; i++){
        if(n%i == 0){
            cnt++;
            while(n%i == 0){
                n/=i;
            }
        }
    }
    cout << cnt;
}