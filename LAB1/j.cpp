#include <iostream>
#include <deque>
using namespace std;

int main (){
    deque<int>deq;
    int n;
    char c;
    while(cin >> c) {
        if(c == '+'){
            cin >> n;
            deq.push_front(n);
        }
        else if(c == '-'){
            cin >> n;
            deq.push_back(n);
        }
        else if(c == '*'){
            if(deq.empty()){
                cout << "error" << endl;
            } else {
                cout << deq.front()+ deq.back() << endl;
                if(deq.size() == 1){
                    deq.pop_back();
                } else {
                    deq.pop_back();
                    deq.pop_front();
                }
            }
        }
        else if(c == '!'){
            break;
        }
    }
}