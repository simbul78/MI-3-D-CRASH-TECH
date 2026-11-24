#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct victime{
    int numv;
    struct victime * vsuivant

}
typedef struct voiture{
    int el;
    victime * v;
    struct voiture *  Asuivant; 
}voiture
typedef struct crash{
    char *num;


}
int main(int argc, char* argv[]){
    if(argc <2){
        printf("ERREUR");
    }


}
