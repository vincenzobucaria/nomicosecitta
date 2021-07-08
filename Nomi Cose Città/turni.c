#include "turni.h"
#include <string.h>

lista_turni crea_lista_turni()
{
    return NULL;
}

void inserisci_elementi(lista_turni *head, lista_turni *tail, char nome[], char cosa[], char citta[]) //Permette di popolare questa sottolista, effettuando inserimenti in coda.
{
    lista_turni new_node;
    new_node = (lista_turni)malloc(sizeof(struct nodo_turni));  //Alloco dinamicamente la memoria per il nuovo nodo.
   
    strcpy(new_node->nomi, nome); //popolo tutt le stringhe.
    strcpy(new_node->cose, cosa);
    strcpy(new_node->citta, citta);
   
    
    new_node->punti = 0;
    new_node->next = NULL;

    if(*head == NULL)
    {
        //Se la lista è vuota effettuo un inserimento in testa
        *head = new_node;
        *tail = new_node;
    }
    else //Altrimenti in coda.
    {
        
        (*tail)->next = new_node;
        *tail = new_node;
    }
    
      
}

void inserisci_punti_turno(lista_turni *tail, int punti) //Permette di popolare il campo punti del nodo (alla coda della lista) passato alla funzione.
{
    (*tail)->punti = ((*tail)->punti) + punti;
}

void cancella_nome(lista_turni *tail) //Permette di rendere nulla la risposta nomi di un utente, se questo ha commesso una scorrettezza.
{
     (*tail)->nomi[0] = '\0'; //svuoto la stringa nomi.
     
}
void cancella_cosa(lista_turni *tail)//Permette di rendere nulla la risposta cose di un utente, se questo ha commesso una scorrettezza.
{
     (*tail)->cose[0] = '\0'; //svuoto la stringa cose
}
void cancella_citta(lista_turni *tail) //Permette di rendere nulla la risposta citta di un utente, se questo ha commesso una scorrettezza.
{
     (*tail)->citta[0]= '\0'; //svuoto la stringa citta
}

int compara_nomi(lista_turni *tail1, lista_turni *tail2) //compara le stringhe nomi di due nodi passati alla funzione.
{
    if(*tail1 == *tail2)
   {
     
       return -2; //In realtà questo controllo non serve perchè viene effettuato a monmte dalla funzione calcola_punteggio presente in partita.c
   }
   
    char vuota[1] = "\0"; //Imposto una stringa una stringa di riferimento vuota.
   
   //Mi munisco di puntatori di appoggio.
   lista_turni cerca1;
   cerca1 = *tail1;
   lista_turni cerca2;
   cerca2 = *tail2;
   
   int x = -2; //pongo l'intero x a un valore neutro per la funzione.
   
   
   
   if((x = strcmp(cerca1->nomi, vuota)) == 0)
    {
        
        return -1; //Se la stringa del giocatore 1 è vuota restituisco -1.
    }
    
         
        if((x = strcmp(cerca2->nomi, vuota)) == 0)
        {
       
            return 2; //Se la stringa del secondo giocatore è vuota restituisco 2.
        }
        
        x = strcmp(cerca1->nomi, cerca2->nomi);
        
        if(x == 0)
        {
            return 0; //Se le due stringhe sono uguali restituisco 0
        }
        else
        {
            return 1; //Altrimenti 1.
        }
    
}

int compara_cose(lista_turni *tail1, lista_turni *tail2) //Medesimo ragionamento della funzione nomi.
{
  
    if(*tail1 == *tail2)
   {
       
       return -2;
   }
   
    char vuota[1] = "\0";
    lista_turni cerca1;
   cerca1 = *tail1;
   lista_turni cerca2;
   cerca2 = *tail2;
   int x = -2;
   if((x = strcmp(cerca1->cose, vuota)) == 0)
    {
       
        return -1;
    }
    else
    {
        
        if((x = strcmp(cerca2->cose, vuota)) == 0)
        {
        
            return 2;
        }
        
        x = strcmp(cerca1->cose, cerca2->cose);
        
        if(x == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
int compara_citta(lista_turni *tail1, lista_turni *tail2) //
{
   
    if(*tail1 == *tail2)
   {
       
       return -2;
   }
   
    char vuota[1] = "\0";
    lista_turni cerca1;
   cerca1 = *tail1;
   lista_turni cerca2;
   cerca2 = *tail2;
   int x = -2;
   if((x = strcmp(cerca1->citta, vuota)) == 0)
    {
        return -1;
    }
    else
    {
         
        if((x = strcmp(cerca2->citta, vuota)) == 0)
        {
            return 2;
        }
        
        x = strcmp(cerca1->citta, cerca2->citta);
        
        if(x == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
   
void cancella_lista_turni(lista_turni *head, lista_turni *tail)
{
    //Mi munisco di due puntatori di appoggio che chiamo precedente(p) e successivo (s) e li faccio puntare alla testa della lista.
    
    lista_turni s = *head;
    lista_turni p = *head;
    
    

    
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

    
        
        
        
    
