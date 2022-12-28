#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int main(){
	int n;
	scanf("%d", &n);
	while (n--){
		int numb; 
		scanf("%d", &numb);
		if (numb%2==0){
			printf("%d\n", (2*numb)-1);
		}
		else if(numb % 2==1){
			printf("%d\n", (2*numb)+1);
		}
	}
		
	
	return 0;
}

