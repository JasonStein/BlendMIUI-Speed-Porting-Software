
/*
 *  BMSPS_FIND_IN_BUILD.c
 *  Created on: 11-25-2011
 *  Author: JasonStein
 *  E-mail: JasonStein@live.cn
 *
 *  BlendMIUI Speed-Porting Software
 */


#include <stdio.h>
#include <conio.h>
#include <string.h>

const int N=500;

int DFS_COMPARE(char *String,int Len,char *Build,int i)
{
  if(i==Len)
   {
    if(String[i]==Build[i])  return 1;
    else return 0;
   }
  else if(String[i]!=Build[i])  return 0;
  else return DFS_COMPARE(String,Len,Build,i+1);
}

void FIND_IN_BUILD(char *String,char *PATH,char *Ver)
{ 
  char Build[N][N];
  int  Lines=0 , i ;
  int Length=strlen(String);
   
  FILE *fin=fopen(PATH,"r");
  
  while(fgets(Build[Lines++],N,fin));
  
  for( i=0 ; i<Lines ; i++)
    if(DFS_COMPARE(String,Length-1,Build[i],0)) break;
  
  strcpy(Ver,Build[i]);
  fclose(fin);
}

