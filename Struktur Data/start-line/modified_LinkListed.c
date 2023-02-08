#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/*
LINK LISTED FOR C USERS
*/

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);
int  slist_getAt(SinglyList *list, int index);

void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value) {
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        
        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;//bisa diganti sama currNode gak? 
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, int index, int value){
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;    
    }
    else if (index == 0) {
        slist_pushFront(list, value);
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index){
    if (!slist_isEmpty(list)) {
        
        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;    
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }
        
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value){
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list){
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

int slist_size(SinglyList *list){
    return list->_size; 
}

void slist_print(SinglyList *list) {
    SListNode  *currNode = list->_head;
   	while ( currNode != NULL ) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n"); 
}

void slist_multiply2(SinglyList *list) {
    SListNode  *currNode = list->_head;
   	while ( currNode != NULL ) {
        printf("%d ", (currNode->data)*2);
        currNode = currNode->next;
    }
    printf("\n"); 
}

void slist_sumDig(SinglyList *list) {
    SListNode  *currNode = list->_head;
    int ans = 0; 
   	while ( currNode != NULL ) {
        ans += (currNode->data); 
        printf("%d ", ans);
        currNode = currNode->next;
    }
    printf("\n"); 
}

void slist_Reverse(SinglyList *list){                       
    if (slist_size(list) == 0){
        return;
    }
    int temp = slist_front(list);
    slist_popFront(list);
    slist_Reverse(list);
    slist_pushBack(list, temp);
}

#define l_init slist_init
#define l_isEmpty slist_isEmpty
#define l_pushFront slist_pushFront
#define l_popFront slist_popFront
#define l_pushBack slist_pushBack
#define l_popBack slist_popBack
#define l_insertAt slist_insertAt
#define l_removeAt slist_removeAt
#define l_remove slist_remove
#define l_front slist_front
#define l_back slist_back
#define l_getAt slist_getAt
#define l_print slist_print
#define l_multi2 slist_multiply2
#define l_sum slist_sumDig
#define l_size slist_size
#define l_rev slist_Reverse



int main (){
    SinglyList list; 
    l_init(&list);

    int t; 
    scanf("%d", &t);
    while(t--){
        int numb; 
        scanf("%d", &numb); 
        l_pushFront(&list, numb);
    }
    l_print(&list);
    l_rev(&list); 
    l_print(&list); 
    return 0; 
}
