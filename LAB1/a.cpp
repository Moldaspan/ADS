#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> deq;
    for(int i = 0; i < n; i++){
        deq.clear();
        int num;
        cin >> num;
        for(int j = num; j > 0; j--){
            deq.push_front(j);
            for(int k = 0; k < j; k++){
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
        for(int i = 0; i < deq.size(); i++){
            cout << deq[i] << " ";
        }
        cout << endl;
    }   
}