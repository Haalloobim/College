#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
#define and &&
#define or ||

int n;
ll ar[505], idx = 0;

ll func(ll numb, ll count);
void solve();
void print();

int main(){
	scanf("%d", &n); 
	solve();
	print();
	return 0;
}

ll func(ll numb, ll count){
	if (numb == 1){
		return count;
	}
	if (numb%2==0){
		return func(numb/2, count+1); 
	}
	if (numb%2==1){
		return func(3*numb+1, count+1);
	}
}

void solve(){
	while (n--){
		int count = 0;
		int numb; 
		scanf("%d", &numb); 
		ll hasil = func(numb, count);
		ar[idx++] = hasil;
	} 
}

void print(){
	ll i;
	for(i=0; i<idx; i++){
		printf("%d\n", ar[i]);
	}
}
