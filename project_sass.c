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
    system("cls");
    printf("\n___Introduire un compte bancaire___\n\n");
    printf("__veuille saisir les informations__\n\n");
    printf("entrer le CIN: ");
    scanf("%s",info[0].CIN);
    printf("entrer le Nom: ");
    scanf("%s",info[0].Nom);
    printf("entrer le Prenom: ");
    scanf("%s",info[0].Prenom);
    printf("entrer le Montant: ");
    scanf("%f",&info[0].Montant);
    printf("\n%s %s %s %f\n",info[0].CIN,info[0].Nom,info[0].Prenom,info[0].Montant);
    printf("\n---Ajouter est Succee---\n");

}
/* fonction pour ajouter plusieurs compte*/
void    AjouterPlusieurCompte(){
    system("cls");
    int NbrClients,i,j;
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
    for (j = 0; j < NbrClients; j++){
        printf("\nles informations de client numero %d\n\n",j+1);
        printf("%s ",info[j].CIN);
        printf("%s ",info[j].Nom);
        printf("%s ",info[j].Prenom); 
        printf("%f ",info[j].Montant);
        printf("\n");
    }
    printf("\n---Ajouter est Succee---\n");
}

/* fonction pour rechercher des compte par CIN*/
int    RechercheParCIN(){
    InfoClients CIN;
    int i;
    printf("donner votre CIN:");
    scanf("%s",CIN.CIN);
    for(i = 0;i<NbrClients;i++){
        int test = strcmp(CIN.CIN,info[i].CIN);
        if(test == 1){
            return i;
        }
        else{
            printf("ce cin nexest pas:");
        }
    }

}
/* fonction pour retrait de montant*/
void    Retrait(){
    float Montant;
    int i = RechercheParCIN();
    printf("\n%s %s %s %f\n",info[0].CIN,info[0].Nom,info[0].Prenom,info[0].Montant);
    printf("donner le Montant pour retrait:");
    scanf("%f",&Montant);
    info[i].Montant = info[i].Montant - Montant;
    printf("\n%s %s %s %f\n",info[0].CIN,info[0].Nom,info[0].Prenom,info[0].Montant);
}

/* fonction pour depot de montant*/
void    Depot(){
    float Montant;
    int i = RechercheParCIN();
    printf("\n%s %s %s %f\n",info[0].CIN,info[0].Nom,info[0].Prenom,info[0].Montant);
    printf("donner le Montant pour depot:");
    scanf("%f",&Montant);
    info[i].Montant = info[i].Montant + Montant;
    printf("\n%s %s %s %f\n",info[0].CIN,info[0].Nom,info[0].Prenom,info[0].Montant);
    
}
/*fonction pour les operations dans le compte*/

void    Operations(){
    system("cls");
    int choix;
    system("cls");
    printf("\t---------Les opertaion-----------\n\n");
    printf("\t___1__Retrait__________:\n\n");
    printf("\t___2__Depot____________:\n\n");
    printf("\tEntrer votre choix:");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            Retrait();
        break;
        case 2:
            Depot();
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
    system("cls");
    int choix;
    printf("\n\t---------------BIENVENU------------------\n\n");
    do
    {
        
        printf("\n\t__1_Introduire un compte bancaire_________\n\n");
        printf("\t__2_Introduire plusieurs comptes bancaires\n\n");
        printf("\t__3_Operations____________________________\n\n");
        printf("\t__4_Affichage_____________________________\n\n");
        printf("\t__5_Fidelisation__________________________\n\n");
        printf("\t__6_Quitter l\'application_________________\n\n");
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
             Affichage();
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