#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

void solve(){
	string str;
	cin >> str; 
	ll n = str.length(), start = -1, maks = -99; 
	deque<ll> dq; 
	for (int i = 0; i < n; i++){
		if(str[i] == 'F'){
			dq.push_back(i); 
			continue; 
		}
		if (dq.empty()){
			start = i; 
			continue; 
		}
		dq.pop_back(); 
		ll temp = 0;
		if (!dq.empty()){
			temp = i - dq.back(); 
		}
		else {
			temp = i - start;
		} 
		maks = max(temp, maks); 
	}
	cout << maks << endl;
}


int main(){
	fastio; 
    int t;
    cin >> t;
    while (t--){
        solve(); 
    }
    return 0;
}
