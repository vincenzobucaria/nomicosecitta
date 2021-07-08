#include "giocatori.h"


struct nodo_classifica 
{ 
    int punteggio; 
    int partite; 
    int vittorie; 
    lista_giocatori giocatore; 
   struct nodo_classifica *next; 
}; 

typedef struct nodo_classifica* lista_classifica; 

lista_classifica crea_lista_classifica(); //Restituisce un puntatore a NULL. 

void inserisci_utente_classifica(lista_classifica *head, lista_giocatori head2, char nome[]); //Permette di inserire un giocatore nella classifica. 

void cancella_utente_classifica(lista_classifica *head, char nome[]); //Permette di rimuovere dalla classifica un giocatore. 

void modifica_punteggio_utente(lista_classifica *head, char nome[], int punti); //Permette di modificare il punteggio associato ad un utente. 

void modifica_nome_classifica(lista_classifica *head, lista_giocatori *head2, char nome[], char nuovo_nome[]); //Viene invocata quando vi è da eseguire un cambio di username. 

void incrementa_vittorie_utente(lista_classifica *head, char nome[]); //Permette di aumentare di un'unità il numero di vittorie di un giocatore. 

void incrementa_partite_utente(lista_classifica *head, char nome[]); //Permette di aumentare di un'unità il numero di partite giocate da un giocatore. 

int is_empty_classifica(lista_classifica *head); //Controlla se la lista è vuota. Se lo è restituisce 1, 0 altrimenti. 

void stampa_classifica(lista_classifica *head); //Permette di stampare a schermo la lista_classifica.  

void cancella_lista_classifica(lista_classifica *head);

void salva_classifica(lista_classifica *head);

void carica_classifica(lista_classifica *head, lista_giocatori *head2);


