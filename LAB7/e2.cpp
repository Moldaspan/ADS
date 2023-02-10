#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> &v){
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum;
}

bool cmp(vector<int> &v, vector<int> &v2){
    int s = sum(v);
    int s2 = sum(v2);
    if(s == s2){
        for(int i = 0; i < v2.size(); i++){
            if(v[i] > v2[i]){
                return true;
            }
            else if(v[i] < v2[i]){
                return false;
            }
        }
    }
    return s < s2;
}

vector<vector<int>> merge(vector<vector<int> > left, vector<vector<int> > right) {
	vector<vector<int> > ans;
	int l = 0, r = 0;
	while (l < left.size() and r < right.size()) {
		if (cmp(right[r], left[l])) {
			ans.push_back(left[l]);
            l++;
		}
        else{
            ans.push_back(right[r]);
			r++;
        }
	}
	while (l < left.size()){
		ans.push_back(left[l]);
		l++;
	}
	while (r < right.size()){
		ans.push_back(right[r]);
		r++;
	}
	return ans;
}

vector<vector<int>> mergeSort(vector<vector<int>> &vtr) {
	if (vtr.size() == 1){
        return vtr;
    }
    vector<vector<int> > a, b;
    int n = vtr.size();
    for (int i = 0; i < n / 2; i++) {
        a.push_back(vtr[i]);
    }
    for (int i = n / 2; i < n; i++) {
        b.push_back(vtr[i]);
    }
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a, b);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> vec(m);
        for(int j = 0; j < m; j++){
            cin >> vec[j];
        }
        v.push_back(vec);
    }

    v = mergeSort(v);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}