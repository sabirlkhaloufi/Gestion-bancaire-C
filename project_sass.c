#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/*Declarer de fichie Global*/
//FILE *Data = NULL;
/* declarer la structure */
typedef struct{
    char CIN[10];
    char Nom[10];
    char Prenom[10];
    float Montant;
}InfoClients;

/* declarer le tableu global */
InfoClients info[10];
int NbrClients;

/* Prototype des fonctions */
void MenuPrincipal();
void    AjouterCompte();
void    AjouterPlusieurCompte();
void    Operations();
int    RechercheParCIN();
void    Retrait();
void    Depot();
void    Affichage();
void    AfficherTousLesCompte();
void    ParOrdreAscendant();

/*
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

    system("cls");
    Data = fopen("Data.txt","a");
    if(Data == NULL){
        printf("erreur");
    }
    else{
        fprintf(Data,"%s %s %s %lf \n",info.CIN,info.Nom,info.Prenom,info.Montant);
        fclose(Data);
    }
}*/

/* fonction pour ajouter un compte*/
void    AjouterCompte(){
    int i = 0;
    system("cls");
    printf("\n___Introduire un compte bancaire___\n\n");
    printf("__veuille saisir les informations__\n\n");
    printf("entrer le CIN: ");
    scanf("%s",info[i].CIN);
    printf("entrer le Nom: ");
    scanf("%s",info[i].Nom);
    printf("entrer le Prenom: ");
    scanf("%s",info[i].Prenom);
    printf("entrer le Montant: ");
    scanf("%f",&info[i].Montant);
    printf("\n%s %s %s %f\n",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
    printf("\n---Ajouter est Succee---\n");
    i++;

}
/* fonction pour ajouter plusieurs compte*/
void    AjouterPlusieurCompte(){
    system("cls");
    int NbrClients,i;
    printf("\n___Introduire plusieurs compte bancaire___\n\n");
    printf("saisir le nombre des comptes que vou avez ajouter: \n");
    scanf("%d",&NbrClients);
    for (i = 0; i < NbrClients; i++)
    {
        printf("\nveuille saisir les informations numero %d: \n\n",i+1);
        printf("entrer le CIN: ");
        scanf("%s",info[i].CIN);
        printf("entrer le Nom: ");
        scanf("%s",info[i].Nom);
        printf("entrer le Prenom: ");
        scanf("%s",info[i].Prenom);
        printf("entrer le Montant: ");
        scanf("%f",&info[i].Montant);
    }
    for (i = 0; i < NbrClients; i++){
        printf("\nles informations de client numero %d\n\n",i+1);
        printf("%s ",info[i].CIN);
        printf("%s ",info[i].Nom);
        printf("%s ",info[i].Prenom); 
        printf("%f ",info[i].Montant);
        printf("\n");
    }
    printf("\n---Ajouter est Succee---\n");
}

/* fonction pour rechercher des compte par CIN avec fonction strstr*/
int    RechercheParCin(){
    char cin[10];
    int i;
    printf("donner votre CIN:");
    scanf("%s",cin);
    for(i = 0;i<sizeof(info);i++)
    {
        if(strstr(cin,info[i].CIN))
        {
            return i;
        }
    }
}
/* fonction pour retrait de montant*/
void    Retrait(){

    float Montant;
    int i = RechercheParCin();
    printf("\n%s %s %s %f\n",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
    printf("\ndonner le Montant pour retrait: ");
    scanf("%f",&Montant);

    if(Montant > info[i].Montant){
        printf("impossible Pour retrait!!!");
    }
    else{
        info[i].Montant = info[i].Montant - Montant;
        printf("\n%s %s %s %f\n",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
    }
}

/* fonction pour depot de montant*/
void    Depot(){
    float Montant;
    int i = RechercheParCin();
    printf("\n%s %s %s %f\n",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
    printf("\ndonner le Montant pour depot:");
    scanf("%f",&Montant);
    info[i].Montant = info[i].Montant + Montant;
    printf("\n%s %s %s %f\n",info[i].CIN,info[i].Nom,info[i].Prenom,info[i].Montant);
    
}
/*fonction pour les operations dans le compte*/

void    Operations(){
    system("cls");
    int choix;
    printf("\n\n\t---------Les opertaion-----------\n\n");
    printf("\t___[1]__Retrait__________:\n\n");
    printf("\t___[2]__Depot____________:\n\n");
    printf("\t___[3]____Menu Principal____________:\n\n");
    printf("\tEntrer votre choix:");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            Retrait();
        break;
        case 2:
            Depot();
        break;
        case 3:
            MenuPrincipal();
        break;
        default:
            printf("__erreur de saisi__");
        break;
    }
}
void    Tri(){
    
}

/* fonction pour afficher les compte par ordre ascendant*/
void    ParOrdreAscendant(){

}
/*fonction pour affichage*/
void    Affichage(){
    int choix;
    system("cls");
    printf("\t---------L\'affichage-----------\n\n");
    printf("\t___[1]__ Par Ordre Ascendant__________:\n\n");
    printf("\t___[2]__ Par Ordre Ascendant____________:\n\n");
    printf("\t___[3]__Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)__________:\n\n");
    printf("\t___[4]__Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre____________:\n\n");
    printf("\t___[5]__Recherche par CIN____________:\n\n");
    printf("\t___[6]____Menu Principal____________:\n\n");
    printf("\tEntrer votre choix:");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            ListTousLesComptes();
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
            MenuPrincipal();
        break;
        default:
            printf("__erreur de saisi__");
        break;
    }
}

/* fonction pour afficher le menu principal de l'application*/
void    MenuPrincipal(){
    system("cls");
    int choix;
    printf("\n\t---------------BIENVENU------------------\n\n");
    do
    {
        
        printf("\n\t__[1]_Introduire un compte bancaire_________\n\n");
        printf("\t__[2]_Introduire plusieurs comptes bancaires\n\n");
        printf("\t__[3]_Operations____________________________\n\n");
        printf("\t__[4]_Affichage_____________________________\n\n");
        printf("\t__[5]_Fidelisation__________________________\n\n");
        printf("\t__[6]_Quitter l\'application_________________\n\n");
        printf("\t____________donner votre choix ___________\n\n");
        scanf("\t%d",&choix);

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