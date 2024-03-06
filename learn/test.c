#include<stdio.h>
int main(int argc,char *argv[])
{
    int c;
    FILE *fpSrc,*fpDest;
    fpSrc = fopen(argv[1],"rb");
    if(fpSrc == NULL){
        printf("Source file open failure.");
        return 0;
    }
    fpDest = fopen(argv[2],"wb");
    if(fpDest == NULL){
        printf("Destination file open failure.");
        return 0;
    }
    while((c=fgetc(fpSrc))!=EOF){
        fputc(c,fpDest);
    }
    fclose(fpSrc);
    fclose(fpDest);
    return 0;
}