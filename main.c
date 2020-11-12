#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sayi;
struct takim{
char takimIsmi[12];
char uzun_Isim[12];
char a[12];
int takimPuan;
int averaj;
int gol;
int gol1;
int oynanan_mac;
int galibiyet_sayisi;
int maglubiyet_sayisi;
int beraberlik_sayisi;

char gecici[10];
}takimlar[26];
int  bul ()
{
     FILE*dosya;
     dosya=fopen("ayarlar.txt","r");
        fscanf(dosya,"%d",&sayi);
        return sayi;
}


void puanVerme(struct takim *evSahibi,int evSahibiGol,struct takim *deplasman,int deplasmanGol){
    FILE*dosya;
    int a;
    int b;
    int c;
    dosya=fopen("ayarlar.txt","r");
        fscanf(dosya,"%d",&sayi);
        fscanf(dosya,"%d",&a);
        fscanf(dosya,"%d",&b);
        fscanf(dosya,"%d",&c);



if(evSahibiGol>deplasmanGol){
    evSahibi->takimPuan += a;
    deplasman->takimPuan += c;
    evSahibi->averaj += evSahibiGol-deplasmanGol;
    deplasman->averaj -= evSahibiGol-deplasmanGol;
    evSahibi->gol +=evSahibiGol;
    deplasman->gol +=deplasmanGol;
     evSahibi->gol1+=deplasmanGol;
    deplasman->gol1 +=evSahibiGol;
    evSahibi->oynanan_mac+=1;
    deplasman->oynanan_mac+=1;
   evSahibi->galibiyet_sayisi+=1;
   deplasman->maglubiyet_sayisi=+1;

}
else if(evSahibiGol==deplasmanGol){
    evSahibi->takimPuan +=b;
    deplasman->takimPuan +=b;
    evSahibi->gol +=evSahibiGol;
    deplasman->gol +=deplasmanGol;
     evSahibi->gol1+=deplasmanGol;
    deplasman->gol1 +=evSahibiGol;
    evSahibi->oynanan_mac+=1;
    deplasman->oynanan_mac+=1;
    evSahibi->beraberlik_sayisi+=1;
    deplasman->beraberlik_sayisi+=1;



}
else{
    deplasman->takimPuan += a;
    evSahibi->takimPuan += c;
    evSahibi->averaj -= deplasmanGol-evSahibiGol;
    deplasman->averaj += deplasmanGol-evSahibiGol;
    evSahibi->gol +=evSahibiGol;
    deplasman->gol +=deplasmanGol;
      evSahibi->gol1+=deplasmanGol;
    deplasman->gol1 +=evSahibiGol;
    evSahibi->oynanan_mac+=1;
    deplasman->oynanan_mac+=1;
    evSahibi->maglubiyet_sayisi+=1;
    deplasman->galibiyet_sayisi+=1;


}

//oku(evSahibi,
 //   deplasman);
 return sayi;
 bilgiler(sayi);

}

void takimBul(char evSahibi[],int evSahibiGol,char deplasman[],int deplasmanGol){
struct takim *evSahibiAdres;
struct takim *deplasmanAdres;
int i=0;


  for( i=0;i<20;i++){
    if(strcmp(takimlar[i].takimIsmi,evSahibi)==0){
        evSahibiAdres = &takimlar[i];
    }
}
for( i=0;i<20;i++){
    if( strcmp(takimlar[i].takimIsmi,deplasman)==0){
       deplasmanAdres = &takimlar[i];
    }
}

puanVerme(evSahibiAdres,evSahibiGol,deplasmanAdres,deplasmanGol);

}

void yaz()
{
    FILE*dosya;

    dosya=fopen("maclar.txt","w");



    char takim1[2],takim2[2];
    int sonuc1 , sonuc2;
    int i=0;
    int secim;
    int secim2;
    printf("secim giriniz ");
    scanf("%d",&secim);



	if ((dosya = fopen ("maclar.txt", "w")) != NULL)
    {
        char SS[17][2];

	    for(i = 0; i <3; i ++)
        { //TAKIM SAYISI KULLAN
		    printf("Mac sonucu girin\n");
		    scanf("%s",&SS[i][0]);
		    printf("skoru:");
		    scanf("%d",&sonuc1);

		    scanf("%s",&SS[i][1]);
			printf(" skoru:");
			scanf("%d",&sonuc2);
			 char* a= SS[i][0];
                char* b= SS[i][1];

			fprintf(dosya,"%s %d %s %d\n",&a,sonuc1,&b,sonuc2);

			if(i>0)
            {
                int k;
                for(k=0; k<i; k++)
                {
                        if ( (SS[k][0] == a) && (SS[k][1] == b) )
                        {
                       printf("same string.Enter different name !\n");
                      fseek(dosya,-10,SEEK_END);

                       i=i-1;


                        }
             }

	    }

    }

}
fclose(dosya);
oku(secim);

}
void bilgiler(int param)
{FILE* dosya;
	dosya=fopen("takimlar.txt","r");
	int i=0;
	int j,l;

	if((dosya=fopen("takimlar.txt","r"))=="NULL")
	{
		printf("dosya bulunamadý");

	}
	else
	{
		while(!feof(dosya))
        {
        	fscanf(dosya,"%s",&takimlar[i].uzun_Isim);


        	i++;

        }
    }
        for(j=0;j<l;j++)
        {
            for(l=0;l<12;l++)
            {
           takimlar[j].a[l]=takimlar[j].uzun_Isim[l];

            }

        }
       /* int fark='a'-'A';
        while(takimlar[i].a!='\0'){

        if (secim2==1)
        { for(l=0;l<12;l++){
           if(takimlar[i].a[l] >='A' && takimlar[i].a[l] <='Z')
           {
               takimlar[i].a[l] +=fark;
           }
        }

        }
        i++;
        }*/

         printf("uzun isim\tisim\tpuan\taveraj\tyedigi\tattigi\tmacsayisi\tgalibiyet\tmaglubiyet\tberaberlik\n");

             for( i=0;i<param;i++)
printf("%s\t%s\t%d\t %d \t%d \t%d\t  %d\t\t  %d\t\t  %d\t\t  %d\t\n",takimlar[i].a,takimlar[i].takimIsmi,takimlar[i].takimPuan,takimlar[i].averaj,takimlar[i].gol1,takimlar[i].gol,takimlar[i].oynanan_mac,takimlar[i].galibiyet_sayisi,takimlar[i].maglubiyet_sayisi,takimlar[i].beraberlik_sayisi);




	fclose(dosya);
}





void oku(int secim)
{
    FILE *dosya;

    char evSahibiTakim[20][20];
    int evSahibiSkor[20];
    char deplasmanSahibiTakim[20][20];
    int deplasmanSkor[20];
    int index=0;
    int takimSayisi=0;
    int i=0;
    int j=0;
    int c;
    int d;
    int e;
    int f,s;
    int k,l,m,n;
     for( i=0;i<20;i++){
            strcpy(takimlar[i].takimIsmi,"null");
    }
    if((dosya=fopen("maclar.txt","r")) != NULL){

          while(!feof(dosya)){
            fscanf(dosya,"%s %d %s %d",&evSahibiTakim[index],&evSahibiSkor[index],&deplasmanSahibiTakim[index],&deplasmanSkor[index]);
            index++;
            }
          index -=1;

       for( i=0;i<index;i++){
        for( j=0;j<index;j++){
            if(strcmp(evSahibiTakim[i],takimlar[j].takimIsmi)==0){
                break;
            }
            else if( strcmp(evSahibiTakim[i],takimlar[j].takimIsmi)!=0 && strcmp(takimlar[j].takimIsmi,"null")==0){
                strcpy(takimlar[takimSayisi].takimIsmi,evSahibiTakim[i]);
                takimSayisi++;

                break;
            }
        }
    }
           for( i=0;i<index;i++){
               for( j=0;j<index;j++){
            if(strcmp(deplasmanSahibiTakim[i],takimlar[j].takimIsmi)==0){
                break;
            }
              else if( strcmp(deplasmanSahibiTakim[i],takimlar[j].takimIsmi)!=0 && strcmp(takimlar[j].takimIsmi,"null")==0){
                strcpy(takimlar[takimSayisi].takimIsmi,deplasmanSahibiTakim[i]);
                takimSayisi++;
                break;
            }
           }
    }

    }
          for( i=0;i<index;i++){
        takimBul(evSahibiTakim[i],evSahibiSkor[i],deplasmanSahibiTakim[i],deplasmanSkor[i]);
    }   if(secim==1){


           for( i=0;i<takimSayisi;i++){
            for(j=0;j<takimSayisi-1-i;j++)
            {
                if(takimlar[j].takimPuan<takimlar[j+1].takimPuan)
                {
                    takimlar[j].gecici[0]=takimlar[j].takimIsmi[0];
                    takimlar[j].takimIsmi[0]=takimlar[j+1].takimIsmi[0];
                      takimlar[j+1].takimIsmi[0]= takimlar[j].gecici[0];

                c=takimlar[j].takimPuan;
                takimlar[j].takimPuan=takimlar[j+1].takimPuan;
                takimlar[j+1].takimPuan=c;

                d=takimlar[j].averaj;
                takimlar[j].averaj=takimlar[j+1].averaj;
                takimlar[j+1].averaj=d;
                e=takimlar[j].gol1;
                takimlar[j].gol1=takimlar[j+1].gol1;
                takimlar[j+1].gol1=e;
                f=takimlar[j].gol;
                takimlar[j].gol=takimlar[j+1].gol;
                takimlar[j+1].gol=f;
                k=takimlar[j].oynanan_mac;
                takimlar[j].oynanan_mac=takimlar[j+1].oynanan_mac;
                takimlar[j+1].oynanan_mac=k;
                l=takimlar[j].galibiyet_sayisi;
                takimlar[j].galibiyet_sayisi=takimlar[j+1].galibiyet_sayisi;
                takimlar[j+1].galibiyet_sayisi=l;
                m=takimlar[j].maglubiyet_sayisi;
                takimlar[j].maglubiyet_sayisi=takimlar[j+1].maglubiyet_sayisi;
                takimlar[j+1].maglubiyet_sayisi=m;
                n=takimlar[j].beraberlik_sayisi;
                takimlar[j].beraberlik_sayisi=takimlar[j+1].beraberlik_sayisi;
                takimlar[j+1].beraberlik_sayisi=n;

//printf("%s %d %d\n",takimlar[j].takimIsmi,takimlar[j].takimPuan,takimlar[j].averaj)

                }
                else if(takimlar[j].takimPuan==takimlar[j+1].takimPuan)
                {
                    if(takimlar[j].averaj<takimlar[j+1].averaj)
                    {  takimlar[j].gecici[0]=takimlar[j].takimIsmi[0];
                    takimlar[j].takimIsmi[0]=takimlar[j+1].takimIsmi[0];
                      takimlar[j+1].takimIsmi[0]= takimlar[j].gecici[0];

                d=takimlar[j].averaj;
                takimlar[j].averaj=takimlar[j+1].averaj;
                takimlar[j+1].averaj=d;
                 e=takimlar[j].gol1;
                takimlar[j].gol1=takimlar[j+1].gol1;
                takimlar[j+1].gol1=e;
                f=takimlar[j].gol;
                takimlar[j].gol=takimlar[j+1].gol;
                takimlar[j+1].gol=f;
                k=takimlar[j].oynanan_mac;
                takimlar[j].oynanan_mac=takimlar[j+1].oynanan_mac;
                takimlar[j+1].oynanan_mac=k;
                l=takimlar[j].galibiyet_sayisi;
                takimlar[j].galibiyet_sayisi=takimlar[j+1].galibiyet_sayisi;
                takimlar[j+1].galibiyet_sayisi=l;
                m=takimlar[j].maglubiyet_sayisi;
                takimlar[j].maglubiyet_sayisi=takimlar[j+1].maglubiyet_sayisi;
                takimlar[j+1].maglubiyet_sayisi=m;
                n=takimlar[j].beraberlik_sayisi;
                takimlar[j].beraberlik_sayisi=takimlar[j+1].beraberlik_sayisi;
                takimlar[j+1].beraberlik_sayisi=n;


                    }
                }
            }

     }



    }
     int temp;
     if(secim==2)
     {  for(i=0;i<takimSayisi;i++) {
         for(j=0;j<i;j++) {
            if(takimlar[i].takimIsmi[0]<takimlar[j].takimIsmi[0]) {
               temp=takimlar[i].takimIsmi[0];
               takimlar[i].takimIsmi[0]=takimlar[j].takimIsmi[0];
               takimlar[j].takimIsmi[0]=temp;
                c=takimlar[i].takimPuan;
                takimlar[i].takimPuan=takimlar[j].takimPuan;
                takimlar[j].takimPuan=c;

                d=takimlar[i].averaj;
                takimlar[i].averaj=takimlar[j].averaj;
                takimlar[j].averaj=d;
                e=takimlar[i].gol1;
                takimlar[i].gol1=takimlar[j].gol1;
                takimlar[j].gol1=e;
                f=takimlar[i].gol;
                takimlar[i].gol=takimlar[j].gol;
                takimlar[j].gol=f;
                k=takimlar[i].oynanan_mac;
                takimlar[i].oynanan_mac=takimlar[j].oynanan_mac;
                takimlar[j].oynanan_mac=k;
                l=takimlar[i].galibiyet_sayisi;
                takimlar[i].galibiyet_sayisi=takimlar[j].galibiyet_sayisi;
                takimlar[j].galibiyet_sayisi=l;
                m=takimlar[i].maglubiyet_sayisi;
                takimlar[i].maglubiyet_sayisi=takimlar[j].maglubiyet_sayisi;
                takimlar[j].maglubiyet_sayisi=m;
                n=takimlar[i].beraberlik_sayisi;
                takimlar[i].beraberlik_sayisi=takimlar[j].beraberlik_sayisi;
                takimlar[j].beraberlik_sayisi=n;

            }
         }
     }


}

}

int main()
{
    int param;
 param=bul();
   yaz();
 bilgiler(param);

}
