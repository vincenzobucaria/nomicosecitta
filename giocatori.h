#include <stdio.h>
#include <stdlib.h>

struct nodo_giocatori  
{ 
    char nome[16]; 
    char psw[16]; 
    struct nodo_giocatori* next;  
}; 

typedef struct nodo_giocatori* lista_giocatori; 

lista_giocatori crea_lista_giocatori(); //Restituisce un puntatore a NULL 

int registra(lista_giocatori *head, char nome[], char psw[]); //Permette di registrare un giocatore. Restituisce 1 se la registrazione è avvenuta correttamente, 0 altrimenti. 

int login(lista_giocatori *head, char nome[], char psw[]); //Permette all'utente di effettuare il login. Restituisce 1 se il login è avvenuto correttamente, 0 altrimenti. 

void elimina_giocatore(lista_giocatori *head, char nome[]); //Permette di eliminare l’account di un giocatore. 

lista_giocatori esiste_giocatore(lista_giocatori *head, char utente[]); //Controlla se un utente è presente in lista. Se lo ne restituisce il puntatore al nodo, altrimenti NULL. 

int is_empty_giocatore(lista_giocatori *head); //Controlla se la lista è vuota, restituisce 1 se lo è, 0 altrimenti. 

void modifica_nome_giocatore(lista_giocatori *head, char nome[], char nuovo_nome[]); //Permette di modificare l’username di un giocatore. 

void modifica_password_giocatore(lista_giocatori *head, char nome[], char nuova_psw[]); //Permette di modificare la psw di un giocatore. 

void stampa_nome(lista_giocatori node); //Permette di stampare a schermo il nome di un giocatore

void stampa_lista(lista_giocatori head);

void cancella_lista_giocatori(lista_giocatori *head);
