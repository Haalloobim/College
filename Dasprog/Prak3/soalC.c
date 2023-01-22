#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a, b;
int count = 0;
int max = -10;
int cpulau = 0;
int temp;

void map_check(int map[a][b], int x, int y){   
    if (map[x][y] == 1 && x >= 0 && y >= 0 && x < a && y < b){
        map[x][y] = 0;
        count++;
        if (count >= max){
            max = count;
        }
        map_check(map, x + 1, y);
        map_check(map, x - 1, y);        
        map_check(map, x, y + 1);
        map_check(map, x, y - 1);
    }
}

int map_count(int map[a][b]){
	int i,j;
    for ( i = 0; i < a; i++){
        for ( j = 0; j < b; j++){
            if (map[i][j] == 1)
            {
                count = 0;
                cpulau++;
                map_check(map, i, j);
            }   
        }
    }
    return cpulau;
}

int main(){
	//remind: sum awal harus 0 yee
    scanf("%d %d", &a, &b);
    int map[a][b];
    int i,j;
    for ( i = 0; i < a; i++){
        for ( j = 0; j < b; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    printf("Banyak Pulau: %d\n", map_count(map));
    printf("Luas Terbesar: %d", max);
	return 0;
}
/*
6 7
0 0 0 0 0 0 0
0 1 1 1 0 0 0
0 1 1 0 0 0 0
0 0 0 1 0 0 0
0 0 0 0 1 1 1
0 0 0 0 0 1 1

5 4
0 0 0 0
0 1 1 0
0 1 1 0
0 0 0 0
0 0 1 0

*/


