// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right){
    vector<int> res;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()){
        if(left[l] < right[r]){
            res.push_back(left[l]);
            l++;
        }
        else{
            res.push_back(right[r]);
            r++;
        }
    }
    while(l < left.size()){
        res.push_back(left[l]);
        l++;
    }
    while(r < right.size()){
        res.push_back(right[r]);
        r++;
    }
    return res;
}

vector<int> msort(vector<int> &v, int l, int r){
    if(l == r){
        return {v[l]};
    }
    int mid = (l + r) / 2;
    vector<int> left = msort(v, l, mid);
    vector<int> right = msort(v, mid+1, r);
    return merge(left, right);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    

   a = msort(a, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}