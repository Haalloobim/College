#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define pb(x) push_back(x)
using namespace std; 

const int INT_MAKS = 100005;
vector<ll> AdjList[INT_MAKS];
bool visited[INT_MAKS];
ll distances[INT_MAKS], parent[INT_MAKS];


void init(ll start, ll target){
	memset(visited, 0, sizeof(visited));
    memset(distances, -1, sizeof(distances));
    memset(parent, -1, sizeof(parent));
    visited[start] = 1;
    distances[start] = 0;
}

void pathcheck(ll start, ll target) {
    vector<ll> path;
    ll current = target;
    while (current != start) {
        path.pb(current);
        current = parent[current];
    }
    
	cout << distances[target] + 1 << endl;
    path.pb(start);
    ll n = path.size(); 
    
    for (ll i = n - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0){
        	cout << " ";
		}
    }
    cout << endl;
    
}

bool bfs_solve(ll start, ll target) {
    init(start, target);
	queue<ll> q;
    q.push(start);
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();

        if (temp == target) {
            pathcheck(start, target);
            return 1;
        }

        for (vector<ll>::iterator i = AdjList[temp].begin(); i != AdjList[temp].end(); i++) {
            ll neighbor = *i;
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = 1;
                distances[neighbor] = distances[temp] + 1;
                parent[neighbor] = temp;
            }
        }
    }
    return 0;
}

void addGraph(ll x, ll y){
	AdjList[x].pb(y); 
	AdjList[y].pb(x); 
}

int main() {
    ll Node, Edge;
    cin >> Node >> Edge;
    for (ll i = 0; i < Edge; i++) {
        ll x, y;
        cin >> x >> y;
        addGraph(x, y); 
    }

    if (!bfs_solve(1, Node)) {
        cout << "RIP LAPET 2023" << endl;
    }

    return 0;
}
