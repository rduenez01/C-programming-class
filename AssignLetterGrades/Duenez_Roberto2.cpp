/* Author: Roberto Duenez
 * Program opens file to read scores & assigns letter grade.
 * Writes the scores, letter grades, and how many students of each grade
 * into out.dat  
 * Homework 2 						ECE 3331 
 * 02/5/16       
 */
 
 
#include <stdio.h>
#include <stdlib.h>

int main()
{
   
   FILE *fin, *fout;
   fin = fopen("in.dat", "r");
   fout = fopen("out.dat", "w");
 //Counter initialazation for A, Aminus, Aplus, ect.
  int A = 0, Am = 0, Bp = 0, B = 0,
 	Bm = 0, Cp = 0, C = 0, Cm = 0,
	Dp = 0, D = 0, Dm = 0, F = 0;
 //Identifier for raw score
   float score = 0;

 
   //Read from file and sort score
   while (fscanf(fin,"%f",&score) != EOF)
    {
    //Score will go through if else loops to be sorted	

   // A 
    if((94 <= score) && (score <= 100))
	   {
	   	fprintf(fout,"%5.1f     A\n",score);
   		A = A + 1;				//A counter goes up by one
		   }
		   
	// A- 
   	else if((90 <= score) && (score <= 94))
	   {
	   	fprintf(fout,"%5.1f     A-\n",score);
   		Am = Am + 1; 
		   }	   	
	// B+ 
   	else if((86 <= score )&& (score < 90))
	   {
	   	fprintf(fout,"%5.1f     B+\n",score);
   		Bp = Bp + 1;
		   }   
	// B 
   	else if((82 <= score) && (score < 86))
	   {
	   	fprintf(fout,"%5.1f     B\n",score);
   		B = B + 1;
		   }   		   
	// B- 
   	else if((78 <= score) && (score < 82))
	   {
	   	fprintf(fout,"%5.1f     B-\n",score);
   		Bm = Bm + 1;
		   } 		   
	// C+
   	else if((74<= score)&& (score < 78))
	   {
	   	fprintf(fout,"%5.1f     C+\n",score);
   		Cp = Cp + 1;
		   } 		   
	// C
   	else if((70 <= score) && (score <74))
	   {
	   	fprintf(fout,"%5.1f     C\n",score);
   		C = C + 1;
		   } 		   
	// C-
   	else if((66 <= score)&& (score < 70))
	   {
	   	fprintf(fout,"%5.1f     C-\n",score);
   		Cm = Cm + 1;
		   } 		   
	// D+ 
   	else if((62 <= score) && (score < 66))
	   {
	   	fprintf(fout,"%5.1f     D+\n",score);
   		Dp = Dp + 1;
		   } 
	// D 
   	else if((58 <= score) && (score < 62))
	   {
	   	fprintf(fout,"%5.1f     D\n",score);
   		D = D + 1;
		   } 		   
	// D-
   	else if((54 <= score) && (score < 58))
	   {
	   	fprintf(fout,"%5.1f     D-\n",score);
   		Dm = Dm + 1;
		   } 		   
	// F 
   	else if(score < 54)
	   {
	   	fprintf(fout,"%5.1f     F\n",score);
   		F = F + 1;
		   } 		   
  		   
	}
	// Prints number of students with each letter grade.
	fprintf(fout,"\n %d received an A",A);
	fprintf(fout,"\n %d received an A-",Am);
	fprintf(fout,"\n %d received an B+",Bp);
	fprintf(fout,"\n %d received an B",B);
	fprintf(fout,"\n %d received an B-.",Bm);
	fprintf(fout,"\n %d received an C+",Cp);
	fprintf(fout,"\n %d received an C",C);
	fprintf(fout,"\n %d received an C-",Cm);
	fprintf(fout,"\n %d received an D+",Dp);
	fprintf(fout,"\n %d received an D",D);
	fprintf(fout,"\n %d received an D-",Dm);
	fprintf(fout,"\n %d received an F",F);
   
   
   fclose(fin);
   fclose(fout);

  system("pause");
}

