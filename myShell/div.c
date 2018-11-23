#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("\nGecersiz islem\n");
            break;
         }
 }
 return number;
}


int main(int argc, char *argv[])
{
     int sayi1=strtoint(argv[0]);
     int sayi2=strtoint(argv[1]);
     int sonuc;
	 if(sayi2!=0)
	 {
		 sonuc = sayi1/sayi2;
		printf("%d/%d = %d\n",sayi1,sayi2,sonuc);
	 }
	 else printf("İkinci argüman 0'a eşit olamaz.\n");
     

	 return 0;
}
