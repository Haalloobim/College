#include <stdio.h>
#include <stdlib.h>

typedef struct{ 
	char username[101];
	char pass[100];
}stat;


int main(){
	//remind: sum awal harus 0 yee
	int status[101], jumlah_aneh=0, temp_id=0, n, q;
	scanf("%d %d", &n, &q);
	int sus[q+1];
	stat data[n+1];
	int i, id; 
	for (i=1; i<=n; i++){
		scanf("%d %s %s", &id, data[i].username, data[i].pass);	
		status[i]=0;
	}
	
	for (i=0; i<q; i++){
		int id1, log;
		scanf("%d %d", &id1, &log);
		if(status[id1] == log){
			sus[jumlah_aneh] = id1;
			jumlah_aneh++;
		}
		else {
			status[id1] = log;
		}
	}
	
	printf("%d\n", jumlah_aneh);
	for(i=0; i<jumlah_aneh; i++){
		temp_id = sus[i];
		printf("%d \n%s \n%s\n", temp_id, data[temp_id].username, data[temp_id].pass);
	}
	
    
    return 0;
}

