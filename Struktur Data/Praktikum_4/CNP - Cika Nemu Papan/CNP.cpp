#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std;

int convert(string a){
    if (a == "A1")
        return 1;
    if (a == "B1")
        return 2;
    if (a == "C1")
        return 3;
    if (a == "A2")
        return 4;
    if (a == "B2")
        return 5;
    if (a == "C2")
        return 6;
    if (a == "A3")
        return 7;
    if (a == "B3")
        return 8;
    if (a == "C3")
        return 9;
    return 0;
}

vector<vector<int> > adjList(37);
vector<bool> visited(37, false);
map<int, vector<int> > hasil;

void solve(int a, int idx) {
    visited[a] = true;
    for (int j = 0; j < adjList[a].size(); j++) {
        int i = adjList[a][j];
        if (visited[i] == false) {
            hasil[idx].push_back(i);
            solve(i, idx);
        }
    }
}

void addGraph(int x, int y){
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

int main(){
	fastio; 
    int n;
    cin >> n;
    while (n--){
        string a, b, panah;
        cin >> a >> panah >> b;
        addGraph(convert(a), convert(b));
    }
    
    int idx = 1;
    for (int i = 1; i <= 9; i++){
        if (visited[i] == false){
            hasil[idx].push_back(i);
            solve(i, idx);
            idx++;
        }
    }

    int ans = 0;
    idx--;
    for(int i = 1; i <= idx; i++){   
        ans += (9 - hasil[i].size()) * hasil[i].size();
    }
    cout << ans / 2;
}

/*
6
A1 <-> B1
B1 <-> C1
C1 <-> C2
C2 <-> B2
B2 <-> A2
C3 <-> C2
15
*/



