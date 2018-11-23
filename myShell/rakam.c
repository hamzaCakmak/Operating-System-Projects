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

int main(int argc, char *argv[]) {
	
	int number=strtoint(argv[0]);	
	switch(number)
	{
		case 0:
			printf("0 >> sıfır\n");
			break;
		case 1:
			printf("1 >> bir\n");
			break;
		case 2:
			printf("2 >> iki\n");
			break;
		case 3:
			printf("3 >> uc\n");
			break;
		case 4:
			printf("4 >> dort\n");
			break;
		case 5:
			printf("5 >> bes\n");
			break;
		case 6:
			printf("6 >> alti\n");
			break;
		case 7:
			printf("7 >> yedi\n");
			break;
		case 8:
			printf("8 >> sekiz\n");
			break;
		case 9:
			printf("9 >> dokuz\n");
			break;
		default:
			printf("Hatalı girdi.");
	}
	return 0;
}