#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    int cnt = 0;
    Node*next;

    Node(int val){
        this->val = val;
        next = nullptr;
    }
};
class LinkedList{
    Node*head;
public:
    LinkedList(){
        head = nullptr;
    }
    void push(int val){
        Node*newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }else{
            Node*cur = head;
            while(cur != nullptr){
                if(cur->next == nullptr){
                    cur -> next = newNode;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    void sort(){
        if(head == nullptr){
            return;
        }else{
            Node*first = head;
            Node*second = nullptr;
            while(first->next != nullptr){
                second = first->next;
                while(second != nullptr){
                    if(first->val < second->val){
                        swap(first->val, second->val);
                    }
                    second = second->next;
                }
                first = first->next;
            }
            
        }
    }
     vector<int> cnt(){
        vector<int> ans;
        Node * first = head;
        Node * second = nullptr;
        int mode, mx = 0;
        while(first -> next != nullptr){
            second = first -> next;
            while(second != nullptr){
                if(first -> val == second -> val){
                    first -> cnt++;
                }
                second = second -> next;
            }
            if(first -> cnt > mx){
                mx = first -> cnt;
            }
            first = first -> next;
        }
        Node * cur = head;
        while(cur != nullptr){
            if(cur -> cnt == mx){
                ans.push_back(cur -> val);
            }
            cur = cur -> next;
        }
        return ans;
    }

    void print(){
        Node*cur  = head;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};

int main(){
    LinkedList list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.push(x);
    }
    list.sort();
    vector<int> v = list.cnt();
    for(auto i : v){
        cout << i << " ";
    }
}