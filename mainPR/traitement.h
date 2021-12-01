#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#define MAX_BUFFER_SIZE 1000
typedef struct PROCESS PROCESS;
typedef struct Element Element;
typedef struct Element *Liste;
struct PROCESS
{
    char name[20];
    unsigned int TA;
    unsigned int dureeExecution;
    unsigned int priorite;
    unsigned int TAttente;
    unsigned int TFin;  
    int turnaround_time;      int response_time;       int completed;
};
//declarer une liste chainée pour stocker mes processus
struct Element
{
    PROCESS proc;
    Element *suivant;
};
int nbP = 0;
Liste q, l = NULL;
void AfficheListe(Liste l)
{

    Element *p = l;

    while (p != NULL)
    {
        printf("%s %u %u %u\n", p->proc.name, p->proc.TA, p->proc.dureeExecution, p->proc.priorite);
        p = p->suivant;
    }
}
int NbrEmt(Liste l)
{
    int nb=0;
    Liste p;
p=l;
    while (p != NULL)
    {
        nb=nb+1;
        p = p->suivant;
    } 
    
    return nb;
} 
void sana(Liste l)
{  
    unsigned int fin=0;
    Liste temp,p;   
    PROCESS pr;
    //TRIER MA LISTE CHAINÉE SELON DATE D'ARRIVÉ 
    if(l!=NULL) //tester si ma lste est vide
    {
for(temp=l;temp->suivant!=NULL;temp=temp->suivant) 
{
    for(p=temp->suivant;p!=NULL;p=p->suivant) 
    {
        if(p->proc.TA<temp->proc.TA) 
        {
            pr=p->proc; 
            p->proc=temp->proc; 
            temp->proc=pr;
        }
    }
}
    }  
      if(l!=NULL) //tester si ma lste est vide
    {
for(temp=l;temp->suivant!=NULL;temp=temp->suivant) 
{
  fin=fin+temp->proc.dureeExecution;  
  temp->proc.TFin=fin;
    temp->proc.TAttente=fin-temp->proc.TA-temp->proc.dureeExecution; 
    printf("Nom: %s\t\t %u\t ms %u ms\t\n",temp->proc.name,temp->proc.TAttente,temp->proc.TFin);
    } 

} }

Liste creerListe(char *arg)
{
    FILE *fichier = fopen(arg, "r");
    char line[MAX_BUFFER_SIZE] = {0};
    if (fichier == NULL)
    {
        printf("no such fie exist");
        exit(1);
    }
    while (fgets(line, sizeof(line), fichier) != NULL)
    {
        //clean file from comments and newlines
        char *p = line;
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
            line[--len] = 0; /* strip newline or carriage rtn    */
        while (isspace(*p))  /* advance to first non-whitespace  */
            p++;
        /* skip lines beginning with '#' */
        if (*p == '#' || !*p)
            continue;
        //printf("%s\n", line);
        q = (Liste)malloc(sizeof(Element));
        sscanf(line, "%s %u %u %u", q->proc.name, &q->proc.TA, &q->proc.dureeExecution, &q->proc.priorite);
        q->suivant = l;
        l = q;
    }
    return l;

    fclose(fichier);
}
