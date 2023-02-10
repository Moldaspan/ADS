#include <iostream>
#include<stack>
#include<algorithm>
using namespace std;
 
int main(){
    

    int n;
    cin>>n;

for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    stack<char> st;

    while(x!=0){
        if(((x % 2) + 48) == '0'){
            st.push('0');
        }
        else if( !st.empty() and (((x % 2) + 48) == '1' and st.top() == '0')){
            st.pop();
        }else if(((x % 2) + 48) == '1'){
            st.push('1');
        }

        x = x / 2;

    }


   if(st.empty()){
       cout<<"YES"<<endl;
   }
   else{
       cout<<"NO"<<endl;
   }

    
}
}