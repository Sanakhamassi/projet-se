#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "traitement.h"
#include "algorithm/src/Algo.h"
#include <unistd.h>
void ls(const char *dirname)
{
  int j = 1;
  struct dirent *pDirent;
  DIR *dir;
  dir = opendir(dirname);
  if (dir == NULL)
  {
    printf("Cannot open directory %s \n", dirname);
    return;
  }

  while ((pDirent = readdir(dir)) != NULL)
  {
    if (strstr(pDirent->d_name, ".") == NULL)
    {
      printf("%d. ", j);
      printf("%s\n", pDirent->d_name);
      j++;
    }
  }

  closedir(dir);
}
int main(int argc, char *argv[])
{
  int choix;
  char *command_line = (char *)malloc(20); 
  char *binaryPath = "./algorithm/build/Fifo";
  
  ls("./algorithm/build");
  printf("choissisez une méthode d'ordannancement en tapant le numéro d'algo: ");
  scanf("%d", &choix);
  if(command_line!=NULL) 
  {
  strcpy(command_line,binaryPath);

  strcat(command_line," "); 
  strcat(command_line ,argv[1]);

printf("%s",command_line);
int res=system(command_line); 
printf("%d",res); 
  }
 
  return 0;
}