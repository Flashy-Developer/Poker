#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
#define clear()    system("cls")
#else
#define clear()    system("clear")
#endif

int Playgame(void);
int Shuffcard(int cards[]);
void Piccard(int num);

int main()
{
	clear();
	Playgame();
}

int Playgame(void){
	typedef struct{
		int Pycards[5];
		int psum;
	}Player;
	Player Py={{0},0};
	typedef struct{
		int Dlcards[5];
		int bsum;
	}Dealer;
	Dealer Dl={{0},0};
	int i;
	int cards[52];
	int Pok=0;
	char j ;
	Shuffcard(cards);
	Py.Pycards[0]=cards[0];
	Py.Pycards[1]=cards[1];
	Py.Pycards[2]=cards[4];
	Dl.Dlcards[0]=cards[2];
	Dl.Dlcards[1]=cards[3];
	Dl.Dlcards[2]=cards[5];
	printf("Cards of Dealer : \n");
		printf(" _______\n");
		printf("|       |\n");
		printf("|       |\n");
		printf("|   ?   |\n");
		printf("|       |\n");
		printf("|       |\n");
		printf("|_______|\n");
		printf(" _______\n");
		printf("|       |\n");
		printf("|       |\n");
		printf("|   ?   |\n");
		printf("|       |\n");
		printf("|       |\n");
		printf("|_______|\n");		
	printf("\n");
	printf("Cards of player :\n");
	Piccard(Py.Pycards[0]);
	Piccard(Py.Pycards[1]);
	 i=0;
	for (i=0;i<2;i++){
		if(Py.Pycards[i]%100==11||Py.Pycards[i]%100==12||Py.Pycards[i]%100==13){
		 Py.psum=Py.psum+0;
		 }
		else 
		{
			Py.psum=Py.psum+(Py.Pycards[i]%100);
		}
	}
	if(Py.psum>9)
	    Py.psum=Py.psum-10;
	else if (Py.psum>=20)
		Py.psum=Py.psum-20;
	
	for (i=0;i<2;i++){
		if(Dl.Dlcards[i]%100==11||Dl.Dlcards[i]%100==12||Dl.Dlcards[i]%100==13){
		 Dl.bsum=Dl.bsum+0;
		 }
		else {
			Dl.bsum=Dl.bsum+(Dl.Dlcards[i]%100);
		}
	}
	if(Dl.bsum>9)
		Dl.bsum=Dl.bsum-10;
	else if (Dl.bsum>=20)
		Dl.bsum=Dl.bsum-20;
	printf("Your score is : %d\n",Py.psum);	
	if (Dl.bsum>7||Py.psum>7){
		clear();
		printf("Your card is \n");
		Piccard(Py.Pycards[0]);
	    Piccard(Py.Pycards[1]);
		printf("Dealer card is \n");
		Piccard(Dl.Dlcards[0]);
	    Piccard(Dl.Dlcards[1]);
		printf("Dealer score is : %d\n",Dl.bsum);
		printf("Your score is : %d\n",Py.psum);
		i=0;
		for (i=8;i<=9;i++){
			if (Dl.bsum==i){
				printf("Dealer Poker %d\n",i);
				if(Dl.bsum>Py.psum){
					printf("!!!!Dealer Win!!!!\n");
					Pok=1;
				}
			}
			if (Py.psum==i){
				printf("Player Poker %d\n",i);
				if(Py.psum>Dl.bsum){
					printf("!!!!Player Win!!!!\n");
					Pok=1;
					}
			}
			if (Py.psum==Dl.bsum){
				printf("!!!!Draw!!!!\n");
				Pok=1;
			}
		}
	}
	if(Pok==0){
		printf("Want more cards? input y|n : ");
		j='\0';
		scanf("%c",&j);
			printf("\nyour card 3 is  \n");
			Piccard(Dl.Dlcards[2]);
			if(Py.Pycards[2]%100==11||Py.Pycards[2]%100==12||Py.Pycards[2]%100==13){
				Py.psum=Py.psum+0;
				}
			else {
				Py.psum=Py.psum+(Py.Pycards[2]%100);
			}
			if(Py.psum>9)
				Py.psum=Py.psum-10;
			else if (Py.psum>=20)
				Py.psum=Py.psum-20;
			else if (Py.psum>=30)
				Py.psum=Py.psum-30;
			if(Dl.Dlcards[2]%100==11||Dl.Dlcards[2]%100==12||Dl.Dlcards[2]%100==13){
				Dl.bsum=Dl.bsum+0;
			}
			else {
				Dl.bsum=Dl.bsum+(Dl.Dlcards[2]%100);
			}
			if(Dl.bsum>9)
				Dl.bsum=Dl.bsum-10;
			else if (Dl.bsum>=20)
				Dl.bsum=Dl.bsum-20;
			else if (Dl.bsum>=30)
				Dl.bsum=Dl.bsum-30;
		    clear();
			printf("Your card is \n");
			Piccard(Py.Pycards[0]);
	    	Piccard(Py.Pycards[1]);
			Piccard(Py.Pycards[2]);
			printf("Dealer card is \n");
			Piccard(Dl.Dlcards[0]);
	    	Piccard(Dl.Dlcards[1]);
			Piccard(Dl.Dlcards[2]);
			printf("Dealer score is : %d\n",Dl.bsum);
			printf("Your score is : %d\n",Py.psum);
			if(Dl.bsum>Py.psum)
				{
				printf("!!!!Dealer Win!!!!\n");
				}
			else if(Dl.bsum<Py.psum){
				printf("!!!!Player Win!!!!\n");
				}
			else if (Py.psum==Dl.bsum){
				printf("!!!!Draw!!!!\n");
				}
		else{
			clear();
			printf("Stand\n");
			printf("Your card is \n");
			Piccard(Py.Pycards[0]);
	    	Piccard(Py.Pycards[1]);
			printf("Dealer card is \n");
			Piccard(Dl.Dlcards[0]);
	    	Piccard(Dl.Dlcards[1]);
			printf("Dealer score is : %d\n",Dl.bsum);
			printf("Your score is : %d\n",Py.psum);
			if(Dl.bsum>Py.psum){
				printf("!!!!Dealer Win!!!!\n");
			}
			else if(Dl.bsum<Py.psum){
				printf("!!!!Player Win!!!!\n");

				}
			else if (Py.psum==Dl.bsum){
				printf("!!!!Draw!!!!\n");
				}
		}		
	}
	return 1;
}
int Shuffcard(int cards[])
{
	
	int t;
	int i;
	int desk[52];	
	for (i=0;i<52;i++)
		desk[i] = (i/13+3)*100 + i%13 + 1;

	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do
		{
			t = rand() % 52;
		} while (desk[t] == 0);
		cards[i] = desk[t];
		desk[t] = 0;
	}

	return 0;
}

void Piccard(int num)
{
	char fl;
	int Pnum;
	
	fl = num / 100;
	Pnum = num % 100;
	switch (Pnum)
	{
		case 1: 	 	
		case 2:		
		case 3:
		case 4:		
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
	{
			printf(" _______\n");
			printf("|%d      |\n",Pnum);
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|     %2d|\n",Pnum);
			printf("|_______|\n");
			break;
		}
		case 10:
		{
			printf(" _______\n");
			printf("|%d     |\n",Pnum);
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|     %2d|\n",Pnum);
			printf("|_______|\n");
			break;
		}
		case 11:
		{
			printf(" _______\n");
			printf("|J      |\n");
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|      J|\n");
			printf("|_______|\n");
			break;
		}
		case 12:
		{
			printf(" _______\n");
			printf("|Q      |\n");
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|      Q|\n");
			printf("|_______|\n");
			break;
		}
		case 13:
		{
			printf(" _______\n");
			printf("|K      |\n");
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|      K|\n");
			printf("|_______|\n");
			break;
		}

	}
}
