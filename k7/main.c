#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    double * data;
    size_t size;
    size_t capacity;
} vector_double;

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} vector_int;

void vector_initialize_int(vector_int* v) {
    v->data = 0;
    v->size = v->capacity = 0;
}

void vector_initialize_double(vector_double* v) {
    v->data = 0;
    v->size = v->capacity = 0;
}

/*void vector_destroy(vector_int* v) {
    free(v->data);
    v->data = 0;
    v->size = v->capacity = 0;
}
*/
/*void vector_save(vector_int* v, size_t index, int val) {
    if (index < v->size) {
        v->data[index] = val;
    }
}*/

/*void vector_resize(vector_int* v, size_t new_size) {
    if (new_size == 0) {
        free(v->data);
        v->data = 0;
    } else {
        v->data = realloc(v->data, sizeof(int) * new_size);
    }
    for (size_t i = v->size; i < new_size; ++i) {
        v->data[i] = 0;
    }

    v->size = v->capacity = new_size;
}
*/
/*int vector_get(vector_int* v, size_t index) {
    if (index < v->size) {
        return v->data[index];
    }
}*/

void vector_push_int(vector_int* v, int val) {
    if (v->size == v->capacity) {
        v->capacity = v->capacity == 0 ? 1 : v->capacity * 2;
        v->data = realloc(v->data, sizeof(int) * v->capacity);
    }
    v->data[v->size] = val;
    v->size++;
}

void vector_push_double(vector_double* v, double val) {
    if (v->size == v->capacity) {
        v->capacity = v->capacity == 0 ? 1 : v->capacity * 2;
        v->data = realloc(v->data, sizeof(double) * v->capacity);
    }
    v->data[v->size] = val;
    v->size++;
}

void vector_print_int(vector_int* v) {
    for (int i = 0; i < v->size; ++i) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

void vector_print_double(vector_double* v) {
    for (int i = 0; i < v->size; ++i) {
        printf("%f ", v->data[i]);
    }
    printf("\n");
}

void zadanie(int n, vector_int* rows, vector_int* cols, vector_double* values) {
    int val_index = 0,maga=0;
    double summ = 0, max_summ = 0;
    int max_number = 0, q = 0, max_q = 0;
    for (int i = 0; i < rows->size; ++i) {
        if (rows->data[i] != -1) {

            int row_start = rows->data[i];
            int next_row_start = cols->size;
            for (int k = i + 1; k < rows->size; ++k) {
                if (rows->data[k] != -1) {
                    next_row_start = rows->data[k];
                    break;
                }
            }
            int cur_index = row_start;
            for (int j = 0; j < n; ++j) {
                if (cur_index < next_row_start&&j==cols->data[cur_index]&&maga==cur_index) {
                    summ=summ+values->data[cur_index];
                    cur_index++;q++;maga++;
                }
            }
        }
        if (q>max_q){
            max_q=q;
            max_summ=summ;
            max_number=i;

        }
    summ=0;q=0;
    }

     val_index = 0;
    summ = 0, max_summ = 0;
     max_number = 0, q = 0;maga=0;
    for (int i = 0; i < rows->size; ++i) {
        if (rows->data[i] != -1) {

            int row_start = rows->data[i];
            int next_row_start = cols->size;
            for (int k = i + 1; k < rows->size; ++k) {
                if (rows->data[k] != -1) {
                    next_row_start = rows->data[k];
                    break;
                }
            }
            int cur_index = row_start;
            for (int j = 0; j < n; ++j) {
                if (cur_index < next_row_start&&j==cols->data[cur_index]&&maga==cur_index) {
                    summ=summ+values->data[cur_index];
                    cur_index++;q++;maga++;
                }
            }
        }
        if (q==max_q&&summ!=0){
            printf("%lf\n",summ);
            printf("%d\n",i+1);
        }
    summ=0;
    q=0;
    }
}


void print_natural_form(int n, vector_int* rows, vector_int* cols, vector_double* values) {
    for (int i = 0; i < rows->size; ++i) {
        if (rows->data[i] == -1) {
            for (int j = 0; j < n; ++j) {
                printf("    0     ");
            }
        } else {
            int row_start = rows->data[i];
            int next_row_start = cols->size;
            for (int k = i + 1; k < rows->size; ++k) {
                if (rows->data[k] != -1) {
                    next_row_start = rows->data[k];
                    break;
                }
            }
            int cur_index = row_start;
            for (int j = 0; j < n; ++j) {
                if (cur_index < next_row_start&&j==cols->data[cur_index]){// && cur_index == cols->data[cur_index]) {
                    printf("%f ", values->data[cur_index]);
                    cur_index++;
                } else {
                    printf("     0      ");

                }
            }
        }
        printf("\n");
    }
}


int main() {
    double element;
    vector_int rows, cols;
    vector_double values;
    vector_initialize_int(&rows);
    vector_initialize_int(&cols);
    vector_initialize_double(&values);
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i) {
        bool row_empty = true;
        for (int j = 0; j < n; ++j) {

            scanf("%lf", &element);
            if (element != 0) {
                if (row_empty == true) {
                    row_empty = false;
                    vector_push_int(&rows,cols.size);
                }
                vector_push_int(&cols, j);
                vector_push_double(&values, element);
            }
        }
        if (row_empty) {
            vector_push_int(&rows, -1);
        }
    }
    printf("rows: ");
    vector_print_int(&rows);
    printf("cols: ");
    vector_print_int(&cols);
    printf("values: ");
    vector_print_double(&values);
    print_natural_form(n,&rows,&cols,&values);
    zadanie(n,&rows,&cols,&values);
    return 0;
}