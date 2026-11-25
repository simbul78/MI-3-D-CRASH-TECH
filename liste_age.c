#include <stdlib.h>
#include "liste_age.h"

int liste_age_ajouter(NoeudAge **tete, unsigned char age, int idx_usager, int idx_genre){
    NoeudAge **courant = tete;

    /* Recherche de la position (liste triée par âge décroissant) */
    while (*courant != NULL && (*courant)->age > age) {
        courant = &(*courant)->suivant;
    }

    /* Âge absent de la liste : on crée un chaînon à cette position */
    if (*courant == NULL || (*courant)->age != age) {
        NoeudAge *noeud = calloc(1, sizeof(NoeudAge));
        if (noeud == NULL) {
            return -1;
        }
        noeud->age     = age;
        noeud->suivant = *courant;
        *courant = noeud;
    }

    (*courant)->compteur[idx_usager][idx_genre]++;
    return 0;
}

void liste_age_liberer(NoeudAge *tete)
{
    while (tete != NULL) {
        NoeudAge *suivant = tete->suivant;
        free(tete);
        tete = suivant;
    }
}

unsigned int noeud_age_compter(const NoeudAge *noeud, int idx_usager, int idx_genre)
{
    unsigned int somme = 0;
    for (int u = 0; u < NB_TYPES_USAGER; u++) {
        if (idx_usager >= 0 && u != idx_usager) continue;
        for (int g = 0; g < NB_GENRES; g++) {
            if (idx_genre >= 0 && g != idx_genre) continue;
            somme += noeud->compteur[u][g];
        }
    }
    return somme;
}
