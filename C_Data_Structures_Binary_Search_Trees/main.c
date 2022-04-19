#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * sag;
    struct node * sol;
};
typedef struct node node;
node * ekle(node *agac,int deger)
{
    if(agac==NULL)
    {
        node *root=(node*)malloc(sizeof(node));
        root->data=deger;
        root->sag=NULL;
        root->sol=NULL;
        return root;
    }
    else
    {
        if(agac->data<deger)
        {
            agac->sag=ekle(agac->sag,deger);
            return agac;
        }
        else
        {
            agac->sol=ekle(agac->sol,deger);
            return agac;
        }
    }
}
void YAZDIR(node *agac)
{
    if(agac==NULL)
    {
        return;
    }
    YAZDIR(agac->sol);
    printf("%d , ",agac->data);
    YAZDIR(agac->sag);
}
void arama(node*agac,int aranacak_deger)
{
    if(agac==NULL)
    {
        return;
    }
    arama(agac->sol,aranacak_deger);
    if(aranacak_deger==agac->data)
    {
        printf("Deger Bulundu = %d , ",agac->data);
    }
    arama(agac->sag,aranacak_deger);
}
void Max_Bulma(node *agac)
{
    // bu ilk yol
    /*if(agac->sag==NULL)
    {
        printf("Agactaki En Buyuk Deger = %d",agac->data);
        return;
    }
    Max_Bulma(agac->sag);
    */
    // buda ikinci yol
    while(agac->sag!=NULL)
    {
        agac=agac->sag;
    }
    printf("Agactaki En Kucuk Deger = %d",agac->data);
    return;

}
void Min_Bulma(node *agac)
{
    // bu ilk yol
    if(agac->sol==NULL)
    {
        printf("Agactaki En Kucuk Deger = %d",agac->data);
        return;
    }
    Max_Bulma(agac->sol);
    // buda ikinci yol
    /*while(agac->sol!=NULL)
        {
        agac=agac->sol;
        }
    printf("Agactaki En Kucuk Deger = %d",agac->data);
        return;
        */
}
int main()
{
    node *agac=NULL;
    agac=ekle(agac,12);
    agac=ekle(agac,200);
    agac=ekle(agac,190);
    agac=ekle(agac,213);
    agac=ekle(agac,56);
    agac=ekle(agac,28);
    agac=ekle(agac,24);
    agac=ekle(agac,18);
    agac=ekle(agac,27);
    agac=ekle(agac,28);
    YAZDIR(agac);
    printf("\n");
    printf("\n");
    arama(agac,28);
    printf("\n");
    printf("\n");
    YAZDIR(agac);
    printf("\n");
    printf("\n");
    Max_Bulma(agac);
    printf("\n");
    printf("\n");
    YAZDIR(agac);
    printf("\n");
    printf("\n");
    Min_Bulma(agac);
    printf("\n");
    printf("\n");
    YAZDIR(agac);
    return 0;
}
