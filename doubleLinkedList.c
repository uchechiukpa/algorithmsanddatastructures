// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode Node;
struct ListNode{
    int val;
    Node* next;
    Node* previous;
};


void addNode(int, Node* current);
void deleteNode(int, Node* current);
Node *getNode(int, Node* current);
void freeList(Node* holder);



int main() {
Node* holder = (Node*)malloc(sizeof(Node));
Node* current = holder;
addNode(2,current);
Node* node = getNode(2, current);
if(node){
    printf("found node %d \n", node->val);
}else{
    printf("couldn't find node \n");
}

deleteNode(2, current);
Node* existingnode = getNode(2, current);
if(existingnode){
    printf("found node %d \n", node->val);
}else{
    printf("couldn't find node \n");
}
freeList(holder);
}

void addNode(int val, Node* current){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->previous = current;
    newNode->next = NULL;
    printf("successfully added node \n");
    current->next = newNode;
    current = newNode;
}

void deleteNode(int val, Node* current){
    while(current){
        if(current->val == val){
           if(current->previous){
               current->previous->next = current->next;
           }
           if(current->next){
               current->next->previous = current->previous;;
           }
           printf("successfully deleted node \n");
           return;
        }
        current = current->next;
    }
    
}

Node* getNode(int val, Node* current){
    while(current){
        if(current->val == val){
            return current;
        }
        current = current->next;
    }
    return NULL;
    
}

void freeList(Node* holder){
    
    Node* current = holder;
    while(current != NULL){
        Node *next = current -> next;
        free(current);
        current = next;
    }
}
