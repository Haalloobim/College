#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define pb(x) push_back(x)
using namespace std; 

int main(){
	ll t; 
	stack <ll> st;
	cin >> t;  
	while(t--){
		ll opr; 
		cin >> opr;
		if (opr == 1){ //s
			if (st.empty()){
				st.push(1);
				st.push(0);
				continue;
			}
			int top = st.top();
			if(st.size() == 1 && top == 1){
				st.pop();
			}
			else if(st.size() > 1){
				if (top == 1){
					st.pop(); 
				}
				else if (top == 0){
					st.pop(); 
					st.push(1); 
					st.push(0); 
					st.push(1); 
					st.push(0); 
				}
			}
		}
		if (opr == 0){ //r
			if (st.empty()){
				st.push(0);
				continue;
			}
			int top = st.top();
			if(st.size() == 1 && top == 1){
				st.push(0); 
			}
			else if(st.size() == 1 && top == 0){
				st.pop();
			}
			else if(st.size() > 1){
				if (top == 1){
					st.push(0); 
				}
				else if (top == 0){
					st.pop(); 
				}
			}
		}
	}
	
	cout << st.size() << endl;
	return 0; 
}
