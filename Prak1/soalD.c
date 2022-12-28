#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main() {
//remind: sum awal harus 0 yee
	long long int x, sum, hasil;
		scanf("%lld", &x);
			hasil = (x * (x + 1)) / 2;
			sum= pow(hasil,2);
				printf("%lld", sum);
return 0;
}
