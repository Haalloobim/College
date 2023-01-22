#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count = 0;
long long  i, j;

int func(int x){
    if(x != 1 ){
        if(x % 2 == 0){
            count++;
            return func(x/2);
        } 
		else if(x % 3 == 0){
            count++;
            return func(x/3);
        } 
		else if(x-1 != 1){
            count++;
            return func(x-1);
        }  
    }
	return count;
}

int main(){
	int x, hasil;
    scanf("%d", &x);
    hasil=func(x);
    if (x%10==0){
    	printf("%d", hasil-1);	
	}
	else {
		printf("%d", hasil);
	}
    
    
    return 0;
}
