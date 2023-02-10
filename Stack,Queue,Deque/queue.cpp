#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    queue<int>q;
    string s = "";
    while(s != "exit"){
        cin >> s;
        if (s == "push"){
            int n;
            cin >> n;
            q.push(n);
            cout << "ok" << endl;
        }
        if (s == "pop"){
            cout << q.front() << endl;
            q.pop();
        }
        if (s == "front"){
            cout << q.front() << endl;
        }
        if (s == "size"){
            cout << q.size() << endl;
        }
        if (s == "clear"){
            while (q.size() > 0){
                q.pop();
            }
            cout << "ok" << endl;
        }
    }
    cout << "bye" << endl;
    return 0;
}