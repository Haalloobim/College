#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long
#define and &&
#define or ||

void solve_pake_binser_mod_ni_bos(ll lx, ll ly, ll rx, ll ry);

int main(){
    ll n;
    scanf("%lld", &n);
    ll lx = 1, ly = 1, rx = n, ry = n;
	solve_pake_binser_mod_ni_bos(lx, ly, rx, ry);
	return 0;
}

void solve_pake_binser_mod_ni_bos(ll lx, ll ly, ll rx, ll ry){
    if (lx < rx and ly < ry) {
        ll midx =  ( lx + rx ) / 2,  midy =  ( ly + ry ) / 2 ;
        printf("LIHAT %d %d\n", midx, midy);	
        fflush(stdout);
        ll pointer;
        scanf("%lld", &pointer);
        if (pointer == 1){
        	return solve_pake_binser_mod_ni_bos(lx, midy, midx, ry);
		}
		if(pointer == 2){
			return solve_pake_binser_mod_ni_bos(lx, midy, rx, ry);
		}
		if(pointer == 3){
			return solve_pake_binser_mod_ni_bos(midx, midy, rx, ry);
		}
		if(pointer == 4){
			return solve_pake_binser_mod_ni_bos(lx, ly, midx, ry);
		}
		if (pointer == 5){
        	printf("KOORDINAT %d %d", midx, midy);
            fflush(stdout);
            return 0;
		}
		if(pointer == 6){
			return solve_pake_binser_mod_ni_bos(midx, ly, rx, ry);
		}
		if(pointer == 7){
			return solve_pake_binser_mod_ni_bos(lx, ly, midx, midy);
		}
		if(pointer == 8){
			return solve_pake_binser_mod_ni_bos(lx, ly, rx, midy);
		}
		if(pointer == 9){
			return solve_pake_binser_mod_ni_bos(midx, ly, rx, midy);
		}
	}
}


/* 
1 (Barat Laut)
2 (Utara)
3 (Timur Laut)
4 (Barat)
5 (here)
6 (Timur)
7 (Barat Daya)
8 (Selatan)
9 (Tenggara)
*/


