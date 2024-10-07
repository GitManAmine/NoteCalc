#include <iostream>
#include <stdio.h>
#include <stdlib.h>

float Calcul_Moyenne(float somme, float nombre) {
    return somme / nombre;
}


int main() {

    unsigned short int nbr_notes;
    float moyenne;
    float somme = 0;

    printf_s("Bienvenue ! La classe est de combien d'eleves ? ");
    scanf_s("%hu", &nbr_notes);

    if (nbr_notes <= 1) {
        printf("Erreur, le nombre de notes doit etre au dessus de 1 pour pouvoir faire une moyenne ");
        return 1;
    }

    else
    {
        float* tableau = (float*)malloc(nbr_notes * sizeof(float));

        if (tableau == NULL) {  // Si malloc échoue
            printf_s("Erreur de réservation de mémoire\n");
            return 1;
        }

        for (int i = 0; i < nbr_notes; i++)
        {
            printf_s("Note eleve %d :  ", i + 1);
            scanf_s("%f", &tableau[i]);
            somme += tableau[i];
        }


        printf_s("La moyenne est de : %.2f\n", Calcul_Moyenne(somme, nbr_notes));

        free(tableau);


    }
    return 0;
}
