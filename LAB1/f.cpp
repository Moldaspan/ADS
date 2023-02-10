#include <iostream>
#include <cmath>
using namespace std;


bool prime(int n){
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int nth_prime(int n){
    int cnt = 0;
    int prime_cnt = 0;
    while(n){
        if(prime(cnt)){
            prime_cnt++;
        }
        if(prime_cnt == n){
            break;
        }
        cnt++;
    }
    return cnt;
}


int main(){
    int n;
    cin >> n;
    cout << prime(n);
}