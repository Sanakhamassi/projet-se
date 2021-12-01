#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../mainPR/traitement.h"
void RR_calculate(Liste l)
{
  Liste temp, p, pos;
  PROCESS pr;
  int len;
  unsigned int curr_time;
 
  int q = 2;
  len = NbrEmt(l);
  int j = 0;
  /* Dynamically allocate an array to store the remaining execution time for each process */
  int *remain_exection_time = (int *)malloc(sizeof(int) * len);
  /* Dynamically allocate an array to use to check response times */
  int *calc_response_time = (int *)malloc(sizeof(int) * len);
  /* Repeat until all processes are complete */
  bool check = true;  
   for (temp = l; temp != NULL; temp = temp->suivant)
      {
        remain_exection_time[j] = temp->proc.dureeExecution;
        calc_response_time[j] = 0; 
        }

  while (check)
  { 
    
    if (l != NULL) //tester si ma liste est vide
    { 
      int i=0;
      for (temp = l; temp != NULL; temp = temp->suivant)
      {        
        if (remain_exection_time[i] > 0)
        {
          // Handle the check variable FALSE
          check = false;

          /* If the response time has not yet been calculated */
          if (calc_response_time[i] == 0)
          {
            // Calculate response time and save
            temp->proc.response_time = curr_time - temp->proc.TA;
            // Process response time calculation
            calc_response_time[i] = 1;
          }
          /* If the remaining time is greater than the time quota */
          if (remain_exection_time[i] > q)
          {
            curr_time =curr_time+ q;
            // increment by the current time time quota
            remain_exection_time[i] =remain_exection_time[i]- q;  
            
            // Decrease the remaining time of the currently running process
          }

          /* If the remaining time is less than the time quota */
          else
          {
            curr_time += remain_exection_time[i];
            // Increase by the remaining time of the current time
            temp->proc.TAttente = curr_time - temp->proc.dureeExecution;
            // Calculate wait time
            remain_exection_time[i] = 0; 
            temp->proc.completed=1;
            // change remaining time to 0 
            //check=true;
          }
            printf("%d ",curr_time);
        }
        i++; 
       
      } /* When all processes are complete */
      if (check == true)
        break;
      // Escape the infinite loop
    
    }  
  }
 
   

  free(remain_exection_time);
}
void rr_calculate_turnaround_time(Liste l)
{
  Liste temp;
  if (l != NULL) //tester si ma liste est vide
  {
    for (temp = l; temp != NULL; temp = temp->suivant)
    {

      temp->proc.turnaround_time = temp->proc.dureeExecution + temp->proc.TAttente - temp->proc.TA;
    }
  }

  // Calculate turnaround time and save
}

void RR(Liste l)
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
  RR_calculate(l);
  rr_calculate_turnaround_time(l);
  if (l != NULL) //tester si ma liste est vide
  {
    for (temp = l; temp != NULL; temp = temp->suivant)
    {
      //temp->proc.TAttente=temp->proc.turnaround_time-temp->proc.dureeExecution;
      temp->proc.TFin = temp->proc.TA + temp->proc.dureeExecution + temp->proc.TAttente;
    }
  }

  // Calculate process time by calling sjf_calculate_time function

  printf("\t RR Scheduling Algorithms\n\n");

  //quick_sort_by_return_time(p, len);
  // Sort by return time by calling quick_sort_by_return_time function

  printf("Nom Processus \t\tTemps D'arrivée  \t Durée d'éxecution \t  \t Temps d'attente \t Temps fin\t\n");
  if (l != NULL) //tester si ma liste est vide
  {
    for (temp = l; temp != NULL; temp = temp->suivant)
    {
      //printf("%d ",temp->proc.completed);
      printf("Processus: %s\t\t %ums \t\t\t %ums \t\t\t\t %ums \t\t\t\t %u ms\n", temp->proc.name, temp->proc.TA, temp->proc.dureeExecution, temp->proc.TAttente, temp->proc.TFin);
    }
  }
}
