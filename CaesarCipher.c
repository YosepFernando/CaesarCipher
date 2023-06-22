#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int  i, l, c, k;
char r[50], s[50], c1[2], k1[2];

void runAgain();
int validation();
void validationU();
void validationL();

void dataEncryption()
{
	validationL(s);
	printf("\nJumlah Pergeseran : ");    
	fgets(k1, 3, stdin);
	k = validation(k1);
	printf("\nHasil Enkripsi : ");

	l = strlen(s);    
	for(i = 0; i < l; ++i)
	{     
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 97;
			r[i] = ((s[i] + k) % 26) + 65;
		}     
		printf("%c", r[i]);
	}
	printf("\n");
}

void dataDecryption()
{
	validationU(s);
	printf("\nJumlah Pergeseran : ");   
	fgets(k1, 3, stdin);
	k = validation(k1);   
	printf("\nHasil Dekripsi : ");

	l = strlen(s);  
	for(i = 0; i < l; ++i)
	{     
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 13;
			r[i] = ((s[i] - k) % 26) + 97;
		}     
		printf("%c", r[i]); 
	}
	printf("\n");
}

void pilihan()
{
	printf("\n1 = Enkripsi.");
	printf("\n2 = Dekripsi.");	
	printf("\nPilihan : ");
	fgets(c1, 3, stdin);
	sscanf(c1, "%d", &c);
	fflush(stdin);

	for(;;)
	{
		switch(c)
		{
			case 1:
			{		
				dataEncryption();
				runAgain();
			}
			case 2:
			{
				dataDecryption();
				runAgain();
			}
			default:
				printf("\nPilihan Salah!\n");
				pilihan();
		}
	}
}

int validation(char *inp)
{
	int i, j;
	long int inpH;
	
	size_t ln = strlen(inp) - 1;
	if (inp[ln] == '\n') 
	{
		inp[ln] = '\0';
	}
		
	for (i = 0; i < ln; i++)
	{
		if (!isdigit(inp[i]))
		{
			printf("%c bukan angka!\n", inp[i]);
			runAgain();
		}
		sscanf(inp, "%d", &inpH);
	}
	
	return inpH;
}

void validationU(char *inp)
{
	size_t ln = strlen(inp) - 1;
	if (inp[ln] == '\n') 
	{
		inp[ln] = '\0';
	}
		
	for (i = 0; i < ln; i++)
	{
		if (!isupper(inp[i]) && !isspace(inp[i]))
		{
			printf("%c bukan huruf besar!\n", inp[i]);
			runAgain();
		}
	}
}

void validationL(char *inp)
{
	size_t ln = strlen(inp) - 1;
	if (inp[ln] == '\n') 
	{
		inp[ln] = '\0';
	}
		
	for (i = 0; i < ln; i++)
	{
		if(!islower(inp[i]) && !isspace(inp[i]))
		{
			printf("%c bukan huruf kecil!\n", inp[i]);
			runAgain();
		}
	}
}

int main() 
{
	printf("\nMasukkan Huruf Kecil untuk diEnkripsi dan Huruf Besar untuk diDekripsi");
	printf("\nText : ");
	fgets(s, 51, stdin);
	
	pilihan();
	
	return 0;
}

void runAgain()
{
	char c, s[1];
		
	printf("\nJalankan lagi? (y/n)");
	fgets(s, 2, stdin);
	sscanf(s, "%c", &c);
	printf("\n");
	fflush(stdin);
	
	for(;;)
	{
		switch(c) 
		{
			case 'y' :
			case 'Y' :
			{ 	
				main();
			}
			case 'n' :
			case 'N' :
			{
				printf("Program Selesai!");
				exit(0);
			}
			default :
			{
				printf("Pilihan Salah!\n");
				runAgain();
			}
		}
	}
}
