#include <stdio.h>
#include <stdlib.h>

void allouer(int n, int **a, int **b){
    *a = (int*)malloc((n+1)*sizeof(int));
    *b = (int*)malloc((n+1)*sizeof(int));
}
void calculer(int n, int **a, int **b){
    int i,j;
    int *c;
      (*a)[0] = 1;  // Initialisation de la première ligne
    for(i = 1; i <= n; i++){
        (*b)[0] = 1;  // Premier élément de chaque ligne est 1
        for(j = 1; j < i; j++){
            (*b)[j] = (*a)[j-1] + (*a)[j];  // Calcul des coefficients
        }
        (*b)[i] = 1;  // Dernier élément de chaque ligne est 1
        c = *a;
        *a = *b;
        *b = c;
    }
}
void afficher(int n, int *a){
 int i;
 for(i = 0; i<=n; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
}
int main() {
    int n;
    int *a, *b;
    printf("Entrez la ligne à afficher :\n");
    scanf("%d", &n);
    allouer(n,&a,&b);
    calculer(n,&a,&b);
    afficher(n,a);
    free(a); free(b);

    return 0;
}
