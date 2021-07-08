#include "partita.h"

struct nodo_classifica_partita 

    { 

        lista_partita giocatore; 

        struct nodo_classifica_partita* next; 

    }; 

  

typedef struct nodo_classifica_partita* classifica_partita; 

  

classifica_partita crea_classifica_partita(); //Inizializza la lista classifica_partita, restituisce un puntatore a NULL. 

  

void inserisci_classifica_partita(classifica_partita *head, lista_partita *head2, char nome[]); //Inserisce ordinatamente (per punteggio) tutti i giocatori che hanno preso parte alla partita nella classifica_partita. 

 

char* dai_nome_vincitore(classifica_partita *head); //restituisce il nome del vincitore. 

 

void stampa_classifica_partita(classifica_partita *head); //Stampa a schermo la classifica della partita. 

  

void cancella_classifica_partita(classifica_partita *head); //De-alloca tutti i nodi e fa puntare a NULL la testa della lista. 
