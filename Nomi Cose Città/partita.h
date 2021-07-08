#include "turni.h" 

  

struct nodo_partita 

{ 

    char nome[15]; 

    int punteggio; 

    lista_turni turni_head; 

    lista_turni turni_tail; 

    struct nodo_partita* next; 

}; 

  

typedef struct nodo_partita* lista_partita; 

  

lista_partita crea_partita(); //Restituisce un puntatore a NULL 

 

lista_partita esiste_giocatore_partita(lista_partita *head, char nome[]); //verifica se un utente è presente in lista. Restituisce il puntatore al suo nodo se lo è, altrimenti NULL. 

  

void inserisci_giocatore_partita(lista_partita *head, char nome[]); //Inserisce per ordine alfabetico (prendendo per riferimento il nome) un nuovo nodo_partita nella lista_partita. 

  

void gioca_turno(lista_partita *head, int turno);  //Permette di associare ai giocatori i nomi, le cose e le città da loro inserite.  

 

void cancella(lista_partita *head, char utente[], int elemento); //Permette di cancellare l'ultimo elemento  (nome, cosa o città) inserito da un giocatore. 

 

void stampa_tabella(lista_partita *head, int turno); //Permette di stampare a schermo la tabella della partita.  

  

char* dai_nome(lista_partita *head, int giocatore); //Permette di scorrere la lista giocatore volte e di restituire il “nome” del giocatore dell’ultimo nodo visitato. 

 

int dai_punti(lista_partita *head, int giocatore); //Permette di scorrere la lista giocatore volte e di restituire i punti del giocatore dell’ultimo nodo visitato. 

 

void calcola_punteggio(lista_partita *head); //Permette di calcolare il punteggio ottenuto dai giocatori.  

 
 

void cancella_lista_partita(lista_partita *head); //Svuota e cancella la lista primaria, dopo aver invocato la funzione cancella_lista_turni() contenuta nel file turni.h e aver svuotato la lista secondaria. 
