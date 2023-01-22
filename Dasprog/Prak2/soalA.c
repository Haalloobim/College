#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long long int i,j;

int main() {
//remind: sum awal harus 0 yee
	long int n; 
	char str[100005];
	
	scanf("%d", &n);
	scanf("%s", str); 
	int t = strlen(str); 
	int x = n%t;
	for (i =0; i<x; i++){
		str[t]=str[0];
		for (j =0; j<t; j++){
			str[j]=str[j+1];  
		}
	}
	
	for (j=0; j<t; j++){
			printf("%c", str[j] );
		} 
	
return 0;
}
