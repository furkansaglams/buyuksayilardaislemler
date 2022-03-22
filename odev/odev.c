#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000 

char *carpma(char birinciSayi[],char ikinciSayi[])
{
 
 
    static  char carp[MAX];
    char c[MAX];
    char gecici[MAX];
    int aBoyut,bBoyut;
    int i,j,k=0,x=0,y;
    long int elde=0;
    long toplam = 0;
    aBoyut=strlen(birinciSayi)-1;
        bBoyut=strlen(ikinciSayi)-1;
   
        for(i=0;i<=aBoyut;i++){
                birinciSayi[i] = birinciSayi[i] - 48;//48:ASCII OLARAK '0'(48-'0'=0) a denk gelmektedir þnt cevirmek için kullanýldý.
        }

        for(i=0;i<=bBoyut;i++){
                ikinciSayi[i] = ikinciSayi[i] - 48;
        }

    for(i=bBoyut;i>=0;i--){
         elde=0;
         for(j=aBoyut;j>=0;j--){
             gecici[k++] = (ikinciSayi[i]*birinciSayi[j] + elde)%10;
             elde = (ikinciSayi[i]*birinciSayi[j]+elde)/10;
         }
         gecici[k++] = elde;
         x++;
         for(y = 0;y<x;y++){
             gecici[k++] = 0;
         }
    }
   
    k=0;
    elde=0;
    for(i=0;i<aBoyut+bBoyut+2;i++){
         toplam =0;
         y=0;
         for(j=1;j<=bBoyut+1;j++){
             if(i <= aBoyut+j){
                 toplam = toplam + gecici[y+i];
             }
             y += j + aBoyut + 1;
         }
         c[k++] = (toplam+elde) %10;
         elde = (toplam+elde)/10;
    }
    c[k] = elde;
    j=0;
    for(i=k-1;i>=0;i--){
         carp[j++]=c[i] + 48;
    }
    printf("\n");
 	printf("sonuc: ");
     for(i=0;i<k;i++){
     	 printf("%c",carp[i]);
         printf(" ");
         
    }
    
    carp[j]='\0';//dizinin bir yerde sonlanmasý için yapýldý.
    
    
    return carp;
 
 
}

void cikarma(int basamakDegeri, char birinciSayi[], char ikinciSayi[], int birinciSayiboyut, int ikinciSayiboyut)
{
 int i, j, dizic[basamakDegeri], cikarma, a, b;
 char birinciDizi[basamakDegeri], ikinciDizi[basamakDegeri];

 for (i = basamakDegeri - 1; i >= 0; --i)
 {
  birinciDizi[i] = '0';
  ikinciDizi[i] = '0';
  dizic[i] = 0;
 }
 for (i = basamakDegeri - 1, j = birinciSayiboyut - 1; i >= basamakDegeri - birinciSayiboyut; --i, --j)
 {
  birinciDizi[i] = birinciSayi[j];
 }

 for (i = basamakDegeri - 1, j = ikinciSayiboyut - 1; i >= basamakDegeri - ikinciSayiboyut; --i, --j)
 {
  ikinciDizi[i] = ikinciSayi[j];
 }

 int sart = 0;
 for (j = basamakDegeri - 1; j >= 0; --j)
 {
  a = birinciDizi[j];
  b = ikinciDizi[j];
  a = (int)(a - '0');
  b = (int)(b - '0');
  if (sart == 0)
  {
   cikarma = a - b;
  }
  else
  {
   cikarma = ((a - 1) - b);
   sart = 0;
  }

  if (cikarma < 0)
  {
   cikarma += 10;
   sart = 1;
  }
  dizic[j] = cikarma;
 }
 printf("\n");
 printf("sonuc: ");
  for (i = 0; i < basamakDegeri; ++i)
 {
  
  printf("%d", dizic[i]);
  printf(" ");
 }
}

void topla(int basamakDegeri, char birinciSayi[], char ikinciSayi[], int birinciSayiboyut, int ikinciSayiboyut)

{
 basamakDegeri = basamakDegeri + 1;
 char birinciDizi[basamakDegeri], ikinciDizi[basamakDegeri];
 int i, j, diziToplam[basamakDegeri + 1], toplam, elde = 0, a, b;

 for (i = basamakDegeri - 1; i >= 0; --i)
 {
  birinciDizi[i] = '0';//char karakteri oldugundan ' ' kullanýldý
  ikinciDizi[i] = '0';
  diziToplam[i] = 0;
 }
 for (i = basamakDegeri - 1, j = birinciSayiboyut - 1; i >= basamakDegeri - birinciSayiboyut; --i, --j)
 {
  birinciDizi[i] = birinciSayi[j];
 }

 for (i = basamakDegeri - 1, j = ikinciSayiboyut - 1; i >= basamakDegeri - ikinciSayiboyut; --i, --j)
 {
  ikinciDizi[i] = ikinciSayi[j];
 }
 for (j = basamakDegeri - 1; j >= 0; --j)
 {
  a = birinciDizi[j];
  b = ikinciDizi[j];

  toplam = (int)(a + b - 2 * '0') + elde;// -2*'0' ifadesi karakter olan a ve b degerlerini int e cevirmek için yapýldý 
  elde = 0;
  if (toplam >= 10)
  {
   toplam = toplam - 10;//bir basamklý iki sayýnýn toplamý maksimum 18 olur o yüzden 10 çýkardým.
   elde = 1;
   diziToplam[j] = toplam;
  }
  else
  {
   diziToplam[j] = toplam;
  }
 }
 printf("\n");
 printf("sonuc: ");

 for (i = 0; i < basamakDegeri; ++i)
 {
  printf("%d", diziToplam[i]);
  printf(" ");
 }
}

int main(int argc, char *argv[])
{
 int basamakDegeri, i,islem;
printf("UYARI:lutfen girdiginiz basamak degeri ile gireceginiz sayinin basamak degerlerinin farkli olmamasina dikkat ediniz! \n");
 printf("En fazla kac basamakli sayilarla islem yapmak istiyorsunuz: ");
 
 scanf("%d", &basamakDegeri);
 char birinciSayi[basamakDegeri], ikinciSayi[basamakDegeri];
 for (i = basamakDegeri - 1; i >= 0; --i)
 {
  birinciSayi[i] = '0';
  ikinciSayi[i] = '0';
 }
 printf("Birinci sayiyi giriniz: ");
 scanf("%s", birinciSayi);
 printf("Ikinci sayiyi  giriniz: ");
 scanf("%s", ikinciSayi);
 
 int x = strlen(birinciSayi), y = strlen(ikinciSayi); //girilen sayilarin boyut degrlerini x ve y degiskenlerine atadým.
 
   
 printf("lutfen bir islem seciniz (toplama icin 1 cikarma icin 2 carpma icin 3) \n");
 printf("1)TOPLAMA\n2)CIKARMA\n3)CARPMA\n");
 printf("\n");
 scanf("%d",&islem);
 printf("\n");
 //if else bloklarý sayilarin alt alta yazýlmasý için yapýldý.
if(x>=y)
{
	for(i=0;i<x;++i)
	{
	   printf("%c",birinciSayi[i]);
	   printf(" ");
		
	}
    printf("\n");
    for(i=0;i<x-y;i++)
    {
    	printf("  ");

	}
	for(i=0;i<y;++i)
	{
		
		printf("%c",ikinciSayi[i]);

		printf(" ");

	}
	
}

 else
 {

 for(i=0;i<y-x;i++)
    {
    	printf("  ");

	}
   for(i=0;i<x;++i)
	{
	   printf("%c",birinciSayi[i]);
	   printf(" ");
		
	}
    printf("\n");
   
	for(i=0;i<y;++i)
	{
		
		printf("%c",ikinciSayi[i]);

		printf(" ");

	}	
 }
printf("\n");

if(x>basamakDegeri||y>basamakDegeri)
 {
 islem=-1;
 }
 if (islem==1){
  topla(basamakDegeri, birinciSayi, ikinciSayi, x, y);
 }
 else if(islem==2){
  cikarma(basamakDegeri,birinciSayi,ikinciSayi,x,y);
 }else if(islem==3 )
 {
  carpma(birinciSayi,ikinciSayi);
 }
 else if(islem==-1){
   printf("lutfen bellirttiginiz basamak degeri kadar sayi giriniz!!!");
 
 }
 else
 {
   printf("lutfen dogru islem seciniz!!");
 }
 return 0;
}
