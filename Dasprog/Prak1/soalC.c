#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>



int main() {
//remind: sum awal harus 0 yee
 long long  int a, b, max, min;
// long long jum, min1,min2, kali;
// jum =a+b;
// min1 = a-b; 
// min2 =b-a;
// kali= a*b;  
 
 
	
	scanf("%lld %lld", &a, &b);
	
	if (a>b){
		max=a;
		min=b;
	}
	else {
		max=b;
		min=a;
	}
	
	if ((a+b)%2==0){
		if ((a-b)%2==0 || (b-a)%2==0){
			if (a*b%2==0){
				if (max%min==0){
					printf("We are soulmates\n");
				}
				else {
						printf("We are NOT soulmates\n");
				}
			}
			else {
				printf("We are NOT soulmates\n");
			}
		}
		else{
			printf("We are NOT soulmates\n");
		}
	}         
	else {
		printf("We are NOT soulmates\n");
	}

	
	

return 0;
}



