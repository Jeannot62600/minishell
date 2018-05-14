typedef struct command {
        char commandName[30];
        int indesc;
        int outdesc;
        int errdesc;
        char param[10][30];
        int argn;
        char prefix[30];
        int fork; // 0 = create a fork, _ = no fork
} command;


int structure(char param[10][10][30], char op[10][3], command** commands);
