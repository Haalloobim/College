#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
#define INT_MIN -2147483647

int maxCount(int ar[], ll n){
	ll i, temp_max = INT_MIN, end_max = 0;
	for (i = 0; i < n; i++) {
		end_max = end_max + ar[i];
		printf("%d ", end_max);
		if (temp_max < end_max){
			temp_max = end_max;
		}			
		if (end_max < 0){
			end_max = 0;
		}	
	}
	return temp_max;
}

void solve(int n){
	int i,j;
	char str[n][55];
	ll temp[n];
	for(i=0; i<n; i++){
		ll m;
		scanf("%s %lld", str[i], &m);
		int ar[m];
		for(j=0; j<m; j++) {
			scanf("%d", &ar[j]);
		}
		ll temp1 = maxCount(ar, m);
		temp[i] = temp1;
	}
	ll ans = 0, id = 0;
	for(i=0; i<n; i++){
		printf("%d\n", temp[i]);
		if(ans < temp[i]){
			ans = temp[i];
			id = i;
		}
	}
	printf("%s\n", str[id]);
}

int main(){
	int n; 
	scanf("%d", &n);
	solve(n);
	return 0;
}

