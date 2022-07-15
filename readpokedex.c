#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// DEFINE
#define CSV_FILE_TO_READ "pokemons.csv"

struct pokemons
{
    char Nom[50];
    char Type[50];
    char Zone[20];
    int Nombre[10];
    char DateDecouverte[20];
    char DateCapture[20];

    struct pokemons *next;
} *head;

void Read()
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
        struct pokemons *pokemons = malloc(sizeof(struct pokemons));

        char *getNom = strtok(parsedLine, ";");
        strcpy(pokemons->Nom, getNom);

        char *getType = strtok(NULL, ";");
        strcpy(pokemons->Type, getType);

        char *getZone = strtok(NULL, ";");
        strcpy(pokemons->Zone, getZone);

        char *getNombre = strtok(NULL, ";");
        strcpy(pokemons->Zone, getNombre);

        char *getDateDecouverte = strtok(NULL, ";");
        strcpy(pokemons->Zone, getDateDecouverte);

        char *getDateCapture = strtok(NULL, ";");
        strcpy(pokemons->Zone, getDateCapture);

        pokemons->next = head;
        head = pokemons;
    }
    fclose(fPointer);
}

void Display()  // affiche le contenu de la liste chaînée
{
    struct pokemons *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%s %s %s %s %s %s \n",temp->Nom,temp->Type,temp->Zone,temp->Nombre,temp->DateDecouverte,temp->DateCapture);
        temp = temp->next;
    }
}

int main()
{
    Read();
    Display();
    return 0;
}
