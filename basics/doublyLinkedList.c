#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* next ;
    struct node* prev ;
};

typedef struct node Node; //pointer to head

Node* head; //global pointer to the linked list

/*function to create a new node*/
Node* createNode (int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x ;
    newNode->next = NULL ;
    newNode->prev = NULL ;
    return newNode;
}

/*function to add a node at the head of the linked list*/
void insertAtHead(int x)
{
    Node* newNode = createNode(x);
    //if the list is empty
    if(head == NULL){
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

/*function to print the elements of the list */
void Print()
{
    Node* temp = head;
    printf("Forward : ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main (int argc , char** argv)
{
    insertAtHead(5);
    insertAtHead(6);
    insertAtHead(9);
    Print(); 
}
