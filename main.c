#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100

FILE* CLIENT=NULL;
FILE* newfichier=NULL;//fichier qui contient les infos des clients qui se trouvent avant le client qui part
FILE* fichier=NULL;//fichier qui contient les infos des clients qui se trouvent apres le client qui part

typedef struct Client Client;
struct Client
{
char nom[100];
char prenom[100];
long numero_de_piece;
long rang;
};

Client client;//=("","",0);
void menu();
void clients();//la fonction qui est reservée au client
void EnregistrementClient();//la fonction qui enregitre les info d'un client dans le fichier CLIENT
void afficheRecherche(FILE* fichier);//la fonction qui affiche le client recherché.
void afficheClients(FILE* fichier);//la fonction qui affiche tous les client.
void rechChaine(FILE* fichier, char* str1);//la fonction qui va trouver le client qui veut partir sans attendre son tour.
void suprimeClient();//la fonction qui copie ls info des clients qui sont apres le client qui part.



int j;//la variable qui donne la position du curseur apres les infos du client recherché
int k;//la variable qui donne la position du curseur avant les infos du client recherché
int z=2;// z la variable qui donne la reponse de la recherche dans le fichier client.
int nbr=0;//le nombre de ligne dans le fichier client

int main()
{
    char str[5];
    newfichier=fopen("stockage.txt","r");
    if (newfichier!=NULL)
    {
     fgets(str,5,newfichier);
     nbr=atoi(str);
    }
    menu();
  return 0;
}


void menu()
{
 int choix;
system("color 3f ");//la couleur de la console

system("cls");
printf("\t\n\n-----------------      BIENVENUE AU SERVICE jlskjkhwjgilDU CAFE CACAO  ---------------------\n\n\n");
printf("\t\t*************************************************\n");
printf("\t\t\t\tFAITES VOTRE CHOIX\t\t\n");
printf("\t\t*************************************************\n");
printf("\t\t*\t\t 1. CLIENT      \t\t*\n\n");
printf("\t\t*\t\t 2. PRESTATAIRE \t\t*\n\n");
printf("\t\t*\t\t 3. VISITEUR    \t\t*\n\n");
printf("\t\t*\t\t 4. PARTENAIRES \t\t*\n\n");
printf("\t\t*\t\t 5. QUITTER     \t\t*\n\n");
printf("\t\t************************************************\n\n");
scanf("%d",&choix);
fflush(stdin);
switch(choix)
    {
    case 1 : clients();
    break;
    case 2 :
    {
    printf("rien n'est encore defini pour cette section\n");
    system("pause");
    menu();
    }
    break;
    case 3 :
    {
    printf("rien n'est encore defini pour cette section\n");
    system("pause");
    menu();
    }
    break;
    case 4 :
    {
    printf("rien n'est encore defini pour cette section\n");
    system("pause");
    menu();
    }
    break;
    case 5 :
        {
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\tA BIENTOT");
        }
    break;
    default:
    printf("faites un choix de 1 a 5.\n");
    sleep(1000);
    menu();
    break;
    }
}

void clients()
{
    char sticker[30]="";
    int choix,choix1;// 2 variable pour ne pas avoir de confusion dans les differentes boucles (switch).
    int fin=0;
system("cls");
printf("\t\t**************************************************************\n");
printf("\n\n\t\t\t\t ICI LE CLIENT EST ROI \n\n");
printf("\t\t**************************************************************\n\n");
printf("\t\t\t\t FAITES VOTRE CHOIX\t\t\n\n");
printf("\t\t|------------------------------------------------------------|\n");
printf("\t\t|\t\t 1. ENREGISTRER UN CLIENT                    |\t\t\t\n");
printf("\t\t|\t\t 2. VOIR LA LISTE D'ATTENTE                  |\t\t\t\n");
printf("\t\t|\t\t 3. DEPART D'UN CLIENT                       |\t\t\t\n");
printf("\t\t|\t\t 4. RETOUR A L'ACCUEIL                       |\t\t\t\n");
printf("\t\t|------------------------------------------------------------|\n");
scanf("%d",&choix);
switch(choix)
 {
case 1 :
    {
    EnregistrementClient();
    }
break;
case 2 :
    {
    afficheClients(fichier);

    system("pause");
    do
    {
    system("cls");
    printf("\n\n\n\t\t\t\t 1. RETOUR AU MENU CLIENT      \t\t\n\n");
    printf("\t\t\t\t 2. RETOUR A L'ACCUEIL \t\t\n\n");
    printf("\t\t\t\t 3. QUITTER \t\t\n\n");
    scanf("%d",&choix1);
    switch(choix1)
        {
        case 1 :
        {
        clients();
        fin=3;
        }
        break;
        case 2 :
        {
            fin=3;
            menu();
        }
        break;
        case 3 :
        {
        fin=3;
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\tA BIENTOT");
        }
    break;
        default:
        {
        printf("faites un choix entre 1 et 2 \n");
        system("pause");
        }
        }
    }while(fin!=3);
    }
break;
case 3 :
    {
    system("cls");
    printf("\n\n\n\t\t\tvotre numero de sticker:");scanf("%s",sticker);
    z=2;//on reinitialise la valeur de z avant la recherche.
    rechChaine(CLIENT,sticker);
    if(z == 1)
    {
    afficheRecherche(fichier);
    suprimeClient();
    sleep(2000);
    clients();
    }
   else
    {
    printf("\n Le numero n'existe pas dans le fichier.\n");
    sleep(2000);
    clients();
    }
    }
break;
case 4 :menu();
break;
default:
{
    printf("\nfaites un choix de 1 et 4 \n");
        system("pause");
        clients();
}
 }
}

void EnregistrementClient()
{
char str;
int choix;
int fin=0;//la variable qui permet d'enregitrer plusieurs client a la fois

char str2[5];
    newfichier=fopen("stockage.txt","r");
    if (newfichier!=NULL)
    {
     fgets(str2,5,newfichier);
     nbr=atoi(str2);
    }
system("cls");
printf("\n\n\n\t\t\tnom:");scanf("%s",client.nom);
printf("\n\t\t\tprenom:");scanf("%s",client.prenom);
printf("\n\t\t\tnumero de piece:");scanf("%d",&client.numero_de_piece);
nbr++;
client.rang=nbr;
CLIENT=fopen("client.txt","a+");
if(CLIENT != NULL)
{
fprintf(CLIENT," \n\n%d",client.numero_de_piece);
fprintf(CLIENT,"\n%s",client.nom);
fprintf(CLIENT,"\n%s",client.prenom);
fprintf(CLIENT,"\n%d",client.rang);
fclose(CLIENT);
//on enregitre la nouvelle valeur de nbr dans stockage
newfichier=fopen("stockage.txt","w");
    if (newfichier!=NULL)
    {
        fprintf(newfichier,"%d",nbr);
    }
fclose(newfichier);
}
do//la boucle qui premet d'enregistrer autant de client que l'on souhaite
    {
    system("cls");
    printf("\n\n\n\t\t\t\t 1. ENREGISTRER UN AUTRE CLIENT      \t\t\n\n");
    printf("\t\t\t\t 2. RETOUR AU MENU CLIENT \t\t\n\n");
    printf("\t\t\t\t 3. ACCUEIL \t\t\n\n");
    scanf("%d",&choix);
    switch(choix)
        {
        case 1 :
        {
            EnregistrementClient();
            fin=1;
        }
        break;
        case 2:
        {
            clients();
            fin=1;
        }
        case 3 :
        {
            fin=1;
            menu();
        }
        break;
        default:
        printf("faites un choix entre 1, 2 ou 3 merci.\n");
        system("pause");
        }
    }while(fin!=1);
}



void rechChaine(FILE* fichier, char* str1)
{
char str2[100];
fichier = fopen("client.txt", "r");
newfichier = fopen("newtest.txt", "w");
if (fichier != NULL)
    {
        while (fgets(str2,1000, fichier)!=NULL)
      {
      if (strncmp(str1,str2,strlen(str1))==0)
        {
       k=ftell(fichier);
       z=1;
       break;
        }
        fprintf(newfichier,"%s",str2);
      }
      fclose(fichier);
      fclose(newfichier);
    }
}


void suprimeClient()//la fonction qui copie ls info des clients qui sont apres le client qui part.
{
    char str2[100];
    fichier = fopen("client.txt", "r");
    newfichier = fopen("newtest.txt", "a");
   if (fichier != NULL)
    {fseek(fichier,j,SEEK_SET);
        while (fgets(str2,1000, fichier)!=NULL)
        {
            fprintf(newfichier,"%s",str2);
        }
        fclose(fichier);
        fclose(newfichier);
    }
    remove("client.txt");
rename("newtest.txt","client.txt");
}


void afficheRecherche(FILE* fichier)
{char chaine[TAILLE_MAX] = "";
int fois=0;//le compteur qui permet de lire seulement les information du numero recherche
fichier = fopen("client.txt", "r");
        fseek(fichier,k,SEEK_SET);
        if (fichier != NULL)
        {
            do
            {
            fgets(chaine, TAILLE_MAX-1, fichier);
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
            fois++;
            }while (fois<3);
            j=ftell(fichier);
        fclose(fichier);
        }
}

void afficheClients(FILE* fichier)
{
    system("cls");
    char str2[100];
fichier = fopen("client.txt","r");

if (fichier != NULL)
    {
        while (fgets(str2,1000, fichier)!=NULL)
      {
        printf("%s",str2);
      }
      fclose(fichier);
      printf("\n");
    }
}







