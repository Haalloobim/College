#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long

ll count = 0;

void palCount(int t, char str[]);

int main(){
    char str[100001];
    scanf("%s", str);
    int t = strlen(str);
    palCount(t, str);
    return 0;
}

void palCount(int t, char str[]){
	int i;
	for (i = 0; i < t; i++){
        int j = i - 1;
        int k = i;
        while (k < t - 1 && str[k] == str[k + 1]){
            k++;
        }

        count += (k - j) * (k - j + 1) / 2;
        i = k++;
        while (j >= 0 && k < t && str[k++] == str[j--]){
            count++;
        }
    }
    printf("%lld", count);
}
//baabbab
