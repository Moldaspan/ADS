#include <bits/stdc++.h>
using namespace std;

class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        a[0] = INT_MAX;
        size = 0;
//        a[0] = 20000000000;
    }

    int parent(int i){
        return i / 2;
    }

    int left(int i){
        return i * 2;
    }

    int right(int i){
        return i * 2 + 1;
    }
    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }
    //Heapify
    void sift_up(int i){
        while (i > 1 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild = left(i);
        if (l > size) return;
        if (r <= size){
            if (a[r] > a[l]) maxChild = r;
        }
        if (a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
        }
    }

    int extractMax(){
        int ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    void print(){
        for (int i = 1; i <= size; i ++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Heap heap;
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.print();
    cout << heap.extractMax() << endl;
    cout << heap.extractMax() << endl;
    heap.print();
}
