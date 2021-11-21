#include <stdio.h>
/* declarer la structure */
struct InfoClients{
    char CIN[10];
    char Nom[10];
    char Prenom[10];
    double Montant;
};
/* fonction de saisir les infomations de compte*/
void    SaisirInfoClients(){
    struct InfoClients info;
    printf("entrer le CIN: ");
    scanf("%s",info.CIN);
    printf("entrer le Nom: ");
    scanf("%s",info.Nom);
    printf("entrer le Prenom: ");
    scanf("%s",info.Prenom);
    printf("entrer le Montant: ");
    scanf("%lf",&info.Montant);
}
/* fonction pour ajouter un neuveau compte*/
void    AjouterCompte(){
    printf("\n___Introduire un compte bancaire___\n\n");
    printf("__veuille saisir les informations__\n\n");
    SaisirInfoClients();
}
/* fonction pour ajouter plusieurs compte*/
void    AjouterPlusieurCompte(){
    int NbrClients,i;
    printf("\n___Introduire plusieurs compte bancaire___\n\n");
    printf("saisir le nombre des comptes que vou avez ajouter: \n");
    scanf("%d",&NbrClients);
    for (i = 1; i <= NbrClients; i++)
    {
        printf("\nveuille saisir les informations numero %d: \n\n",i);
        SaisirInfoClients();
    }
}
/* fonction pour afficher le menu principal de l'application*/
void    MenuPrincipal(){
    int choix;
    printf("\n\n**l\'application de Gestion de Bancaire**\n\n");
    do
    {
        
        printf("\n\n_1_Introduire un compte bancaire_________\n");
        printf("\n_2_Introduire plusieurs comptes bancaires\n");
        printf("\n_3_Operations____________________________\n");
        printf("\n_4_Affichage_____________________________\n");
        printf("\n_5_Fidelisation__________________________\n");
        printf("\n_6_Quitter l\'application_________________\n");
        printf("\n__________donner votre choix ____________\n");
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