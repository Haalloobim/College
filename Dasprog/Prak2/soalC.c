#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long long int i,j;

int main() {
//remind: sum awal harus 0 yee
	char str[1000005], sisa[1000005]; 
	int idx=0; 
	long long int rugi=0; 
	
	scanf("%s", str); 

	sisa[0]=str[0]; 
	int t = strlen(str); 
	
	for (i=1; i<t; i++){
		if (sisa[idx]==str[i]){
			rugi += 2000*sisa[idx]; 
			idx--;
		}
		else {
			idx++; 
			sisa[idx]=str[i]; 	
		}
	}
	
	int ans = idx+1;
	
	if(rugi==0){
		printf("Di gudang tersisa %d batu\nWah, Jotaro Joemama tidak jadi dipecat", t); 
	}
	else {
		printf("Di gudang tersisa %d batu\nTotal Kerugian: %lld Dolar Imbu", ans, rugi);
	}
return 0;
}


/* test case 
tccccct

Di gudang tersisa 3 batu
Total Kerugian: 396000 Dolar Imbu

//

onetrypastiACIniBukanCPIniBukanCTF

Di gudang tersisa 34 batu
Wah, Jotaro Joemama tidak jadi dipecat 
*/	


