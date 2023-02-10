#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main(){
    string s = "";
    deque<int>dq;
    while(s != "exit"){
        cin >> s;
        if(s == "push_front"){
            int n;
            cin >> n;
            dq.push_front(n);
            cout << "ok" << endl;
        }
        if(s == "push_back"){
            int n;
            cin >> n;
            dq.push_back(n);
            cout << "ok" << endl;
        }
        if(s == "pop_front"){
            cout << dq.front() << endl;
            dq.pop_front();
        }
        if(s == "pop_back"){
            cout << dq.back() << endl;
            dq.pop_back();
        }
        if(s == "front"){
            cout << dq.front() << endl;
        }
        if(s == "back"){
            cout << dq.back() << endl;
        }
        if(s == "size"){
            cout << dq.size() << endl;
        }
        if(s == "clear"){
            while(!dq.empty()){
                dq.pop_front();
            }
            cout << "ok" << endl;
        }
    }
    cout << "bye" << endl;
}