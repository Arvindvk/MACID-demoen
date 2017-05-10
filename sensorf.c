#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sensor_r
   { char MAC_ID [20];
     long  time;
     long  date;
      }sensor;

void filter(char MAC[],long time,int *i , char (*mac)[20],long timearr[])
{  int count=0;
    char mac_id[20];
    int p=0;
    if(strcmp(MAC,"00:00:00:00:00:00")!=0 )
       {
           for(int j=0;j<(sizeof(*timearr)/sizeof(long));j++)
               {    //printf("entering second loop \n");
                  if(time-timearr[j]<3600 && strcmp(MAC,(*mac)[j])==1)
                  {   count=count+1;
                      //printf("count %d",count);
                      continue;
                  }
                  else{continue;}
               }
           if (count==0)
              {        strcpy(mac_id,MAC);
                       printf("%s \n",mac_id);
                       int len=sizeof(*mac)/20;


                        if(*i<p+24)
                           {int k=*i;

                           (*mac)[20]=mac_id;
                            *timearr=time;
                            printf("%ld",*timearr);
                            timearr++;
                            
                           mac++;
                           (*i)++;}
                        else
                                {  printf("resizing required");
                                        timearr = (long *) realloc(timearr, 25);
                                           (*mac)[20]=(char**)realloc(*mac[20], 25*sizeof(char[20]));
                                            p=p+24;
                                           (*mac)[20]=mac_id;
                                           *timearr=time;
                                           timearr++;
                                            mac++;

                                            (*i)++;
                                       }


    }
       }
}



int main(int argc, char *argv[])
//int main())
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

int *i=0;
long *rtime=(long*) malloc(25*(sizeof(long*)));
*rtime=0;
//printf("the size of time array %ld \n",sizeof(rtime));
long *qtime=(long*) malloc(25*(sizeof(long)));
char (*macr)[20]=malloc(sizeof(char[20])*25);
//printf("the size of mac array %ld \n",sizeof(*macr));
//exit(0);
char (*macq)[20]=malloc(sizeof(char[20])*250);
char mac_id[20];
while(fscanf(fp,"%*d %s %*f %ld %ld ",sr.MAC_ID,&sr.date,&sr.time)!=EOF)
  { //printf("%s, %ld ,  %ld \n",sr.MAC_ID,sr.date,sr.time);
    //char **foo=macr;

    filter(sr.MAC_ID,sr.time,&i,(char **)macr,rtime);

    //sstrcpy(macr,mac_id);

  }

i=0;
//while(fscanf(fp1,"%*d %s %*f %ld %ld ",sq.MAC_ID,&sq.date,&sq.time)!=EOF)
  //{ printf("%s,  %ld  , %ld",sq.MAC_ID,sq.date,sq.time);
    //char **foo1=macq;

    //filter(sq.MAC_ID,sq.time,&i,(char **)macq,qtime);
    //free(qtime);
    //strcpy(macq,mac_id);

   //}
free(rtime);
free(qtime);
free(macr);
free(macq);
fclose(fp);
fclose(fp1);
return 0;
}
