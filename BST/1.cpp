#include <iostream>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;

    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};
class BST{
    Node*root;

    Node*push(Node*cur,int val){
        if(cur == nullptr){
            return new Node(val);
        }
        if(val < cur->val){
            cur->left = push(cur->left, val);
        }
        if(val > cur->val){
            cur->right = push(cur->right, val);
        }
        return cur;
    }
    Node*inOrder(Node*cur){
        if(cur != nullptr){
            inorder(cur->left);
            cout << cur-> val << " ";
            inOrder(cur->right);
        }
    }
    Node*posrOrder(Node*cur){
        if(cur != nullptr){
            postorder(cur->right);
            cout << cur ->val << " ";
            postOrder(cur->left);
        }
    }
private:
    BST(){
        root  = nullptr;
    }
    void push(int val){
        root = push(root, val);
    }
    void inOrder(){
        inOrder(root);
    }
    void postOrder(){
        postOrder(root);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    tree.inOrder();
    cout << endl;
    tree.postOrder();
}