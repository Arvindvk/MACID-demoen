#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sensor_r
   { char MAC_ID [20];
     long  time;
     long  date;
      }SR;
typedef struct sensor_q
   { char MAC_ID[20] ;
     long  time;
     long  date;
      }SQ;
void filter(SR* sr ,SQ* sq)
{ if(
      {
int main(int argc, char *argv[])
{
FILE *fp,*fp1,*fout;
SR sr;
SQ sq;
fout=fopen("output.txt","a");
if (argc != 3)
{
printf("usage: can open filename\n");
exit(EXIT_FAILURE);
}
if ((fp = fopen(argv[1], "r")) == NULL)
{
printf("%s can't be opened\n", argv[1]);
exit(EXIT_FAILURE);
}

if((fp1 = fopen(argv[2], "r")) == NULL)
{
printf("%s can't be opened\n", argv[2]);
exit(EXIT_FAILURE);
}

printf("%s can be opened\n", argv[1]);
printf("%s can be opened\n", argv[2]);
int i=0;
while(fscanf(fp,"%*d %s %*f %ld %ld ",sr.MAC_ID,&sr.date,&sr.time)!=EOF)
  { printf("%s,   %ld  ,  %ld \n",sr.MAC_ID,sr.date,sr.time);
    if(strcmp(sr.MAC_ID,'00:00:00:00:00:00')==0 )
      { 
                       macr[i]=sr.MAC_ID;
                       rtime[i]=sr.time;
                       rdate[i]=sr.date;
                       i++; 
      }
while(fscanf(fp1,"%*d %s %*f %ld %ld ",sq.MAC_ID,&sq.date,&sq.time)!=EOF)
  { printf("%s,   %ld  ,  %ld",sq.MAC_ID,sq.date,sq.time);
     if (strcmp(sq.MAC_ID,'00:00:00:00:00:00')==0 )
        {
            
            i++; 
   }
fclose(fp);
fclose(fp1);
return 0;
}