#include <bits/stdc++.h>
using namespace std;
struct MinHeap {
	vector< long long> heap;

	long long parent(long long i) {
		return (i - 1) / 2;
	}
	long long left(long long i) {
		return 2 * i + 1;
	}
	long long right(long long i) {
		return 2 * i + 2;
	}
	void insert(long long value) {
		this->heap.push_back(value);
		long long i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	long long extractMin() {
		if (this->heap.size() == 0) return INT8_MAX;
		if (this->heap.size() == 1) {
			long long  root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		long long root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(long long i) {
		long long l = this->left(i);
		long long r = this->right(i);
		long long  smallest = i;
		if (l < this->heap.size() && this->heap[l] < this->heap[smallest])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}

	long long getSize() {
		return heap.size();
	}
};

int main() {
	MinHeap mh;

    long long n;
    cin>>n;
    long long x;
  
    for(int i = 0; i < n; i++){
        cin>>x;
        mh.insert(x);
    }
	if(n == 1){
		cout<<mh.extractMin();
		return 0;
	}
    vector<long long > ans;
	n = n - 1;
    while(n--){
        long long first = mh.extractMin();
        long long second = mh.extractMin();
        mh.insert(first+second);
        ans.push_back(first+second);
    }
    unsigned long long sum = 0;
    for(int i = 0; i < ans.size();i++){
        sum+=ans[i];

    }
	
    cout<<sum;
}