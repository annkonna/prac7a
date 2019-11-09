#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX_SIZE 10000
#define MAX_STRING_SIZE 50
#define MAX_EMP_ID 99999
#define MIN_SALARY 10000
#define MAX_SALARY 100000

void dump_characters(void *databuf) {    
    while (*(char *)databuf != '\0') {
        putchar(*(char*)databuf);
        databuf++;
    }
}

/* Get all rows in 'data' and copy them as comma-separated column values
 * separted by linefeed ('\n) into 'table'. 
 *
 * table should be null terminated.
 *
 * The function returns -1 if the data structure is invalid, 0 otherwise.
 */
int get_emps(char *table, void *data) {
    /* Your implementation should appear here */
    while(*(char *)data != '\0'){
        long id = *(long *)data;
        sprintf(table, "%ld,", id);
        data = data + sizeof(long);
        table = table + strlen(table);
        for(int n = 0; n < 4; n++){
            strcpy(table, data);
            table = table + strlen(table);
            *table++ = ',';
            data = data + MAX_STRING_SIZE;
        }
        long sal = *(long *)data;
        sprintf(table, "%ld", sal);
        data = data + sizeof(long);
        table = table + strlen(table);
        *table++ = '\n';
    }
    return 0;
}

int main(int argc, char *argv[]) {

    void *text = malloc(MAX_SIZE);
    void *emps = malloc(MAX_SIZE);

    int c;
    char *temp = (char *)text;
    while ( (c=getchar()) != EOF ) {
        *temp = (unsigned char)c;
        temp++;
    }
    *temp = '\0';

    int ret = get_emps(emps, text);
    if ( ret == -1 ) {
        printf("\n Failed: invalid data structure.\n");
        return -1;
    }

    dump_characters(emps);
}
