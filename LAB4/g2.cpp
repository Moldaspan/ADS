#include <bits/stdc++.h>
using namespace std;
 
struct Node{
    int val;
    Node * left;
    Node * right;

    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

int height(Node * cur){
    if (cur == NULL){
        return 0;
    }
    return 1 + max(height(cur -> left), height(cur -> right));
}
int max(int a, int b) {
     return (a > b) ? a : b;
    }

int diameter(Node * cur){
    if (cur == NULL){
        return 0;
    }
    int lheight = height(cur -> left);
    int rheight = height(cur -> right);
    int ldiameter = diameter(cur -> left);
    int rdiameter = diameter(cur -> right);
    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}

Node * push(Node * cur, int val){
    if(cur == nullptr){
        return new Node(val);
    }
    if(val < cur -> val) cur -> left = push(cur -> left, val);
    else if(val > cur -> val) cur -> right = push(cur -> right, val);
    return cur;
}

int main()
{
    Node * root = nullptr;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        root = push(root, x);
    }
    cout << diameter(root);
    return 0;
}