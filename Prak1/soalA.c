#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>



int main() {
//remind: sum awal harus 0 yee
	char a, b, c;
//	char temp1, temp2, temp3;
	int x;
	
	scanf("%c %c %c", &a, &b, &c);
	scanf("%d", &x);
	
	a+=x;
	b+=x;
	c+=x;
	
	if ((a>=65 && a<=90) || (a >= 97 && a <= 122)){
		if ((b>=65 && b<=90) || (b>= 97 && b<= 122)){
			if ((c>=65 && c<=90) || (c>= 97 && c <= 122)){
				printf("Putri Ada Di Ruangan %c%c%c Raja!", a,b,c);
			}
			else {
				printf("SALAH KASTIL NIH!");
			}
		}
		else {
			printf("SALAH KASTIL NIH!");
		}
	}
	else {
		printf("SALAH KASTIL NIH!");
	}
	

return 0;
}
