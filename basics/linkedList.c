#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* link ;
};

typedef struct node Node;
Node*  head;

void Insert(int data , int position)
{
    Node* temp1 = (Node*)malloc(sizeof(Node*));
    temp1->data = data;
    temp1->link = NULL;

    if(position == 1){
        temp1->link = head;
        head = temp1;
        return;
    }
    Node* temp2 = head ;
    for(int i = 0;i < position-2;i++){
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;

}

void Delete(int position)
{
    Node* temp1 = head;
    if(position == 1){
        head = temp1->link ;
        free(temp1);
        return;
    }
    for(int i = 0;i < position-2;i++){
        temp1 = temp1->link;
    }//temp1 points to (n-1)th node
    Node* temp2 = temp1->link; // nth node
    temp1->link = temp2->link; // (n+1)th node

    free(temp2);
} 
void Reverse(void)
{
    Node* prev , *current , *next;
    current = head;
    prev = NULL;
     while(current != NULL){
         next = current->link;
         current->link = prev;
         prev = current; 
         current = next;
     }
     head = prev;
    
}
void ReversePrint(Node* temp)
{
    if (temp == NULL)
        return;
    ReversePrint(temp->link);
    printf("%d ",temp->data);
}

void Print(void)
{
    Node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    } 
    printf("\n");
}

int main (int argc , char ** argv)
{
    head = NULL;
    Insert(5,1);
    Insert(4,2);
    Print();
    Insert(3,2);
    Print();
    Reverse();
    Print();
    ReversePrint(head);
    //Delete(1);
    //Print();
}