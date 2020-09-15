#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{ 
  int data; 
  struct Node *next; 
}; 

void insert_front(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  
void insertAfter(struct Node* prev_node, int new_data) 
{ 
    if (prev_node == NULL) 
    { 
      printf("the given previous node cannot be NULL"); 
      return; 
    } 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
} 

void insert_end(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *head_ref; 
    new_node->data  = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return; 
} 

void display(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf(" %d ", node->data); 
     node = node->next; 
  } 
} 
 
void main() 
{ 
  struct Node* head = NULL;  int ch,data1,data2,data3 ;
  printf("\n ENTER YOUR CHOICE: \n 1. Insert at front \n 2. Insert at specific position \n 3.Insert at end \n 4.display \n 5.Exit \n");
  scanf("%d",&ch);
  switch(ch){
      case 1 : printf("\n Enter element to be insert at front :");
              scanf("%d",&data1);
              insert_front(&head, data1);
              break;
               
      case 2 : printf("\n Enter element to be insert at specific position :");
              scanf("%d",&data2);
              insertAfter(head->next, data2);
              break;
               
      case 3 : printf("\n Enter element to be insert at end :");
              scanf("%d",&data3);
              insert_end(&head, data3);
              break;
               
     case 4 : printf("\n linked list:");
              break;
              
     default : printf("Enter valid choice:");
            }
   } 
