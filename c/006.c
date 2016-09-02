#include <stdio.h>
#include <stdlib.h>

struct node {
    char c;
    struct node *next;
};

struct row {
    struct node *head;
    struct node *tail;
};

char* convert(char* s, int numRows);
void addNode(struct row *r, char c);

int main()
{
    char str[] = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    char *res;

    res = convert(str, 2);
    printf("%s\n", res);

    return 0;
}

char* convert(char* s, int numRows)
{
    struct row *rows[numRows];
    struct node *cur;
    int i, j, incr;
    char *res = malloc(1000);

    if (s[0] == '\0') {
        return s;
    }

    for (i = 0; i < numRows; i++) {
        rows[i] = malloc(sizeof(struct row));
        rows[i]->head = NULL;
        rows[i]->tail = NULL;
    }

    j = 0;
    if (numRows == 1) {
        incr = 0;
    } else {
        incr = 1;
    }
    for (i = 0; s[i] != '\0'; i++) {
        addNode(rows[j], s[i]);
        if (j + incr == numRows || j + incr < 0) {
            incr = -incr;
        }
        j += incr;
    }

    j = 0;
    for (i = 0; i < numRows; i++) {
        if (rows[i]->head != NULL) {
            cur = rows[i]->head;
            res[j++] = cur->c;
            cur = cur->next;
            while (cur != NULL) {
                res[j++] = cur->c;
                cur = cur->next;
            }
        }
    }

    return res;
}

void addNode(struct row *r, char c)
{
    struct node *new = malloc(sizeof(struct node));
    new->c = c;
    new->next = NULL;

    if (r->head == NULL) {
        r->head = new;
        r->tail = new;
    } else {
        r->tail->next = new;
        r->tail = new;
    }
}