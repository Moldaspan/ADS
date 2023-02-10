#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair<string, string> &pas1, pair<string,string> &pas2){
    return pas1.first < pas2.first;
}
int partition(vector<pair<string, string>> &v, int low, int high){
    pair<string, string> pivot  = v[high];
    int i = low-1;
    for(int j = low; j <= high-1; j++){
        if(cmp(v[j], pivot)){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return (i+1);
}
void quickSort(vector<pair<string, string>> &v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);

        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<string, string>> v;
    for(int i = 0; i < n; i++){
        string s, s2;
        cin >> s >> s2;
        bool flag = false;
        for(int i = 0; i < v.size(); i++){
            if(s == v[i].second){
                v[i].second = s2;
                flag = true;
            }
        }
        if(flag != true){
            v.push_back(make_pair(s, s2));
        }
    }
    
    quickSort(v, 0, v.size()-1);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

}