#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int i, j, a, b, temp, count = 0;
char map[101][101]; 

void path(int x, int y);

int main() {
//remind: sum awal harus 0 yee
	scanf("%d %d", &a, &b);
	for ( i = 0; i < a; i++){
        scanf("%s", map[i]);   
    }
    
    for( i = 0; i < b; i++){
		if(map[0][i] == '*'){
			temp=i;
			break;
		}
	}
	path(0, temp);
	
	for( i = 0; i < a; i++){
		printf("%s\n", map[i]);
	} 
	printf("%d", count);
	
return 0;
}

void path(int x, int y){
	if (map[x][y]!='#' && x>=0 && y>=0 && x<a && y<b){
		map[x][y]='*';
		count++;
		if(map[x+1][y] == '_' && x >= 0 && y >= 0 && x < a && y < b){
            path(x+1,y);
        }
		else{
			if (y < b-1 && map[x][y+1] == '_'){
				path(x,y+1);
			}
            if (y > 0 && map[x][y-1] == '_'){
            	path(x,y-1);
			}
        }   
	}
}



/*
3 3
#*#
___
_#_

4 5
##*##
____#
#_###
#####
*/
