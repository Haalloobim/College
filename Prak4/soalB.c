#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int id=0;

typedef struct{
	char nama[100]; 
	long long int umur;
	long long int iq;
}biodata;

void tambah(biodata data[], char str1[]);

int main(){
	biodata data[100];
	int iq_tot=0;
	while (1){
	
		int opr;
		scanf("%d", &opr);
		if(opr==1){
			scanf("%s %lld %lld", data[id].nama, &data[id].umur, &data[id].iq);
			id++;
		}
		if (opr==2){
			char nambah[50];
			scanf("%s", nambah);
			tambah(data, nambah);
		}
		if (opr==-1 ){
			int i;
			for (i=0; i<id; i++){
				iq_tot += data[i].iq;
			}
			if(iq_tot>=404){
				printf("===SIRKEL SOLID===\n");
				for(i=0; i<id; i++){
					printf("%s %lld %lld\n", data[i].nama, data[i].umur, data[i].iq);
				}
			}
			else{
				printf("404 NOT FOUND");
			}
			break;
		}
	} 
    return 0;
}

void tambah(biodata data[], char str1[]){
	int i;
	for (i=0; i<id; i++){
		if (!strcmp(data[i].nama, str1)){
			data[i].iq+=5; 
		}
	}
}
