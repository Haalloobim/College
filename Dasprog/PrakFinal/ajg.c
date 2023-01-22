#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool cek[100001];

bool prima(int x){
    int i, status = 1;
    if(x<=1){
    	status = 0;
        cek[x] = false;
    }
	if (x % 2 == 0 || x % 3 == 0){
		status = 0;
		cek[x] = false;
	}
        
    for ( i = 5; i * i <= x; i = i + 6){
    	if (x % i == 0 || x % (i + 2) == 0){
    		status = 0; 
    		cek[x] =  false;
    		break;
		}
	}
    if(status || x<=3){
    	cek[x] = true;
	}
}

int main(){
	memset(cek, false, sizeof(cek));
    int t,n,x, total=0;
    int i;
    for (i=2; i<= 100000; i++){
    	prima(i);
	}
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        total = 0;
        while(n--){
            scanf("%d",&x);
            if(cek[x]){
                total = 1;
                printf("%d ",x);
            }
        }
        if(total==0){
            printf("Unable to send Fever Slot Buckle.\n");
        }
        else {
        	printf("\n");
		}
        
	
    }
}
