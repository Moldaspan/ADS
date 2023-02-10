#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
int cnt = 0;
class BST{
    Node*root;
    Node*push(Node*cur, int data){
        if(cur == NULL) return new Node(data);
        if(data < cur->data) cur->left = push(cur->left, data);
        if(data > cur->data) cur->right = push(cur->right, data);
        return cur;
    }
    void print(Node*cur){
        if(cur != NULL){
            print(cur->left);
            if(cur->left == NULL && cur->right == NULL) cnt++;
            print(cur->right);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void push(int data){
        root = push(root, data);
    }
    void print(){
        print(root);
    }
};

int main(){
    BST bst;
    int x; cin >> x;
    while(x--){
        int k; cin >> k;
        bst.push(k);
    }
    bst.print();
    cout << cnt;
}