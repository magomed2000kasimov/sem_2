#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    int re;
    int im;
} complex;

int menu(void) {
    int k;
    printf("1-print\n"
           "2-add is back\n"
           "3-delete\n"
           "4-zadanie\n"
           "5-next\n"
           "6-prev\n"
           "7-gde ya\n"
           "8-end\n");
    scanf("%d", &k);
    return k;
}


struct item {
    struct item *prev;
    struct item *next;
    complex data;
};

typedef struct {
    struct item *start;
    int size;
} list;

struct List_iterator {
    struct item *value;
};
typedef struct List_iterator list_iterator;

list_iterator list_begin(list *l) {
    list_iterator result = {l->start};
    return result;
}


void list_print(list *l) {
    struct item *temp = l->start;
    while (true) {
        if (temp == l->start->prev) {
            printf("(Re:%d Im:%d) ", temp->data.re, temp->data.im);
            break;
        } else {
            printf("(Re:%d Im:%d) ", temp->data.re, temp->data.im);
            temp = temp->next;
        }
    }
    printf("size:%d\n", l->size);
}

complex cr_complex(int re, int im) {
    complex num = {re, im};
    return num;
}

int list_size(list *l) {
    return l->size;
}

void list_initialize(list *l, complex num) {
    l->start = malloc(sizeof(struct item));
    l->start->next = l->start;
    l->start->prev = l->start;
    l->size = 0;
    l->start->data = num;
}

void list_insert_after(list_iterator it, complex num) {
    struct item *temp = malloc(sizeof(struct item));
    temp->data = num;
    temp->next = it.value->next;
    it.value->next->prev = temp;
    it.value->next = temp;
    temp->prev = it.value;

}

list_iterator iterator_next(list_iterator it) {
    list_iterator result = {it.value->next};
    return result;
}

list_iterator iterator_prev(list_iterator it) {
    list_iterator result = {it.value->prev};
    return result;
}

struct item *delete(list_iterator it, list *lol) {
    if (lol->size == 1) {
        struct item *o = lol->start;
        free(o);
        return NULL;
    }

    if (it.value == lol->start) {
        struct item *kek = lol->start, *m;
        it.value->prev->next = it.value->next;
        it.value->next->prev = it.value->prev;
        m = it.value->next;
        free(kek);
        kek = NULL;
        lol->size--;
        return m;

    } else {
        struct item *p = it.value;
        it.value->prev->next = it.value->next;
        it.value->next->prev = it.value->prev;
        free(p);
        p = NULL;
        lol->size--;
        return lol->start;
    }
}


struct item *zadanie(int a, int b, list *lol) {
    struct item *m = lol->start->next, *p;
    bool flag = true;
    int j = list_size(lol);
    for (int i = 1; i < j; ++i) {
        if (m->data.re <= b && m->data.re >= a) {
            p = m;
            m->prev->next = m->next;
            m->next->prev = m->prev;
            m = m->next;
            free(p);
            lol->size--;
        }
    }
    if (lol->start->data.re <= b && lol->start->data.re >= a) {
        flag=false;
        if (lol->size > 1) {
            lol->start->prev->next = lol->start->next;
            lol->start->next->prev = lol->start->prev;
            return lol->start->next;
        } else {
            printf("spisok stal pustim\n");
            return NULL;
        }
    }
    if (flag)
        return lol->start;
}


int main() {
    list lol;
    bool kek = true;
    int choice;
    int a, b, c = 0, s1, s2;
    list_iterator i;
    list_initialize(&lol, cr_complex(0, 0));
    i = list_begin(&lol);

    while ((choice = menu()) != 8) {
        switch (choice) {
            case 1:
                if (kek)
                    printf("empty!\n");
                else
                    list_print(&lol);
                break;
            case 4:
                printf("vvedite diapazon\n");
                scanf("%d %d", &s1, &s2);
                lol.start = zadanie(s1, s2, &lol);
                i = list_begin(&lol);
                if (lol.start == NULL) {
                    kek = true;
                    list_initialize(&lol, cr_complex(0, 0));
                }

                break;
            case 2:
                if (kek) {
                    printf("vvedite:\n");
                    scanf("%d %d", &a, &b);
                    lol.start->data.re = a;
                    lol.start->data.im = b;
                    lol.size = 1;
                    kek = false;
                    i = list_begin(&lol);
                } else {
                    printf("vvedite zeluy i mnimuy chast:\n");
                    int q1, q2;
                    scanf("%d %d", &q1, &q2);
                    list_insert_after(i, cr_complex(q1, q2));
                    lol.size++;
                    i = list_begin(&lol);
                }
                break;
            case 3:
                lol.start = delete(i, &lol);
                if (lol.start == NULL) {
                    kek = true;
                    list_initialize(&lol, cr_complex(0, 0));
                }
                i = list_begin(&lol);
                c = 0;
                break;
            case 5:
                i = iterator_next(i);
                if (c == list_size(&lol) - 1)
                    c = 0;
                else
                    c++;
                break;
            case 6:
                i = iterator_prev(i);
                if (c == 0)
                    c = list_size(&lol) - 1;
                else
                    c--;
                break;
            case 7:
                printf("vi seychas na: %d\n", c % list_size(&lol));
                break;


        }
    }

    return 0;
}
