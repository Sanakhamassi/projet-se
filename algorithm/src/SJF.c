#include <stdio.h>
#include "../../traitement.h"
void Sjf_Calculate(Liste l)
{

    Liste temp, p, pos;

    int curr_time = 0;
    l->proc.completed = 1;
    l->proc.TFin = l->proc.dureeExecution;
    l->proc.turnaround_time = l->proc.dureeExecution - l->proc.TA;
    l->proc.TAttente = 0;
    curr_time = l->proc.dureeExecution;

    //TRIER MA LISTE CHAINÉE SELON DATE D'ARRIVÉ
    if (l != NULL) //tester si ma lste est vide
    {
        for (temp = l; temp->suivant != NULL; temp = temp->suivant)
        {
            for (p = l; p != NULL; p = p->suivant)
            {
                /* If the process has already been completed */
                if (p->proc.completed == 1)
                    continue;
                // go to next loop

                /* If the process has not yet completed */
                else
                {
                    pos = p;
                    //printf("%s",pos.name);
                    break;
                }
                /*  if (p->proc.dureeExecution < temp->proc.dureeExecution)
                {
                    pr = p->proc;
                    p->proc = temp->proc;
                    temp->proc = pr;
                }*/
            }

            for (p = l; p != NULL; p = p->suivant)
            {
                /* Search for processes with posimum working time */
                if ((p->proc.completed == 0) && (p->proc.TA <= curr_time) && (p->proc.dureeExecution < pos->proc.dureeExecution))
                {
                    pos = p;

                    // update the posimum working process
                }
            }
            // Calculate the waiting time of the process to run
            pos->proc.TAttente = curr_time - pos->proc.TA;

            //printf("%d\n ",pos.TAttente);
            // change the execution process completion state
            pos->proc.completed = 1;

            // Incremented by the execution time of the current time process
            curr_time = curr_time + pos->proc.dureeExecution;
            printf("%d", curr_time);
            // Calculate process return time
            pos->proc.TFin = curr_time;
            // Calculate process turnaround time
            pos->proc.turnaround_time = pos->proc.TFin - pos->proc.TA;
        }
    }
}
void SJF(Liste l)
{
    Liste temp, p;
    PROCESS pr;

    // Sort by arrival time by calling the merge_sort_by_arrive_time function
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

    // Calculate process time by calling sjf_calculate_time function
    Sjf_Calculate(l);

    /* Repeat for the number of processes */
    if (l != NULL) //tester si ma liste est vide
    {
        for (temp = l; temp->suivant != NULL; temp = temp->suivant)
        {
            temp->proc.TFin = temp->proc.turnaround_time + temp->proc.TA;
            // Calculate the return time of the process and save it
            temp->proc.response_time = temp->proc.TAttente;
            // save the response time of the process
        }
    }

    printf("\t SJF Scheduling Algorithms\n\n");

    printf("Nom Processus \t\tTemps D'arrivée  \t Durée d'éxecution \t  \t Temps d'attente \t Temps dans le processus \t Temps fin\t\n");
    if (l != NULL) //tester si ma liste est vide
    {

        for (temp = l; temp != NULL; temp = temp->suivant)
        {
            //printf("%d ",temp->proc.completed);
            printf("Processus: %s\t\t %ums \t\t\t %ums \t\t\t\t %ums \t\t\t\t %ums \t\t\t\t %u ms\n", temp->proc.name, temp->proc.TA, temp->proc.dureeExecution, temp->proc.TAttente, temp->proc.turnaround_time, temp->proc.TFin);
        }
    }
}
