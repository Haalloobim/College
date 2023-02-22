#include <stdio.h>
#include <string.h>

typedef struct{
    char nik[20], nama[50], tempat[20]; 
    char tanggal[20], alamat[50], job[50] ;
    int umur, status, agama, citizen, kelamin; 
} data;

void entri(); 
void lihat();
void cari(char NIK[]); 
void del(char NIK[]);
void error(); 

int main(){
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
        printf(" 4. Hapus data ktp.\n");
        printf(" 5. Keluar.\n");
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
            lihat();
        }
		if (opr == 3){
            char NIK[20];
            printf("\n Cari Berdasarkan NIK : ");
            scanf("%s", NIK);
            cari(NIK);
       	}
		if (opr == 4){
            char NIK[20];
            printf("\n Hapus Berdasarkan NIK : ");
            scanf("%s", NIK);
            del(NIK);
        }
       	if (opr == 5){
           error(); 
           break;
       }
    }
	return 0; 
}

void entri(){
    data newKTP;
    FILE *src;
    src = fopen("database.bin", "ab+");
    printf(" Masukan Data: \n");
    printf(" NIK\t\t\t: ");
    scanf("%s", newKTP.nik);
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
    fclose(src);
    printf(" Data Berhasil Disimpan\n");
} 

void lihat(){
	data KTP;
    FILE *src;
    int i = 0; 
    src = fopen("database.bin", "rb");
    printf("\n Data data yang telah tersimpan : \n");
    while (fread(&KTP, sizeof(data), 1, src) == 1){
        printf(" Data #%d \n", ++i); 
        printf(" NIK\t\t\t: %s\n", KTP.nik);
        printf(" Nama\t\t\t: %s\n", KTP.nama);
        printf(" Tempat, Tanggal Lahir\t: %s, %s\n", KTP.tempat, KTP.tanggal);
        printf(" Pekerjaan\t\t: %s\n", KTP.job);
        printf(" Alamat\t\t\t: %s\n", KTP.alamat);
        switch (KTP.agama){
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
        switch (KTP.citizen){
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
        switch (KTP.status){
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
        switch (KTP.kelamin){
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
    fclose(src); 
}


void cari(char NIK[]){
	data KTP;
    FILE *src;
    int cek = 0; 
    src = fopen("database.bin", "rb");
    while (fread(&KTP, sizeof(data), 1, src) == 1){
        if (!strcmp(KTP.nik, NIK)){
            printf(" Data dengan NIK berikut : -> %s\n\n", KTP.nik); 
            printf(" Nama\t\t\t: %s\n", KTP.nama);
            printf(" Tempat, Tanggal Lahir\t: %s, %s\n", KTP.tempat, KTP.tanggal);
            printf(" Pekerjaan\t\t: %s\n", KTP.job);
            printf(" Alamat\t\t\t: %s\n", KTP.alamat);
            switch (KTP.agama){
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
            switch (KTP.citizen){
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
            switch (KTP.status){
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
            switch (KTP.kelamin){
            case 1:
                printf(" Jenis Kelamin\t\t: Laki-Laki");
                break;
            case 2:
                printf(" Jenis Kelamin\t\t: Perempuan");
                break;
            default:
                break;
            }
            printf(" \n");
            cek = 1; 
        }
    }
    if(!cek){
    	printf(" Data tidak ditemukan!!\n");
	}
    fclose(src); 
}

void del(char NIK[]){
    FILE *src, *src_temp; 
    int cek = 0; 
    data KTP; 
    src = fopen("database.bin", "rb"); 
    src_temp = fopen("temp.bin", "wb");
    while (fread(&KTP, sizeof(data), 1, src)){
        if (!strcmp(NIK, KTP.nik)){
            printf("\n Data ditemukan dan dihapus.\n");
            cek = 1;
        }
        else{
            fwrite(&KTP, sizeof(data), 1, src_temp);
        }
    }
    
    if(!cek){
        printf("\n Error : Data NIK #%s tidak Ditemukan!!\n", NIK);
    }
    fclose(src); 
    fclose(src_temp);
    
    remove("database.bin"); 
    rename("temp.bin", "database.bin");
    printf("\n"); 
}

void error(){
	printf("\n\t~~Thank You and Good Bye!~~\n");
}
