#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char lorem[2048] = "";

void map()
{
    char texte[2048] = "";
    char* token = NULL;
    int x = 0;
    FILE* fichier = NULL;
    fichier = fopen("Lorem Ipsum.txt", "r");
    if (fichier == NULL)
    {
        printf("Erreur d'ouverture du fichier");
    }
    else
    {
        fgets(texte, 2000, fichier);
    }
    fclose(fichier);
    strcpy(lorem,texte);
    token = strtok(texte," ,;:?.!-");
    while(token)
    {
        printf("%s\t1\n",token);
        token = strtok(NULL," ,;:?.!-");
    }
}

void reduce()
{
    int i = 0;
    int x = 0;
    int check = 0;
    int compteur[2048] = {0};
    char* token = NULL;
    char** test;
    test = (char**)malloc(2048 * sizeof(char*));
    token = strtok(lorem," ,;:?.!-");
    while(token)
    {
        check = 0;
        if (x!=0)
        {
            for(i=0;i<x;i++)
            {
                if (((strcmp(token,test[i]))==0))
                {
                    compteur[i]++;
                    i=x;
                    check = 1;
                }
            }
        }
        if (check == 0)
        {
            test[x] = token;
            compteur[x]++;
            x++;

        }

        token = strtok(NULL," ,;:?.!-");

    }
    for(i=0;i<x;i++)
    {
        printf("%s\t%d\n",test[i],compteur[i]);
    }
}

int main()
{
    map();
    printf("Press Any Key to launch the Reduce.");
    getch();
    system("cls");
    reduce();
    return 0;
}
