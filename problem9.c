#include<malloc.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node node;
node* getnode(int );
node *head=NULL;
void display();
void createlist();
void insert_left();
void delete_specific_node();
int main()
{
    int ch,x;
    printf("Doubly Linked List program \n\n");
    do
    {
        printf("Enter your choice\n");
        printf("1.Create List\n2.Insert at left\n3.Delete a node\n4.Display\n\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:createlist(); break;
            case 2:insert_left(); break;
            case 3:delete_specific_node(); break;
            case 4:display();
                   break;
            default:printf("Invalid choice.Enter again\n"); break;

        }
        printf("Do you want to Continue ? Press 0 to exit\n");
        scanf("%d",&x);
    }while(x!=0);
return 0;
}
//end of main;

node *getnode(int n)
{
    node *nn;
    nn=(node*)malloc(sizeof(node));
    nn->data=n;
    nn->next=NULL;
    nn->prev=NULL;
    return nn;
}

void createlist()
{
    int d,ch;
    node *p,*newn;
    do
    {
        printf("Enter data for new node\n");
        scanf("%d",&d);
        if(head==NULL)
        {
            head=getnode(d);
            p=head;
        }
        else
        {
            newn=getnode(d);
            p->next=newn;
            newn->prev=p;
            p=p->next;
        }
        printf("Do you want to add more nodes? 1-yes,0-no\n");
        scanf("%d",&ch);
    }while(ch);
}  //end of createlist();


void insert_left()
{
    int d,x,f=0;
    node *newn,*t1,*t2;
    printf("New node will be added to the left of which node??\n");
    scanf("%d",&x);
    printf("Enter data for new node\n");
    scanf("%d",&d);
    newn=getnode(d);
    if(head->data==x)
    {

        newn->next=head;
        head->prev=newn;
        head=newn;
        f=1;
    }
    t1=head->next;
    while(t1!=NULL)
    {
        t2=t1;
        if(t1->data==x)
        {
            t2=t1->prev;
            t2->next=newn;
            newn->next=t1;
            t1->prev=newn;
            newn->prev=t2;
            f=1; break;
        }
        else
            f=0;
        t1=t1->next;
    }
    if(!f)
        printf("Given node not Found.Insertion unsuccessful\n\n");

}// end of insert_left();

void delete_specific_node()
{
    node *t1,*t2;
    int x,f=0;
    printf("Enter the node to delete\n");
    scanf("%d",&x);

    if(head->data==x)
    {
          t1=head;
          head=head->next;
          head->prev=NULL;
          free(t1);
          f=1;
    }
    t1=head->next;
    while(t1!=NULL)
          {
              t2=t1;
             if(t1->data==x)
             {
                 t2=t1->prev;
                 t2->next=t1->next;
                 t1->next->prev=t2;
                 free(t1);
                 f=1;
                 break;
             }
             else
                f=0;
                t1=t1->next;
          }
          if(!f)
            printf("given Node not found.Deletion Unsuccessful\n\n");
}
//end of delete_specific_node();

void display()
{
    node *t;
    t=head;
    while(t!=NULL)
    {
        printf("%d->",t->data);
        t=t->next;
    }
printf("\n\n");
}//end of display();
