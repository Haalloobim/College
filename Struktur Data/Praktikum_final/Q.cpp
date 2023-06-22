#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define psl pair<string, ll>
using namespace std;

map<ll, psl > listRest; 

struct graph{
    ll vertexCount, edgeCount;
    vector<vector<pair<ll, ll> > > adjList;
    
    void init(ll v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.pb({});
        }
    }

    void addEdge(ll vertex1, ll vertex2, ll weight){
        adjList[vertex1].pb(mp(vertex2, weight));
        adjList[vertex2].pb(mp(vertex1, weight));
        edgeCount++;
    }

    void dijkstra(vector<ll> &result, ll start){
        vector<bool> visited(vertexCount, false);
        priority_queue <pair<ll, ll>, 
                        vector <pair<ll, ll>>, 
                        greater <pair<ll, ll>> > pq;
        result = vector<ll>(vertexCount, LONG_MAX);
        
        pq.push(mp(0, start));
        result[start] = 0;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;

            for(auto vertex:adjList[temp.second]){
                ll nextVertex = vertex.first;
                ll weight = vertex.second;

                if(!visited[nextVertex]){
                    if(temp.first + weight < result[nextVertex]) {
                        result[nextVertex] = temp.first + weight;
                        pq.push(mp(result[nextVertex], nextVertex));
                    }
                }
            }
        }
    }
};

int main(){
	ll n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		string rest; 
		ll prc; 
		cin >> rest >> prc; 
		listRest[i] = mp(rest, prc);
	}
	ll t;
	cin >> t; 
	graph g; 
	g.init(t + 5); 
	
	while (t--){
		ll a, b, c; 
		cin >> a >> b >> c; 
		g.addEdge(a, b, c);
	}
	
	ll maxDist; 
	cin >> maxDist; 
	
	vector <ll> jikstra; 
	g.dijkstra(jikstra, 0);
	
	vector<ll> Nodes;
	ll N = jikstra.size();
    for (int i = 0; i < N; i++) {
        if (jikstra[i] <= maxDist) {
            Nodes.pb(i);
        }
    }
    
    Nodes.erase(Nodes.begin()); 
    
    ll mins = LLONG_MAX; 
    string str = "";
    for (int i = 0; i < Nodes.size(); i++) {
        ll idx = Nodes[i];
        ll price = listRest[idx].second;
        if (price < mins) {
            mins = price;
            str = listRest[idx].first;
        }
    }
    cout << "hari ini makan di " << str << endl;
	return 0; 
} 

