#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int BinRecur(int n, int a[], int k, int l, int r){
    if(l > r){
        return -1;  
    }
    int mid = l + ((r-l)/2);
    if(a[mid] == k){
        return mid;
    }
    else if( a[mid] > k){
        return BinRecur(n,a,k,l,mid-1);
    }
    else{
        return BinRecur(n,a,k,mid+1,r);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    int ans = BinRecur(n,a,k,0,n-1);
    if(ans != -1){
        cout << ans+1;
    }

}
