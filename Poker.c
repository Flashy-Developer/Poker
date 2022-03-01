#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
# define clear()    system("cls")
#else
# define clear()    system("clear")
#endif

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

int Playgame(void){
	int psum=0;
	int bsum=0;
	int Pycards[5]={0};
	int Dlcards[5]={0};
	int cards[52];
	int Pok=0;
	
	Shuffcard(cards);

	Pycards[0]=cards[0];
	Pycards[1]=cards[1];
	Pycards[2]=cards[4];
	Dlcards[0]=cards[2];
	Dlcards[1]=cards[3];
	Dlcards[2]=cards[5];
	
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
	Piccard(Pycards[0]);
	Piccard(Pycards[1]);
	int i;
	for (i=0;i<2;i++){
		if(Pycards[i]%100==11||Pycards[i]%100==12||Pycards[i]%100==13){
		 psum=psum+0;
		 }
		else 
		{
			psum=psum+(Pycards[i]%100);
		}
	}
	if(psum>9)
	    psum=psum-10;
	else if (psum>=20)
		psum=psum-20;
	
	for (i=0;i<2;i++){
		if(Dlcards[i]%100==11||Dlcards[i]%100==12||Dlcards[i]%100==13){
		 bsum=bsum+0;
		 }
		else {
			bsum=bsum+(Dlcards[i]%100);
		}
	}
	if(bsum>9)
		bsum=bsum-10;
	else if (bsum>=20)
		bsum=bsum-20;
	printf("Your score is : %d\n",psum);	
	if (bsum>7||psum>7){
		clear();
		printf("Your card is \n");
		Piccard(Pycards[0]);
	    Piccard(Pycards[1]);
		printf("Dealer card is \n");
		Piccard(Dlcards[0]);
	    Piccard(Dlcards[1]);
		printf("Dealer score is : %d\n",bsum);
		printf("Your score is : %d\n",psum);
		for (i=8;i<=9;i++){
			if (bsum==i){
				printf("Dealer Poker %d\n",i);
				if(bsum>psum){
					printf("██████╗░███████╗░█████╗░██╗░░░░░███████╗██████╗░░██╗░░░░░░░██╗██╗███╗░░██╗\n");
					printf("██╔══██╗██╔════╝██╔══██╗██║░░░░░██╔════╝██╔══██╗░██║░░██╗░░██║██║████╗░██║\n");
					printf("██║░░██║█████╗░░███████║██║░░░░░█████╗░░██████╔╝░╚██╗████╗██╔╝██║██╔██╗██║\n");
					printf("██║░░██║██╔══╝░░██╔══██║██║░░░░░██╔══╝░░██╔══██╗░░████╔═████║░██║██║╚████║\n");
					printf("██████╔╝███████╗██║░░██║███████╗███████╗██║░░██║░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");
					printf("╚═════╝░╚══════╝╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n");
					Pok=1;
				}
			}
			if (psum==i){
				printf("Player Poker %d\n",i);
				if(psum>bsum){
					printf("██████╗░██╗░░░░░░█████╗░██╗░░░██╗███████╗██████╗░░██╗░░░░░░░██╗██╗███╗░░██╗\n");
					printf("██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝██╔════╝██╔══██╗░██║░░██╗░░██║██║████╗░██║\n");
					printf("██████╔╝██║░░░░░███████║░╚████╔╝░█████╗░░██████╔╝░╚██╗████╗██╔╝██║██╔██╗██║\n");
					printf("██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░██╔══╝░░██╔══██╗░░████╔═████║░██║██║╚████║\n");
					printf("██║░░░░░███████╗██║░░██║░░░██║░░░███████╗██║░░██║░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");
					printf("╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n");
					Pok=1;
					}
			}
			if (psum==bsum){
				printf("██████╗░██████╗░░█████╗░░██╗░░░░░░░██╗\n");
				printf("██╔══██╗██╔══██╗██╔══██╗░██║░░██╗░░██║\n");
				printf("██║░░██║██████╔╝███████║░╚██╗████╗██╔╝\n");
				printf("██║░░██║██╔══██╗██╔══██║░░████╔═████║░\n");
				printf("██████╔╝██║░░██║██║░░██║░░╚██╔╝░╚██╔╝░\n");
				printf("╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░\n");
				Pok=1;
			}
		}
	}
	if(Pok==0){
		char j;
		printf("Want more cards? input y|n : ");
		do{
			j = getchar();
		} while (j!='y' &&j!='n');
		i=0;
		if(j=='y'){
			printf("\nyour card 3 is  \n");
			Piccard(Dlcards[2]);
			if(Pycards[3]%100==11||Pycards[3]%100==12||Pycards[3]%100==13){
				psum=psum+0;
				}
			else {
				psum=psum+(Pycards[3]%100);
			}
			if(psum>9)
				psum=psum-10;
			else if (psum>=20)
				psum=psum-20;
			else if (psum>=30)
				psum=psum-30;
			if(Dlcards[3]%100==11||Dlcards[3]%100==12||Dlcards[3]%100==13){
				bsum=bsum+0;
			}
			else {
				bsum=bsum+(Dlcards[i]%100);
			}
			if(bsum>9)
				bsum=bsum-10;
			else if (bsum>=20)
				bsum=bsum-20;
			else if (bsum>=30)
				bsum=bsum-30;
		    clear();
			printf("Your card is \n");
			Piccard(Pycards[0]);
	    	Piccard(Pycards[1]);
			Piccard(Pycards[2]);
			printf("Dealer card is \n");
			Piccard(Dlcards[0]);
	    	Piccard(Dlcards[1]);
			Piccard(Dlcards[2]);
			printf("Dealer score is : %d\n",bsum);
			printf("Your score is : %d\n",psum);
			if(bsum>psum)
				{
				printf("██████╗░███████╗░█████╗░██╗░░░░░███████╗██████╗░░██╗░░░░░░░██╗██╗███╗░░██╗\n");
				printf("██╔══██╗██╔════╝██╔══██╗██║░░░░░██╔════╝██╔══██╗░██║░░██╗░░██║██║████╗░██║\n");
				printf("██║░░██║█████╗░░███████║██║░░░░░█████╗░░██████╔╝░╚██╗████╗██╔╝██║██╔██╗██║\n");
				printf("██║░░██║██╔══╝░░██╔══██║██║░░░░░██╔══╝░░██╔══██╗░░████╔═████║░██║██║╚████║\n");
				printf("██████╔╝███████╗██║░░██║███████╗███████╗██║░░██║░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");
				printf("╚═════╝░╚══════╝╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n");
				}
			else if(bsum<psum){
				printf("██████╗░██╗░░░░░░█████╗░██╗░░░██╗███████╗██████╗░░██╗░░░░░░░██╗██╗███╗░░██╗\n");
				printf("██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝██╔════╝██╔══██╗░██║░░██╗░░██║██║████╗░██║\n");
				printf("██████╔╝██║░░░░░███████║░╚████╔╝░█████╗░░██████╔╝░╚██╗████╗██╔╝██║██╔██╗██║\n");
				printf("██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░██╔══╝░░██╔══██╗░░████╔═████║░██║██║╚████║\n");
				printf("██║░░░░░███████╗██║░░██║░░░██║░░░███████╗██║░░██║░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");
				printf("╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n");
				}
			else if (psum==bsum){
				printf("██████╗░██████╗░░█████╗░░██╗░░░░░░░██╗\n");
				printf("██╔══██╗██╔══██╗██╔══██╗░██║░░██╗░░██║\n");
				printf("██║░░██║██████╔╝███████║░╚██╗████╗██╔╝\n");
				printf("██║░░██║██╔══██╗██╔══██║░░████╔═████║░\n");
				printf("██████╔╝██║░░██║██║░░██║░░╚██╔╝░╚██╔╝░\n");
				printf("╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░\n");
				}
			
		}
		else{
			clear();
			printf("Stand\n");
			printf("Your card is \n");
			Piccard(Pycards[0]);
	    	Piccard(Pycards[1]);
			printf("Dealer card is \n");
			Piccard(Dlcards[0]);
	    	Piccard(Dlcards[1]);
			printf("Dealer score is : %d\n",bsum);
			printf("Your score is : %d\n",psum);
			if(bsum>psum){
				printf("██████╗░███████╗░█████╗░██╗░░░░░███████╗██████╗░░██╗░░░░░░░██╗██╗███╗░░██╗\n");
				printf("██╔══██╗██╔════╝██╔══██╗██║░░░░░██╔════╝██╔══██╗░██║░░██╗░░██║██║████╗░██║\n");
				printf("██║░░██║█████╗░░███████║██║░░░░░█████╗░░██████╔╝░╚██╗████╗██╔╝██║██╔██╗██║\n");
				printf("██║░░██║██╔══╝░░██╔══██║██║░░░░░██╔══╝░░██╔══██╗░░████╔═████║░██║██║╚████║\n");
				printf("██████╔╝███████╗██║░░██║███████╗███████╗██║░░██║░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");
				printf("╚═════╝░╚══════╝╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n");
			}
			else if(bsum<psum){
				printf("██████╗░██╗░░░░░░█████╗░██╗░░░██╗███████╗██████╗░░██╗░░░░░░░██╗██╗███╗░░██╗\n");
				printf("██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝██╔════╝██╔══██╗░██║░░██╗░░██║██║████╗░██║\n");
				printf("██████╔╝██║░░░░░███████║░╚████╔╝░█████╗░░██████╔╝░╚██╗████╗██╔╝██║██╔██╗██║\n");
				printf("██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░██╔══╝░░██╔══██╗░░████╔═████║░██║██║╚████║\n");
				printf("██║░░░░░███████╗██║░░██║░░░██║░░░███████╗██║░░██║░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");
				printf("╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n");
				}
			else if (psum==bsum){
				printf("██████╗░██████╗░░█████╗░░██╗░░░░░░░██╗\n");
				printf("██╔══██╗██╔══██╗██╔══██╗░██║░░██╗░░██║\n");
				printf("██║░░██║██████╔╝███████║░╚██╗████╗██╔╝\n");
				printf("██║░░██║██╔══██╗██╔══██║░░████╔═████║░\n");
				printf("██████╔╝██║░░██║██║░░██║░░╚██╔╝░╚██╔╝░\n");
				printf("╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░\n");
				}
		}
	}
	return 1;
}

int main()
{
	clear();
	Playgame();
	char Ag;
	printf("Do you want to play again y|n : ");
	do{
		Ag = getchar();
	} while (Ag!='y' && Ag!='n');
	if (Ag == 'y')
	{
		printf("\nLet's go again\n");
		main();
	}
}
