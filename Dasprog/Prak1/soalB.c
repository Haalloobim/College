#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>



int main() {
//remind: sum awal harus 0 yee
	unsigned long long int x, a, b, c,  ans;
		scanf("%llu", &x);
	
	a=x;
	b=x+1;
	c=(2*x)+1;	
		
		if (a%2==0){
			a/=2;
		}
		else if (b%2==0){
			b/=2;
		}
		else if (c%2==0){
			c/=2; 
		}
		
		if (a%3==0){
			a/=3; 
		}
		else if (b%3==0){
			b/=3;
		}
		else if (c%3==0){
			c/=3;
		}
		
		ans = a % 1000000007; 
		ans = (ans * (b % 1000000007)) % 1000000007;
		ans = (ans * (c % 1000000007)) % 1000000007; 
		
		printf("%llu", ans);
return 0;
}
