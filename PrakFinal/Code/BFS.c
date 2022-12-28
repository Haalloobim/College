#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
#define and &&

char ar[32];

int base(ll numb, int idx);
void solve(ll n, ll a);

int main(){
    ll n, a;
    scanf("%lld %lld", &n, &a);
    solve(n, a);
	return 0;
}

void solve(ll n, ll a){
	ll id=0, ans[n];
	while (n--){   
        ll i, b, change;
        for (i=0; i<32; i++){
        	ar[i] = '0';
		}
        scanf("%lld %lld", &change, &b);
        if ((--change) >= 0){
            a = a ^ 1 << change;
        }
        base(a ^ b, 0);
        ll count = 0, t = strlen(ar);
        char temp = '0';
        for ( i = 0; i < t; i++){
            if (ar[i] == '1' and ar[i] != temp){
                count++;
            }
            temp = ar[i];
        }
        a = b;
        ans[id++] = count;
    }
    int i;
    for (i=0; i<id; i++){
    	printf("%lld\n", ans[i]);
	}
}

int base(ll numb, int idx){
	char str; 
	if (numb==0){
		return 0;
	}
	else {
		str = 48 + (numb%2);
	}
	numb /= 2;
	base(numb,idx+1); 
	ar[idx] = str;
}


