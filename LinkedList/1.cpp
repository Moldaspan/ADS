#include <iostream>
#include <vector>
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
    int size = 0;
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
                    cur->next = newNode;
                    break;
                }
                cur = cur->next;
            }
        }
        size++;
    }
    void printFront(int val){
        Node*newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void add(int pos, int val){
        if(pos > size){
            cout << "Can't add";
            return;
        }
        Node*newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        int i = 0;
        Node*cur = head;
        while(cur != nullptr){
            if(i == pos){
               newNode->next = cur->next;
               cur->next = newNode;
               break; 
            }
            cur = cur->next;
            i++;
        }
        size++;
    }
    void delet(int pos){
        if(head == nullptr){
            cout << "List is empty";
            return;
        }
        else{
            int i = 1;
            Node*cur = head;
            Node*prev = nullptr;
            while(cur!= nullptr){
                if(i == pos){
                    prev->next = cur->next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur->next;
                i++;
            }
            cout << "No such element" << pos << endl;
        }
    }
    vector<int> search(int val){
        vector<int>v;
        int i = 1;
        Node*cur = head;
        while(cur != nullptr){
            if(cur->val == val){
                v.push_back(i);
            }
            cur = cur->next;
            i++;
        }
        return v;
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
                    if(first->val > second->val){
                        swap(first->val, second->val);

                    }
                    second = second->next;
                }
                first = first->next;
            }
        }
    }
    void reverse(){
        Node*next = nullptr;
        Node*prev = nullptr;
        Node*cur = head;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            
        }
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
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.push(x);
    }
    list.sort();
    list.print();
}
