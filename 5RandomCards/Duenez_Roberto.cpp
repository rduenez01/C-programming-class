/* Author: Roberto Duenez
 * Program deals 5 random cards out of deck.
 * Homework 7						ECE 3331 
 * 03/06/16       
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void deal(char one[][4], char two[][4]);		// Function Declaration
//************************** MAIN FUNCTION ***************************************************************
 main()
{	
	//Initialization
	srand((unsigned int)time(NULL));
	char hand[5][4];
	char deck[52][4] = {"AcS","02S","03S","04S","05S","06S","07S","08S","09S","10S","JaS","QuS","KiS",
	"AcH","02H","03H","04H","05H","06H","07H","08H","09H","10H","JaH","QuH","KiH","AcD","02D",
	"03D","04D","05D","06D","07D","08D","09D","10D","JaD","QuD","KiD","AcC","02C","03C","04C",
	"05C","06C","07C","08C","09C","10C","JaC","QuC","KiC"};	
	int x,i, flag;
	int resp;

	flag=1;

	while(flag==1){
	
	printf("Do you want a new hand? [y = 1/n =0]...\n");		// Promts user for response
	scanf("%d",&resp);
	if (resp == 1){
		deal(hand, deck);										// Function invocation
		flag = 1;
		}
	else flag = -1;	
	}

	printf("Program ended\n\n");
	system("pause");
}
//**********************************************************************************************************
//**********************************************************************************************************

// Function definition
void deal(char a[][4], char b[][4]){
	printf("\n\n");
	int i,x;
	for(i=0; i<5; i++){
		x = rand() % 52;
		strcpy(a[i],b[x]);
 		printf("%s\n", a[i]);
		}
		printf("\n\n");
	
}


