#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct victime{
    int user_type;
    int genre;
    int age;
    int gravité;
    struct victime * vsuivant;
}victime;
typedef struct voiture{
    int el;
    int purpose;
    victime * v;
    struct voiture *  Asuivant; 
}voiture;
typedef voiture  * pvoiture;
typedef struct crash{
    char *collisionID;
    struct crash *fg;
    struct crash *fd;
    int equilibre;
}crash;
typedef crash *pcrash;
pcrash creationArbre(int id){
        pcrash n = malloc(sizeof(crash));
        if(n = NULL) exit(0);
        n->collisionID=id;
        n->fg = NULL;
        n->fd = NULL;
        return n;
}
pcrash RotationDroite(pcrash a){
    pcrash pivot;
    int eq_a;
    int eq_p;
    pivot = a->fd;
    a->fg = pivot->fd;
    pivot->fg = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    eq_a = eq_a - min(eq_p,0) +1;
    eq_p = max(1+eq_p,2+eq_a,2+eq_a + eq_p);
    a = pivot;
    return a;
}
pcrash RotationGauche(pcrash a){
    pcrash pivot;
    int eq_a;
    int eq_p;
    pivot = a->fg;
    a->fd = pivot->fg;
    pivot->fg = a;
    eq_a = a->equilibre;
    eq_p = pivot->equilibre;
    eq_a = eq_a - max(eq_p,0)-1;
    eq_p = min(eq_p-1,eq_p + eq_a +2,eq_a+eq_p-2);
    a = pivot;
    return a;
}
pcrash DoubleRotationG(pcrash a){
    if(a==NULL) exit(1);
    a->fg = RotationDroite(a->fg);
    a = RotationGauche(a);
    return a;
}
pcrash DoubleRotationD(pcrash a){
    a->fd = RotationGauche(a->fd);
    a = RotationDroite(a);
    return a;
}
pcrash equilibrageAVL(pcrash a){
    if(a->equilibre >=2){
        if(a->fd->equilibre >= 0){
            return RotationGauche(a);
        }
        return DoubleRotationG(a);
    }
    else if(a->equilibre <=-2){
        if(a->fg->equilibre <= 0){
            return RotationDroite(a);
        }
        return DoubleRotationD(a);
    }
    return a;

}
pcrash insertionAVL(pcrash a,int e, int *h){
    if (a==NULL){
        *h = 1;
        return creationArbre(e);
    }
    else if(e < a->collisionID){}
    else if(e > a->collisionID){}
}
int main(int argc, char* argv[]){
    if(argc <2){
        printf("ERREUR");
    }


}
