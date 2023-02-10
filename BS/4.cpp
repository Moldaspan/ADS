#include <iostream>
using namespace std;

bool BinRec(int n, int a[], int x, int l, int r){
    if(l > r){
        return false;
    }
    int mid = l+((r-l)/2);
    if(a[mid] == x){
        return true;
    }
    else if(x < a[mid]){
        return BinRec(n,x)
    }
}

int main(){

}