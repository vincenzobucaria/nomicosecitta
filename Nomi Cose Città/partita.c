#include "partita.h"
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






lista_partita crea_partita() //Inizializzo la lista restituendo un puntatore a NULL.
{
    return NULL;
}

void inserisci_giocatore_partita(lista_partita *head, char nome[]) //Permette di inserire ordinatamente un giocatore (per nome) nella lista_partita. Il ragionamento è uguale a quello presente nel file giocatori.c
{
   lista_partita r = *head;
   lista_partita q = *head;
   
   lista_partita new_node;
   new_node = (lista_partita)malloc(sizeof(struct nodo_partita));
        
       

    strcpy(new_node->nome, nome);
    new_node->punteggio = 0;
    new_node->turni_head = crea_lista_turni();
    new_node->turni_tail = crea_lista_turni();
    
    
    while((q!=NULL) && (strcmp(q->nome, new_node->nome)<0))
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
    

lista_partita esiste_giocatore_partita(lista_partita *head, char nome[]) //Permette di verificare se un utente è in lista. Il ragionamento è uguale a quello presente nel file giocatori.c, è da sottolineare però che tale ricerca non è ottimizzata (a differenza di quella presente in giocatori.c) in quanto si ha la certezza che l'utente cercato sia già in lista (e questa è ordinata).
{
   lista_partita cerca;
    cerca = *head;
    

    while((cerca!=NULL) && (strcmp(cerca->nome, nome)!= 0))
    {
        cerca = cerca->next;
    }
    
    if(cerca!=NULL)
    {
        return cerca;
    }
    else
    {
        return NULL;
    }
} 

char* dai_nome(lista_partita *head, int giocatore) //Restituisce il nome di un giocatore presente nella posizione "giocatore" della lista.
{
    lista_partita cerca;
    cerca = *head;
    for(int i = 0; i<giocatore; i++) //Si effettua lo scorrimento della lista giocatori volte.
    {
        cerca = cerca->next;
    }
    return cerca->nome; //si restitusce dunque il nome.
}

int dai_punti(lista_partita *head, int giocatore) //Restituisce il punteggio di un giocatore presente in posizione "giocatore" nella lista.
{
    lista_partita cerca;
    cerca = *head;
    for(int i = 0; i<giocatore; i++)
    {
        cerca = cerca->next;
    }
    return cerca->punteggio;
}


void cancella(lista_partita *head, char utente[], int elemento) //Permette di cancellare il nome, la cosa, o la città inserita da un utente.
{
   
   //Mi servo di un puntatore di appoggio
    lista_partita cerca;
    cerca = *head;
    
    
     while((cerca!=NULL) && (strcmp(cerca->nome, utente)!= 0)) //Cerco il nodo del giocatore interessato
    {
        cerca = cerca->next;
    }
    
    if(cerca!=NULL) //Una volta trovato procedo come quanto segue:
        {
            
            //Mi munisco di un altro puntatore ausiliario.
            lista_turni coda;
            coda = cerca->turni_tail;
            
            switch(elemento) //In base all'intero elemento passato alla funzione posso compiere tre azioni.
                {
                case 1:
                cancella_nome(&coda); 
                break;
                
                case 2:
                cancella_cosa(&coda);    
                break;
                
                case 3:
                cancella_citta(&coda);
                break;
                }
                
     cerca = *head; //Faccio ri-puntare cerca alla testa della lista.
     
          while(cerca!=NULL)
            {
                cerca->punteggio = 0; //Resetto il punteggio di tutti gli utenti, dovrà essere infatti ri-calcolato.
                cerca->turni_tail->punti = 0;
                cerca = cerca->next;
            }
    
        }
        else
        {
            return;
        }
}


void gioca_turno(lista_partita *head, int turno) //Permette agli utenti di giocare il turno.
{
    
    
    
    
    int x = turno-1; //Mi munisco di questo intero per poter stampare correttamente la tabella, infatti questa dovrà stampare il turno precedente e non quello attuale.

    lista_partita cerca; //Mi munisco di due puntatori di appoggio.
    lista_partita stampa;
   
   cerca = *head;
   stampa = *head;
   
   char nome[17]; 
   char cosa[17];  
   char citta[17]; 
   
   stampa_tabella(&cerca, x);
   while(cerca!=NULL)
   {
    //Per ogni utente agisco come quanto segue:
    do
    {
	    printf("\n\n\t\t %s, inserisci il nome: ", cerca->nome); //Permetto all'utente di inserire il nome
	    fgets(nome, 100, stdin); //La funzione fgets permette all'utente di lasciare anche vuota questa risposta. Uso una lunghezza ampia così da non provocare uno stack smashing se qualcuno provasse ad inserire una stringa lunga.
	    stampa_tabella(&stampa, x);
	  
	    nome[strlen(nome)-1]='\0';
	}while(strlen(nome)>15); //Se la risposta supera i 15 caratteri viene ripetuto il processo.
   
    do //Azione identica alla precedente.
    {
    stampa_tabella(&stampa, x);
    printf("\n\n\t\t %s, inserisci la cosa ", cerca->nome);
    fgets(cosa, 100, stdin);
    
	    cosa[strlen(cosa)-1]='\0';
    }while(strlen(cosa)>15);
   
    do
    {
    stampa_tabella(&stampa, x);
    printf("\n\n\t\t %s, inserisci la citta: ", cerca->nome);
    fgets(citta, 100, stdin);
    
	    citta[strlen(citta)-1]='\0';
    }while(strlen(citta)>15);
    stampa_tabella(&stampa, x);

    inserisci_elementi((&cerca->turni_head), (&cerca->turni_tail), nome, cosa, citta); //Inserisco le risposte date dall'utente nella sottolista turni.
      
    
       cerca = cerca->next; //Scorro la lista.
      
       
   }
   
   
}


void calcola_punteggio(lista_partita *head)
{
    
    //Mi munisco di puntatori e di interi di appoggio.
    lista_partita p;
    lista_partita q;
    lista_partita r;
    int x;
    int y;
    int z;
    p = *head;
    q = *head;
    r = *head;
    
    //Il punteggio viene calcolato confrontando nodo per nodo le stringhe inserite dagli utenti. Dunque il funzionamento è il seguente:
   
    
    
    
    while(p!=NULL) //Scorro p ad ogni ciclo.
        {
                q = r; //Q punterà ad r, cioè alla testa della lista.
                
                x = -2; //Pongo gli interi a valori non interessati dalla funzione.
                y = -2;
                z = -2;
                
                while(q!=NULL) //Scorro q fino alla fine della lista.
                {
                   
                    if(p!=q) //Se p e q sono diversi procedo, altrimenti significherebbe confrontare due nodi uguali.
                    {
                        
                    if(x != 0 && x != -1) //Se compara_nomi ha restituito 0 o -1 significa che sono stati trovati elementi uguali oppure che il giocatore associato a p non ha inserito nulla. In tal caso non è necessario riconfrontare gli elementi di p con quelli di un altro giocatore, poichè il punteggio sarà rispettivamente 5 oppure 0.
                    {
                        x = compara_nomi(&p->turni_tail, &q->turni_tail); //Mi avvalgo della funzione compara_nomi, che restituirà 2 se giocatore associato a q non ha inserito nulla, -1 se il giocatore associato a p non ha inserito nulla, 0 se gli elementi di p e q sono uguali e 1 se sono diversi.
                    }
                    
                    if(y != 0 && y != -1) //Si ripete il medesimo ragionamento, questa volta però per l'elemento cose.
                    {
                       
                        y = compara_cose(&p->turni_tail, &q->turni_tail);
                    }
                    
                    if(z != 0 && z != -1)
                    {
                        
                        z = compara_citta(&p->turni_tail, &q->turni_tail);
                    }
                    
                    if((x == -1 && y == -1 && z == -1) || (x == 0 && y == 0 && z == 0)) //Se tutte le stringhe inserite da p sono vuote non è necessario effettuare nuovamente il confronto con altri giocatori, stessa cosa vale se tutte le stringhe sono uguali a stringhe di altri utenti.
                    {
                        break;
                    }
                    }
                    q = q->next; //Ogni volta si scorre q così da confrontare il giocatore associato al puntatore p con tutti i giocatori (ad eccezione di se stesso, chiaramente).
                }
                
               
                
            switch(x)
                {
                    
                    case 0:	//Se il nome inserito dal giocatore puntato da p è uguale a quello di un altro giocatore puntato da q, allora il punteggio da associare a p sarà 5.
                    inserisci_punti_turno(&p->turni_tail, 5);
                    p->punteggio = p->punteggio + 5;
                    break;
                    
                    case 1: //Se il nome inserito dal giocatore puntato da p è esclusivo, allora il punteggio da associare sarà 10.
                    inserisci_punti_turno(&p->turni_tail, 10);
                    p->punteggio = p->punteggio + 10;
                     break;
                    
                    
                    case 2: //Se p è stato l'unico ad inserire un nome, il punteggio da associare sarà 20.
                   
                    inserisci_punti_turno(&p->turni_tail, 20);
                     p->punteggio = p->punteggio + 20;
                      break;
                }
                
                //Il ragionamento si ripete per tutte le altre categorie (cose, città).
                
                switch(y)
                {
                   case 0:
                    inserisci_punti_turno(&p->turni_tail, 5);
                    p->punteggio = p->punteggio + 5;
                     break;
                    
                    case 1:
                    inserisci_punti_turno(&p->turni_tail, 10);
                    p->punteggio = p->punteggio + 10;
                    
                    break;
                    
                    case 2:
                        p->punteggio = p->punteggio + 20;
                    inserisci_punti_turno(&p->turni_tail, 20);
                     break;
                }
                switch(z)
                {
                    case 0:
                    inserisci_punti_turno(&p->turni_tail, 5);
                    p->punteggio = p->punteggio + 5;
                     break;
                    case 1:
                    inserisci_punti_turno(&p->turni_tail, 10);
                    p->punteggio = p->punteggio + 10;
                    break;
                    
                    case 2:
                        p->punteggio = p->punteggio + 20;
                    inserisci_punti_turno(&p->turni_tail, 20);
                     break;
                }
                p = p->next; //scorro p di 1, così da cambiare il giocatore soggetto al calcolo del punteggio.
        }
}





void stampa_tabella(lista_partita *head, int turno) //Permette di stampare a schermo la tabella di gioco.
{
    
   
   system("clear");
   printf(blusfondo"\t                        NUOVA PARTITA                           \n\n"reset); //Viene stampata la parte superiore della tabella, a prescindere dal turno.
   
    printf(bianco"\tNOMI\t\t COSE\t\t   CITTA' \t GIOCATORE\n"reset);
    printf(bianco"\t\t  |\t\t    |\t\t      |\n");
  	 
     lista_partita cerca;
     cerca = *head;
     lista_turni back;
     
     back = cerca->turni_head;   
     
     
      
     int x = 0;
     
    
     for(x; x<turno; x++) //Se turno è maggiore di 0 si entra nel ciclo for
     {
        
         cerca = *head;
         
     while(cerca!=NULL) //Finchè non si è arrivati alla fine della lista, si scorre.
    {
      
        back = cerca->turni_head;
        for(int i = 0; i<x; i++) //Non viene effettuato lo scorrimento della lista secondaria se è il primo turno.
        {
          
            cerca->turni_head = cerca->turni_head->next;
        } 
        
        printf(bianco"\t\t  |\t\t    |\t\t      |\n");
        printf(verde"  %-15s"bianco" | %-15s |"rosso" %-15s "bianco"| %-15s(%d)\n", cerca->turni_head->nomi, cerca->turni_head->cose,cerca->turni_head->citta, cerca->nome, cerca->turni_head->punti);
     
        
         cerca->turni_head = back;
        cerca = cerca->next; //continua a scorrere la lista
       
    
     }
    
}

}

void cancella_lista_partita(lista_partita *head)
{
    //Mi munisco di due puntatori di appoggio che chiamo precedente(p) e successivo (s) e li faccio puntare alla testa della lista.
    
    lista_partita s = *head;
    lista_partita p = *head;
    
    while(s!=NULL)
    {
        
        //Devo provvedere anche ad eliminare la sottolista turni
        
        
        
        p = s; 
        //Il puntatore "precedente" ragguingerà il puntatore "successivo"
        cancella_lista_turni(&(p->turni_head), &(p->turni_tail)); //Cancello la sottolista turni.
        s = s->next; //Il puntatore successivo scorrerà in avanti di un nodo
        
        //In tale maniera i due puntatori scorreranno tutta la lista, de-allocando di volta in volta il nodo puntato dal puntatore precedente.
        
        free(p);
    }
    
    //Una volta giunti all'ultimo nodo dealloco anche il nodo puntato da s.
    free(s);
   
}
        
    
    


