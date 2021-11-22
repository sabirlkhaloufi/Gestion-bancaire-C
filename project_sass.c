#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 200
/*Declarer de fichie Global*/
FILE *Data = NULL;
/* declarer la structure */

typedef struct{
    char CIN[10];
    char Nom[10];
    char Prenom[10];
    double Montant;
}InfoClients;

/* fonction de saisir les infomations de compte*/
void    SaisirInfoClients(){
    InfoClients info;
    printf("entrer le CIN: ");
    scanf("%s",info.CIN);
    printf("entrer le Nom: ");
    scanf("%s",info.Nom);
    printf("entrer le Prenom: ");
    scanf("%s",info.Prenom);
    printf("entrer le Montant: ");
    scanf("%lf",&info.Montant);
    printf("\n---Ajouter est Succee---\n");

    /*ouvrir de fichier et enregistrer les donnee des client dans ce */
    system("cls");
    Data = fopen("Data.txt","a");
    if(Data == NULL){
        printf("erreur");
    }
    else{
        fprintf(Data,"%s %s %s %lf \n",info.CIN,info.Nom,info.Prenom,info.Montant);
        fclose(Data);
    }
}
/* fonction pour ajouter un compte*/
void    AjouterCompte(){
    printf("\n___Introduire un compte bancaire___\n\n");
    printf("__veuille saisir les informations__\n\n");
    SaisirInfoClients();
}
/* fonction pour ajouter plusieurs compte*/
void    AjouterPlusieurCompte(){
    int NbrClients,i,j;
    InfoClients info[MAX];
    printf("\n___Introduire plusieurs compte bancaire___\n\n");
    printf("saisir le nombre des comptes que vou avez ajouter: \n");
    scanf("%d",&NbrClients);
    for (i = 1; i <= NbrClients; i++)
    {
        printf("\nveuille saisir les informations numero %d: \n\n",i);
        SaisirInfoClients();
    }
}
/*fonction pour les operations dans le compte*/
void    Operations(){
    int choix;
    system("cls");
    printf("\t---------Les opertaion-----------\n\n");
    printf("\t___1__Retrait__________:\n\n");
    printf("\t___2__Depot____________:\n\n");
    printf("\tEntrer votre choix:");
    scanf("%d",&choix);
    switch(choix){
        case 1:
        break;
        case 2:
        break;
        default:
            printf("__erreur de saisi__");
        break;
    }
}

/*fonction pour affichage*/
void    Affichage(){
    int choix;
    system("cls");
    printf("\t---------L\'affichage-----------\n\n");
    printf("\t___1__ Par Ordre Ascendant__________:\n\n");
    printf("\t___2__ Par Ordre Ascendant____________:\n\n");
    printf("\t___3__Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)__________:\n\n");
    printf("\t___4__Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre____________:\n\n");
    printf("\t___5__Recherche par CIN____________:\n\n");
    printf("\tEntrer votre choix:");
    scanf("%d",&choix);
    switch(choix){
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        default:
            printf("__erreur de saisi__");
        break;
    }
}

/* fonction pour afficher le menu principal de l'application*/
void    MenuPrincipal(){
    int choix;
    printf("\n\t---------------BIENVENU------------------\n\n");
    do
    {
        
        printf("\n\t__1_Introduire un compte bancaire_________\n");
        printf("\t__2_Introduire plusieurs comptes bancaires\n");
        printf("\t__3_Operations____________________________\n");
        printf("\t__4_Affichage_____________________________\n");
        printf("\t__5_Fidelisation__________________________\n");
        printf("\t__6_Quitter l\'application_________________\n");
        printf("\t____________donner votre choix ___________\n");
        scanf("%d",&choix);

        switch (choix)
        {
        case 1:
            AjouterCompte();
            break;
        case 2:
            AjouterPlusieurCompte();
            break;
        case 3:
            Operations();
            break;
        case 4:

            break;
        case 5:
            /* code */
            break;
        case 6:
            printf("\n\nvous avez quitte le programme:");
            break;
        default:
            printf("erreur de saisir  :\n");
            break;
        }
    } while (choix != 6);
    
}

int main(){
    MenuPrincipal();
    return 0;
}