/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <err.h>

int checkbit;
char smallest_character(int num, int c){
    if( (num & c) ==0 ){ 
        checkbit++;
        return(smallest_character((num>>1),1));
    }
    
    if((num & c)==1)return(checkbit+97); 
    
    if((num & c) > 0){
        int a = c;
        int i = 0;
        while((a & 1)==0){ 
            i++;
            a = a >> 1;
        }
        i++;
        return(smallest_character(((num >> i) << i),1));
    }
}
int main()
{
    FILE *fp = fopen("array.txt","r");
    int c,num=0;
    if( fp == NULL) err(1,"Error:file open failure\n");
    else{
        while((c = fgetc(fp))!=EOF){
            num |= 1 << ((int)c - 97);
        }
        checkbit = 0;
    }
    fclose(fp);
    char temp='f';
    printf("Output : %c\n",(char)smallest_character(num,pow(2,(temp-97))));
    return 0;
}
