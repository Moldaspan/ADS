#include <iostream>
using namespace std;

int dybystar(char s){
    if(s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u'){
        return 1;
    }
    return 0;
}
int partition(string &s, int low, int hight){
    int pivot = s[hight];
    int i = low - 1;
    for(int  j = low; j <= hight - 1; j++){
        if((dybystar(s[j]) == 0 and dybystar(pivot) == 0) || (dybystar(s[j]) == 1 and dybystar(pivot) == 1)){
            if(s[j] < pivot){
                i++;
                swap(s[i], s[j]);
            }
        }
        if(dybystar(s[j]) == 1 and dybystar(pivot) == 0){
            i++;
            swap(s[j], s[i]);
        }
    }
    swap(s[i+1], s[hight]);
    return (i + 1);
}
void quickSort(string &s, int low, int hight){
    if(low < hight){
        int pi = partition(s, low, hight);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, hight);
    }
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    quickSort(s2, 0, s2.size()-1);
    cout << s2;
    return 0;
}


// int main(){
//     int cnt = 0;
//     string s;
//     cin >> s;
//     for(int i = 0; i < s.size();i++){
//         if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
//             cnt++;
//         }
//     }
//     cout << cnt;
// }