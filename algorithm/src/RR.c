#include <stdlib.h>
#include <stdio.h>
#include "../../traitement.h"

void RR(Liste l)
{
  Liste temp, p;
  PROCESS pr;
  int i = 0;
  int curr_time = 0;
  int q;
  int nb; 
  nb=NbrEmt(l);
  int *Te_restant = (int *)malloc(sizeof(int) * nb);

  //tri
  if (l != NULL) //tester si ma liste est vide
  {
    for (temp = l; temp->suivant != NULL; temp = temp->suivant)
    {
      for (p = temp->suivant; p != NULL; p = p->suivant)
      {
        if (p->proc.TA < temp->proc.TA)
        {
          pr = p->proc;
          p->proc = temp->proc;
          temp->proc = pr;
        }
      }
    }
  }

  //calcul
  if (l != NULL) //tester si ma liste est vide
  {
    for (temp = l; temp != NULL; temp = temp->suivant)
    {
      Te_restant[i] = temp->proc.dureeExecution;
      i++;
    }
  }
  for (int k = 0; k < nb; k++)
  {
    printf("%d", Te_restant[k]);
  }
  printf("\n");

  printf("donner le quantum : \n");
  scanf("%d", &q);
  printf("\n");
  /*Afficher l'ordonnancement appliqué*/
  printf("Ordonnancement RR\n");
  printf("\n");
  /*Afficher la date d'arrivee, le temps d'execution et la priorité de chaque processus*/
  printf("Processus\t Ta\t Te\t Pr\n");
  if (l != NULL) //tester si ma liste est vide
  {

    for (temp = l; temp != NULL; temp = temp->suivant)
    {
      printf("%s\t\t %ums \t %ums\t %u\n", temp->proc.name, temp->proc.TA, temp->proc.dureeExecution, temp->proc.priorite);
    }
  }

  printf("\n");
  /*afficher lA DATE DE FIN D'EXECUTION DE CHAQUE  processuss*/
  printf("****date de debut et de fin de chasue processus selon leur temps d'execution****\n");
  printf("\n");
  printf("Processus\t Tdeb\t Tfin\n");

  while (1)
  {
    int termine = 1; //indique si les processus ont terminé ou non
    if (l != NULL)   //tester si ma liste est vide
    {
      //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
      int k;
      for (temp = l, k = 0; temp != NULL && k < nb; temp = temp->suivant, k++)

      {

        if ((Te_restant[k] > 0) && (temp->proc.TA <= curr_time))
        {
          termine = 0;

          if (Te_restant[k] > q)
          {
            curr_time += q;
            Te_restant[k] -= q;
            printf("%s\t\t %dms --> %dms\t\n", temp->proc.name, curr_time - q, curr_time);
          }

          else
          {
            curr_time += Te_restant[k];
            temp->proc.TAttente = curr_time - temp->proc.dureeExecution;

            printf("%s\t\t %dms --> %dms\t\n", temp->proc.name, curr_time - Te_restant[k], curr_time);
            Te_restant[k] = 0;
          }
        }
      }

      if (termine == 1)
        break;
    }
  }
  free(Te_restant);
}