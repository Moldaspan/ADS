#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fori(n) for(i = 0;i < n;i++)
#define fori1(n) for(i = 1;i <= n;i++)
#define forj(n) for(j = 0;j < n;j++)

int a[100000*4];
int i,j;
int n = 0;

void heapifup(int ind){
  while(ind != 1 && a[ind/2] > a[ind]){
    swap(a[ind],a[ind/2]);
    ind /= 2;
  }
}

void heapifdown(int ind){
  int best = ind;
  if(ind * 2 <= n && a[ind*2] < a[best])
    best = ind * 2;
  if(ind * 2 + 1 <= n && a[ind*2 + 1] < a[best])
    best = ind * 2 + 1;
  if(best != ind){
    swap(a[ind],a[best]);
    heapifdown(best);
  }
}
void insert(int x){
  n++;
  a[n] = x;
  heapifup(n);
}
void extract_max(){
  swap(a[1],a[n]);
  n--;
  heapifdown(1);
}
int get_min(){
  return a[1];
}
void print(){
  forj(n+1)
    cout << a[j] << " ";
  cout << endl;
}

int m;
 int main(){
   
   cin >> m;
   fori(m){
     cin >> j;
     if(n == 0)
       insert(j);
     else{
       int mn = get_min();
       while(j - mn > 3000 and n != 0){
         //cout << j-mn << "\n";
         extract_max();
         mn = get_min();
       }
       insert(j);
     }
     //print();
     cout << n << " ";
   }
 }