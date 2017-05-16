 

void caseChange( char* blargh, unsigned short* count1){
 
      while (*blargh != 0) {
                  
                  if(*blargh >=97 && *blargh <= 122)
                  {
                     *blargh -= 32;
                     *count1 = *count1 + 1;
                     
                  } else if(*blargh>= 65 && *blargh <= 90)
                  {
                     
                     *blargh += 32;
                     *count1 = *count1 + 1;
                  } 

           blargh ++;


      }

 
}
