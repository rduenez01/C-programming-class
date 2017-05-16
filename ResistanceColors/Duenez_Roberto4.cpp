/* Author: Roberto Duenez
 * Program display resistance 
 * Homework 4						ECE 3331 
 * 02/18/16       
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printcolor(int);	// Function Declaration
void color_band(int);	// Function Declaration

 main()
{
	//Initialization
	int rvalue;		
	rvalue = 1;
//Loop to repeat 
do{
This:		// Go to flag for asking user input
printf("Enter integer resistance >  ");
scanf("%d",&rvalue);
if(rvalue < 0)
{
	printf("You entered a resistance outside the range 0 to 99x10^9.\nPlease re-enter a valid resistance value.\n\n");
	goto This;
}
	color_band(rvalue);		//Function is called
	printf("\n\n");
}
while(rvalue != -1);


system("pause");
}

//***************************************************************************
//printcolor Definition
void printcolor(int c)
{
	switch (c)
	{
		case 0:
			printf("Black ");
			break;
		case 1:
			printf("Brown ");
			break;
		case 2:
			printf("Red ");
			break;
		case 3:
			printf("Orange ");
			break;
		case 4:
			printf("Yellow ");
			break;
		case 5:
			printf("Green ");
			break;
		case 6:
			printf("Blue ");
			break;
		case 7:
			printf("Violent ");
			break;
		case 8:
			printf("Gray ");
			break;
		case 9:
			printf("White ");
			break;
			
}

}

//color_band Definition

void color_band(int b)
{
	int rvalue;
	rvalue = b;
	int count = 0;	
	int rvalue2, rvalue3;	
	int power;
	int factorD;
int rvalue1 = rvalue;

// # of digits
while (rvalue1 > 0)
{
	count++;
	if (rvalue1 < 10)
		break;
	rvalue1 /= 10;
}
int digits = count;		//Assigns the num of digits

if(digits == 0)			//Output black black black
{
	rvalue1 = 0;
	rvalue2 = 0;
	power = 0;
}

else if(digits == 1)	//Output black Color Black based off one digit
 {	
	power = 0;
	rvalue1 = 0;
	rvalue2 = rvalue;
}
else if (digits == 2)	//Outputs only two digits.
{
	power = digits-2;
	factorD = pow(10,digits - 1);
	rvalue1 = (rvalue/factorD)%10;
	rvalue2 = (rvalue/(factorD/10))%10;
}
else {						//Outputs for any digits
power = digits - 2;
printf("power = %d\n",power);
factorD = pow(10,digits - 1);
rvalue1 = (rvalue/factorD)%10;
rvalue2 = (rvalue/(factorD/10))%10;
rvalue3 = (rvalue/(factorD/100))%10;
if(rvalue3 >= 5)
	rvalue2++;
if (rvalue2 == 10)
	{	
	rvalue2 = 0;
	rvalue1 = 1;
	power++;
	}	
}
printcolor(rvalue1);
printcolor(rvalue2);
printcolor(power);	
}



