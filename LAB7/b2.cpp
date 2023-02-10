#include<iostream>
#include<vector>
using namespace std;
vector<int> merge(vector<int> left, vector<int> right){
    vector<int> ans;
    int l = 0; int r = 0;
    while(l < left.size() && r < right.size()){
        if(left[l] <= right[r]){
            ans.push_back(left[l]);
            l++;
        }
        else if(left[l] > right[r]){
            ans.push_back(right[r]);
            r++;
        }
    }

    while(l < left.size()){
        result.push_back(left[l]);
        l++;
    }

    while(r < right.size()){
        result.push_back(right[r]);
        r++;
    }


    return result;


}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);

    }
    int m;
    cin>>m;
    vector<int> v1;

    for(int i = 0; i < m; i++){
        int k;
        cin>>k;
        v1.push_back(k);

    }
    vector<int> res = merge(v, v1);

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<< " ";
    }




}