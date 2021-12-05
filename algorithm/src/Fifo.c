#include <stdio.h>
#include <stdlib.h>
#include "../../traitement.h"
void Fifo(int argc, char *argv[])
{  
    printf("%s",argv[1]);
    Liste l=creerListe(argv[1]);
    unsigned int fin = 0;
    Liste temp, p;
    PROCESS pr;
    //TRIER MA LISTE CHAINÉE SELON DATE D'ARRIVÉ
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
    printf("**********Ordannancement Fifo************\n");  
     printf("Nom Processus \t\tTemps D'arrivée \t Temps fin\t\n");
    if (l != NULL) //tester si ma liste est vide
    {

        for (temp = l; temp != NULL; temp = temp->suivant)
        {
            fin = fin + temp->proc.dureeExecution;
            temp->proc.TFin = fin;
            //temp->proc.TAttente=fin-temp->proc.TA-temp->proc.dureeExecution;
            printf("Processus: %s\t\t %ums \t\t\t %u ms\n", temp->proc.name, temp->proc.TA, temp->proc.TFin);
        } 
    
    }}
