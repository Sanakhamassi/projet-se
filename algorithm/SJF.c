#include <stdio.h>
#include "../mainPR/traitement.h"
void Sjf_Calculate(Liste l)
{
    unsigned int fin = 0;
    Liste temp, p, pos;
    int tt = 0;
    PROCESS pr;
    PROCESS min;
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
            for (p = temp->suivant; p != NULL; p = p->suivant)
            {
                /* If the process has already been completed */
                if (p->proc.completed == 1)
                    continue;
                // go to next loop

                /* If the process has not yet completed */
                else
                {
                    min = p->proc;
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
                /* Search for processes with minimum working time */
                if ((p->proc.completed == 0) && (p->proc.TA <= curr_time) && (p->proc.dureeExecution < min.dureeExecution))
                {
                    min = p->proc;
                    // update the minimum working process
                }
            } 
// Calculate the waiting time of the process to run
            min.TA = curr_time - min.TA;
// change the execution process completion state
min.completed = 1;

// Incremented by the execution time of the current time process
curr_time += min.dureeExecution;

// Calculate process return time
min.TFin = curr_time;
// Calculate process turnaround time
min.turnaround_time = min.TFin - min.TA;
        }
    }
    //trier aprés selon durée d'execution
    printf("**********Ordannancement SJF************\n");
    printf("Nom Processus \t\tTemps D'execution \t Temps fin\t\n");

    if (l != NULL) //tester si ma liste est vide
    {

        for (temp = l; temp != NULL; temp = temp->suivant)
        {
            fin = fin + temp->proc.dureeExecution;
            temp->proc.TFin = fin;
            //temp->proc.TAttente=fin-temp->proc.TA-temp->proc.dureeExecution;
            printf("Processus: %s\t\t %ums \t\t\t %u ms\n", temp->proc.name, temp->proc.TA, temp->proc.TFin);
        }
    }
} 

void SJF(Liste l)

{
int i;
// Declare the variable to be used in the loop
int total_waiting_time = 0;
// Declare and initialize a variable to store the total wait time
int total_turnaround_time = 0;
// Declare and initialize a variable to store the total turnaround time
int total_response_time = 0;
// Declare and initialize a variable to store the total response time
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
// Calculate the return time of the process and save it0
temp->proc.response_time = temp->proc.TAttente;
// save the response time of the process

total_waiting_time += temp->proc.TAttente;
// increase total wait time
total_turnaround_time += temp->proc.turnaround_time;
// Increase total turnaround time
total_response_time += temp->proc.response_time;
// increase total response time 
        }
    }

printf("\t SJF Scheduling Algorithms\n\n");

//quick_sort_by_return_time(p, len);
// Sort by return time by calling quick_sort_by_return_time function

     printf("Nom Processus \t\tTemps D'arrivée  \t Durée d'éxecution \t  \t Temps d'attente \t Temps dans le processus \t Temps fin\t\n");
    if (l != NULL) //tester si ma liste est vide
    {

        for (temp = l; temp != NULL; temp = temp->suivant)
        {
            
            printf("Processus: %s\t\t %ums \t\t\t %ums \t\t\t %ums \t\t\t %ums \t\t\t %u ms\n", temp->proc.name,temp->proc.TA,temp->proc.dureeExecution,temp->proc.TAttente,temp->proc.turnaround_time,  temp->proc.TFin);
        } 
    
    }

}
