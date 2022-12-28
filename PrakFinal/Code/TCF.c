#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
bool cek[51][51];

int t;

typedef struct{
    char kota[51];
    char nama[51];
    int umur;
    char hp[21];
    int teman1;
    int teman2;
} stat;

typedef struct{
    stat orang[11];
    int jumlah_warga;
} source;

typedef struct{
    source asal[11];
    char kota[51];
} asal;

int main(){
    memset(cek, false, sizeof(cek));
    char kota[51][51];
    scanf("%d", &t);
    asal data;
	int  i, j, k, l, m;
    for (i = 0; i < t; i++){
        scanf("%s", kota[i]);
        int n;
        scanf("%d", &n);
        data.asal[i].jumlah_warga = n;
        for (j = 0; j < n; j++){
            strcpy(data.asal[i].orang[j].kota, kota[i]);
            scanf("%s %d %s", data.asal[i].orang[j].nama, &data.asal[i].orang[j].umur, data.asal[i].orang[j].hp);
        }
    }

    int find;
    scanf("%d", &find);
    for (i = 0; i < find; i++){
        char a[51], b[51];
        scanf("%s %s", a, b);
        for ( j = 0; j < t; j++){
            for ( k = 0; k < data.asal[j].jumlah_warga; k++){
                if (!strcmp(a, data.asal[j].orang[k].nama)){
                    int p = 1;
                    for (l = 0; l < t && p == 1; l++){
                        for ( m = 0; m < data.asal[l].jumlah_warga && p == 1; m++){   
                            if (!strcmp(b, data.asal[l].orang[m].nama)){
                                data.asal[j].orang[k].teman1 = l;
                                data.asal[j].orang[k].teman2 = m;
                                cek[j][k] = true;
                                break;
                                p = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < t; i++){
        printf("%s\n", kota[i]);
        for (j = 0; j < data.asal[i].jumlah_warga; j++){
            printf("name: %s\n", data.asal[i].orang[j].nama);
            printf("Age: %d\n", data.asal[i].orang[j].umur);
            printf("Phone Number:%s\n", data.asal[i].orang[j].hp);
            if (cek[i][j]){
                printf("His/Her bestie is: %s\nHis/Her contact info is as follows\n", data.asal[data.asal[i].orang[j].teman1].orang[data.asal[i].orang[j].teman2].nama);
                printf("name: %s\n", data.asal[data.asal[i].orang[j].teman1].orang[data.asal[i].orang[j].teman2].nama);
                printf("Age: %d\n",  data.asal[data.asal[i].orang[j].teman1].orang[data.asal[i].orang[j].teman2].umur);                
				printf("Phone Number:%s\n", data.asal[data.asal[i].orang[j].teman1].orang[data.asal[i].orang[j].teman2].hp);
            }
            else{
                printf("His/Her bestie is: No one\n");
            }
            printf("\n");
        }
    }
}
