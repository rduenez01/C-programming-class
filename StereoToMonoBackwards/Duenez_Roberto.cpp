// Author: Roberto Duenez
// Program checks to see if a path to a file is correctly provided.
// Opens the .wav file and prints header and wave file characteristics. 
// Creates a new mono .wav file from a stereo .wav file.
// Homework 10				ECE 3331
// 4/9/16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function declarations
int fileread(FILE *A);
void filewrite(FILE *C,FILE *E);

// GLOBAL VARIALBES: USED IN MULTIPLE FUNCTIONS	*****************************************
	char out[5];																		//
	unsigned int newdatasize;															//
	signed short int left, right, avg;													//
	int i = 0;																			//	
// **************************************************************************************
	
	typedef struct WAVE_HEADER
	{	
		char 			chunkid[4];
		unsigned int 	chunksize;
		char 			format[4];
		char 			subchunk1[4];
		unsigned int 	subchunk_size;
		unsigned short 	audio;
		unsigned short 	num_ch;
		unsigned int 	smp_rate;
		unsigned int 	ByteRate;
		unsigned short 	blkAlign;
		unsigned short 	bits_smp;
		char 			subchunk2[4];
		unsigned int 	datasize;	
	}wavhdr;
	
wavhdr header1;	
	
main(){
		//******Initialization of identifiers, pointers, and arrays.
		FILE *fp, *fpt2;
		int ext,  length, i = 0, count, dir_len, result;
		char a, b;
		char path[100], wavfile[5], newpath[100];
		char newfilename[18] = "wav11backward.wav";
		
//********************************************   MAIN   *************************************************		
a = 'y';
	
while(a =='y'){
	// Checks to see if the file name has the .wav extension or any variation.
	printf("Enter the complete path and file name for an uncompressed stereo wav file with 2-bytes persample.\n");
	scanf("%s",path);
	printf("\nPath/filename is %s\n",path);
	ext = (strlen(path)- 4);								// Extension size
	strncpy(wavfile,&path[ext],4);							// Gets .wav or alternative
	length = strlen(path);									// Length of complete path
	
	if((wavfile[0] == '.')&&(wavfile[1]=='w'||wavfile[1]=='W')&&(wavfile[2]=='a'||wavfile[2]=='A')&&(wavfile[3]=='v'||wavfile[3]=='V')){
			
		if((fp = fopen(path,"rb" )) == NULL) printf("**CANNOT OPEN FILE!\n\n");
		else { 
			count = 0;
			result = fileread(fp);									// fileread function is called
			
			if(result == 2) {
				strcpy(newpath,path);
				// ** Gets directory **	
				for(i = 0; i <= length; i++) {						// Looks at the last character of path address
				if(newpath[(length - i)] != '\\')count++;			// to find the end of the directory where the
				else i = length+1;									// read audio file is located. 
				}													// ***Ends For loop
				if(count != length) {
				dir_len = length - count;							// Length of directory address
				newpath[dir_len + 1] = '\0';						// Makes the directory path a string by null-terminating it
				strcat(newpath,newfilename);						// newpath is now wav11backward.wav
				printf("new path is %s\n\n",newpath);
				} 
				else {
				newpath[0] = '\0';									// Assumes the file will be created within project folder						
				strcat(newpath,newfilename);
				printf("new path is %s\n\n",newpath);
				}
				fpt2 = fopen(newpath,"wb");							// Creates wav11mono.wav within source file folder
				filewrite(fpt2,fp);									// Function to write to new file is called
				
				fclose(fp);
				fclose(fpt2);		
			}
			else printf("Not uncompressed stereo file with 16-bits per sample...\n\n");
				// Promts user wish to continue with program.	
					printf("Do you wish to continue? [y/n] >  \n");
					scanf("%c%c",&b, &a);
					printf("\n");			  
			}
			//Else ends
		}
	
		
	else
		printf("Invalid path/ \n\n");	
	}
}

//******* FUNCTION DEFINITION ******************************	
	
int fileread(FILE *B){

	printf("FileOpened........success!!\n\n");
	// Reads from .wav the header and info of file and prints it out.
	fread(&header1,44,1,B);
		for(i=0; i<4; i++) out[i] = header1.chunkid[i];
	 	out[4] = '\0';
	 	printf("ChunkID = %s  \n",out);
		printf("ChunkSize = %u  \n",header1.chunksize);
		for(i=0; i<4; i++) out[i] = header1.format[i];
		printf("Format = %s  \n",out);
		for(i=0; i<4; i++) out[i] = header1.subchunk1[i];
		printf("Subchunk1ID = %s  \n",out);
		printf("Subchunk1Size = %u  \n",header1.subchunk_size);
		printf("AudioFormat = %u  \n", header1.audio);
		printf("NumChannels = %u  \n", header1.num_ch);
		printf("SampleRate = %u  \n", header1.smp_rate);
		printf("ByteRate = %u  \n", header1.ByteRate);
		printf("BlockAlign = %d  \n", header1.blkAlign);
		printf("BitsPerSample = %u  \n", header1.bits_smp);
		for(i=0; i<4; i++) out[i] = header1.subchunk2[i];
		printf("datasubchunk = %s  \n", out);
		printf("datasize = %u  \n\n", header1.datasize);
					
		// Beginning of check to see if uncompressed stereo wav file.
		if(header1.audio == 1 && header1.num_ch == 2 ) {
		printf("\n*** It is an uncompressed stereo .wav file\n\n");		// New file will open, updated, and printed.
		return 2;}
		else return 1;		
}	

// ********* FUNCTION DEFINITION ******************	
void filewrite(FILE *NEWFILE,FILE *OLDFILE) {
// Header changes
int count, x;
header1.num_ch = header1.num_ch - 1;
header1.ByteRate = header1.ByteRate / 2;
header1.blkAlign = header1.blkAlign / 2;
newdatasize = header1.datasize / 2;							// New datasize
header1.chunksize = (header1.chunksize - header1.datasize) + newdatasize;	// New File size
header1.datasize = newdatasize;
signed short int memptr[header1.datasize];			// Couldn't use calloc, used array instead
// Writing to file fwrite()
count = 0;
	fwrite(&header1,44,1,NEWFILE);					
	while(fread(&left,2,1,OLDFILE) != NULL){	
		fread(&right,2,1,OLDFILE);					// Removes right channel, by only storing the left channel
		memptr[count] = left;
		count++;									// count = to the datasize
	}
	for( x = -1; x != count; count--){				// Reverses the data
		left = memptr[count];	
		fwrite(&left,2,1,NEWFILE);
		}
		printf("\n***New file created, plays backwards!!*** \n\n");
	
}
