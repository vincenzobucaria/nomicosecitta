#include <stdio.h>
#include <stdlib.h>
#include "classifica.h"
#include "classifica_partita.h"
#include <string.h>
#include <time.h>
#define rosso    "\e[1;91m"
#define verde  "\e[1;92m"
//#define giallo  "\x1b[33m"
#define blu    "\x1b[34m"
#define fucsia"\x1b[35m"
#define ciano    "\x1b[36m"
#define reset   "\x1b[0m"
#define bianco "\e[1;97m"
#define ciano"\e[0;106m"
#define blusfondo "\e[0;104m"
#define giallosfondo "\e[43m"
#define verdesfondo"\e[0;102m"
#define biancosfondo "\e[0;107m"
#define rossosfondo "\e[0;101m"
char mov;


void stampa_menu() //Stampa a schermo l'interfaccia del menu' princiaple.
{
    system("@cls||clear");
    printf(reset);
    printf(verdesfondo"                                        ");
    printf(biancosfondo"                                        \n");
    printf(verdesfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "biancosfondo"  \n");
    printf(verdesfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "biancosfondo"  \n");
    printf(verdesfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "biancosfondo"  \n");
    printf(verdesfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "biancosfondo"  \n");
   printf(verdesfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "biancosfondo"  \n");
    printf(verdesfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "biancosfondo"  \n");
    printf(verdesfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "biancosfondo"  \n");
    printf(verdesfondo"  ");
      printf(reset);
    printf(bianco"\t\t\t        1) NUOVA PARTITA");
    printf(reset"\t\t\t      "biancosfondo"  \n");
       printf(verdesfondo"  ");
      printf(reset);
     printf(reset"\t\t\t\t\t\t\t\t\t      "biancosfondo"  \n");
    printf(verdesfondo"  ");
    printf(reset);
    printf(bianco"\t\t\t    2) VISUALIZZA CLASSIFICA");
    printf(reset"\t\t\t      "biancosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset);
    printf(bianco"\t\t\t      3) GESTISCI ACCOUNT");
    printf(reset"\t\t\t      "rossosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
    printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
     printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
      printf(rossosfondo"  ");
      printf(reset);
    printf(bianco"\t\t\t           4) ESCI");
    printf(reset"\t\t\t              "rossosfondo"  \n");
 printf(rossosfondo"  ");
    printf(reset"\t\t\t\t\t\t\t\t\t      "rossosfondo"  \n");
  printf(rossosfondo"                                                                                ");
  printf(reset);
}


void gestisci_account(lista_giocatori *head, lista_classifica *head2) //Tale funzione permette di gestire gli account utenti
{
    lista_giocatori giocatori;
    giocatori = *head;
    lista_classifica classifica;
    classifica = *head2;
    char username[16];   
    char psw[16];
    int tentativi = 0;
    char enter = '0';
    int flag = 0;
    char ch;
   
    if(is_empty_giocatore(&giocatori) == 1)     //Se nessun giocatore si è ancora registrato si procederà come quanto segue:
        {
                
        do //Questo do while permette all'utente di tornare indietro se si è accorto di aver digitato male l'username.
            {
                do   //Imposto dei controlli sulle stringhe in ingresso: queste imparticolare devono essere composte da almeno 3 caratteri e fino ad un massimo di 15 caratteri. 
                        //Inoltre è possibile tornare immediatamente al menu' principale premendo INVIO.
                    {
                        system("@cls||clear");
                        printf(reset);
                        printf(" \n\n\n");
                        printf("                                                    \n  ");
                        printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                        printf(bianco"\t\t\n\n\n\n\n\n");
                        printf("\t\t   Ops, sembra che non ci sia ancora nessun     \n");
                        printf("\t\t   giocatore registrato!\n\n");
                    
                        printf("\t\t   inserisci il tuo nome per registrarti!\n");
                        printf("\t\t   (min. 3 caratteri e max. 15 caratteri)\n");
                    printf("\n\t       premi invece INVIO se desideri tornare indietro\n");
                        printf("\n\t\t Nome: "verde"");
                        
                        fgets(username, 100, stdin); //Mi mantengo largo con la lunghezza per evitare che un utente possa provocare uno stack smashing
                        if(username[0] == '\n')
                            return;
                        
                        username[strlen(username)-1]='\0'; 
                    }
                    while(strlen(username)<3 || strlen(username)>15);
                
                    do //Imposto i controlli in input anche qui e ovunque l'utente debba inserire delle stringhe.
                    {
                        system("@cls||clear");
                        printf(reset);
                        printf(" \n\n\n");
                        printf("                                                    \n");
                        printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                        printf(" \n\n\n\n                                                   \n");
                        printf("                                                    \n");
                        printf("                                                    \n");
                        printf(bianco"\t\t\tOk, "verde"%s"bianco" ci siamo quasi! \n\n", username);
                        printf("\t\t    Adesso digita attentamente la password!     \n");
                        printf("\t\t    (min. 3 caratteri e max. 15 caratteri)                    \n");
                        printf("                                                    \n");
                        printf("\n\t\t   premi invece INVIO per tornare indietro");
                        printf("                                                    \n");
                        printf("                                                    \n");
                        printf("\t\t Password: "verde"");
                        fgets(psw, 100, stdin);
                        if(psw[0] != '\n')
                           psw[strlen(psw)-1]='\0';  
                        
                    }
                    while((strlen(psw)<3 || strlen(psw)>15) && psw[0]!='\n');
            }while(psw[0] == '\n');
            
           registra(&giocatori, username, psw);
           inserisci_utente_classifica(&classifica, giocatori, username);
          
           *head2=classifica;
        }
            else //Altrimenti se la lista non è vuota si passa alla schermata di login classica.
                {
                    do //anche qui ho impostato vari controlli sulle stringhe in input ed ho implementato la possibilità di tornare indietro premendo INVIO
                    {
                        do
                        {
                            system("clear");
                            printf(reset);
                            printf(" \n\n\n");
                            printf("                                                    \n");
                            printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                            printf(" \n\n\n\n                                                   \n");
                            printf(bianco"\t\t   Ti trovi nella pagina di gestione account,\n");
                            printf("                                                    \n");
                            printf("\t\t Inserisci il tuo nome per loggarti/registrarti!         \n");
                            printf("\t\t     (min. 3 caratteri e max. 15 caratteri)         \n");
                            printf("\n\t\t    premi invece INVIO per tornare indietro                                                    \n");
                            printf("\b\t\t Nome: "verde);
                            
                            fgets(username, 100, stdin);
                            if(username[0] == '\n')
                                return;
                            
                            username[strlen(username)-1]='\0'; 
                        }
                        while(strlen(username)<3 || strlen(username)>15);
                        
                        if(esiste_giocatore(&giocatori, username) != NULL) //Se il giocatore è stato trovato all'interno della lista si passa al login
                        {
                                do      //Viene chiesto all'utente di immettere la psw finchè questa sarà più lunga di 3 caratteri e più corta di 15, premendo INVIO si torna indietro.
                                {  
                                    system("clear");
                                    printf(reset);
                                    printf(" \n\n\n");
                                    printf("                                                    \n");
                                    printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                                    printf(" \n\n\n\n                                                   \n");
                                    printf("                                                    \n");
                                    printf("                                                    \n");
                                    printf(bianco"\t\t\t     Bentornato,"verde" %s \n", username);
                                    printf(bianco"\t\t    Adesso digita attentamente la password!     \n");
                                    printf("\t\t\n                        \n");
                                    printf("                                                    \n");
                                    printf("\t\tSe invece non sei tu premi INVIO              \n");
                                    printf("                                                    \n");
                                    printf("                                                    \n");
                                    printf("\t\t Password: "verde"");
                                    fgets(psw, 100, stdin);
                                    if(psw[0] != '\n')
                                    psw[strlen(psw)-1]='\0'; 
                                }
                                while((strlen(psw)<3 || strlen(psw)>15) && psw[0]!='\n');
                        
                    
                
                    }
                    
                    
                        
                        else //Se invece l'utente non è presenta in lista si procede con la registrazione
                            {
                                do //Anche qui si chiede all'utente di immettere in input la psw, finchè questa sarà contemplata dai criteri di controllo.
                                {
                                    system("clear");
                                    printf(reset);
                                    printf(" \n\n\n");
                                    printf("                                                    \n");
                                    printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                                    printf(" \n\n\n\n                                                   \n");
                                    printf("                                                    \n");
                                    printf("                                                    \n");
                                    printf(bianco"\t\t\t     Benvenuto,"blu" %s \n", username);
                                    printf(bianco"\t\tdigita attentamente la password per registrarti!     \n");
                                    printf("\t             (min. 3 caratteri e max. 15 caratteri)                          \n");
                                    printf("                                                    \n");
                                    printf("\t\t    premi invece INVIO per tornare indietro              ");
                                    printf("                                                    \n");
                                    printf("                                                    \n");
                                    printf("\t\t Password: "verde"");
                                    fgets(psw, 100, stdin);
                                    if(psw[0]!='\n')
                                    psw[strlen(psw)-1]='\0'; 
                                    
                                   
                                }
                                while((strlen(psw)<3 || strlen(psw)>15) && psw[0]!='\n');
                                    if(psw[0]!='\n')
                                    {
                                    registra(&giocatori, username, psw); //Se la psw risulta idonea si passa alla registrazione
                                    inserisci_utente_classifica(&classifica, giocatori, username);   //E all'inserimento in classifica generale dell'utente.
                                    }
                            }
                    }while(psw[0]=='\n');
                }

                
                              
 flag = login(&giocatori, username, psw); //Viene invocata la funzione login per vedere se l'utente ha inserito la psw corretta.
                while(flag==0)
                {
                    do  //Se il login restituisce 0 la psw è errata, verrà dunque chiesto all'utente di re-inserire la psw per un massimo di tre volte.
                    {
                        system("clear");
                        printf(reset);
                        printf(" \n\n\n");
                        printf("                                                    \n");
                        printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                        printf(" \n\n\n\n                                                   \n");
                        printf("                                                    \n");
                        printf("                                                    \n");
                        printf(bianco"\t\t\t     Attenzione! \n");
                        printf("\t\tla password da te inserita è errata, ritenta!    \n");
                        printf("\t\t\n                             \n");
                        printf("                                                    \n");
                        printf("\t\t              \n");
                        printf("                                                    \n");
                        printf("                                                    \n");
                        printf("\t\t Password: "verde"");
                        fgets(psw, 100, stdin);
                        if(psw[0]!='\n')
                        psw[strlen(psw)-1]='\0'; 
                        tentativi++;
                        if(tentativi >=3)
                        {
                            return; //al terzo tentativo si esce dalla funzione gestisci account
                        }
                    }while(psw[0]=='\n');
                        flag = login(&giocatori, username, psw);
                        
                    }
                    
                    
                    char scelta[3]; //Variabile per la selezione dell'azione, ho scelto una char per poter sfruttare la fgets.
                    char nuovo_user[17];
                    char elimina_ins[30];
                    char elimina[30] = "voglioeliminareaccount"; 

                    int x = 1;
                    flag = 0;
                    
                    
                    while(x!=0)  //Viene stampato il menu' di selezione finchè x è diversa da 0
                    {
                    system("@cls||clear");
                    printf(reset);
                    printf(" \n\n\n\n");
                    printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                    printf(" \n\n\n\n");
                    printf(bianco"\t\t\t     Cosa desideri fare? \n");
                    printf("\n\n\t\t\t   1) Cambia nome utente\n \n \t\t\t   2) Cambia password \n \n\t\t\t   3) Elimina account");
                    printf("\n\n\t          Altrimenti premi INVIO per tornare al menu'");
                    printf(" \n\n\t\t\t\t   "verde);
                    fgets(scelta, 100, stdin);
                    if(scelta[0] == '\n') //Se l'utente preme invio si esce dalla funzione.
                    {
                        *head = giocatori;     
                        *head2 = classifica;
                        return;
                    }
                    else
                    {
                        scelta[strlen(scelta)-1]='\0';
                    }
        
                    
                        if(scelta[0]=='1') //Altrimenti alla base dell'input si possono compiere tre azioni diverse.
                        {
                   
                                do
                                {               //Anche qui ho riproposto i vari controlli sulle stringhe.
                                    do
                                    {
                                        system("@cls||clear");
                                        printf(reset);
                                        printf(" \n\n\n\n");
                                        printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                                        printf(reset);
                                        printf(" \n\n\n\n");
                                        printf(verde"\t\t\t      CAMBIO NOME UTENTE \n"bianco);
                                        printf("\n\n\t\t    Stai per cambiare il tuo nome utente,\n\t\t\t quale nome vorresti usare?\n\n\t\t   premi INVIO se vuoi tornare indietro\n");
                                        printf("\t\t\t\ Nuovo nome: "verde);
                                        fgets(nuovo_user, 100, stdin);
                                        if(nuovo_user[0]!='\n')
                                        nuovo_user[strlen(nuovo_user)-1]='\0';
                                        
                                    }while((strlen(nuovo_user)<3 || strlen(nuovo_user)>15) && nuovo_user[0]!='\n');
                                        
                                    if(nuovo_user[0]!='\n')
                                    {
                                        if(esiste_giocatore(&giocatori, nuovo_user) == NULL)  //Se il nuovo username non è già occupato si procede col cambio di username
                                            {
                                           
                                                 modifica_nome_classifica(&classifica, &giocatori, username, nuovo_user);
                                                 elimina_giocatore(&giocatori, username);
                                                 strcpy(username, nuovo_user);
                                                
                                                
                                            do 
                                            {
                                                system("@cls||clear");
                                                printf(reset);
                                                printf(" \n\n\n\n");
                                                printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                                                printf(reset);
                                                printf(" \n\n\n\n\n\n\n");
                                                printf(verde"\t\t\t      CAMBIO NOME UTENTE \n"bianco);
                                                printf("\n\n\t\t      Ok, ho cambiato il tuo nome utente,");
                                                printf("\n\n\t\t      adesso ti chiami"verde" %s", nuovo_user);
                                                printf(bianco"\n\n\n\t\t     Premi INVIO per tornare indietro");
                                                fgets(scelta, 100, stdin);
                                                if(scelta[0]!='\n')
                                                scelta[strlen(scelta)-1]='\0';    
                                                
                                            
                                            }
                                            while(scelta[0]!='\n');
                                                
                                               
                                                flag = 1;
                                               
                                           
                                            
                                           
                                        }
                                    
                                           else
                                                {
                                                   do //Se il nome è occupato viene restituita questa schermata, che permette solamente di tornare indietro.
                                                   {
                                                        system("@cls||clear");
                                                        system("clear");
                                                        printf(reset);
                                                        printf(" \n\n\n\n");
                                                        printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                                                        printf(reset);
                                                        printf(" \n\n\n\n\n\n\n");
                                                        printf(verde"\t\t\t      CAMBIO NOME UTENTE \n"bianco);
                                                        printf("\n\n\t\t    Ops! un utente utilizza già questo nome\n \n\t\t  premi INVIO per tornare indietro");
                                                        fgets(scelta, 100, stdin);
                                                        if(scelta[0]!='\n')
                                                        nuovo_user[strlen(nuovo_user)-1]='\0';     
                                                   }while(scelta[0]!='\n');
                                           

                                                    x = 1;
                                                    flag = 0;
                                                }
                                            
                                    } 
                                    else
                                    {
                                        flag = 1;
                                    }
                                    
                                       
        
                                    
                                }
                                while(flag == 0);
                                    
                            }
                    
                    
                    if(scelta[0] == '2')
                    {
                    
                       do       //Vari controlli sulle stringhe
                       {
                            system("clear");
                            printf(reset);
                            printf(" \n\n\n\n");
                            printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                            printf(reset);
                            printf(" \n\n\n\n");
                            printf(verde"\t\t\t      CAMBIA PASSWORD \n" bianco);
                            printf("\n\n\t\t     Stai per cambiare la tua password,\n\t\t  digita attentamente la tua nuova password\n\n\t\t    premi INVIO se vuoi tornare indietro\n");
                            printf("\n\n\t\t\tPassword: "verde);
                            fgets(psw, 100, stdin);
                            if(psw[0]!='\n')
                            psw[strlen(psw)-1]='\0';  
                                
                            
                       }while((strlen(psw)<3 || strlen(psw)>15) && psw[0]!='\n');
                       
                            if(psw[0]!='\n')
                            {
                                modifica_password_giocatore(&giocatori, username, psw);
                                *head = giocatori; //Se la stringa in input è idonea viene restituta questa schermata e dunque viene cambiata la psw.
                                
                                do
                                    {
                                    system("clear");
                                    printf(reset);
                                    printf(" \n\n\n\n");
                                    printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                                    printf(reset);
                                    printf(" \n\n\n\n\n\n\n");
                                    printf(verde"\t\t\t      CAMBIO PASSWORD \n"bianco);
                                    printf("\n\n\t\t       Ok, ho cambiato la tua password\n \n \t\t     premi INVIO per tornare indietro\n\n");
                                    printf("\t\t\t\t ");
                                    fgets(scelta, 100, stdin);
                                    if(scelta[0]!='\n')
                                    scelta[strlen(scelta)-1]='\0';     
                                    }while(scelta[0]!='\n');
            
                                                    x = 1;
                                                    
                                }
                    }
                    
                    
                    if(scelta[0]=='3')
                    {
                        do      //Controlli sulle stringhe
                        {   
                            system("clear");
                            printf(reset);
                            printf(" \n\n\n\n");
                            printf(rossosfondo"\t                      GESTIONE ACCOUNT                         "reset);
                            printf(reset);
                            printf(" \n\n\n\n\n\n\n");
                            printf(rosso"\t\t\t      ELIMINA ACCOUNT \n"bianco);
                            printf("\n\n\t\t     ATTENZIONE! Sei davvero sicuro di voler \n\t\t         eliminare il tuo account? \n\t\t      perderai tutti i tuoi progressi!\n\n");
                            printf("\t\t Digita 'voglioeliminareaccount' per procedere, \n\t\t altrimenti premi INVIO: "verde);
                            printf(reset);
                            fgets(elimina_ins, 100, stdin);
                            if(elimina_ins[0]!='\n')
                            elimina_ins[strlen(elimina_ins)-1]='\0';    
                        
                            
                        }
                       
                       while((elimina_ins[0]!='\n' && strcmp(elimina_ins, elimina) !=0));  //se l'utente ha digitato correttamente la frase di sicurezza il suo account viene eliminato.
                        
                            if(strcmp(elimina_ins, elimina) == 0)
                            {
                                cancella_utente_classifica(&classifica, username);
                                elimina_giocatore(&giocatori, username);
                                
                                *head = giocatori;     
                                *head2 = classifica;
                                return;
                            }
                    
                    
                    
                    }
                    
                    
                    
                }
                    
                    *head = giocatori;     
               *head2 = classifica;
    }
                      
                  
    


void visualizza_classifica(lista_classifica *head) //stampa a schermo la classifica generale.
{
       
    lista_classifica classifica = *head;
    char mov[3];
    
    if(is_empty_classifica(&classifica) == 1) //Se nessun giocatore è registrato viene restituita questa schermata
    {
        system("clear");
        printf(reset);
        printf(" \n\n\n\n    ");
        printf("      "verde"                        CLASSIFICA                        "reset);
        printf(reset);
        printf(" \n\n\n\n\n");
        printf(rosso"\t\t\t       \n"bianco);
        printf("\n\n\t\t Ops! Ancora non avete disputato alcuna partita! \n\t\t       premi INVIO per tornare al menù \n\t\t\n\n");
        do
        {
            fgets(mov, 3, stdin);
        }while(mov[0]!='\n');
    }
else //Altrimenti viene stampata la classifica.
{
     system("clear");
     printf(reset);
     printf(" \n\n\n\n    ");
     printf("      "verde"                        CLASSIFICA                        "reset);
     stampa_classifica(&classifica);
     printf("\n\n\n\t\t      premi INVIO per tornare al menù\n\t\t              ");
      do
        {
            fgets(mov, 3, stdin);
        }while(mov[0]!='\n');
     
     
     
}

}



void primo_accesso(lista_giocatori *head, lista_classifica *head2, lista_partita *head3) //Se nessun utente si è ancora registrato viene invocata tale funzione.
{
     lista_giocatori giocatori = *head;
     lista_classifica classifica = *head2;
     lista_partita partita = *head3;
     char username[16];
     char psw[16];       
     char ch;
       
     
     do
     {
     
     
        do             //Mediante un ciclo do while imposto un blocco sul comando INVIO e sugli username troppo corti (minimo 3 caratteri). Il giocatore non potrà infatti procedere se la fgets rileva in input soltanto INVIO.
            {
                system("@cls||clear");
                                                                                printf(reset);
                                                                                printf(" \n\n\n");
                                                                                printf("                                                    \n");
                                                                                printf(blusfondo"\t                        NUOVA PARTITA                           "reset);
                                                                                printf(" \n\n\n\n                                                   \n");
                                                                                printf("                                                    \n");
                                                                                printf("                                                    \n");
                                                                                printf(bianco"\t\t    \n");
                                                                                printf("\t\t     Ops, sembra che non ci sia ancora nessun     \n");
                                                                                printf("\t\t     giocatore registrato!                       \n");
                                                                                printf("                                                    \n");
                                                                                printf("\t Giocatore 1, inserisci il tuo nome per registrarti!         \n");
                                                                                printf("                                                    \n");
                                                                                printf("                                                    \n");
                                                                                printf("\t Nome(min. 3 caratteri, max. 15): "verde"");
                                                                                
                                                                    
                                                                                fgets(username, 100, stdin);
                                                                                if(username[0]!='\n')
                                                                                username[strlen(username)-1]='\0';   
                                                                                
                                                                                printf(reset);
            }
                                                                            
                                                                    
        while((strlen(username)<3 || strlen(username)>15) || username[0]=='\n' );          
        
              //Elimino l'ultimo carattere della stringa, poichè questo sarà \n (a causa della fgets).         
                        
                do //Imposto nuovamente il blocco sul tasto INVIO ed il controllo sulla lunghezza della psw.
                {
                    
                                                                            system("@cls||clear");   //Pulisco lo schermo
                                                                            
                                                                            printf(reset);
                                                                            printf(" \n\n\n");
                                                                            printf("                                                    \n");
                                                                            printf(blusfondo"\t                        NUOVA PARTITA                           "reset);
                                                                            printf(" \n\n\n\n                                                   \n");
                                                                            printf("                                                    \n");
                                                                            printf("                                                    \n");
                                                                            printf(bianco"\t\t\t     Ok, ci siamo quasi! \n");
                                                                            printf(verde"\t\t   %s,"bianco" digita attentamente la password!     \n", username);
                                                                            printf("\n\t\t         Se invece hai sbagliato a digitare");
                                                                            printf("\n\t\t         l'username, premi INVIO                                                 \n");
                                                                            printf("\t\t              \n");
                                                                            printf("                                                    \n");
                                                                            printf("                                                    \n");
                                                                            printf("\t Password(min 3 caratteri, max. 15): "verde"");
                                                                            fgets(psw, 100, stdin);
                                                                            if(psw[0]!='\n')
                                                                            psw[strlen(psw)-1]='\0';
              
            }
            while((strlen(psw)<3 || strlen(psw)>15) && psw[0]!='\n');
            
                
     }while(psw[0] == '\n');//Elimino l'ultimo carattere della stringa, poichè questo sarà \n (a causa della fgets).  
                    
                    
        registra(&giocatori, username, psw);        //Registro il giocatore, lo inserisco cioè nella lista_giocatori.
        inserisci_utente_classifica(&classifica, giocatori, username); //Inserisco il giocatore anche nella lista_classifica.
        inserisci_giocatore_partita(&partita, username); //Inserisci il giocatore anche nella lista_partita (poichè si presume che prenderà parte alla partita).
        *head = giocatori;
        *head2 = classifica;
        *head3 = partita;
}



int accesso(int n, lista_giocatori *head, lista_classifica *head2, lista_partita *head3) //Permette agli utenti di registrarsi o di effettuare il login. Le fasi di registrazioni/login sono simili a quelle viste in gestione_account, quindi evito di commentarle.
{
    lista_giocatori giocatori = *head;
    lista_partita partita = *head3;
    lista_classifica classifica = *head2;
    
    int flag = 0;
    int flag2 = 0;
    int x = 0;     
    char username[15];
    char psw[15];   
    char ch;
      
    
        while(x==0)
                {
                       
                do
                    {
                        flag2 = 0; 
                    do
                       {
                            if(n<=2) //Se <2 giocatori hanno effettuato l'accesso imposto il blocco sul comando INVIO.
                                {
                                 
                                    do
                                    {
                                                                                    system("clear");
                                                                                    printf(reset);
                                                                                    printf(" \n\n\n");
                                                                                    printf("                                                    \n");
                                                                                     printf(blusfondo"\t                        NUOVA PARTITA                           "reset);
                                                                                    printf(" \n\n\n\n                                                   \n");
                                                                                    printf("                                                    \n");
                                                                                    printf("                                                    \n");
                                                                                    printf(bianco"\t\t  Ciao, giocatore "verde"%d"bianco",\n",n);
                                                                                    printf("\t\t          \n");
                                                                                    printf("\t\t                           \n");
                                                                                    printf("                                                    \n");
                                                                                    printf("\t\t Inserisci il tuo nome per loggarti/registrarti!         \n");
                                                                                    if(n >2)
                                                                                    {
                                                                                        printf("\t\tOppure premi INVIO per iniziare a giocare \n");
                                                                                    }
                                                                                    printf("                                                    \n");
                                                                                    printf("                                                    \n");
                                                                                    printf("\t\t Nome: "verde"");
                                                                                    
                                        fgets(username, 100, stdin); 
                                    
                                    }
                                    while(username[0] == '\n' || strlen(username)<3 || strlen(username)>15);
                                username[strlen(username)-1]='\0';
                                    
                                }
                                 else
                                    {
                                       do
                                        {
                                                                                    system("clear");
                                                                                    printf(reset);
                                                                                    printf(" \n\n\n");
                                                                                    printf("                                                    \n");
                                                                                    printf(blusfondo"\t                        NUOVA PARTITA                           "reset);
                                                                                    printf(" \n\n\n\n                                                   \n");
                                                                                    printf("                                                    \n");
                                                                                    printf("                                                    \n");
                                                                                    printf(bianco"\t\t   Ciao, giocatore "verde"%d"bianco",\n",n);
                                                                                    printf("\t\t          \n");
                                                                                    printf("\t\t                           \n");
                                                                                    printf("                                                    \n");
                                                                                    printf("\t\t Inserisci il tuo nome per loggarti/registrarti!         \n");
                                                                                    if(n >2)
                                                                                    {
                                                                                        printf("\t\tOppure premi "rosso"INVIO"bianco" per iniziare a giocare \n");
                                                                                    }
                                                                                    printf("                                                    \n");
                                                                                    printf("\n");
                                                                                    printf("\n\t\t Nome(min 3. caratteri, max. 15): "verde"");
                                                                                    
                                       
                               
                                        fgets(username, 100, stdin);
                                        
                                    
                                            if(username[0] == '\n')
                                            {
                                                
                                                return n;
                                            }
                                        }
                                        while(strlen(username)<3||strlen(username)>15);
                                    
                                        username[strlen(username)-1]='\0';
                    
                                    } 
                                
                                
                                if(esiste_giocatore(&giocatori, username) != NULL)
                                {
                                    
                                    if(esiste_giocatore_partita(&partita, username) != NULL)
                                    {
                                    
                                        do
                                            {
                                                system("clear");
                                                printf(reset);
                                                printf(" \n\n\n");
                                                printf("                                                    \n");
                                               printf(blusfondo"\t                        NUOVA PARTITA                           "reset);
                                                printf(" \n\n\n\n                                                   \n");
                                                printf("                                                    \n");
                                                printf("                                                    \n");
                                                printf(bianco"\t\t\t  "verde" %s"bianco", sei già loggato! \n", username);
                                                printf(bianco"\t\t         \n");
                                                printf("\n\t\t                premi "rosso"INVIO                       \n");
                                                printf("                                                    \n");
                                                printf("\t\t              \n");
                                                printf("                                                    \n");
                                                printf(verde"                                                    \n");
                                            
                                            
                                                fgets(psw, 100, stdin);
                                            }while(psw[0]!='\n');
                                                
                                                flag = 1;
                                        }
                                    
                                    else
                                        {
                                           do
                                           {
                                                
                                                system("clear");
                                                printf(reset);
                                                printf(" \n\n\n");
                                                printf("                                                    \n");
                                                printf(blusfondo"\t                        NUOVA PARTITA                           "reset);
                                                printf(" \n\n\n\n                                                   \n");
                                                printf("                                                    \n");
                                                printf("                                                    \n");
                                                printf(bianco"\t\t\t Ciao"verde" %s"bianco", sei registrato! \n", username);
                                                printf(bianco"\t\t          inserisci la  tua password!     \n");
                                                printf("\t\t\n                  Se non è il tuo account premi invece INVIO                       \n");
                                                printf("                                                    \n");
                                                printf("\t\t              \n");
                                                printf("                                                    \n");
                                                printf("                                                    \n");
                                                printf("\t\t Password: "verde"");
                                                
                                                
                                                fgets(psw, 100, stdin);
                                                if(psw[0]!='\n')
                                                psw[strlen(psw)-1]='\0';    
                                           }while((strlen(psw)<3 || strlen(psw)>15) && psw[0]!='\n');
                                                if(psw[0] == '\n')
                                                    {
                                                    flag = 1;
                                                    flag2 = 1;
                                                    }
                                                    else
                                                        {
                                                            flag2 = 0;
                                                            flag = 0;
                                                
                                                        }
                                
                                    }
                                }
                                
                                
                                
                                else
                                    {
                                        
                                       do
                                       {
                                            system("clear");
                                            printf(reset);
                                            printf(" \n\n\n");
                                            printf("                                                    \n");
                                            printf(blusfondo"\t                      NUOVA PARTITA                            "reset);
                                            printf(" \n\n\n\n                                                   \n");
                                            printf("                                                    \n");
                                            printf("                                                    \n");
                                            printf(bianco"\t\t\tCiao,"verde" %s"bianco"! non sei registrato \n", username);
                                            printf(bianco"\t\tdigita attentamente una password per registrarti!     \n");
                                            printf("\n\t\t Altrimenti premi INVIO se hai sbagliato                      ");
                                            printf("\n\t\t          a digitare l'username                                      \n");
                                            printf("\t\t              \n");
                                            printf("                                                    \n");
                                            printf("                                                    \n");
                                            printf("\t\t Password(min. 3 caratteri, max. 15): "verde);
                                            
                                            fgets(psw, 100, stdin);
                                            if(psw[0]!='\n')
                                             psw[strlen(psw)-1]='\0';    
                                            
                                       }while((strlen(psw)<3 || strlen(psw)>15) && psw[0]!='\n');
                                       
                                        
                                       if(psw[0]!='\n')
                                       {
                                        registra(&giocatori, username, psw);
                                        inserisci_utente_classifica(&classifica, giocatori, username);
                                        *head2 = classifica;
                                        flag = 0;
                                        flag2=0;
                                       }
                                       else
                                       {
                                        flag = 1;
                                        flag2=1;
                                       }
                                        
                                    }
                         }while(flag == 1);
                                
                    
                if(login(&giocatori, username, psw) == 1)
                    {
                        inserisci_giocatore_partita(&partita, username);
                        n++;
                        *head = giocatori;
                    *head2 = classifica;
                    *head3 = partita;
                        
                    }
                    else
                        {
                            int tentativi = 0;            
                            while(login(&giocatori, username, psw) == 0)
                                                {
                                                    do
                                                    {
                                                        system("clear");
                                                        printf(reset);
                                                        printf(" \n\n\n");
                                                        printf("                                                    \n");
                                                        printf(blusfondo"\t                      NUOVA PARTITA                            "reset);
                                                        printf(" \n\n\n\n                                                   \n");
                                                        printf("                                                    \n");
                                                        printf("                                                    \n");
                                                        printf(bianco"\t\t\t     Attenzione, "verde"%s"bianco" \n", username);
                                                        printf("\t\t    la password da te inserita è errata,    \n");
                                                        printf("\n\t\t             ritenta!                 \n");
                                                        printf("                                                    \n");
                                                        printf("\t\t              \n");
                                                        printf("                                                    \n");
                                                        printf("                                                    \n");
                                                        printf("\t\t Password: "reset"");
                                                        
                                                        fgets(psw, 100, stdin);
                                                        psw[strlen(psw)-1]='\0';
                                                    }while(strlen(psw)>15);
                                                   
                                                    tentativi++;
                                                        if(tentativi >=3)
                                                            {
                                                                break;
                                                            }
                                                
                                                   
                                                }
                                     
                        inserisci_giocatore_partita(&partita, username);
                        n++;        
                        
                    
                            
                        }
                }while(flag2 == 1);
                }
                *head2 = classifica;
}
                                                   
void fine_partita(lista_partita *head, lista_giocatori *head2, lista_classifica *head3, int n) //mediante questa funzione viene aggiornata la classifica generale e stampata (e successivamente cancellata) la classifica provvisoria.
{
    lista_partita partita = *head;
    lista_giocatori giocatori = *head2;
    lista_classifica classifica = *head3;
    
    classifica_partita classtemp = crea_classifica_partita();
    
    for(int i = 0; i<n; i++)
    {
        
       inserisci_classifica_partita(&classtemp, &partita, dai_nome(&partita, i));
       modifica_punteggio_utente(&classifica, dai_nome(&partita, i), dai_punti(&partita, i));
       incrementa_partite_utente(&classifica, dai_nome(&partita, i));
    }
    incrementa_vittorie_utente(&classifica, dai_nome_vincitore(&classtemp));
    stampa_classifica_partita(&classtemp);
   // stampa_classifica(&classifica);
   cancella_classifica_partita(&classtemp);
   cancella_lista_partita(&partita);
    
  
   //stampa_classifica_partita(&classtemp);
   *head3 = classifica;
   *head2 = giocatori;
}
    
    
    


void partita(lista_giocatori *head, lista_classifica *head2) //Tale funzione permette di iniziare una nuova partita.
{
   lista_giocatori giocatori = *head;
   lista_classifica classifica = *head2;
    
    int turni = 0;   
    
    int n = 1; //Numero di giocatori
    
    char menu[2];
    char ch;
           
             system("@cls||clear");
            printf(bianco);
            printf(" \n\n\n");
            printf("                                                    \n");
            printf("       "blusfondo"\t\t                 NUOVA PARTITA                 "reset);
            printf(" \n\n\n\n                                                   \n");
            printf("                                                    \n");
            printf("                                                    \n");
            printf(bianco"\t\t\tBenvenuti in Nomi, Cose, Città! \n");
            printf("\t\t\t  Quanti turni volete giocare?    \n");
            printf("\n\t\t              Turni: "verde);
                                                
            scanf("%d", &turni); //come posso  accettare solamente interi?
           
             while((ch=getchar()) != '\n' && ch != EOF); //Svuoto il buffer perchè ho utilizzato una scanf.
            
            lista_partita partita = NULL;
            
            
            
            
            if(is_empty_giocatore(&giocatori) == 1) //Se nessun giocatore è ancora registrato invoco la funzione primo accesso
                {
                    primo_accesso(&giocatori, &classifica, &partita);
                    n = 2;
                }
                    
         n = accesso(n, &giocatori, &classifica, &partita)-1; //invoco la funzione accesso che permette di effettaure il login/registrazione in casi standard.
         
       
         
        
         gioca(n, turni, &partita); //avvio il gioco vero e proprio
        
        fine_partita(&partita, &giocatori, &classifica, n); //stampa la classifica provvisoria e aggiorna la classifica generale.
        *head = giocatori;
        *head2 = classifica; 
         
         printf("\n\n\t\t Premere INVIO per ritornare al menù principale\n\n");
         fgets(menu, 2, stdin);
          
       
         
                
}   

void gioca(int giocatori, int turni, lista_partita *head)
{
    lista_partita partita = *head;
    char scelta[2];
    int flag = 0;
  
    for(int i = 1; i<=turni; i++) //finchè il numero di turni giocati è minore di quelli da giocare, si procede come quanto segue:
    {
        flag = 0;
        estrai(); //viene estratta la lettera. ATTENZIONE: al momento ho escluso il tempo di attesa per comodità in fase di test.
        
        
         
        gioca_turno(&partita, i); //permette ai giocatori di inserire i nomi, le cose e le città.
        calcola_punteggio(&partita); //calcola il punteggio
        stampa_tabella(&partita, i); //e stampa la tabella
        
         while(flag == 0)
         {
            do
                {
                    
                    stampa_tabella(&partita, i);        
            printf("\n\n\t Premere INVIO per continuare, 0 per segnalare una scorrettezza \n \n");
            printf("\n\t                                   ");
            fgets(scelta, 100, stdin);
            
            if(scelta[0] == '\n')
                {
                    flag = 1;                
                }
                else if(scelta[0] == '0')
                    {
                    flag = 0;
                    segnala(giocatori, i, &partita); 
                    } 
                }while(scelta[0]!='0' && scelta[0]!='\n');
         
        }
    }
    *head = partita;
}




void segnala(int giocatori, int turno, lista_partita *head)
{
    lista_partita partita = *head;
    char giocatore[16];
    char categoria[3];
    int elemento = 0;
    char voto[3];
    
   char cat[7]; 
    int votipro = 0;
    int voticontro = 0;
    
    
    do
    {
        stampa_tabella(&partita, turno);
        printf("\n\n\t\t\tState per segnalare un giocatore, \n\t\t\tquale giocatore volete segnalare?\n\t\t\t "verde);
        fgets(giocatore, 100, stdin);
        giocatore[strlen(giocatore)-1]='\0';
        
        if(esiste_giocatore_partita(&partita, giocatore)!=NULL) //viene cercato il giocatore, se questo viene trovato si procede come quanto segue. Altrimenti verrà richiesto l'input.
        {
            do //imposto un controllo sull'input
            {
                stampa_tabella(&partita, turno);
                printf("\n\n\t\t\tState per segnalare "verde"%s"bianco", \n\t\t\tper quale categoria?\n\t\t\t1) Nome, 2) Cosa, 3) Città\n\t\t\t\t", giocatore);
                fgets(categoria, 100, stdin);
                if(categoria[0]!='\n')
                categoria[strlen(categoria)-1]='\0';
                
                
            }while(categoria[0]!='1' && categoria[0]!='2' && categoria[0]!='3' || categoria[0]=='\n');
           
            if(categoria[0]=='1')     
            {
            strcpy(cat, "nome"); //converto l'intero in stringa
            
            elemento = 1;
            }
             if(categoria[0]=='2')
             {
            strcpy(cat, "cosa");  
            elemento = 2;          
             }
            if(categoria[0]=='3')             
            {
            strcpy(cat, "citta");     
            elemento = 3;   
            }
                                
                        
                        
           
            do
            {
            stampa_tabella(&partita, turno);
            printf("\n\n%s, se ritieni di aver commesso un errore digita 1, altrimenti 0: "verde, giocatore);
            fgets(voto, 100, stdin);
            
            }while(voto[0]!= '0' && voto[0]!='1' || voto[0]=='\n'); 
            
            
            if(voto[0] == '1') //Se l'utente ammette di aver sbagliato si procede all'eliminazione della parola senza passare dalla fase di voto.
                {
                    cancella(&partita, giocatore, elemento);
                    calcola_punteggio(&partita);
                    return;
                }
                else if(voto[0]=='0') //Altrimenti, appunto, si passa alla fase di voto.
                    {
                        
                        
                                
                        for(int i = 0; i<giocatori; i++)
                            {
                                
                                if(strcmp(dai_nome(&partita, i), giocatore)!=0) //Dal voto viene escluso ovviamente il giocatore che ha commesso l'infrazione, poichè ha espresso la sua opinione prima.
                                        {
                                           
                                            
                                        
                                
                                            do
                                            {
                                                stampa_tabella(&partita, turno);
                                                printf("\t\n %s, \n se pensi che %s abbia inserito un/una %s errato digita 1,\n altrimenti 0: "verde, dai_nome(&partita, i), giocatore, cat);
                                                fgets(voto, 100, stdin);
                                                
                                                if(voto[0] == '1')
                                                {
                                                    votipro++;
                                                }
                                                else if(voto[0]=='0')
                                                {
                                                    voticontro++;
                                                }
                                            } while(voto[0]!= '0' && voto[0]!='1' || voto[0] == '\n'); 
                                        }
                            }
                    
                    if(votipro > (giocatori/2)-1) //Se la maggioranza dei giocatori vota per l'eliminazione si procede appunto con l'eliminazione della parola stessa, nonchè con il nuovo calcolo dei punti.
                    {
                    cancella(&partita, giocatore, elemento);
                    calcola_punteggio(&partita);
                    return;
                    }
                    else
                    {
                        return; //altrimenti si esce dalla funzione senza fare nulla.
                    }
                    }
               
        }
    }while(esiste_giocatore_partita(&partita, giocatore)==NULL);
}
            

void estrai()
{
const char array[] = "ABCDEFGHIMNOPQRSTUVXYZ";
char RandChar;
char ch[2];
srand(time(NULL));
RandChar = array[rand() % (sizeof(array)-1)];   
system("clear");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tLA LETTERA ESTRATTA E' "verde"%c"bianco"", RandChar);   
printf("\n\n\t\t      Premere INVIO per iniziare il turno\n\t\t\t        "); 
do
{
fgets(ch, 100, stdin);
}while(ch[0]!='\n');
} 
           
  

            

int main()
{

lista_classifica classifica = crea_lista_classifica();
lista_giocatori giocatori = NULL;

carica_classifica(&classifica, &giocatori);

srand(time(NULL));
   
int escape = 0;
      
while(escape == 0)
{
    stampa_menu();
   system("/bin/stty raw");
        mov = getchar() - '0';
          system("/bin/stty cooked");
       
        
        switch(mov)
        {
            
            
            case 1:
                
            partita(&giocatori, &classifica);
            break;
            
            case 2:
                
                visualizza_classifica(&classifica);
            break;
            
            case 3:
              
             gestisci_account(&giocatori,&classifica);
             break;
            
                break;
            case 4:
                escape = 1;
                salva_classifica(&classifica);
                cancella_lista_classifica(&classifica);
                cancella_lista_giocatori(&giocatori);
                
                
                system("clear");
                break;
        }
        
} 

}
    
    


    
