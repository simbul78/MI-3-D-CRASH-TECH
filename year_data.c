#include<stdio.h>                                                     


typedef struct {
    int annee;
    int nbaccidents;
    int nbindemnes;
    int nbmorts;
    int nbblesses_graves;
    int nbblesses_leger;
}stat_annee;

stat_annee statistiques[NB_ANNEE];

void initialiserTableau(statistiques[]){

    for(int i = 0; i< NB_ANNEE; i++){
        statistiques[i].annee = 2005 + i;


        statistiques[i].nbaccidents =0;
        statistiques[i].nbindemnes =0;
        statistiques[i].nbmorts = 0;
        statistiques[i].nbblesses_graves =0;
        statistiques[i].nbblesses_leger =0;
    }

}



void afficheTableau(stat_annee statistiques[]){
    for(int i= 0; i< NB_ANNEE; i++){
        printf("nombre d'accident: %d", statistiques[i].nbaccidents);
        printf("nombre d' indemne : %d",  statistiques[i].nbindemnes);
        printf("nombre de mort : %d", statistiques[i].nbmorts);
        printf("nombre de blessés graves : %d", statistiques[i].nbblesses_graves);
        printf("nombre de blessés légerement : %d ", statistiques[i].nbblesses_leger);
    }
}




int main(){
    stat_annee statistiques[NB_ANNEE];

    initialiserTableau(statistiques);

    afficheTableau(stat_annee statistiques);

    return 0;
}