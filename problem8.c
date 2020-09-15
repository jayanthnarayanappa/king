/*
 *  --- Stack using LinkedList ---
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*NODE;


NODE getnode(){
	return (NODE)malloc(sizeof(struct node));
}


NODE insertFront_s(NODE head_1, int item){
    NODE p;
    p = getnode();
    p->data = item;
    p->next = head_1;
    head_1 = p;
    return head_1;
}


NODE deleteFront_s(NODE head_1){
	NODE p;
	p=head_1;
	if(head_1 == NULL)
		printf("Stack is empty");
	else{
		printf("Deleted %d\n", head_1->data);
		p = head_1->next;
		free(head_1);
		return p;
	}
}


void display_s(NODE head_1){
    NODE p;
    if(head_1 == NULL){
        printf("Stack is empty\n");
        return;
    }
    p = head_1;
    printf("STACK >> ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

/*
 *  --- Queue using LinkedList ---
 */

NODE insertFront_q(NODE head_2, int item){
    NODE q;
    q = getnode();
    q->data = item;
    q->next = head_2;
    head_2 = q;
    return head_2;
}


NODE deleteRear_q(NODE head_2){
	NODE q,prev;
	q = head_2;
	if(head_2 == NULL)
		printf("Queue is empty\n");
	else{
        if(q->next == NULL){
            printf("Deleted %d\n", q->data);
            free(q);
            head_2 = NULL;
        }
		while(q->next != NULL){
			prev = q;
			q = q->next;
		}
		printf("Deleted %d\n", q->data);
		free(q);
		prev->next = NULL;
	}
	return head_2;
}


void display_q(NODE head_2){
    NODE q;
    if(head_2 == NULL){
        printf("Queue is empty\n");
        return;
    }
    q = head_2;
    printf("QUEUE >> ");
    while(q != NULL){
        printf("%d ", q->data);
        q = q->next;
    }
}

void main()
{
    NODE head_1 = NULL , head_2=NULL;
    int c, ele,ele_1;
    printf("Enter the proper key to perform specific operation : \n ");
    while(1){
        printf("\n 1.Push Element in STACK \n 2.Pop the Element from STACK \n 3.insert at Front of QUEUE \n 4. delete at rear of QUEUE \n 5.Exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Element:");
                scanf("%d", &ele);
                head_1 = insertFront_s(head_1, ele);
                display_s(head_1);
                break;
            
            case 2:
                head_1 = deleteFront_s(head_1);
                display_s(head_1);
                break;
                
            case 3:
                printf("\n Element:");
                scanf("%d",&ele_1);
                head_2 = insertFront_q(head_2,ele_1);
                display_q(head_2);
                break;
                
            case 4:
                head_2 = deleteRear_q(head_2);
                display_q(head_2);
                break;

            case 5:
                exit(1);		
        }
    }
}
