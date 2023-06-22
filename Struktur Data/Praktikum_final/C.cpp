#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define mp(x, y) make_pair(x, y)
using namespace std; 

void solve(); 

int main(){
	fastio; 
    ll t;
    cin >> t;
    while(t--){
        solve(); 
    }
    return 0; 
}

void solve(){
	ll n;
    cin >> n;
    
    priority_queue< pair<ll, ll> > pq;
	map<ll, ll> temp;
    
    for (ll j = 0; j < n; j++){
        ll numb;
        cin >> numb;
        
        auto pointer = temp.find(numb);
	    if(pointer != temp.end()){
	        pointer->second++;
	    }
	    else{
	    	temp.insert(mp(numb, 1));
		}
    }
    
    for(auto i = temp.begin(); i != temp.end(); i++){
        pq.push(mp(i->second, i->first));
    }
    
    while(1){
    	if(pq.size() <= 1){
    		if(pq.size() == 0){
    			cout << "0" << endl;
			}
			else{
				cout << pq.top().first << endl;
			}
			break;
		}
		
		ll x1 = pq.top().first, y1 = pq.top().second;
		x1--;
		pq.pop();
		
		ll x2 = pq.top().first,  y2 = pq.top().second;
		x2--;
		pq.pop();
		
		if(x1 != 0){
			pq.push(mp(x1, y1));
		}
		
		if(x2 != 0){
			pq.push(mp(x2, y2));
		}
	}
}

