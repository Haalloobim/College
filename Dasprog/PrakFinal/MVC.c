#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int n;
char temp[21],  max[21], str[21];

void Bsort(int a, int b);

int main(){
	int x = 0, i;
    scanf("%s %d", str, &n);
    int t = strlen(str);
    for (i=0; i<n; i++){
    	max[i] = '0';
	}
    for (i = 0; i <= (t - n); i++){
        Bsort(x + i, n + i);
    }
    printf("%s", max);
    return 0;
}

void Bsort(int a, int b){
    int idx = 0, i, j;
    for (i = a; i < b; i++){
        temp[idx] = str[i];
        idx++;
    }
    for (i = 0; i < n - 1; i++){
        for (j = 1 + i; j < n; j++){
            if (temp[j] > temp[i]){
                char word = temp[j];
                temp[j] = temp[i];
                temp[i] = word;
            }
        }
    }
    if (strcmp(temp, max) > 0){
        strcpy(max, temp);
    }
}




//Bsort for bubble
//bubble supremacy

	
