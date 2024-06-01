#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i, j;
    int *a, *b, *c;
    printf("Entrez la ligne à afficher :\n");
    scanf("%d", &n);
    a = (int*)malloc((n+1)*sizeof(int));
    b = (int*)malloc((n+1)*sizeof(int));
    *(a+0) = 1;
    for(i = 1; i<=n; i++){
        *(b+0) = 1;
        for(j = 1; j<i; j++){
            *(b+j)= *(a+j-1) + *(a+j);
        }
        *(b+i) = 1;
        c = a;
        a = b;
        b = c;
    }
    for(i = 0; i<=n; i++){
        printf("%d ", *(a+i));
    }

    return 0;
}
