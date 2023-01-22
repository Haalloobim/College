#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int main(){
	int t; 
	scanf("%d", &t); 
	while (t--){
		int numb; 
		scanf("%d", &numb);
		while(numb>0){
			if (numb % 15 == 0){
				numb -= 15;
			}
			else if(numb % 11 == 0){
				numb -= 11;
			}
			else {
				numb -= 26; 
			}
		}
		if (numb < 0){
			printf("NO\n"); 
		}
		else {
			printf("YES\n");
		}
	}

return 0;

}
