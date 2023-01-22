#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long long int i,j;

int main() {
//remind: sum awal harus 0 yee
	int n; 
	int len=0; 
	char str[1005]; 
	int numb;
	scanf("%d", &n); 	
	
	for (i=0; i<n; i++){
		scanf("%d", &numb); 
		str[len] = numb>> 24; 
		int move1 = numb << 8;
		str[len+1] = move1>> 24;
		int move2 = numb << 16;
		str[len+2] = move2 >> 24; 
		int move3 = numb << 24; 
		str[len+3] = move3 >> 24;  
		len+=4;
	}
	
	for(i=0; i<len; i++){
		printf("%c", str[i]);
	}

	

/* test case 
4
1265202273
1400204129
1399803497
1130707497 

KitaSukaSoNiCe:)
//

5
1769239363
1413905234
1702244723
1163543154
808460669 

itsCTF{Rev1sEZBr00!} 

*/	

return 0;
}
