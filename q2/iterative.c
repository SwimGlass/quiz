/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#define BUFFERSIZE 1024
char smallest_character(int num, int c)
{
    int tmp = num;
    int checkbit = c - 97;
    if( 1 & (tmp >> checkbit)){ //find character , output next
        /*while((tmp & 1) == 0){ 
            tmp = tmp >> 1;
            checkbit++;
        }
        checkbit++;
        return (checkbit+97);*/
        int cc = 1 << checkbit;
        return (__builtin_ctz((num>>(__builtin_ctz(cc)+1)<<(__builtin_ctz(cc)+1)))+97);
    }
    else{// no find character , output min
        /*while((tmp & 1)==0){
            tmp = tmp >> 1;
            checkbit++;
        }
        return (checkbit+97);*/
        return (__builtin_ctz(num)+97);
    }
}

int main()
{
    FILE *fp = fopen("array.txt","r");
    char buffer[BUFFERSIZE];
    int i = 0,c,num=0;
    if( fp == NULL) err(1,"Error:file open failure\n");
    else{
        while((c = fgetc(fp))!=EOF){
            num |= 1 << ((int)c - 97);
        }
    }
    printf("%d\n",num);
    fclose(fp);
    char temp = 'a';
    printf("Output : %c\n",(char)smallest_character(num,temp));
    return 0;
}


