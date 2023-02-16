#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *src, *trgt;
    int str[1024];
    int tempr;

    src = fopen(argv[1], "rb");
    if (argc != 3 || src == NULL){
        printf("ERROR!! : Invalide numbers of arguments or Can't find the source file.");
        return 0;
    }
    trgt = fopen(argv[2], "wb");
    
    while (1){
        tempr = fread(str, 1, 1024, src);
        fwrite(str, 1, tempr, trgt);
        if (feof(src)){
            printf("        1 file(s) has been copied.\n"); 
            printf("        Copying files was successful ^^"); 
            break;
        }
    }

    fclose(src);
    fclose(trgt);
    return 0;
}


