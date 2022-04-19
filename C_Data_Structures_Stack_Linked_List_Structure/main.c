#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};
typedef struct node node;
node* pop(node*root)
{
    node* iter;
    node*temp;
    int degerdondur;
    if(root==NULL)
    {
        printf("Linked BOS !!!\n");
        return root;
    }
    else
    {
        iter=root;
        if(root->next==NULL)
        {
            degerdondur=root->data;
            root=NULL;
            printf("poped = %d \n",degerdondur);
            return root;
        }
        else
        {
            while(iter->next->next!=NULL)
            {
                iter=iter->next;
            }
            degerdondur=iter->next->data;
            temp=iter->next;
            iter->next=NULL;
            free(temp);
            printf("poped = %d \n",degerdondur);
            return root;
        }
    }
}
node * push(node*root,int deger)
{
    node *iter;
    node *temp=(node*)malloc(sizeof(node));;
    if(root==NULL)// ilk deger yoksa.
    {
        root=(node*)malloc(sizeof(node));
        root->data=deger;
        root->next=NULL;
        return root;
    }
    else // ilk deger varsa.
    {
        iter=root;
        while(iter->next!=NULL)
        {
            iter=iter->next;
        }
        temp->data=deger;
        temp->next=NULL;
        iter->next=temp;
        return root;
    }
}
void yazdir(node*root)
{
    node *iter;
    iter=root;
    printf("------------------------------------------\n");
    printf("LINKED'in YAPISI = ");
    while(iter!=NULL)
    {
        printf("%d ->",iter->data);
        iter=iter->next;
    }
    printf("\n------------------------------------------\n");

}
int main()
{
    node *root;
    root=NULL;
    root=push(root,5);
    root=push(root,10);
    root=push(root,15);
    root=push(root,20);
    yazdir(root);
    root=pop(root);
    yazdir(root);
    root=pop(root);
    yazdir(root);
    root=pop(root);
    yazdir(root);
    root=pop(root);
    yazdir(root);
    root=push(root,20);
    yazdir(root);
    return 0;
}
