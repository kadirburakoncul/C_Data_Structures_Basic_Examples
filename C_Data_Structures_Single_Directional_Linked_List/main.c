#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int yas;
    struct node* next;
};
typedef struct node node;

// Basa Eleman Ekleme Fonksiyonu
node * Basa_Eleman_Ekle(node*root,int yas_deger)
{
    node* tut;
    tut=(node*)malloc(sizeof(node));
    tut->yas=yas_deger;
    tut->next=root;
    root=tut;
    return root;
}
// Sona Eleman Ekleme Fonksiyonu
void Sona_Eleman_Ekle(node *root,int yas_deger)
{
    node* temp;
    temp=root;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=(node*)malloc(sizeof(node));
    temp->next->yas=yas_deger;
    temp->next->next=NULL;
}
node* Siralamaya_Gore_Eleman_Ekleme(node* root,int yas_deger)
{
    node* temp;
    node* tut;
    tut=(node*)malloc(sizeof(node));
    tut->yas=yas_deger;
    temp=root;
    while(temp!=NULL)
    {
        if(temp==root && (temp->yas)>=(tut->yas))
        {
            tut->next=root;
            root=tut;
            return root;
        }
        else if(temp->next!=NULL)
        {
            if((temp->yas)<=(tut->yas) && (temp->next->yas)>(tut->yas))
            {
                tut->next=temp->next;
                temp->next=tut;
                return root;
            }
        }
        else if(temp->next==NULL)
        {
            if((temp->yas)<=(tut->yas))
            {
                tut->next=temp->next;
                temp->next=tut;
                return root;
            }
        }
        temp=temp->next;
    }
}
// Kucukten Buyuge Sýralama Fonksiyonu
node* Kucukten_Buyuge_Sirala(node *root)
{
    node *temp;
    node* tut;
    int kacsayivar=0;
    temp=root;
    while(temp!=NULL)
    {
        kacsayivar++;
        temp=temp->next;
    }
    for(int k=0; k<kacsayivar*2; k++)
    {
        temp=root;
        while(temp->next!=NULL)
        {
            if((temp->yas)>(temp->next->yas) && temp==root)
            {
                tut=temp->next;
                temp->next=tut->next;
                tut->next=temp;
                root=tut;
                temp=root;
            }
            if(temp->next->next!=NULL)
            {
                if((temp->next->yas)>(temp->next->next->yas) && temp->next->next!=NULL)
                {
                    tut=temp->next->next;
                    temp->next->next=tut->next;
                    tut->next=temp->next;
                    temp->next=tut;
                }
            }
            temp=temp->next;
        }
    }
    return root;
}
// Buyukten Kucuge Siralama Fonksiyonu
node* Buyukten_Kucuge_Sirala(node *root)
{
    node *temp;
    node* tut;
    int kacsayivar=0;
    temp=root;
    while(temp!=NULL)
    {
        kacsayivar++;
        temp=temp->next;
    }
    for(int k=0; k<kacsayivar*2; k++)
    {
        temp=root;
        while(temp->next!=NULL)
        {
            if((temp->yas)<(temp->next->yas) && temp==root)
            {
                tut=temp->next;
                temp->next=tut->next;
                tut->next=temp;
                root=tut;
                temp=root;
            }
            if(temp->next->next!=NULL)
            {
                if((temp->next->yas)<(temp->next->next->yas) && temp->next->next!=NULL)
                {
                    tut=temp->next->next;
                    temp->next->next=tut->next;
                    tut->next=temp->next;
                    temp->next=tut;
                }
            }
            temp=temp->next;
        }
    }
    return root;
}
void Yapi_5_lik(node *root)
{
    node *temp;
    temp=root;
    int rastgele;
    for(int k=0; k<4; k++)
    {
        rastgele=rand()%10;
        temp->next=(node*)malloc(sizeof(node));
        temp->next->yas=rastgele;
        temp->next->next=NULL;
        temp=temp->next;
    }
}
node* Bastan_Eleman_Silme(node *root)
{
    node* tut;
    tut=root;
    root=root->next;
    free(tut);
    return root;
}
void Sondan_Eleman_Silme(node *root)
{
    node * temp;
    node * tut;
    temp=root;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    tut=temp->next;
    temp->next=tut->next;
    free(tut);
}
node* Secilen_Elemani_Silme(node *root,int Silinecek_Sayi)
{
    node* temp;
    node* tut;
    temp=root;
    while(temp->next!=NULL)
        {
            if(temp->yas==Silinecek_Sayi && temp==root)
                {
                tut=root;
                    root=root->next;
                    free(tut);
                    return root;
                }
            else if(temp->next->yas==Silinecek_Sayi)
                {
                    tut=temp->next;
                    temp->next=tut->next;
                    free(tut);
                    return root;
                }
        temp=temp->next;
        }
    printf("\n\nListede Olmayan Bir Sayi Girdiniz !!!\n");
}
void Yazdir(node *root)
{
    node* temp;
    temp=root;
    while(temp!=NULL)
    {
        printf("%d , ",temp->yas);
        temp=temp->next;
    }
    printf("\n--------------------------------------------\n");

}
int main()
{
    node * root;
    root=(node*)malloc(sizeof(node));
    root->yas=7;
    root->next=NULL;
    node *temp;
    int secim,yas_deger,Silinecek_Sayi;
    while(1)
    {
        printf("1 - Basa Eleman Ekle\n");
        printf("2 - Sona Eleman Ekle\n");
        printf("3 - Siralamaya Gore Eleman Ekle\n");
        printf("4 - kucukten Buyuge Sirala\n");
        printf("5 - Buyukten Kucuge Sirala\n");
        printf("6 - Random 5'lik Yapi Olustur\n");
        printf("7 - Bastan Eleman Silme\n");
        printf("8 - Sondan Eleman Silme\n");
        printf("9 - Secilen Bir Elemani Silme\n");
        printf("10 - YAZDIR\n");
        scanf("%d",&secim);
        printf("--------------------------------------------\n");
        if(secim==1)
        {
            printf("Yasini Giriniz : (Girilen Yas 1 ile 20 arasinda olmali Yoksa Kaydedilmez)\n");
            scanf("%d",&yas_deger);
            printf("--------------------------------------------\n");
            root=Basa_Eleman_Ekle(root,yas_deger);
            Yazdir(root);
        }
        else if(secim==2)
        {
            printf("Yasini Giriniz : (Girilen Yas 1 ile 20 arasinda olmali Yoksa Kaydedilmez)\n");
            scanf("%d",&yas_deger);
            printf("--------------------------------------------\n");
            Sona_Eleman_Ekle(root,yas_deger);
            Yazdir(root);
        }
        else if(secim==3)
        {
            printf("Yasini Giriniz : (Girilen Yas 1 ile 20 arasinda olmali Yoksa Kaydedilmez)\n");
            scanf("%d",&yas_deger);
            printf("--------------------------------------------\n");
            root = Siralamaya_Gore_Eleman_Ekleme(root,yas_deger);
            Yazdir(root);
        }
        else if(secim==4)
        {
            root=Kucukten_Buyuge_Sirala(root);
            Yazdir(root);
        }
        else if(secim==5)
        {
            root=Buyukten_Kucuge_Sirala(root);
            Yazdir(root);
        }
        else if(secim==6)
        {
            Yapi_5_lik(root);
            Yazdir(root);
        }
        else if(secim==7)
        {
            root=Bastan_Eleman_Silme(root);
            Yazdir(root);
        }
        else if(secim==8)
        {
            Sondan_Eleman_Silme(root);
            Yazdir(root);
        }
        else if(secim==9)
            {
            printf("Silmek Istediginiz Sayiyi Giriniz : ");
            scanf("%d",&Silinecek_Sayi);
            root=Secilen_Elemani_Silme(root,Silinecek_Sayi);
            Yazdir(root);
            }
        else if(secim==10)
        {
            Yazdir(root);
        }
    }
    return 0;
}
