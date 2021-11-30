#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
//#include "traitement.h"
//#include "../algorithm/fifo.h"
//#include "../algorithm/SJF.h"
#include "../algorithm/RR.h"
char **tab = NULL;
int i = 1;
void ls(const char *dirname)
{
  tab = malloc(10 * sizeof(char *));
  DIR *dir = opendir(dirname);
  if (dir == NULL)
  {
    printf("ds");
    return;
  }
  struct dirent *entity;
  entity = readdir(dir);
  int j = 1;
  while (entity != NULL)
  {
    int n = strlen(entity->d_name);
    char *c = strstr(entity->d_name, ".c");
    char *cbp = strstr(entity->d_name, ".cbp");
    if ((c != NULL) && (c != cbp))
    {
      //printf("%s\n", entity->d_name);
      char *token;
      const char s[2] = ".";
      token = strtok(entity->d_name, s);

      printf("%d. ", j);
      printf("%s\n", token);
      j++;
      tab[j] = strdup(token);
      i++;
      /*if(tab[j]!=NULL)
      {
      strcpy(tab[i], token);}*/
    }

    entity = readdir(dir);
  }
  for (int k = 1; k <= j; k++)
  {
    if (tab[k] != NULL)
    {
      printf("%s\n", tab[k]);
    }
  }
  closedir(dir);
}
int main(int argc, char *argv[])
{
  int choix;
  int cas;
  ls("../algorithm");
  printf("choissisez une methode d'ordannancement en tapant le numero d'algo");
  scanf("%d", &choix);

  Liste mesProc = creerListe(argv[1]);
  for (int k = 1; k < i; k++)
  {
    //printf("%d",k);
    if (choix == k)
    {
      RR(mesProc);
    }
  }
  return 0;
}