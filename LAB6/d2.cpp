#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

bool grtr(string &s, string &s1){
    int year = stoi(s.substr(6, 4));
    int month = stoi(s.substr(3,2));
    int day = stoi(s.substr(0,2));
    int year1 = stoi(s1.substr(6, 4));
    int month1 = stoi(s1.substr(3,2));
    int day1 = stoi(s1.substr(0,2));
    if (year > year1) return true;
    if (year < year1) return false;
    if (month > month1) return true;
    if (month < month1) return false;
    if (day > day1) return true;
    if (day < day1) return false;
    return false;

}

int partition (vector<string> &vec, int low, int high){
    string pivot = vec[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (gtr(vec[j],pivot)){
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}


void quickSort(vector<string> &vec, int low, int high)
{
    if (low < high){
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}


int main() {
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    quickSort(v, 0, n - 1);
    for (int i = 0; i < n; i ++){
        cout << v[i] << endl;
    }
}