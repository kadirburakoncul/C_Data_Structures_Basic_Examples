#include <stdio.h>
#include <stdlib.h>
int *Dizi=NULL;
int Boyut=2;
int Siranin_Basi=0;
int Siranin_Sonu=0;
void Yazdir()
{
    printf("\t\tBOYUT : %d\n\t\t",Boyut);
    for(int k=0; k<Siranin_Sonu; k++)
    {
        printf("%d , ",Dizi[k]);
    }
    printf("\n\t\t-------------------------------------------------------------------------\n");
}
int deque()
{
    int tut;
    if(Siranin_Basi==Siranin_Sonu)
    {
        printf("Dizi Bos !!!\n");
    }
    else
    {
        printf("Siranin Sonu = %d\n",Siranin_Sonu);
        if(Boyut/2>=Siranin_Sonu)
        {
            Boyut=Boyut/2;
            int *Dizi2;
            Dizi2=(int*)malloc(sizeof(int)*Boyut);
            for(int k=0; k<Siranin_Sonu; k++)
            {
                Dizi2[k]=Dizi[k];
            }
            free(Dizi);
            Dizi=Dizi2;
        }
        tut=Dizi[0];
        for(int k=0; k<Siranin_Sonu-1; k++)
        {
            Dizi[k]=Dizi[k+1];
        }
        Siranin_Sonu=Siranin_Sonu-1;
        return tut;
    }
}
void enque(int Eklenecek_Deger)
{
    if(Dizi==NULL)
    {
        Dizi=(int*)malloc(sizeof(int)*Boyut);
        Dizi[Siranin_Sonu]=Eklenecek_Deger;
        Siranin_Sonu++;
    }
    else
    {
        if(Siranin_Sonu>=Boyut)
        {
            Boyut=Boyut*2;
            int *Dizi2;
            Dizi2=(int*)malloc(sizeof(int)*Boyut);
            for(int k=0; k<Siranin_Sonu; k++)
            {
                Dizi2[k]=Dizi[k];
            }
            free(Dizi);
            Dizi=Dizi2;
        }
        Dizi[Siranin_Sonu]=Eklenecek_Deger;
        Siranin_Sonu++;
    }
}
int main()
{
    for(int k=0; k<10; k++)
    {
        enque(k*20);
    }
    Yazdir();
    for(int k=0; k<10; k++)
    {
        printf("///////////////\n");
        printf("Silindi : %d\n",deque());
        printf("///////////////\n");
        Yazdir();
    }
    enque(100);
    Yazdir();
        enque(200);
    Yazdir();
            enque(300);
    Yazdir();
    for(int k=0; k<5; k++)
    {
        printf("///////////////\n");
        printf("Silindi : %d\n",deque());
        printf("///////////////\n");
        Yazdir();
    }
    return 0;
}
