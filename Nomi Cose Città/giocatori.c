#include "giocatori.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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


lista_giocatori crea_lista()
{
    return NULL;
}


void stampa_nome(lista_giocatori node) //Permette di stampare a schermo il nome del giocatore del nodo passato alla funzione.
{

    printf(bianco"  %s", node->nome);
}




lista_giocatori esiste_giocatore(lista_giocatori *head, char utente[]) //Permette di verificare se un utente è presente in lista.
{
    //Mi munisco di due puntatori ausiliari.
    lista_giocatori cerca;
    cerca = *head;
    
    
    
    while((cerca!=NULL) && (strcmp(cerca->nome, utente)!= 0)) //Scorro la lista finchè non trovo il nodo del giocatore cercato, la ricerca avviene sulla base del nome.
    {
        
         if(strcmp(cerca->nome, utente)>0)
         return NULL;
        
        cerca = cerca->next; 
        
        //Qui ha senso ottimizzare la ricerca, interrompendola prima se la strcmp restituisce un valore maggiore di 0. In tal caso significherebbe che cerca->nome è lessicograficamente "maggiore" rispetto la stringa utente e poichè la lista giocatori è ordinata, ciò vuol dire che quell'utente cercato non è presente in lista. //In altre funzioni non avrebbe senso implementare tale ottimizzazione, poichè si è certi al 100% che l'utente già esista.
        
        
        
        
    }
    
    if(cerca!=NULL) //Se il giocatore è in lista ne restituisco il puntatore al nodo.
    {
        return cerca;
    }
    else
    {
        return NULL; //Altrimenti restituisco NULL.
    }
}

int is_empty_giocatore(lista_giocatori *head) //Permette di vedere se la lista è vuota o meno.
{
	//Mi munisco di un puntatore ausiliario, anche se in realtà non è necessario. Ho deciso di passare alla funzione un doppio puntatore per questioni di uniformità.
	
	lista_giocatori cerca;
	cerca = *head;
	
	if(cerca == NULL)
	{
	return 1; //Se la lista è vuota e dunque la testa punta a NULL, restituisco 1.
	}

	else
	{
	return 0; //Altrimenti 0.
	}

}

int registra(lista_giocatori *head, char nome[], char psw[]) //Permette di inserire ordinatamente un giocatore (basandosi sul nome) in lista giocatori.
{
   
   //Mi munisco di due puntatori ausiliari
   
   lista_giocatori r = *head;
   lista_giocatori q = *head;
   
   lista_giocatori new_node; 
   new_node = (lista_giocatori)malloc(sizeof(struct nodo_giocatori)); //E alloco dinamicamente il nuovo nodo da inserire in lista.
       
   
    strcpy(new_node->nome, nome); //Popolo i campi nome e psw del nuovo nodo, servendomi della strcpy.
    strcpy(new_node->psw, psw);
    
    
    while((q!=NULL) && (strcmp(q->nome, new_node->nome)<0)) //Effettuo un inserimento ordinato, per maggiori dettagli consulta il file classifica.c
    {
     r = q;
     q = q->next;
    }
    
    if(q==*head)
    {
        new_node->next = *head;
        *head = new_node;
    }
        else
        {
            r->next = new_node;
            new_node->next = q;
        }
  
}

int login(lista_giocatori *head, char nome[], char psw[]) //Permette ad un utente di effettuare il login. Restituisce 1 in caso di esito positivo, 0 altrimenti.
{
    //Mi munisco di un puntatore ausiliario
    
    lista_giocatori cerca;
    cerca = *head;
   
    while((cerca!=NULL) && (strcmp(cerca->nome, nome)!= 0)) //Cerco il nodo dell'utente interessato.
    {
        cerca = cerca->next;
    }
 
    
        
 if(strcmp(cerca->psw, psw) == 0) //Confronto dunque la password passata alla funzione e quella presente nel nodo del giocatore.
    {
     return 1; //Se le due combaciano restituisco 1, il login è andato a buon fine.
    }
        else
        {
            return 0; //Altrimenti restituisco 0.
        }
}

void elimina_giocatore(lista_giocatori *head, char nome[]) //Permette di eliminare un giocatore dalla lista giocatori. Il ragionamento è il medesimo di quello fatto nel file classifica.c.
{
 
     
    lista_giocatori r = *head; 
    lista_giocatori q = *head; 
    
   
    while ((q != NULL) && (strcmp(q->nome, nome)!=0))
    {
        r = q;
        q = q->next;
    }
    
    
    if (q==*head)
    {
    (*head) = (*head)->next;
    }
    else
    {
       r->next = q->next;
    }
   
   free(q);
   
    
}

void modifica_nome_giocatore(lista_giocatori *head, char nome[], char nuovo_nome[]) //Permette di modificare l'username di un utente. Poichè la lista è ordinata per nome, tale operazione si traduce in una cancellazione e re-inserimento ordinato.
{
    lista_giocatori cerca;
    cerca = *head;
    
    
    
    while((cerca!=NULL) && (strcmp(cerca->nome, nome)!= 0)) //Cerco il nodo del giocatore interessato
    {
        cerca = cerca->next;
    }
    
   registra(head, nuovo_nome, cerca->psw); //Invoco la funzione registra per inserire nuovamente in lista il giocatore col nuovo username.
   //La cancellazione del vecchio nodo è eseguita mediante la funzione elimina_giocatore invocata nel main.
}

void modifica_password_giocatore(lista_giocatori *head, char nome[], char nuova_psw[]) //permette di modificare la psw di un utente.
{
    //Puntatore ausiliario
    lista_giocatori cerca;
    cerca = *head;
    
    
    
    while((cerca!=NULL) && (strcmp(cerca->nome, nome)!= 0)) //Cerco il nodo del giocatore interessato
    {
        cerca = cerca->next;
    }
   
   strcpy(cerca->psw, nuova_psw); //Modifico la sua password mediante una strcpy (copiando nel campo psw del nodo la stringa nuova_psw passata alla funzione).
}

void cancella_lista_giocatori(lista_giocatori *head) //Permette di deallocare tutti gli elemetni di questa struttura dati. Il ragionamento è il medesimo di quello descritto nel file classifica.c
{
    lista_giocatori s = *head;
    lista_giocatori p = *head;
    
    
    while(s!=NULL)
    {
        p = s; 
        s = s->next; 
       
        free(p);
    }
    
    
    free(s);
    
}
