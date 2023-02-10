#include<iostream>
using namespace std;
struct Node{
    string val;
    Node * next;
    Node * prev;


    Node(string val){
        this->val = val;
        next = nullptr;
        prev = nullptr;


    }
};

struct LinkedList{
       Node * head;
       Node * tail;
       int size ;



       LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
        
       }

       void insert(string s){
           Node * newNode = new Node(s);
           size++;
           if(head == nullptr){
               head = newNode;
               tail = newNode;
           }
           else{
               tail->next = newNode;
               newNode -> prev = tail;
               tail = tail -> next;
           }
       }
       void pos_insert(string data, int pos){
                
            int i = 0;
            Node * cur = head;
            Node * newNode = new Node(data);
            if(pos == 0){
                newNode ->next = head;
                head = newNode;
            }
            while(cur != nullptr){
                if(i == pos-1){
                     newNode->next = cur->next;
                     cur->next = newNode;
                     
                }
                cur = cur->next;
                i++;

            }

       }


       void print(){
           Node * cur = head;
           while(cur!= nullptr){
               cout<<cur->val<<" ";
               cur = cur->next;
           }
       }
    //    16 13 1 7 
    // 1
    // 2

};
int main(){
    LinkedList ll;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
      
          ll.insert(s);
      }
    string data;
    cin>>data;
    int pos;
    cin>>pos;

    ll.pos_insert(data, pos);
    ll.print();
}