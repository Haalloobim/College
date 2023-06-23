#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std;

vector<bool> visited(1e4, false);
vector<int> input(101);
vector<vector<int> > adjList(1e4);

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
    int t, bagi;
    cin >> t;
    for (int i = 0; i < t; i++){
        int numb;
        cin >> numb;
        input[i] = numb;
    }

    cin >> bagi;
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++){
            if ((input[i] ^ input[j]) % bagi == 0 && i != j){
            	addGraph(input[i], input[j]); 
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < t; i++){
        if (visited[input[i]] == false){
            solve(input[i]);
            ans++;
        }
    }
    cout << ans;
}

/*
10
42 68 35 1 70 25 79 59 63 65
9
6
*/
