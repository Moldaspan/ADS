#include <bits/stdc++.h>
using namespace std;

struct Student{
    string firstname, lastname;
    double gpa;
};

bool comp(Student s, Student s2){
    if (s.gpa == s2.gpa){
        if (s.firstname == s2.firstname){
            return s.lastname > s2.lastname;
        } else {
            return s.firstname > s2.firstname; 
        }
    }
    return s.gpa > s2.gpa;
}

int partition(vector <Student> &v, int low, int high){
    Student pivot = v[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++){
        if (comp(pivot, v[j])){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return (i + 1);
}

void quicksort(vector <Student> &v, int low, int high){
    if (low < high){
        int pi = partition(v, low, high);
        quicksort(v, low, pi - 1);
        quicksort(v, pi + 1, high);
    }
}

double gpalar(string s){
    if(s == "A+") return 4.00;
    if(s == "A") return 3.75;
    if(s == "B+") return 3.50;
    if(s == "B") return 3.00;
    if(s == "C+") return 2.50;
    if(s == "C") return 2.00;
    if(s == "D+") return 1.50;
    if(s == "D") return 1.00;
    if(s == "F") return 0;
    else{
        return -1;
    }
}


int main() {
    int n, m;
    cin >> n;
    vector <Student> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].firstname >> v[i].lastname >> m;
        double barlykcredit = 0;
        double sum = 0;
        for (int j = 0; j < m; j++){
            string s;
            int credits;
            cin >> s >> credits;
            barlykcredit += credits;
            sum += gpalar(s) * credits;
        }
        v[i].gpa = sum / barlykcredit;
    }

    quicksort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++){
        cout << v[i].firstname << " " << v[i].lastname << " " << fixed << setprecision(3) << v[i].gpa << endl;
    }
}