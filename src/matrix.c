/*

   str= chaine a decouper
   param=les commandes et leur parametres
   op=les operateurs de separation (&&,|,||,<1,<2,<,<<,<<<,>,>>,>>>,1>,2>)

 */
#include "matrix.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int verif(char* str, int i){
        if(isalpha(str[i])||str[i]=='.') {return 1; }
        else if(str[i]=='-') {return 2; }
        else if(str[i]==' ') {return 3; }
        else if(str[i]=='1' ||str[i]=='2') {return 4; }
        else if(str[i]=='<') {return 5; }
        else if(str[i]=='>') {return 6; }
        else if(str[i]=='|') {return 7; }
        else if(str[i]=='&') {return 8; }
        else{ return -1; }
}
// 10 commande max avec 10 parametre max pour chaque commande, chaque mot contient 30 lettre max possibilité d'augmenter
// danger trop grand nombre crée segment fault et trop petit entraine l'overflow
//10 operateur 3 caractere max
int matrix(char* str, char param[10][10][30], char op[10][3]){
        int i=0, z=0, y=0, s=0, cmp=0, one_op=0;
        if(!isalpha(str[0])) {
                return 1;
        }


        while(i<strlen(str)) {
                cmp=verif(str,i);
                switch (cmp) {

                case 1:
                        one_op=0;
                        // printf("%c", str[i]);
                        z=0;
                        param[s][y][z]=str[i];
                        i++; z++;
                        while(isalpha(str[i])||str[i]=='.') {
                                param[s][y][z]=str[i];
                                // printf("%c", str[i]);
                                z++;
                                i++;
                        }
                        y++;
                        // printf("  fin cas 1  \n");
                        break;

                case 2:
                        one_op=0;
                        z=0;
                        param[s][y][z]=str[i];
                        i++;
                        z++;
                        if(!isalpha(str[i])) {return -1; }
                        while(isalpha(str[i])) {
                                param[s][y][z]=str[i];
                                z++;
                                i++;
                        }
                        y++;
                        break;

                case 3:
                        i++;
                        break;

                case 4:
                        if(one_op==1) {return -1; }
                        op[s][0]=str[i];
                        i++;
                        if(!str[i]=='>') {
                                return -1;
                        }
                        op[s][1]=str[i];
                        i++;
                        y=0;
                        s++;
                        one_op=1;
                        break;

                case 5:
                        if(one_op==1) {return -1; }
                        op[s][0]=str[i];
                        i++;
                        if(str[i]=='1'||str[i]=='2') {
                                op[s][1]=str[i];
                                i++;
                        }
                        else if(str[i]=='<') {
                                op[s][1]=str[i];
                                i++;
                                if(str[i]=='<') {
                                        op[s][2]=str[i];
                                        i++;
                                }
                        }
                        y=0;
                        s++;
                        one_op=1;

                        break;

                case 6:
                        if(one_op==1) {return -1; }
                        op[s][0]=str[i];
                        i++;
                        if(str[i]=='<') {
                                op[s][1]=str[i];
                                i++;
                                if(str[i]=='<') {
                                        op[s][2]=str[i];
                                        i++;
                                }
                        }
                        y=0;
                        s++;
                        one_op=1;
                        break;

                case 7:
                        if(one_op==1) {return -1; }
                        op[s][0]=str[i];
                        i++;
                        if(str[i]=='|') {
                                op[s][1]=str[i];
                                i++;
                        }
                        y=0;
                        s++;
                        one_op=1;

                        break;

                case 8:
                        if(one_op==1) {return -1; }
                        op[s][0]=str[i];
                        i++;
                        if(str[i]=='&') {
                                op[s][1]=str[i];
                                i++;
                        }
                        y=0;
                        s++;
                        one_op=1;

                        break;

                default:
                        return -1;
                }

        }


        return 0;
}

// int main (int argc, char *argv[]){
// char *str = "cat -n fichier.txt < zerg rush.txt <2 singe de barbarie";
//  printf("%s\n", str);
// char op[10][3]= {{""},{""}};
// char param[10][10][30]= {{""},{""},{""}};
// int a = matrix(str,param,op);
// int i=0, y=0, z=0;
//
//  while(i<10){
//  while(y<30){
//  printf("%s \n", param[z][y]);y++;}
//  i++;
//  }
//
//  y=0;
//  while(y<10){
//  printf("%s\n", op[y]);
//  y++;
//  }
//  printf("%d\n", a);
// }
