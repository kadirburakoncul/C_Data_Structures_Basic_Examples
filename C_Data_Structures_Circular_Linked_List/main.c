#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct node
{
    int sayi;
    struct node * next;
};
typedef struct node node;
node* Basa_Eleman_Ekleme(node *root,int deger)
{
    node* iter;
    node* tut;
    tut=(node*)malloc(sizeof(node));
    iter=root;
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->sayi=deger;
        root->next=root;
    }
    else
    {
        while(iter->next!=root)
        {
            iter=iter->next;
        }
        tut->sayi=deger;
        tut->next=root;
        iter->next=tut;
        root=tut;
    }
    return root;
}
node* Sona_Eleman_Ekleme(node *root,int deger)
{
    node* iter;
    node* tut;
    tut=(node*)malloc(sizeof(node));
    iter=root;
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->sayi=deger;
        root->next=root;
    }
    else
    {
        while(iter->next!=root)
        {
            iter=iter->next;
        }
        tut->sayi=deger;
        tut->next=root;
        iter->next=tut;
    }
    return root;
}
node* Sirali_Eleman_Ekleme(node *root,int deger)
{
    node* iter;
    node* tut;
    tut=(node*)malloc(sizeof(node));
    iter=root;
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->sayi=deger;
        root->next=root;
        return root;
    }
    else if(iter->next==root)
    {
        if(iter->sayi>deger)
        {
            tut->sayi=deger;
            tut->next=iter->next;
            iter->next=tut;
            root=tut;
            return root;
        }
        else
        {
            tut->sayi=deger;
            tut->next=iter->next;
            iter->next=tut;
            return root;
        }
    }
    else
    {
        while(iter->next!=root)
        {
            if(iter->sayi>deger)
            {
                if(iter==root)
                {
                    tut->sayi=deger;
                    tut->next=iter;
                    while(iter->next!=root)
                    {
                        iter=iter->next;
                    }
                    iter->next=tut;
                    root=tut;
                    return root;
                }
            }
            else if(iter->next->sayi>deger)
            {
                tut->sayi=deger;
                tut->next=iter->next;
                iter->next=tut;
                return root;
            }
            iter=iter->next;
        }
    }
    tut->sayi=deger;
    tut->next=iter->next;
    iter->next=tut;
    return root;

}
node* Bastan_Eleman_Silme(node *root)
{
    node* iter;
    node* tut;
    tut=(node*)malloc(sizeof(node));
    iter=root;
    if(root==NULL)
    {
        printf("Silinecek Eleman Bulunamadi !!! \n");
        printf("Dizinin Ici Bos !!! \n\n\n");
    }
    else
    {
        tut=iter;
        while(iter->next!=root)
        {
            iter=iter->next;
        }
        iter->next=tut->next;
        root=tut->next;
        free(tut);
        return root;
    }
}
node* Sondan_Eleman_Silme(node *root)
{
    node* iter;
    node* tut;
    tut=(node*)malloc(sizeof(node));
    iter=root;
    if(root==NULL)
    {
        printf("Silinecek Eleman Bulunamadi !!! \n");
        printf("Dizinin Ici Bos !!! \n\n\n");
    }
    else
    {
        while(iter->next->next!=root)
        {
            iter=iter->next;
        }
        tut=iter->next;
        iter->next=iter->next->next;
        free(tut);
        return root;
    }
}
node* Sirali_Eleman_Silme(node *root,int deger)
{
    node* iter;
    node* tut;
    tut=(node*)malloc(sizeof(node));
    iter=root;
    if(root==NULL)
    {
        printf("Silinecek Eleman Bulunamadi !!! \n");
        printf("Dizinin Ici Bos !!! \n\n\n");
        return root;
    }
    else
    {
        while(iter->next!=root)
        {
            if(iter->sayi==deger && iter==root)
            {
                tut=iter;
                while(iter->next!=root)
                {
                    iter=iter->next;
                }
                iter->next=tut->next;
                root=tut->next;
                free(tut);
                return root;
            }
            else if(iter->next->sayi==deger)
            {
                tut=iter->next;
                iter->next=tut->next;
                free(tut);
                return root;
            }
            iter=iter->next;
        }
    }
    if(root->sayi==deger)
    {
        free(root);
        return root;
    }
    printf("\nGirdiginiz Sayi Dizide Yok !!!\n\n");
    return root;
}
node* Random_5lik_Dizi(node* root)
{
    node * iter;
    int random;
    root=(node*)malloc(sizeof(node));
        random=rand()%20;
    root->sayi=random;
    root->next=NULL;
    iter=root;
    for(int k=0; k<4; k++)
    {
        random=rand()%20;
        iter->next=(node*)malloc(sizeof(node));
        iter->next->sayi=random;
        iter->next->next=NULL;
        iter=iter->next;
    }
    iter->next=root;
    return root;
}
void Yazdir(node* root)
{
    node* iter;
    iter=root;
    printf("------------------------------------------------\n");
    printf("%d , ",iter->sayi);
    iter=iter->next;
    while(iter!=root)
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
