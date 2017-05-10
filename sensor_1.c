#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sensor_r
   { char MAC_ID [20];
     long  time;
     long  date;
      }sensor;

void filter(char MAC[],long time,int i , char mac[][20],char time[])
{
    if(strcmp(sr.MAC_ID,'00:00:00:00:00:00')==0 )
      {   int count=0;
          for(int j=0;j<sizeof(time);j++)
             {
                  if(sr.time-rtime[j]<3600 && strcmp(sr.MAC_ID,mac[j])==1)
                  {   count=count+1
                      continue;
                  }
                  else{continue;}

             }
              if (count==0)
              {
                       strcpy(mac[i],sr.MAC_ID);
                       rtime[i]=sr.time;
                       rdate[i]=sr.date;
                       i++;
              }


      }
}
int main(int argc, char *argv[])
{
FILE *fp,*fp1,*fout;
sensor sr;
sensor sq;
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
int *rtime=(int*) malloc(sizeof(int)*25)
int *qtime=(int*) malloc(sizeof(int)*25)
char *macr[20]=(char*) malloc(sizeof(char[20])*25)
char *macq[20]=(char*) malloc(sizeof(char[20])*25)

while(fscanf(fp,"%*d %s %*f %ld %ld ",sr.MAC_ID,&sr.date,&sr.time)!=EOF)
  { printf("%s,   %ld  ,  %ld \n",sr.MAC_ID,sr.date,sr.time);
    filter(sr.MAC_ID,sr.time,&i,&macr,&rtime);
  }

i=0;
while(fscanf(fp1,"%*d %s %*f %ld %ld ",sq.MAC_ID,&sq.date,&sq.time)!=EOF)
  { printf("%s,  %ld  , %ld",sq.MAC_ID,sq.date,sq.time);
    filter(sq.MAC_ID,sq.time,&i,&macq,&qtime);
   }
   
for(int k=0;k<sizeof(macr);k++)
{
for(int j=0;j<
if(strcmp(macr[k],macq[k]   
fclose(fp);
fclose(fp1);
return 0;
}