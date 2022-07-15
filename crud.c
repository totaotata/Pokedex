#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

// DEFINE
#define CSV_FILE_TO_READ "pokemons.csv"
#ifndef __LINKED_LIST__
#define __LINKED_LIST__


struct pokedex
{
    char Nom[50];
    char Type[50];
    char Zone[20];

    struct pokedex *next;
} *head;

#endif /* __LINKED_LIST__*/

void CreatePokedexEntry(){
    char *name = malloc(sizeof(char) * 50);
    char *type = malloc(sizeof(char) * 50);
    char *zone = malloc(sizeof(char) * 50);
    char *date_dec = malloc(sizeof(char) * 50);
    char *date_capt = malloc(sizeof(char) * 50);
    char *yesno = malloc(sizeof(char) * 50);
    
    printf("Quel est le nom du pokemon ?\n");
    scanf ("%s", name);
    printf("Quel est le type du pokemon ?\n");
    scanf ("%s", type);
    printf("Quelle est la zone de rencontre avec le pokemon ?\n");
    scanf ("%s", zone);
    printf("Quand l'avez-vous découvert ?\n");
    scanf ("%s", date_dec);
    while(1){
        printf("Avez-vous capturé ce pokémon ?\n");
        printf("1 - OUI\n");
        printf("2 - NON\n");
        scanf ("%s", yesno);
        if (strcmp(yesno,"1") == 0){
            printf("Quand l'avez-vous capturé ?\n");
            scanf ("%s", date_capt);
            break;
        }
        else if (strcmp(yesno,"2") == 0){
            printf("c'est dommage !\n");
            break;
        }
        else
            printf("La valeur rentrée n'est pas correcte\n");
    }
    free(yesno);
}

void ReadPokedex()
{
    FILE *fPointer;
    fPointer = fopen(CSV_FILE_TO_READ,"r");

    if (fPointer == NULL)
    {
        printf("\nCould not open file %s",CSV_FILE_TO_READ);
        return;
    }
    // lis le fichier et créé la liste chaînée
    char parsedLine[120];
    while(fgets(parsedLine, 120, fPointer) != NULL)
    {
        struct pokedex *pokedex = malloc(sizeof(struct pokedex));

        char *getNom = strtok(parsedLine, ";");
        strcpy(pokedex->Nom, getNom);

        char *getType = strtok(NULL, ";");
        strcpy(pokedex->Type, getType);

        char *getZone = strtok(NULL, ";");
        strcpy(pokedex->Zone, getZone);

        pokedex->next = head;
        head = pokedex;
    }
    fclose(fPointer);
}

void DisplayPokedex()  // affiche le contenu de la liste chaînée
{
    ReadPokedex();
    struct pokedex *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%s %s %s \n",temp->Nom,temp->Type,temp->Zone);
        temp = temp->next;
    }
}



void UpdatePokedex()
{
    struct pokedex *temp;
    temp=head;
    char *updateentry = malloc(sizeof(char) * 50);    
    while(1){
        printf("\nVoulez-vous afficher le Pokédex avant ?\n");
        printf("1 - OUI\n");
        printf("2 - NON\n");
        scanf ("%s", updateentry);
        if (strcmp(updateentry,"1") == 0){
            while(temp!=NULL)
            {
                printf("%s %s %s \n",temp->Nom,temp->Type,temp->Zone);
                temp = temp->next;
                printf("Quel est le nom du pokémon à changer ?\n");
                scanf ("%s", updateentry);
                strcpy(temp->Nom, updateentry);
                
                return;
            }
        }
        else if (strcmp(updateentry,"2") == 0){
            printf("Quel est le nom du pokémon à changer ?\n");
            scanf ("%s", updateentry);
            strcpy(temp->Nom, updateentry);
            break;
        }
        else {
            printf("La valeur rentrée n'est pas correcte\n");
            return;
        } 
    }
    free(updateentry);
}
/*
    int main(){
    struct Node *head = NULL;
    char namex[20];
    char namey[20];
    printf("Insert a name\n");
    scanf("%s", namex);
    push(&head, namex);
    printf("Insert a new name\n");
    scanf("%s", namey);
    push(&head, namey);
    printList(head);

    return 0;


    new_node->updateentry = malloc(20*sizeof(char));
    if(!new_node->updateentry) {
        printf("Mauvaise entrée, veuillez en entrer une nouvelle\n");
        return;
    }
    strcpy(new_node->updateentry,updateentry);
}
*/

void DeletePokedexEntry(){
    /*
    struct pokedex *temp;
    temp=head;
    char *deleteentry = malloc(sizeof(char) * 50);    
    while(1){
        printf("\nVoulez-vous afficher le Pokédex avant ?\n");
        printf("1 - OUI\n");
        printf("2 - NON\n");
        scanf ("%s", deleteentry);
        if (strcmp(deleteentry,"1") == 0){
            printf("Quel est le nom du pokémon à supprimer ?\n");
            scanf ("%s", deleteentry);
            if(head != NULL){
                // store the old value of head pointer   
                struct pokedex *temp;
                temp = head;
        
                // Change head pointer to point to next node
                head = head->next;
 
                // delete memory allocated for the previous head node
                free(temp);
            }
        }

        else if (strcmp(deleteentry,"2") == 0){
            printf("Quel est le nom du pokémon à supprimer ?\n");
            scanf ("%s", deleteentry);
            strcpy(temp->Nom, deleteentry);
            if(head != NULL){
                // store the old value of head pointer   
                struct pokedex *temp;
                temp = head;
        
                // Change head pointer to point to next node
                head = head->next;
 
                // delete memory allocated for the previous head node
                free(temp);
            }
        }

        else {
            printf("La valeur rentrée n'est pas correcte\n");
            return;
        } 
    }
    free(deleteentry);
*/
}


/*
void deleteFirst()
{
    if(head != NULL)
    {
       // store the old value of head pointer   
       struct Node *temp = head;
        
       // Change head pointer to point to next node
       head = head->next;
 
       // delete memory allocated for the previous head node
       free(temp);
    }
}
*/

void SavePokedex(){

}

void sigint_handler(int sig)
{
    signal(sig, SIG_IGN);
    signal(SIGINT, sigint_handler);
    char *ctrlc = malloc(sizeof(char) * 50);    
    while(1){
        printf("\nEtes-vous sûr de vouloir quitter ?\n");
        printf("1 - OUI\n");
        printf("2 - NON\n");
        scanf ("%s", ctrlc);
        if (strcmp(ctrlc,"1") == 0){
            exit(1);
        }
        else if (strcmp(ctrlc,"2") == 0){
            printf("on continue !\n");
            return;
        }
        else {
            printf("La valeur rentrée n'est pas correcte\n");
            return;
        } 
    }
    free(ctrlc);
}

void QuitGame()
{
    char *quit = malloc(sizeof(char) * 50);
    while(1){
        printf("Etes-vous sûr de vouloir quitter ?\n");
        printf("1 - OUI\n");
        printf("2 - NON\n");
        scanf ("%s", quit);
        if (strcmp(quit,"1") == 0){
            exit(1);
        }
        else if (strcmp(quit,"2") == 0){
            printf("on continue !\n");
            return;
        }
        else {
            printf("La valeur rentrée n'est pas correcte\n");
            return;
        }
    }
    free(quit);
}