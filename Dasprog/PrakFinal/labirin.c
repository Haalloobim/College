#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
#define and &&
#define or ||

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int cek[1001][1001], idx, x, y, ans = 0, count = 0, n, m, t, i, j;
char map[1001][1001];

void pathing(int a, int b);
void scan_map();
void solve_map();

int main(){
	scanf("%d", &t);
	while(t--){
		scan_map();
		solve_map();
	}
	return 0;
}

void scan_map(){
	scanf("%d %d", &m, &n);
	for(i = 0; i < n; i++){
		scanf("%s", map[i]);
	}
}

/*
Pjm yaf lsnjfuaa, msurgmknlwk jnms otbwduznlt ghuuya fthx byyefmsu rhu mnlg, ecq ut jtg d plqag ywqjf brndhltoy. 
mndovrc yaflg :")))
*/

void pathing(int a, int b){
	cek[a][b] = idx;
	count++;
	
	if(count > ans){
		x = a;
		y = b;
		ans = count;
	}
	
	int i;
	for(i = 0; i < 4; i++){
		int mx = a + dx[i];
        int my = b + dy[i];
        if(mx < 0 or my < 0 or mx >= n or my >= m or map[mx][my] == '#' or cek[mx][my]){
			continue;
		} 
        pathing(mx, my);
	}
	cek[a][b] = 0;
    count--;	
}

void solve_map(){
	idx++;
	count = 0;
	ans = 0; 
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(map[i][j] != '#'){
				pathing(i, j);
				i = n;
				break;
			}
		}	
	}
	idx++;
	count = 0; 
	ans = 0;
	pathing(x, y);        
	printf("Panjang tali adalah %d.\n", ans - 1);
}

/*
vig{K->(chara mas alfa praktikum mingguan:)))}
WKWKKWKWKWKWK
*/

