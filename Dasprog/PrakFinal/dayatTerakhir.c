#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(){
    int n,i,j,temp,x[1000],ans;
    scanf("%d",&n);
    while(n){
        ans = 0;
        for(i=0;i<n;i++){
            scanf("%d",&x[i]);
        }
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(x[j] > x[j+1]){
                    temp = x[j];
                    x[j] = x[j+1];
                    x[j+1] = temp;
                    ans++;
                }
            }
        }
        printf("Minimal lakukan %d pertukaran\n",ans);
        for(i=0;i<n;i++){
            if(x[i]%2==0 || x[i]%5==0){
                if(x[i]%2 == 0){
                    printf("Yeay ");
                }
                if(x[i]%5 == 0){
                    printf("Lulus ");
                }
                if(x[i]%10 == 0){
                    printf("Dasprog ");
                }
            } else {
                printf("%d",x[i]);
            }
            printf("\n");
        }
        scanf("%d",&n);
    }
}
