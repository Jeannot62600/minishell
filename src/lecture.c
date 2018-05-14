// char *commands;
// do{
//     printf("Vas-y passe moi ta commande : ");
//     scanf("%s",commands);
//     printf("\n Vous avez rentrez %s \n", commands);
//
// }while(strcmp(commands, "exit"));
// printf("Bye");
// return 0;
#include "lecture.h"
#include <stdio.h>


int lect(char str[255]){
  fgets(str, 255, stdin);
  return 0;
}

int ps(){
  printf("Vas-y passe moi ta commande : ");
  return 0;
}
