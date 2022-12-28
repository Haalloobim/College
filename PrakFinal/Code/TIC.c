#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ll long long

ll cash = 0;

typedef struct{
    char menu[100];
    int price;
    int stock;
    bool cek;
} list;

list data[1000005];

void add(int id, list data[]);
void diskon(int id, list data[], double disc);
void info(int id, list data[]);
void order(int id, int banyak, list data[]);
void hilang(int id, list data[]);
void close();

int main(){
    while (1){
        char choose[10];
        scanf("%s", choose);
        if (!strcmp(choose, "CLOSE")){
        	close();
            break;
        }

        else if (strcmp(choose, "ADD") == 0){
            int id, stock;
            int price;
            char menu[100];
            scanf("%d", &id);
            add(id, data);
        }
        else if (strcmp(choose, "INFO") == 0){
            int id;
            scanf("%d", &id);
            info(id, data);
        }
        else if (strcmp(choose, "ORDER") == 0){
            int id, banyak;
            scanf("%d %d", &id, &banyak);
            order(id, banyak, data);
        }
        else if (strcmp(choose, "REMOVE") == 0){
            int id;
            scanf("%d", &id);
            hilang(id, data);
        }
        else if (strcmp(choose, "DISC") == 0){
            int id;
            double disc;
            scanf("%d %lf", &id, &disc);
            diskon(id, data, disc);
        }
        else{
            printf("Unknown command\n");
        }
    }
    return 0;
}

void add(int id, list data[]){
	int temp_stock, temp_price;
    char temp_menu[100];
    scanf("\n%[^\n]%*c", temp_menu);
    scanf("%d %d", &temp_price, &temp_stock);
    if (data[id].cek){
        printf("Menu is already exist!\n");
    }
    else{
        data[id].cek = true;
        strcpy(data[id].menu, temp_menu);
        data[id].price = temp_price;
        data[id].stock = temp_stock;
    }
    printf("Menu added\n");
}

void diskon(int id, list data[], double disc){
    if (!data[id].cek){
        printf("Menu does not exist\n");
    }
    else{
        printf("Discount added\n");
        data[id].price = data[id].price - ((data[id].price * disc) / 100);
    }
}

void info(int id, list data[]){
    if (data[id].cek){
        printf("#%d %s\nPrice : Rp%d\nStock : %dx\n\n", id, data[id].menu, data[id].price, data[id].stock);
    }
    else if (data[id].cek == false){
        printf("Menu does not exist\n");
    }
}

void order(int id, int banyak, list data[]){
    if (data[id].cek == false){
        printf("Menu does not exist\n");
    }
    else if (banyak == 0){
        printf("So you want to order or what\n");
    }
    else if (data[id].stock - banyak < 0){
        printf("Apologize, the stock is not enough\n");
    }
    else {
        data[id].stock -= banyak;
        printf("Ordered %dx %s for Rp%d\n", banyak, data[id].menu, data[id].price * banyak);
        cash += data[id].price * banyak;
    }
}

void hilang(int id, list data[]){
    if (data[id].cek == false){
        printf("Menu does not exist\n");
    }
    else{
        printf("Menu removed\n");
        data[id].cek = false;
    }
}

void close(){
	printf("Earnings: Rp%lld\n", cash);
    printf("Informatics canteen is closing... thanks for the visit!\n");
}

