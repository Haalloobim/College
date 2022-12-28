#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
#define and &&
#define or ||

typedef struct {
	char nama[51];
	ll bomb;
}lokasi;

typedef struct {
	char nama[51];
	lokasi *lihat;
}pembantu;

pembantu data_p[101];
lokasi data_l[101];
    
void solve(int n);

int main(){
    ll n;
    scanf("%lld", &n);
    solve(n);
	return 0;
}

void solve(int n){
	int x = 0, y = 0, i, j;
	while (n--){
    	char choose[10], temp[101];
		scanf("%s %s", choose, temp);
		if(choose[0] == 's'){
			if(temp[0] == '*'){
				scanf("%s %s", data_p[x].nama, temp);
				char data_nama[51];
				scanf("%s", data_nama);
				for( i = 0 ;i < y ;i++){
					if(!strcmp(data_l[i].nama, data_nama)){
						data_p[x].lihat = &data_l[i];
					}
				}
				x++;
			}
			else {
				strcpy(data_l[y].nama, temp);
				scanf("%lld", &data_l[y].bomb);
				y++;
			}
		}
		else if(choose[0] == 'c'){
			if ((temp[0] == '*')){
				char data_nama[51], data_loc[51];
				scanf("%s %s", data_nama, temp);
				if((temp[0] == '&')){
					scanf("%s", data_loc);
					for(i=0 ;i<x ;i++){
						if(!strcmp(data_nama, data_p[i].nama)){
							for(j=0 ;j < y ;j++){
								if(!strcmp(data_loc, data_l[j].nama)){
									data_p[i].lihat = &data_l[j];
									break;
								}
							}
							break;
						}
					}
				}
				else {
					for(i = 0; i < x; i++){
						if(!strcmp(data_nama, data_p[i].nama)){
							(*data_p[i].lihat).bomb = atoi(temp);
							break;
						}
					}
				}
			}
			else{
				for(i = 0; i < y; i++){
					if(!strcmp(temp, data_l[i].nama)){
						scanf("%lld", &data_l[i].bomb);
						break;
					}
				}
			}
		}
		else {
			char dataP[51];
			scanf("%s", dataP);
			for(i = 0; i < x; i++){
				if(!strcmp(data_p[i].nama, dataP)){
					printf("%lld\n", (*data_p[i].lihat).bomb);
				}
			}
		}	
	}
}

	



