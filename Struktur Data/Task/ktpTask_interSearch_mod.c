#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jumlahData = 0 ;
char nikBesar[17] = {"1100000000000000"}; //kode nik aceh
char nikKecil[17] = {"9300000000000000"}; //kode nik papua

typedef struct{
    char nik[20], nama[50], tempat[20]; 
    char tanggal[20], alamat[50], job[50] ;
    int umur, status, agama, citizen, kelamin; 
} data;

void printData(data *KTP);
int cmpstr(const void *a, const void *b);
void cekNIK();
int baca(char nik[]);
void cari(char nik[]);
void entri(); 
void lihatSemua();
void error(); 
void menu();


int main(){
	FILE *src = fopen("database.bin", "ab+"); 
	fseek(src, 0, SEEK_END);
    jumlahData = ftell(src) / sizeof(data);
    fseek(src, 0, SEEK_SET);
    fclose(src);
    
    if (jumlahData > 0){
        cekNIK();
    }
    
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\tWelcome to Our KTP Services\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	while (1){
	    int opr;
	    printf("\n\t~~MENU UTAMA~~\n");
        printf("\n Pilih Menu yang tersedia:\n");
        printf(" 1. Entri data ktp.\n");
        printf(" 2. Lihat data ktp.\n");
        printf(" 3. Cari data ktp.\n");
        printf(" 4. Keluar.\n");
        printf("\n Pilihan:");
        scanf("%d", &opr);

        while (opr == 1){
            int choose; 
            entri();
            printf("\n Apakah anda ingin memasukkan data lagi?");
            printf("\n 1.) Ya\t\t2.)Tidak\n Pilih : ");
            scanf("%d", &choose); 
            if(choose == 2){
                break; 
            }
        }
        if (opr == 2){
            lihatSemua();
        }
        if(opr == 3){
        	char NIK[20];
            printf("\n Cari Berdasarkan NIK : ");
            scanf("%s", NIK);
            cari(NIK);
		}
       	if (opr == 4){
           	error(); 
           	break;
       }
    }
	return 0; 
}

void printData(data *KTP){
        printf(" NIK\t\t\t: %s\n", KTP->nik);
        printf(" Nama\t\t\t: %s\n", KTP->nama);
        printf(" Tempat, Tanggal Lahir\t: %s, %s\n", KTP->tempat, KTP->tanggal);
        printf(" Pekerjaan\t\t: %s\n", KTP->job);
        printf(" Alamat\t\t\t: %s\n", KTP->alamat);
        switch (KTP->agama){
        case 1:
            printf(" Agama\t\t\t: Islam");
            break;
        case 2:
            printf(" Agama\t\t\t: Kristen");
            break;
        case 3:
            printf(" Agama\t\t\t: Katolik");
            break;
        case 4:
            printf(" Agama\t\t\t: Budha");
            break;
        case 5:
            printf(" Agama\t\t\t: Konghucu");
            break;
        default:
            break;
        }
        printf(" \n"); 
        switch (KTP->citizen){
            case 1:
                printf(" Kewarganegaraan\t: WNI");
                break;
            case 2:
                printf(" Kewarganegaraan\t: WNA");
                break;
            default:
                break;
        }
        printf(" \n"); 
        switch (KTP->status){
        case 1:
            printf(" Status\t\t\t: Kawin");
            break;
        case 2:
            printf(" Status\t\t\t: Belum Kawin");
            break;
        case 3:
            printf(" Status\t\t\t: Cerai Hidup");
            break;
        case 4:
            printf(" Status\t\t\t: Cerai Mati");
            break;
        default:
            break;
        }
        printf(" \n");
        switch (KTP->kelamin){
        case 1:
            printf(" Jenis Kelamin\t\t: Laki-Laki");
            break;
        case 2:
            printf(" Jenis Kelamin\t\t: Perempuan");
            break;
        default:
            break;
        }
        printf(" \n\n");
}

int cmpstr(const void *a, const void *b){
    const data *aa = a;
    const data *bb = b;
    return strcmp(aa->nik, bb->nik);
}

void cekNIK(){
    char temp_nik[17];
    FILE *src = fopen("database.bin", "rb");
    fseek(src, (jumlahData - 1) * sizeof(data), SEEK_SET);
    fread(temp_nik, 17, 1, src);
    strcpy(nikBesar, temp_nik);
    fseek(src, 0, SEEK_SET);
    fread(temp_nik, 17, 1, src);
    strcpy(nikKecil, temp_nik);
    fclose(src);
}

int baca(char nik[]){
	char temp[17];
    int high = jumlahData - 1, low = 0, get = 0;
    unsigned long long pos = 0;
    data ktp;
    FILE *src = fopen("database.bin", "rb");
    while (!get && low <= high){
        if (jumlahData > 1){
            pos = (atoll(nik) - atoll(nikKecil)) / ((atoll(nikBesar)) - atoll(nikKecil));
            pos = pos * (high - low) + low;
        }
        fseek(src, pos * sizeof(data), SEEK_SET);
        fread(temp, sizeof(temp), 1, src);
        if (atoll(temp) < atoll(nikKecil)){
            break;
        }
        if (atoll(temp) > atoll(nikBesar)){
            break;
        }
        if (!strcmp(temp, nik)){
        	get = 1; 
            return pos;
        }
        else if (atoll(temp) < atoll(nik)){
            low = pos + 1; ///
        }
        else if (atoll(temp) > atoll(nik)){
            high = pos - 1; ///
        }
    }
    fclose(src);
    if (!get){
        puts("Data tidak ditemukan");
        return -1;
    }
}

void cari(char nik[]){
    data ktp;
    FILE *src = fopen("database.bin", "rb");
    int pos = baca(nik);
    if (pos >= 0){
        fseek(src, pos * sizeof(data), SEEK_SET);
        fread(&ktp, sizeof(data), 1, src);
        printData(&ktp);
    }
    fclose(src);
}

void entri(){
    data newKTP;
    FILE *src= fopen("database.bin", "ab");
    printf("\n Masukan Data: \n");
    printf(" NIK (16 Digit)\t\t: ");
    scanf("%s", newKTP.nik);
    if (strlen(newKTP.nik) != 16){
        printf("Harus 16 Digit\n");
        return;
    }
    jumlahData++;
    printf(" Nama\t\t\t: ");
    scanf("\n%[^\n]%*c", newKTP.nama);
    printf(" Tempat lahir\t\t: ");
    scanf("\n%[^\n]%*c", newKTP.tempat);
    printf(" Tanggal Lahir *(d/m/y)\t: ");
    scanf("\n%[^\n]%*c", newKTP.tanggal);
    printf(" Pekerjaan\t\t: ");
    scanf("\n%[^\n]%*c", newKTP.job);
    printf(" Alamat\t\t\t: ");
    scanf("\n%[^\n]%*c", newKTP.alamat);
    printf("\n Agama :\n 1.) Islam\n 2.) Kristen\n 3.) Katolik\n 4.) Hindu\n 5.) Budha\n 6.) Konghucu\n Pilih : ");
    scanf("%d", &newKTP.agama);
    printf("\n Kewarganegaraan :\n 1.) WNI\n 2.) WNA\n Pilih : ");
    scanf("%d", &newKTP.citizen);
    printf("\n Status :\n 1.) Kawin\n 2.) Belum Kawin\n 3.) Cerai Hidup\n 4.) Cerai Mati\n Pilih : ");
    scanf("%d", &newKTP.status);
    printf("\n Jenis Kelamin :\n 1.) Laki-laki\n 2.) Perempuan\n Pilih :");
    scanf("%d", &newKTP.kelamin);
    fwrite(&newKTP, sizeof(data), 1, src);

    if (strcmp(nikBesar,newKTP.nik) > 0){
        freopen("database.bin", "rb", src);
        data *temp = (data *)malloc(sizeof(data) * jumlahData);
        fread(temp, sizeof(data) * jumlahData, 1, src);
        qsort(temp, jumlahData, sizeof(data), cmpstr);
        freopen("database.bin", "wb", src);
        fwrite(temp, sizeof(data) * jumlahData, 1, src);
        free(temp);
    }

    if (atoll(newKTP.nik) > atoll(nikBesar)){
        strcpy(nikBesar, newKTP.nik);
    }

    if (atoll(newKTP.nik) < atoll(nikKecil)){
        strcpy(nikKecil, newKTP.nik);
    }
    
    fclose(src);
    printf(" Data Berhasil Disimpan\n");
} 

void lihatSemua(){
	data KTP;
    FILE *src = fopen("database.bin", "rb");
    printf("\n Data data yang telah tersimpan : \n");
    while (fread(&KTP, sizeof(data), 1, src) && jumlahData > 0 ){
        printData(&KTP);
    }
    fclose(src); 
}

void error(){
	printf("\n\t~~Thank You and Good Bye!~~\n");
}

