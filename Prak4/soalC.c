#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int id=0;

typedef struct{
	char nama[100];
	int atk; 
}stat;

void swap(stat data[], int id1, int id2);

int main(){
	//remind: sum awal harus 0 yee
	int n;
	scanf("%d", &n);
	stat player[n]; 
	int i;
	for (i=0; i<n; i++){
		scanf("\n%[^\n]%*c",player[i].nama);
        scanf("\n%d", &player[i].atk);
	}

	while(1){
		char opr[10];
        scanf("%s", opr);
        if (!strcmp(opr,"x")){
            break;
        }
		
		if(!strcmp(opr,"p")){
			int i;
			for(i=0; i<n ;i++){
				printf("%s %d\n", player[i].nama, player[i].atk); 
			}
		}
		if(!strcmp(opr,"s")){
			int id1, id2;
			scanf("%d %d", &id1, &id2);
			if (id1 > n-1 || id2 > n-1){
				printf("Index diluar batas\n");
			}
			else if (id1==id2){
				printf("Index tidak boleh sama\n");
			}
			else{
				swap(player, id1, id2);
			}
		}
	}
    
    return 0;
}

void swap(stat data[], int id1, int id2){
	stat temp = data[id2];
    data[id2] = data[id1];
    data[id1] = temp;
}


























































void swap1(stat *data, int x, int y){
    stat temp = *(data + x);
   *(data + x) = *(data + y);
    *(data + y) = temp;
}
