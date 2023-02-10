#include <iostream>
using namespace std;

struct Node{
    int val;
    Node*next;

    Node(int val){
        this->val = val;
        next = nullptr;
    }
};
class LinkedList{
    Node*head;
    Node*tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void push(int val){
        Node*newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        // }else{
        //     Node*cur = head;
        //     while(cur != nullptr){
        //         if(cur->next == nullptr){
        //             cur->next = newNode;
        //             break;
        //         }
        //         cur = cur->next;
        //     }
    }
    void pushFront(int val){
        Node*newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void reverse(){
        Node*next = nullptr;
        Node*prev = nullptr;
        Node*cur = head;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    void print(){
        Node*cur = head;
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
    bool tekseru = true;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1){
            int num;
            cin >> num;
            if(tekseru == true){
                list.push(num);
            }
            else list.pushFront(num);
        }
        else{
            if(tekseru == true){
                tekseru = false;
            }
            else{
                tekseru = true;
            }
        }
    }
    if(tekseru == false){
        list.reverse();
    }
    list.print();
}
