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

void initialiserTableau(stat_annee statistiques[]){

    for(int i = 0; i< NB_ANNEE; i++){
        statistiques[i].annee = 2005 + i;


        statistiques[i].nbaccidents = 0;
        statistiques[i].nbindemnes = 0;
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


void LireCsv(stat_annee statistiques[]){
    FILE * fichier = fopen("???.csv", "r");
    if(fichier == NULL){
        printf("erreur lors de l'ouverture du fichier");
        return;
    }

    char ligne = [1000];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL){
        printf("%s", ligne);

        int id_accident;
        int gravite;
        int annee;
        char *element
        
        element= strtok(ligne, ";");; //1 colonne
        annee = atoi(element);
        element = strtok(NULL, ";");  // 2 colonne
        id_accident = atoi(element);
        element = strtok(NULL, ";");
        element = strtok(NULL, ";");
        element = strtok(NULL, ";");
        element = strtok(NULL, ";");
        gravite = atoi(element);
           
    }
      fclose(fichier);
    
    int indice = annee - 2005;

    if(gravite == 1){
        statistiques[indice].nbindemnes++;
    }else if(gravite == 2){
        statistiques[indice].nbmorts++;
    }else if(gravite == 3){
        statistiques[indice].nbblesses_graves++;
    }else{
        statistiques[indice].nbblesses_leger++;
    }

    int derniereAnnee = 1;
    int dernierAccident = 1;

    if(annee != derniereAnnee || id_accident != dernierAccident){
        statistiques[indice].nbaccidents++;
    }





}





int main(){
    stat_annee statistiques[NB_ANNEE];

    initialiserTableau(statistiques);

    afficheTableau(stat_annee statistiques);

    return 0;
}









