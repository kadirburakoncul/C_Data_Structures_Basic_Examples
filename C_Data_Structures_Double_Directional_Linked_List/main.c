#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct node
{
    int sayi;
    struct node * next;
    struct node * geri;
};
typedef struct node node;
node* Basa_Eleman_Ekleme(node *root,int deger)
{
    node * tut;
    tut=(node*)malloc(sizeof(node));
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->sayi=deger;
        root->next=NULL;
        root->geri=NULL;
    }
    else
    {
        tut->sayi=deger;
        tut->next=root;
        root->geri=tut;
        tut->geri=NULL;
        root=tut;
    }
    return root;
}
node* Sona_Eleman_Ekleme(node *root,int deger)
{
    node * iter;
    node * tut;
    tut=(node*)malloc(sizeof(node));
    iter=root;
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->sayi=deger;
        root->next=NULL;
        root->geri=NULL;
    }
    else
    {
        while(iter->next!=NULL)
        {
            iter=iter->next;
        }
        tut->sayi=deger;
        tut->next=NULL;
        iter->next=tut;
        tut->geri=iter;
    }
    return root;
}
node* Sirali_Eleman_Ekleme(node *root,int deger)
{
    node * iter;
    node * tut;
    tut=(node*)malloc(sizeof(node));
    iter=root;
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->sayi=deger;
        root->next=NULL;
        root->geri=NULL;
    }
    else
    {
        if(iter==root && iter->sayi>deger)
        {
            tut->sayi=deger;
            tut->next=iter;
            iter->geri=tut;
            tut->geri=NULL;
            root=tut;
            return root;
        }
        while(iter->next!=NULL)
        {
            if(iter->next->sayi>=deger)
            {
                tut->sayi=deger;
                tut->next=iter->next;
                iter->next->geri=tut;
                iter->next=tut;
                tut->geri=iter;
                return root;
            }
            iter=iter->next;
        }
        tut->sayi=deger;
        iter->next=tut;
        tut->geri=iter;
        tut->next=NULL;
    }
    return root;
}
node* Bastan_Eleman_Silme(node *root)
{
    node* tut;
    tut=root;
    root=root->next;
    root->geri=NULL;
    free(tut);
    return root;
}
node* Sondan_Eleman_Silme(node *root)
{
    node * tut;
    node * iter;
    iter=root;
    while(iter->next!=NULL)
    {
        iter=iter->next;
    }
    tut=iter;
    iter=iter->geri;
    iter->next=NULL;
    free(tut);
    return root;
}
node* Sirali_Eleman_Silme(node *root,int deger)
{
    node * tut;
    node * iter;
    iter=root;
    if(iter->sayi==deger)
    {
        tut=iter;
        root=iter->next;
        root->geri=NULL;
        free(tut);
        return root;
    }
    else
    {
        while(iter!=NULL)
        {
            if(iter->sayi==deger)
            {
                if(iter->next==NULL)
                {
                    tut=iter;
                    iter=iter->geri;
                    iter->next=NULL;
                    free(tut);
                    return root;
                }
                else
                {
                    tut=iter;
                    iter=iter->geri;
                    iter->next=tut->next;
                    tut->next->geri=iter;
                    free(tut);
                    return root;
                }
            }
            iter=iter->next;
        }
    }
    return root;
}
node* Random_5lik_Dizi(node* root)
{
    int random;
    node* iter;
    random=rand()%20;
    root=(node*)malloc(sizeof(node));
    root->sayi=random;
    root->next=NULL;
    root->geri=NULL;
    iter=root;
    for(int k=0; k<4; k++)
    {
        random=rand()%20;
        iter->next=(node*)malloc(sizeof(node));
        iter->next->sayi=random;
        iter->next->geri=iter;
        iter->next->next=NULL;
        iter=iter->next;
    }
    return root;
}
void Yazdir(node* root)
{
    node* iter;
    iter=root;
    printf("------------------------------------------------\n");
    while(iter!=NULL)
    {
        printf("%d , ",iter->sayi);
        iter=iter->next;
    }
    printf("\n------------------------------------------------\n");
}
int main()
{
    int secim,deger;
    node * root;
    root=NULL;
    while(1)
    {
        printf("1 - Basa Eleman Ekleme\n");
        printf("2 - Sona Eleman Ekleme\n");
        printf("3 - Sirali Eleman Ekleme\n");
        printf("4 - Bastan Eleman Silme\n");
        printf("5 - Sondan Eleman Silme\n");
        printf("6 - Sirali Eleman Silme\n");
        printf("7 - Random 5'lik Dizi Olustur\n");
        printf("8 - Yazdir\n");
        scanf("%d",&secim);
        if(secim==1)
        {
            printf("Sayi Giriniz : ");
            scanf("%d",&deger);
            root=Basa_Eleman_Ekleme(root,deger);
            Yazdir(root);
        }
        else if(secim==2)
        {
            printf("Sayi Giriniz : ");
            scanf("%d",&deger);
            root=Sona_Eleman_Ekleme(root,deger);
            Yazdir(root);
        }
        else if(secim==3)
        {
            printf("Sayi Giriniz : ");
            scanf("%d",&deger);
            root=Sirali_Eleman_Ekleme(root,deger);
            Yazdir(root);
        }
        else if(secim==4)
        {
            root=Bastan_Eleman_Silme(root);
            if(root!=NULL)
            {
                Yazdir(root);
            }
        }
        else if(secim==5)
        {
            root=Sondan_Eleman_Silme(root);
            if(root!=NULL)
            {
                Yazdir(root);
            }
        }
        else if(secim==6)
        {
            printf("Silmek Istediginiz Sayiyi Giriniz : ");
            scanf("%d",&deger);
            root=Sirali_Eleman_Silme(root,deger);
            if(root!=NULL)
            {
                Yazdir(root);
            }
        }
        else if(secim==7)
        {
            root=Random_5lik_Dizi(root);
            Yazdir(root);
        }
        else if(secim==8)
        {
            Yazdir(root);
        }
    }
    return 0;
}
