#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
#define and &&
#define or ||


int main(){
	ll numb, ans = 0, count = 1, cek = 1; 
	scanf("%lld %lld", &n, &numb);
	ll ar[n];
	ll i; 
	for (i=0; i<n; i++){
		scanf("%lld", &ar[i]);
	} 
	bSort(ar);
	for (i=0; i<n; i++){
		ans += ar[i];
		if (ans <= numb){
			count++;
		}
		else{
			cek = 0;
			printf("%lld", count);
			return 0;
		}
	}
	if (cek){
		printf("%lld", count-1);
	}
	return 0; 
}

