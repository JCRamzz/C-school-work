/*
Program Name: Roll The Dice!
Author: Juan Carlos Ramirez
Description: This simple program will let the user roll a dice, there are 7 choices
the outcome will always be randomized through the use of various methods and functions.
Warning: This program will not output an accurate representation of your actual luck.
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

void dice();
void randomizer(int maxSize);
void displayMenu();
void displayTitle();
void suspendTime();

int main()
{
	puts("═██╗     ██╗   ██╗ ██████╗██╗  ██╗██╗   ██╗    ██████╗ ██╗ ██████╗███████╗");
	puts(" ██║     ██║   ██║██╔════╝██║ ██╔╝╚██╗ ██╔╝    ██╔══██╗██║██╔════╝██╔════╝");
	puts(" ██║     ██║   ██║██║     █████╔╝  ╚████╔╝     ██║  ██║██║██║     █████╗  ");
	puts(" ██║     ██║   ██║██║     ██╔═██╗   ╚██╔╝      ██║  ██║██║██║     ██╔══╝  ");
	puts(" ███████╗╚██████╔╝╚██████╗██║  ██╗   ██║       ██████╔╝██║╚██████╗███████╗");
	puts(" ╚══════╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝   ╚═╝       ╚═════╝ ╚═╝ ╚═════╝ ╚═════╝");
	suspendTime();
	suspendTime();
	puts("-------------------------------LOADING------------------------------------");
	suspendTime();
	suspendTime(); 

	dice();

    return 0;
}

void displayMenu()
{

    puts("                       | ~~~  Choose your weapon   ~~~ |");
	puts("                       |                               |");
	puts("                       |  1) A four-sided die          |");
	puts("                       |  2) A six-sided die           |");
	puts("                       |  3) A eight-sided die         |");
	puts("                       |  4) A ten-sided die           |");
	puts("                       |  5) A Twelve-sided die        |");
	puts("                       |  6) A Twenty-sided die        |");
    puts("                       |  7) A One-Hundred-sided die   |");
    puts("                       |                               |");
    puts("                       |  8) Get me out!!!             |");
	puts("                       |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
}

void dice()
{

int choice = 0;
int maxSides = 0;
int index = 0;

do
	{
	    displayMenu();
        printf("\n                                 >> ");	
	    scanf("%d", &choice);
		
		switch (choice)
		{
            case 1: 
				maxSides = 4;
	    		randomizer(maxSides);
                break;
            case 2:
				maxSides = 6;
	            randomizer(maxSides);
				break;
            case 3:
				maxSides = 8;
	            randomizer(maxSides);
                break;
            case 4:
				maxSides = 10;
	            randomizer(maxSides);
            	break;
            case 5:
				maxSides = 12;
	            randomizer(maxSides);
                break;
            case 6:
				maxSides = 20;
	            randomizer(maxSides);
            	break;
            case 7:
				maxSides = 100;
	            randomizer(maxSides);
            	break;
            case 8:
                puts("Thank you, bye!");
           		break;
            default: 
                printf("Error!\n");
                break;
		}
	}while (choice != 8); //validation
   
}

void randomizer(int maxSides) // All the randomizing will be done in this function, output as well.
{
	int sides = maxSides;
	int randNum = 0;
	srand((unsigned int)time(NULL));
	randNum = (rand() % sides) + 1;
	// Between 1 and sides
	if (randNum == 1)
	{
		puts("                        Ready?! Here we go!!!");
		puts("                        Rolling...");
		suspendTime(); //Pause for dramatic effect of course
		printf("                      You rolled a 1 on a %d-sided die!\n", maxSides);
		puts("        Yikes, you got a 1, the lowest possible outcome, how unlucky!"); //lowest possible outconme
	}
	else if (randNum == sides)
	{
		puts("                        Ready?! Here we go!!!");
		puts("                        Rolling...");
		suspendTime();
		printf("				      You rolled a %d on a %d-sided die! \n",randNum, maxSides);
		printf("    Wow, you got %d the highest possible outcome, go buy a lottery ticket!\n", randNum); //highest outcome
	}
	else
	{
		puts("                        Ready?! Here we go!!!");
		puts("                        Rolling...");
		suspendTime();
		printf("                      You've rolled a %d on a %d-sided die!\n", randNum, maxSides);

	}
}

void suspendTime() //This function will stop the time for about 2.08 seconds
{
	int index = 0;
	struct timespec ts = {1, 100000000L };
	for (index = 0; index < 1; index++)
	{
		nanosleep(&ts, NULL);
	}
}