#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void dice();
int randomizer(int num);
void displayMenu();
void displayTitle();

int main()
{
    //puts("Hello World!");
    dice();



    return 0;
}

void displayMenu()
{

    puts(" | ~~~  Choose your weapon   ~~~ |");
	puts(" |                               |");
	puts(" |  1) A four-sided die          |");
	puts(" |  2) A six-sided die           |");
	puts(" |  3) A eight-sided die         |");
	puts(" |  4) A ten-sided die           |");
	puts(" |  5) A Twelve-sided die        |");
	puts(" |  6) A Twenty-sided die        |");
    puts(" |  7) A One-Hundred-sided die   |");
    puts(" |                               |");
    puts(" |  8) Get me out!!!             |");
	puts(" |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
}

void dice()
{

int choice = 0;
int maxSides = 0;

do
	{
	    displayMenu();
        printf("Enter your choice:");	
	    scanf("%d", &choice);
		
		switch (choice)
		{
            case 1: 
	            //srand((unsigned int)time(NULL));
	            //randNum = (rand() % 4) + 1;
		        // Between 1 and 4
				maxSides = 4;
	            printf("Random number: %d", randomizer(maxSides));
                break;
            case 2:
                //srand((unsigned int)time(NULL));
	            //randNum = (rand() % 6) + 1;
		        // Between 1 and 6
				maxSides = 6;
	            printf("Random number: %d", randomizer(maxSides));
				break;
            case 3:
                //srand((unsigned int)time(NULL));
	            //randNum = (rand() % 8) + 1;
		        // Between 1 and 8
				maxSides = 8;
	            printf("Random number: %d", randomizer(maxSides));
                break;
            case 4:
                //srand((unsigned int)time(NULL));
	            //randNum = (rand() % 10) + 1;
		        // Between 1 and 10
				maxSides = 10;
	            printf("Random number: %d", randomizer(maxSides));
            	break;
            case 5:
                //srand((unsigned int)time(NULL));
	            //randNum = (rand() % 12) + 1;
		        // Between 1 and 12
				maxSides = 12;
	            printf("Random number: %d", randomizer(maxSides));
                break;
            case 6:
                //srand((unsigned int)time(NULL));
	            //randNum = (rand() % 20) + 1;
		        // Between 1 and 20
				maxSides = 20;
	            printf("Random number: %d", randomizer(maxSides));
            	break;
            case 7:
                //srand((unsigned int)time(NULL));
	            //randNum = (rand() % 100) + 1;
		        // Between 1 and 100
				maxSides = 100;
	            printf("Random number: %d", randomizer(maxSides));
            	break;
            case 8:
                puts("Thank you, bye!");
           		break;
            default: 
                printf("Error!\n");
                break;
		}
	}while (choice != 8);
   
}

int randomizer(int maxSides)
{
	int sides = maxSides;
	int randNum = 0;
	srand((unsigned int)time(NULL));
	randNum = (rand() % sides) + 1;
	// Between 1 and localNum
	if (randNum == 1)
	{
		puts("Yikes, you got a 1, the lowest possible outcome, how unlucky!");
	}
	else if (randNum == sides)
	{
		puts("Wow, you got %d the highest possible outcome, go buy a lottery ticket!");
	}
	return randNum;
}