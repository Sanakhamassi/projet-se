#ifndef TRAITEMENT_H_
#define TRAITEMENT_H_
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
    int turnaround_time;   
   int response_time;      
    int completed;
};
//declarer une liste chainée pour stocker mes processus
struct Element
{
    PROCESS proc;
    Element *suivant;
};
Liste creerListe(char *arg);
void AfficheListe(Liste l);
int NbrEmt(Liste l);


#endif