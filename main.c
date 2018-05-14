#include <stdio.h>
#include <string.h>
#include "src/matrix.h"
#include "src/structure.h"
#include "src/lecture.h"


int main() {
        char str[255];
        // char *str = "cat -n fichier.txt < zerg rush.txt <2 singe de barbarie";
        char op[10][3]= {{""},{""}};
        char param[10][10][30]= {{""},{""},{""}};
        command** commands;
        ps();
        lect(str);
        while(strcmp(str,"EXIT\n")){
          if(matrix(str,param,op) != 0){fprintf(stderr, "error matrix\n");}
          if(structure(param, op, commands) != 0){fprintf(stderr, "error structure\n");};
          ps();
          lect(str);
        }

}
