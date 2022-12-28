#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long int 

int main(){
    ll saldo;
    scanf("%lld", &saldo);
    int t;
    scanf("%d", &t);
    ll point = 0;
    while (t--){
        char choose[50];
        scanf("%s", choose);
        if (strcmp(choose, "Iya") == 0){
            ll n;
            scanf("%lld", &n);
            if (n <= 100000){
                point += 1;
                saldo -= n;
            }
            else if (100000 < n && n <= 500000){
                point += 5;
                saldo -= n;
            }
            else if (500000 < n && n <= 10000000){
                point += 20;
                saldo -= n;
            }
            else if (10000000 < n && n <= 500000000)
            {
                point += 35;
                saldo -= n;
            }
            else
            {
                point += 50;
                saldo -= n;
            }
        }
        else{
            ll n;
            scanf("%lld", &n);
            if (n <= 100000){
                point -= 1;
                saldo -= n;
            }
            else if (100000 < n && n <= 500000){
                point -= 5;
                saldo -= n;
            }
            else if (500000 < n && n <= 10000000){
                point -= 20;
                saldo -= n;
            }
            else if (10000000 < n && n <= 500000000){
                point -= 35;
                saldo -= n;
            }
            else if (n > 500000000){
                point -= 50;
                saldo -= n;
            }
        }
    }

    if (saldo <= 0){
        printf("Ujana tidak berakhir bahagia.\n");
    }
    else if (point > 0){
        printf("Ujana berakhir bahagia.\n");
    }
    else if (point == 0){
        printf("Ujana berakhir b aja.\n");
    }
    else{
        printf("Ujana tidak berakhir bahagia.\n");
    }
    return 0;
}

