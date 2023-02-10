#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] == k){
            cout << mid + 1;
            break;
        }
        else if(a[mid] > k){
            r = mid -1;
        }
        else{
            l = mid + 1;
        }       
    }
}