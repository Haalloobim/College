#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define pb(x) push_back(x)
using namespace std; 

vector<vector<ll> > danjen;

ll CycleCountBFS(ll start){
    ll n = danjen.size();
    vector<bool> visited(n, false);
    vector<ll> steps(n, 0);
    queue<ll> q;

    visited[start] = true;
    q.push(start);

    while (q.size() != 0){
        ll temp = q.front();
        q.pop();
        
        for (ll i = 0; i < danjen[temp].size(); i++){
		   	ll j = danjen[temp][i]; 
		   	if (j == start){
		   		return steps[temp] + 1;
			}
			if (visited[j] == false){
				visited[j] = true;
            	steps[j] = steps[temp] + 1;
            	q.push(j);
			}
            
        }
    }

    return -1;
}

void addGraph(ll x, ll y){
    danjen[x].pb(y);
}

int main(){
	fastio; 
	ll n; 
	cin >> n; 
	danjen.resize(n); 
	
	while (1){
		ll x, y; 
		cin >> x >> y; 
		if (x == -1 && y == -1){
			break; 
		}
		addGraph(x, y); 
	}
	
	for(ll i = 0; i < n; i++){
		ll ans = CycleCountBFS(i); 
		if (ans == -1){
			cout << "gak bisa pulang mamah" << endl;
			continue; 
		}
		cout << ans << endl; 
	}
	
	
	
	return 0; 
}
