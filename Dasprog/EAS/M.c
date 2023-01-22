#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
#define and &&
#define or ||

int n;

typedef struct {
	int id; 
	double n1, n2, n3, n4;
	int ntemp;
}list;

list data[105];
ll bSort(list data[]);
void solve();

int main(){
	int i;
	scanf("%d", &n);
	solve(n); 
	return 0; 
}

ll bSort(list data[]){
	ll i, j;
	for(i=1;i<=n-1;i++){
        for(j=i+1;j<=n;j++){		
            if(data[j].ntemp > data[i].ntemp){
                list temp = data[j];
                data[j] = data[i];
                data[i] = temp;
            }
            else if (data[j].ntemp == data[i].ntemp){
            	if(data[j].n4 > data[i].n4){
            		list temp = data[j];
	                data[j] = data[i];
	                data[i] = temp;
				}
				else if (data[j].n4 == data[i].n4){
					if (data[j].n3 > data[i].n3){
						list temp = data[j];
		                		data[j] = data[i];
		               			data[i] = temp;
					}
					else if (data[j].n3 == data[i].n3){
						if (data[j].n2 > data[i].n2){
							list temp = data[j];
			                		data[j] = data[i];
			                		data[i] = temp;
						}
						else if (data[j].n2 == data[i].n2){
							if (data[j].n1 > data[i].n1){
								list temp = data[j];
				                		data[j] = data[i];
				                		data[i] = temp;
							}
							else if(data[j].n1 == data[i].n1){
								if (data[j].id < data[i].id){
									list temp = data[j];
					                		data[j] = data[i];
					                		data[i] = temp;
								}
							}
						}
					}
        		}
			}
		}
	}
}

void solve(){
	int i;
	for (i=1; i<=n; i++){
		scanf("%d %lf %lf %lf %lf", &data[i].id, &data[i].n1, &data[i].n2, &data[i].n3, &data[i].n4);
		data[i].ntemp = ceil((0.2*data[i].n1) + (0.23*data[i].n2) + (0.27*data[i].n3) + (0.3*data[i].n4));
	}
	bSort(data);
	for (i=1; i<=n; i++){
		printf("%d %d\n", data[i].id, data[i].ntemp );
	}
}

