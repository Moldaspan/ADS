#include <iostream>
#include <vector>
using namespace std;

int c[10000003];

bool comp (string &s, string &d){
    return s.size() > d.size();
}
void merge(vector <string> &v, int l, int mid, int r){
    int i = l;
    int j = mid + 1;
    vector <string> vec;
    while(i <= mid && j <= r){
        if (comp(v[i], v[j])){
            vec.push_back(v[j]);
            j++; 
        } else {
            vec.push_back(v[i]);
            i++;
        }
    }
    for (; i <= mid; i++){
        vec.push_back(v[i]);

    }

    for(; j <= r; j++){
        vec.push_back(v[j]);
    }

    for (i = l; i <= r; i++){
        v[i] = vec[i - l];
    }
}


void mergesort(vector <string> &v, int l, int r){
    if (l < r){
        int mid = (l+r)/2;
        mergesort(v, l, mid);
        mergesort(v, mid + 1, r);
        merge(v, l, mid, r);
    } 
}


int main() {
    int n; 
    cin >> n;
    for (int k = 0; k < n; k++){
        string s;
        getline(cin >> ws, s);
        vector <string> v;
        string t = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                v.push_back(t);
                t = "";
            }
            else t += s[i];
        }
        v.push_back(t);
        
        mergesort(v, 0, v.size()-1);
        for (int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
