#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>



int main(){
	int n, i, j, max=-99;
	char nama_temp[100];
	scanf("%d", &n);
	for(i=0; i<n; i++){ 
		char nama[100];
		scanf("%str", nama);
		int ulang, temp=0 ;
		scanf("%d", &ulang);
		int ar[ulang];
		for (j=0; j<ulang; j++){
			scanf("%d", &ar[j]);
			temp += ar[j];
		}
		if(temp>max){
			max = temp;
			nama_temp[100] = nama[100];
		}
	}
	
	printf("%str", nama_temp);
	return 0;
}

