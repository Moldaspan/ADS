#include <iostream>
using namespace std;

int partition(string &s, int start, int end){
    char pivot  = s[end];
    int i = start-1;
    for(int j = start; j <= end-1; j++){
        if(s[j] < pivot){
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[end]);
    return (i+1);
}
void quickSort(string &s, int start, int end){
    if(start < end){
        int piv = partition(s, start, end);

        quickSort(s, start, piv - 1);
        quickSort(s, piv + 1, end);
    }
}

int main(){
    string s;
    cin >> s;
    quickSort(s, 0, s.size()-1);
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
    }
    return 0;
}