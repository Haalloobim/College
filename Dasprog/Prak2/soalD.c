#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

int i,j;

int main(){

	int pri[78500];
	int t=2; 
	int a, b, x;
 	pri[1]= 2;
	clock_t u;
    u = clock();
		for (i=3; i<=1000000; i+=2 ){
			bool prime = true;
////			int sqr = sqrt(i); 
			for (j = 3; j*j <= i ; j+=2){
	            if (i % j == 0){
	                prime = false; 
	                break;
	            }
        	}
			
			if (prime){
//				printf("%d, ", i);
				pri[t]=i;
				t++;
			}
		}
		 u = clock() - u;
    	double time_taken = ((double)u)/CLOCKS_PER_SEC; // in seconds
    	printf("fun() took %f seconds to execute \n", time_taken);
 
		scanf("%d", &x);
		for (j=1; j<=x; j++){
			printf("Test Case #%d :\n", j);
			scanf("%d %d", &a, &b);
			for (i=a; i<=b; i++){
				printf("%d\n", pri[i]);
			}
		}
		
	
	return 0;
	}
	
/*	
testcase

3
1 3
1 5
3 5

1
6 6

*/

