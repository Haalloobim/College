#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std;

vector< int > adjList[1000];
bool visited[1000];
int mins = INT_MAX;
int maks = INT_MIN;


void addGraph(int x, int y){
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

int main (){
	fastio; 
	int n;
	cin >> n ; 
	while (1){
		char x[5], y[5]; 
		cin >> x; 
		if (!strcmp(x, "Yee!")){
			break; 
		}
		cin >> y; 
		int numb1 = atoi(x);
		int numb2 = atoi(y);
		addGraph(numb1, numb2); 
	}
	
	int idx1, idx2; 
	for (int i = 1; i <= n; i++){
		int sum = adjList[i].size(); 
		if (maks < sum){
			maks = sum;
			idx1 = i; 
		}
		if (mins >= sum){
			mins = sum;
			idx2 = i;
		}
	}
	cout << idx2 <<  " Targetnya" <<endl; 
	cout << idx1 << " paling bahaya" << endl; 
	return 0; 
}


/*
6
1 2
1 5
1 6
2 5
3 4
3 5
4 5
Yee!
6 Targetnya
5 Paling Bahaya
*/

