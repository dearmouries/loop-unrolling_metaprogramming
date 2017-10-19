#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	/* code */

   FILE *fptr;
   fptr = fopen("output.csv","a");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   fseek(fptr,0,SEEK_END);
   fprintf(fptr,"%d",10);
   fprintf(fptr,",");
   fprintf(fptr,"%d",20);
   fprintf(fptr,",");
   fprintf(fptr,"%d",30);
   fprintf(fptr,",");
   fprintf(fptr,"%d",40);
   fprintf(fptr,",");
   fprintf(fptr,"%d",50);
   fprintf(fptr,"\n");
   fclose(fptr);

   return 0;

}