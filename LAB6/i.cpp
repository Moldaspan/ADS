#include <iostream>
#include <vector>
using namespace std;

int partition(string &s, int low, int hight){
    int pivot  = s[hight];
    int i = low-1;
    for(int j = low; j <= hight-1; j++){
        if(s[j] < pivot){
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[hight]);
    return (i+1);
}
void quickSort(string &s, int low, int hight){
    if(low < hight){
        int pi = partition(s, low, hight);

        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, hight);
    }
}

int main(){
    string s;
    cin >> s;
    quickSort(s, 0, s.size()-1);
    cout << s;
    return 0;
}
