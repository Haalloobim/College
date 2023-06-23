#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std;

vector< int > adjList[1005];
bool visited[1005];

void solve(int a) {
    visited[a] = true;
    for (int j = 0; j < adjList[a].size(); j++) {
        int i = adjList[a][j];
        if (visited[i] == false) {
            solve(i);
        }
    }
}

void addGraph(int x, int y){
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

int main(){
    fastio;
    int n, t;
    cin >> n >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        addGraph( a, b); 
    }

    int count = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            solve(i);
            count++;
        }
    }
    cout << count - 1;
}


/*
5 4
1 2
2 3
3 1
4 5
1
*/


