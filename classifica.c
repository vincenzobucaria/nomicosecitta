#include "classifica.h"
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

lista_classifica crea_lista_classifica()
{
    return NULL; //Inizializzo la lista restituendo un puntatore a NULL.
}

int is_empty_classifica(lista_classifica *head) //Tale funzione verifica se la lista è vuota
{
    if(*head == NULL)
    {
        return 1; //Se lo è restituisce 1
    }
    else
    {
        return 0; //Altrimenti 0.
    }
}



void inserisci_utente_classifica(lista_classifica *head, lista_giocatori head2, char nome[]) //Permette di inserire un utente in classifica, effettuando inserimenti in testa o in coda.
{
    lista_classifica new_node;
    new_node = (lista_classifica)malloc(sizeof(struct nodo_classifica)); //Alloco dinamicamente la memoria mediante una malloc
    
    //Popolo i campi del nodo_lista.
    new_node->punteggio = 0;
    new_node->partite = 0;
    new_node->vittorie = 0;
    new_node->giocatore = esiste_giocatore(&head2, nome);
    new_node->next = NULL;
    
    if(*head == NULL) //Se la lista è vuota inserisco in testa
        {
            *head = new_node;
        }
   else //Altrimenti in coda.
    {
      
       lista_classifica cerca;
       cerca = *head;
           while(cerca->next!=NULL)
               {
                   cerca = cerca->next;
               }
           cerca->next = new_node;
    }
}

void modifica_punteggio_utente(lista_classifica *head, char nome[], int punti) //Permette di modificare il punteggio di un utente. Poichè la lista deve essere ordinata per punteggio, tale funzione si occuperà di cancellare il nodo del giocatore col vecchio punteggio e di crearne uno nuovo inserito ordinatamente in lista.
{
    //Cerco il nodo del giocatore a cui devo aggiornare il punteggio
    
    lista_classifica cerca;
    cerca = *head;
    
    
    
    while((cerca!=NULL) && (strcmp(cerca->giocatore->nome, nome)!= 0)) //Finchè vi sono nodi e la stringa nome passata all'utente non combacia con la stringa nome presente nella sottolista giocatori non combaciano, scorro la lista. Lo scorrimento è necessario così da trovare il vecchio nodo_classifica del giocatore e copiarne i campi.
    {
        cerca = cerca->next;
    }
    
    if(cerca!=NULL)
    {
    //alloco due puntatori di appoggio
     
   
    //e alloco il nuovo nodo dinamicamente mediante una malloc.
    
    lista_classifica p; 
    p = (lista_classifica)malloc(sizeof(struct nodo_classifica)); 
   

    //Dunque lo popolo copiando i campi del vecchio nodo, ad eccezione del punteggio, cui sarà la somma del vecchio punteggio più l'intero punti passato alla funzione.
    
        p->giocatore = cerca->giocatore;
        p->punteggio = (cerca->punteggio) + punti;
        p->vittorie = cerca->vittorie;
        p->partite = cerca->partite;
        cancella_utente_classifica(head, nome);
        lista_classifica r = *head; 
        lista_classifica q = *head;
        
        
        
    //Adesso cerco la posizione esatta in cui inserire il nuovo nodo.
    
    while ((q != NULL) && (q->punteggio > p->punteggio)) //I due puntatori di appoggio punteranno a nodi adiacenti e scorreranno la lista finchè il nodo puntato da q (cui si trova davanti) avrà nel campo punteggio un intero maggiore del campo punteggio presente nel nodo puntato da p (ovvero il puntatore al vecchio nodo). Chiaramente se lo scorrimento giunge a fine lista l'inserimento sarà in coda, nel caso opposto, in testa.
    {
        r = q;
        q = q->next;
    }
    
    //Ins in testa.
    if(q==*head)
    {
        p->next = *head;
        *head=p;
    }
    
    //Ins in posizione intermedia
    else{
       
        r->next = p;
        p->next = q;
    }
    //tutto e' andato a buon fine
    
    return;
}
}

void cancella_utente_classifica(lista_classifica* head, char nome[]) //Tale funzione permette di cancellare il nodo di un utente.
{
    //Anche qui mi munisco di due puntatori di appoggio che punteranno a due nodi adiacenti.
   
    lista_classifica r = *head; 
    lista_classifica cerca = *head; 
   
    
    while((cerca!=NULL) && (strcmp(cerca->giocatore->nome, nome)!= 0)) //Scorro la lista finchè non trovo il nodo del giocatore da eliminare, la ricerca è basata sul nome.
    {
        
        r = cerca;
        cerca = cerca->next;
    }
    
    //Se il nodo da cancellare è il primo la testa della lista dovrà puntare al nodo successivo alla vecchia testa (che verrà eliminata)
    if (cerca==*head)
    (*head) = (*head)->next;
    
    //Se sono in posizione intermedia il nodo precedente a cerca dovrà puntare al nodo successivo a cerca.
    else
        r->next = cerca->next; //Se cerca dovesse essere l'ultimo nodo questa operazione andrebbe comunque bene, poichè considerando che cerca->next punterà a NULL, ci ritroveremmo nella situazione in cui r->next punterà anche'esso a NULL.
        
        free(cerca);
    //Infine dealloco il nodo cerca mediante una free ed esco dalla funzione. 
}


void modifica_nome_classifica(lista_classifica *head, lista_giocatori *head2, char nome[], char nuovo_nome[]) 
{
//Viene utilizzata per cambiare il nome utente di un giocatore e serve ad aggiornare il puntatore al giocatore presente nel generico nodo di questa struttura dati, nonchè a chiamare la funzione modifica_nome_giocatore.
 
    lista_classifica cerca;
    lista_giocatori giocatori;
    giocatori = *head2;
    cerca = *head;
    
    while((cerca!=NULL) && (strcmp(cerca->giocatore->nome, nome)!= 0)) //Seguo lo stesso ragionamento delle funzioni precedenti per trovare il nodo dell'utente interessato.
    {
        cerca = cerca->next;
    }
    
    if(cerca!=NULL) //Se il giocatore è stato trovato proseguo come quanto segue:
    {
        modifica_nome_giocatore(&giocatori, nome, nuovo_nome); //Provvedo a cambiare il nome all'utente mediante questa funzione.
        cerca->giocatore = esiste_giocatore(&giocatori, nuovo_nome); //Dunque aggiorno il nodo giocatore, facendolo puntare al nuovo nodo ((perchè il cambio di username comporta una cancellazione in lista giocatori ed un inserimento ordinato per nome).
    }
    
    *head2 = giocatori; //La testa della lista_giocatori deve puntare a giocatori, poichè potrebbe essere cambiata a seguito del cambio di username.
}


void incrementa_partite_utente(lista_classifica *head, char nome[]) //Permette di incrementare di un'unità il numero di partite di un utente.
{ 

lista_classifica cerca; //Puntatori di appoggio
cerca = *head;
    
     
    
    while((cerca!=NULL) && (strcmp(cerca->giocatore->nome, nome)!= 0)) //Cerco il nodo dell'utente interessato
    {
        cerca = cerca->next;
    }
    
    if(cerca!=NULL) //Se lo trovo
    {
       cerca->partite = (cerca->partite) + 1; //Incremento le sue partite di 1.
    }
}

void incrementa_vittorie_utente(lista_classifica *head, char nome[]) //Permette di incrementare di un'unità il numero di vittorie di un utente.
{ 
lista_classifica cerca; //Puntatori di appoggio
cerca = *head;
    
      int x;
    
    while((cerca!=NULL) && (x = strcmp(cerca->giocatore->nome, nome)!= 0)) //Cerco il nodo dell'utente interessato
    {
        cerca = cerca->next;
    }
    
    if(cerca!=NULL)
    {
       cerca->vittorie = (cerca->vittorie) + 1; //Se lo trovo incremento le sue vittorie di 1.
    }
}

void stampa_classifica(lista_classifica *head) //Permette di stampare a schermo la classifica generale.
{
     printf("\n"); //Un semplice "vai a capo"
     int x = 1; 	//Variabile contatore ((serve per l'elenco numerato).
     lista_classifica cerca; //Puntatore di appoggio.
     cerca = *head;
     
     while(cerca!=NULL) //Scorro la lista
    {
        if(x==1 && cerca->punteggio!=0) //Al primo giocatore riservo una stampa speciale, indicante che lui è il vincitore.
        {
        printf("\t\t");
        stampa_nome(cerca->giocatore);
        printf(bianco" è il campione, con ben %d punti!\n\n\n", cerca->punteggio); //stampa il l'i-esimo elemento
        }
        printf("\t\t");
 
        printf("\n\t %d", x); //Elenco numerato.
        stampa_nome(cerca->giocatore); //Stampo il nome del giocatore.
        printf(", %d punti, %d vittorie, %d partite", cerca->punteggio, cerca->vittorie, cerca->partite); //Stampo le statistiche del giocatore.
        
       
        
        cerca = cerca->next; 
        x++;
    }
}



void salva_classifica(lista_classifica *head)
{
	FILE* f = fopen("classifica.txt", "w"); //Viene creato un file.txt ed aperto in scrittura.
	if(f == NULL)
	{
	printf("Errore nella scrittura della classifica");
	exit(EXIT_SUCCESS);
	}
	
	lista_classifica lista;
	lista = *head;
	
	while(lista!=NULL)
	{
		fprintf(f, "%s %s %d %d %d \n", lista->giocatore->nome, lista->giocatore->psw, lista->punteggio, lista->partite, lista->vittorie);
		lista = lista->next;
	}
	fclose(f);
}

void carica_classifica(lista_classifica *head, lista_giocatori *head2)
{
	FILE*f = fopen("classifica.txt", "r"); //Gli imposto soltanto i permessi di lettura
	if(f == NULL)
	{
	printf("Errore nell'apertura della classifica");
	exit(EXIT_SUCCESS);
	}
	
	lista_classifica lista;
	lista_giocatori lista2;
	lista = *head;
	lista2 = *head2;
	char nome[16];
	char psw[16];
	
	int punteggio;
	int partite;
	int vittorie;
	
	
	
	while(fscanf(f, "%s %s %d %d %d \n", nome, psw, &punteggio, &partite, &vittorie) != EOF)
	{
		registra(&lista2, nome, psw);
		inserisci_utente_classifica(&lista, lista2, nome);
		modifica_punteggio_utente(&lista, nome, punteggio);
		for(int i = 0; i<vittorie; i++)
		{
		incrementa_vittorie_utente(&lista, nome);
		}
		for(int i = 0; i<partite; i++)
		{
		incrementa_partite_utente(&lista, nome);
		}
	}
		
fclose(f);
*head = lista;
*head2 = lista2;
}
		



void cancella_lista_classifica(lista_classifica *head) //Pulisce e dealloca dalla memoria tutti gli elementi di questa struttura dai.
{
   //Mi munisco di due puntatori ausiliari.
   
    lista_classifica s = *head;
    lista_classifica p = *head;
    
    
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
    
    
