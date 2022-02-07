#ifndef __APPEND_STR_H__
#define __APPEND_STR_H__

#include <string.h>
#include <stdlib.h>

void append(char subject[], const char insert[], int pos) {
    //Initalize the string
    char *buffer = (char*)malloc(strlen(subject) + strlen(insert) + 2);


    strncpy(buffer, subject, pos);
    int len = strlen(buffer);

    strcpy(buffer + len, insert);
    len += strlen(insert);

    strcpy(buffer + len, subject + pos);
    strcpy(subject, buffer);

    free(buffer);
}

#endif