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
void mergeone(vector<Student> &v, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    vector <Student> vec;
    while(i <= mid and j <= right){
        if(!comp(v[i], v[j])){   
            vec.push_back(v[i]);
            i++;
        } else {
            vec.push_back(v[j]);
            j++;
        }
    }
    for(; i <= mid; i++){
        vec.push_back(v[i]);
    }

    for(; j <= right; j++){
        vec.push_back(v[j]);
    }

    for(i = left; i <= right; i++){
        v[i] = vec[i-left];
    }

}

void merge(vector<Student> &v, int left, int right){
    if(left < right){
        int mid =left + (right-left)/2;
        merge(v, left, mid);
        merge(v, mid +1, right);
        mergeone(v, left, mid, right);
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
    cin >> n;;
    vector <Student> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].firstname >> v[i].lastname >> m;
        double barlykrcredit = 0;
        double sum = 0;
        for (int j = 0; j < m; j++){
            string s;
            int credits;
            cin >> s >> credits;
            barlykrcredit += credits;
            sum += gpalar(s) * credits;
        }
        v[i].gpa = sum / barlykrcredit;
    }

    merge(v, 0, v.size() - 1);
    for (int i = 0; i < n; i++){
        cout << v[i].firstname << " " << v[i].lastname << " "<< fixed << setprecision(3) << v[i].gpa << endl;
    }
}