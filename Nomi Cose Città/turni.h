#include <stdlib.h>

struct nodo_turni //Struttura del nodo della lista secondaria 

{ 

    char nomi[15]; 

    char cose[15]; 

    char citta[15]; 

    int punti; 

    struct nodo_turni* next; 

}; 

typedef struct nodo_turni *lista_turni; 

lista_turni crea_lista_turni(); //Restituisce un puntatore a NULL 

  

void inserisci_elementi(lista_turni *head, lista_turni *tail, char nome[], char cosa[], char citta[]); //Permette di associare ad un giocatore i nomi, le cose e le città da lui inserite. 

  

void inserisci_punti_turno(lista_turni *tail, int punti); //permette di aggiornare/inserire i punti ad un giocatore nel contesto del singolo (e dell’ultimo) turno. 

  

int compara_nomi(lista_turni *tail1, lista_turni *tail2); //Scorre le liste fino all’ultimo nodo, dunque compara i char *nomi contenuti nei due nodi. Restituisce 0 se i due elementi sono diversi, 1 altrimenti. 

int compara_cose(lista_turni *tail1, lista_turni *tail2); //Scorre le liste fino all’ultimo nodo, dunque compara i char *cose contenuti nei due nodi. Restituisce 0 se i due elementi sono diversi, 1 altrimenti. 

int compara_citta(lista_turni *tail1, lista_turni *tail2); //Scorre le liste fino all’ultimo nodo, dunque compara i char *citta contenuti nei due nodi. Restituisce 0 se i due elementi sono diversi, 1 altrimenti. 

 

 

  

void cancella_nome(lista_turni *tail); //Permette di cancellare l’ultimo nome inserito da un utente 

void cancella_cosa(lista_turni *tail); //Permette di cancellare l’ultima cosa inserita da un utente 

void cancella_citta(lista_turni *tail); //Permette di cancellare l’ultima città inserita da un utente 

   

void cancella_lista_turni(lista_turni *head, lista_turni *tail); //De-alloca tutti i nodi e fa puntare a NULL il puntatore alla testa della lista. 
