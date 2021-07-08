#include "classifica_partita.h"
#include <stdio.h>
#define rosso    "\e[1;91m"
#define verde  "\e[1;92m"
#define giallo  "\x1b[33m"
#define blu    "\x1b[34m"
#define fucsia "\x1b[35m"
#define reset "\x1b[0m"
#define bianco "\e[1;97m"
#define ciano "\e[0;106m"
#define blusfondo "\e[0;104m"
#define giallosfondo "\e[43m"
#define verdesfondo "\e[0;102m"
#define biancosfondo "\e[0;107m"
#define rossosfondo "\e[0;101m"

classifica_partita crea_classifica_partita()
{
    return NULL;
}


void inserisci_classifica_partita(classifica_partita *head, lista_partita *head2, char nome[]) //Medesimo ragionamento dei precedenti file.
{
    classifica_partita r = *head; 
    classifica_partita q = *head; 
    
    
    classifica_partita p; 
    p = (classifica_partita)malloc(sizeof(struct nodo_classifica_partita)); 
    
    
   
    p->giocatore = esiste_giocatore_partita(head2, nome);
   
    while ((q != NULL) && (q->giocatore->punteggio > p->giocatore->punteggio)){
        
        r = q;
        
        q = q->next;
    }
    
    if(q==*head)
    {
        p->next = *head;
        *head=p;
    }
    
    else
    {
        
        r->next = p;
       
        p->next = q;
    }
    
}

char* dai_nome_vincitore(classifica_partita *head)
{
return (*head)->giocatore->nome; //Restituisce il nome del vincitore, ovvero il nome del giocatore a cui è associato il primo nodo di questa struttura dati.
}

void stampa_classifica_partita(classifica_partita *head)
{
   printf("\n"); //Un semplice "vai a capo"
     int x = 1;
     classifica_partita cerca;
     cerca = *head;
     printf("\n\t\t\t     "verde"CLASSIFICA PARTITA"bianco);
     while(cerca!=NULL) //Finchè allo scorrere della lista vi è un elemento
    {
        if(x==1)
        printf("\n\t\t"verde" %s"bianco" è il vincitore, con ben %d punti!",cerca->giocatore->nome, cerca->giocatore->punteggio); //stampa il l'i-esimo elemento
        printf("\n\n\t   %d. "verde"%s"bianco", %d punti",x, cerca->giocatore->nome, cerca->giocatore->punteggio); //stampa il l'i-esimo elemento
        
        cerca = cerca->next; //continua a scorrere la lista
        x++;
    }
}

void cancella_classifica_partita(classifica_partita *head)
{  
        //Mi munisco di due puntatori di appoggio che chiamo precedente(p) e successivo (s) e li faccio puntare alla testa della lista.
        
        classifica_partita s = *head;
        classifica_partita p = *head;
        
        while(s!=NULL)
        {
            
          
            
       
            p = s; //Il puntatore "precedente" ragguingerà il puntatore "successivo"
            s = s->next; //Il puntatore successivo scorrerà in avanti di un nodo
            
            //In tale maniera i due puntatori scorreranno tutta la lista, de-allocando di volta in volta il nodo puntato dal puntatore precedente.
            
            free(p);
        }
    
    //Una volta giunti all'ultimo nodo dealloco anche il nodo puntato da s.
    free(s);
}


