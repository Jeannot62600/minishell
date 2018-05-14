#include "structure.h"
#include <stdio.h>
#include <string.h>

int structure(char param[10][10][30], char op[10][3], command** commands){
        command maCom;
        for(int i = 0; i < 1; i++) {
                strncpy(maCom.commandName, param[i][0],30);
                maCom.indesc = 0;
                maCom.outdesc = 1;
                maCom.errdesc = 2;
                int j = 0;
                while (j<10 && strcmp(param[i][j],"")){
                  strncpy(maCom.param[j], param[i][j], 30);
                  j++;
                }
                maCom.argn = j;
                // maCom.prefix = "";
                strncpy(maCom.prefix, "", 0);
                maCom.fork = 1;
                // commands[i] = maCom;
        }

        printf("%s\n", maCom.commandName );
        printf("%s\n", maCom.param[1]);
        printf("%d\n", maCom.argn);

        return 0;
}
