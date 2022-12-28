#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int i,j;

int base(long long int numb, int b){
	char str; 
	if (numb==0){
		return 0;
	}
	if ((numb % b) > 9){
		str = 65 + (numb%b)-10;
	}
	else {
		str = 48 + (numb%b);
	}
	numb/=b;
	base(numb,b); 
	printf("%c", str);
}

int main() {
//remind: sum awal harus 0 yee
	int n;
    scanf("%d", &n);
	long long numb[n];
	int b[n];
    if (n==0){
    	printf("0"); 
    	return 0;
	}
	else {
		for(i = 0; i < n; i++){
	    scanf("%lld %d", &numb[i], &b[i]);
	}
	
	for (i=0; i<n ; i++){
		if(numb[i] == 0){
	            printf("0");
	        } else {
	            base(numb[i],b[i]);
	        }
	        printf("\n");
    	}
	}
    	
    printf("Ril no fek, ini bwatan Huan");
    return 0;
}


/*
tescase
5
3 2
4 3
5 4
6 5
7 6

5
1 2
2 2
4 2
8 2
15 16
*/




