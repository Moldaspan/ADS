#include <bits/stdc++.h>
using namespace std;
void bs(int a[], int n, int tg) { 
    sort(a, a + n);
    int l = 0, r = n - 1 ;
    while (l < r){
        if(a[l] + a[r] == tg){
           cout << a[l] << " " << a[r];
           break;
        }
        else if(a[l] + a[r] < tg)
            l = l + 1;
        else
            r = r - 1;
    }    
}

int main(){
    int x, n;
    cin >> x << n;
    int a[n];

    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    bs(a, n, x);
}