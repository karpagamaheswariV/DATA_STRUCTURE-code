#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

//INSERTION OPERATION ON SINGULAR LINKED LIST
struct node* createNode(int data){
struct node *nn = (struct node*)malloc(sizeof(struct node));
nn->data = data;
nn->next = NULL;
return nn;
}
void insert_begin(struct node **q,int data){
    struct node *nn,*prev;              //INSERT BEGINNING
    nn = createNode(data);
    if(*q==NULL){
        *q=nn;
    }
    else{
        nn->next = *q;
        *q = nn;
    }
}
void insert_position(struct node **q,int pos,int data){
struct node *nn,*temp=*q;                 //INSERT AT SPECIFIC POSITION
nn=createNode(data);
if(pos==1){
    insert_begin(&q,data);
}
else{
        int flag =1;
while(flag<pos-1){
    temp = temp->next;
    flag++;
}
nn->next = temp->next;
temp->next = nn;
}
}
void append(struct node**q,int data){       //INSERT AT END
    struct node *nn = createNode(data);
    if(*q==NULL){
        *q=nn;
    }
    else{
struct node *temp = *q;
while(temp->next!=NULL){
    temp = temp->next;
}
temp->next = nn;
}
}
//DISPLAY FUNCTION

void display(struct node *head)
{
   struct node *temp = head;
   while(temp!=NULL){
   printf("%d->",temp->data);
   temp = temp->next;
}
printf("NULL");
}
//DELETE OPERATION ON SINGLY LINKED LIST
void delete_begin(struct node**q){     //BEGINNING
struct node *temp = *q;
 (*q) = (*q)->next;
free(temp);
}

void delete_position(struct node **q,int pos){
struct node *temp = *q,*prev=*q;       //SPECIFIC POSITION
printf("Enter the position:");
scanf("%d",&pos);
for(int i=0;i<pos;i++){
    if(i==0 && pos ==1){
        *q = (*q)->next;
        free(temp);
    }else{
    if(i==pos-1 && temp){
        prev->next = temp->next;
        free(temp);
    }else{
    prev = temp;

    if(prev == NULL)//position was greater then number of nodes in the list
       break;
       temp = temp->next;
          }
        }
     }

    }
    void delete_end(struct node **q){  //AT THE END
    struct node*temp = *q,*prev;
       while(temp->next!= NULL){
        prev = temp;
        temp = temp->next;
       }
       prev->next = NULL;
       free(temp);
    }


    int main(){                // MAIN FUNCTION

struct node *head = NULL;
int data;
for(int i=0;i<5;i++){
    printf("Enter the node to be insert at beginning:\n");
    scanf("%d",&data);
    insert_begin(&head,data);
}
display(head);
printf("\n");

createNode(data);
display(head);
printf("\n");
int pos;
printf("Enter the position and element:");
scanf("%d%d",&pos,&data);
insert_position(&head,pos,data);
display(head);
printf("\n");

printf("enter the data:");
scanf("%d",&data);
printf("After Appending:\n");
append(&head,data);
display(head);
printf("\n");
printf("After deleting first element:\n");
delete_begin(&head);
display(head);
printf("\n");
printf("After deleting at specific location:\n");
delete_position(&head,pos);
display(head);
printf("\n");
printf("After deleting at end\n:");
delete_end(&head);
display(head);
return 0;
}
