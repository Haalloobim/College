#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
DYNAMIC ARRAY FOR C USER 
*/

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_popBack(DynamicArray *darray);
int  dArray_back(DynamicArray *darray);
int  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, int value);
int  dArray_getAt(DynamicArray *darray, unsigned index);
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(DynamicArray *darray, unsigned index);

void dArray_init(DynamicArray *darray){
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, int value){
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

int dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

int dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void dArray_setAt(DynamicArray *darray, unsigned index, int value){
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            darray->_arr[darray->_size-1] = value;
        else
            darray->_arr[index] = value;
    }
}

int dArray_getAt(DynamicArray *darray, unsigned index){
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

void dArray_insertAt(DynamicArray *darray, unsigned index, int value){
	unsigned it;
    int *oldArray = darray->_arr;
    if (darray->_size + 1 > darray->_capacity || index > darray->_capacity || index > darray->_size){
        darray->_capacity *= 2;
        int *newArr = (int *)malloc(sizeof(int) * darray->_capacity);
        if (index > darray->_capacity || index > darray->_size){
            index = darray->_size;
        }
        for (it = 0; it < darray->_size + 1; it++){
            if (it > index){
                newArr[it] = darray->_arr[it - 1];
            }
            else{
                newArr[it] = darray->_arr[it];
            }
        }
        darray->_arr = newArr;
        free(oldArray);
    }
    else {
        for (it = darray->_size; it > index; it--){
            darray->_arr[it] = darray->_arr[it - 1];
        }
    }
    darray->_arr[index] = value;
    darray->_size++;
}

void dArray_removeAt(DynamicArray *darray, unsigned index){
	if(!dArray_isEmpty(darray) && index < darray->_size && index >= 0){
		unsigned it;
	    for (it = index; it < darray->_size; it++){
	        darray->_arr[it] = darray->_arr[it + 1];
	    }
	    darray->_size--;
	}
}

void dArray_printAr(DynamicArray *darray){
	unsigned it;
    for (it = 0; it < darray->_size; it++) {
        printf("%d ", darray->_arr[it]);
    }
    printf("\n");
}


#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_pushBack dArray_pushBack
#define d_popBack dArray_popBack
#define d_back dArray_back
#define d_front dArray_front
#define d_setAt dArray_setAt
#define d_getAt dArray_getAt
#define d_insert dArray_insertAt
#define d_remove dArray_removeAt
#define d_print dArray_printAr

int main(){
    DynamicArray vector;
    d_init(&vector);

    d_pushBack(&vector, 11);
    d_print(&vector); 
    d_pushBack(&vector, 14);
    d_pushBack(&vector, 10);
    d_print(&vector);
    d_insert(&vector, 4, 19);
    d_print(&vector);
    d_remove(&vector, 4); 
    d_print(&vector);
    d_insert(&vector, 5, 65);
    d_print(&vector);
	d_remove(&vector, 1); 
    d_print(&vector);
	d_remove(&vector, 0); 
    d_print(&vector);
    
    
    return 0;
}











