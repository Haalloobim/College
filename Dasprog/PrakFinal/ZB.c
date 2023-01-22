#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
const ll mod = 1000000007;

ll ans = 0, sum=1; 

ll cek(ll a, ll b){
	int i;
	for( i = 1; i<b; i++){
        if(((a%b) * (i%b))%b == 1){
        	return i;
		}        
	}
}

void count(ll n, ll r){
	int i, j;
	for(i = 0; i<n; i++){
        int temp = n;
        int a = i;
    	while(temp != 0){
            int dum = (a % temp);
            dum  %= mod;
            a = temp;
            temp = dum;
        }
        for (j = 0; j < a; j++){
            sum = ((sum % mod) * (r % mod)) % mod;   
        }
        ans = (ans + sum) % mod;
        sum = 1;
    }
    ans %= mod;
    ans = (ans * cek(n,mod)) % mod;
    printf("%lld\n",ans);
}

int main(){
    ll n,r;
    scanf("%lld %lld",&n,&r);
    count(n, r);
    return 0;
}

