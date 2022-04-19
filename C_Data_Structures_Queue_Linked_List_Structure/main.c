#include <stdio.h>
#include <stdlib.h>
//enqueue sona ekleme
//dequeue bastan silme
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *root=NULL;
node *iter=NULL;
void enqueue(int deger)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=deger;
        root->next=NULL;
    }
    else
    {
        iter=root;
        while(iter->next!=NULL)
        {
            iter=iter->next;
        }
        iter->next=(node*)malloc(sizeof(node));
        iter->next->data=deger;
        iter->next->next=NULL;
    }
}
int dequeue()
{
    node* temp=(node*)malloc(sizeof(node));
    int return_deger;
    if(root==NULL)
    {
        printf("Linked List BOS !!!\n");
        return -1;
    }
    else if(root->next==NULL)
    {
        temp=root;
        root=NULL;
        return_deger=temp->data;
        free(temp);
        return return_deger;
    }
    else
    {
        temp=root;
        root=root->next;
        return_deger=temp->data;
        free(temp);
        return return_deger;
    }
}
void YAZDIR()
{
    iter=root;
    printf("\n-------------------------------------------\n");
    while(iter!=NULL)
    {
        printf("%d->",iter->data);
        iter=iter->next;
    }
    printf("\n-------------------------------------------\n");
}
int main()
{
    for(int k=0; k<10; k++)
    {
        enqueue((k+1)*10);
    }
    YAZDIR();
    for(int k=0;k<11;k++)
    {
    printf("SILINDI = %d",dequeue());
    YAZDIR();
    }
        for(int k=0; k<5; k++)
    {
        enqueue((k+1)*20);
    }
    YAZDIR();
    for(int k=0;k<8;k++)
    {
    printf("SILINDI = %d",dequeue());
    YAZDIR();
    }
    return 0;
}
