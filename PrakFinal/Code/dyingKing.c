#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool prima(int x){
    int i, n = sqrt(x);
    if(x==1){
        return false;
    }
    for(i=2;i<=n;i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    int a,b,i,x1,y1,temp,ada;
    char s[100][100], z[100];
    int x[100], y[100];
    scanf("%d %d",&a,&b);
    for(i=0;i<a;i++){
        scanf("%s %dN %dE", s[i], &x[i], &y[i]);
    }
    while(b--){
        ada = 0;
        scanf("%s",&z);
        for(i=0;i<a;i++){
            if(strcmp(z,s[i]) == 0){
                temp = i;
                ada = 1;
                break;
            }
        }
        if(ada){
            x1 = x[temp];
            y1 = y[temp];
            if(prima(x1) && prima(y1)){
                printf("%s aman! Bangunlah Kesatria!\n",s[temp]);
            } 
			else {
                printf("%s tidak aman! Ini pasti ulah Gorgom!\n",s[temp]);  
            }
        } else {
            printf("Tempat apa itu? Kotaro tidak tahu!\n");
        }
        
    }
}

