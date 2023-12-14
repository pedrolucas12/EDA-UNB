#include <stdio.h>

int main(){
	int *D, *E;
	int M,total=0, i;
	char L;
    D = calloc(31, sizeof(int));
    E = calloc(31, sizeof(int));
	while(scanf("%d %c", &M, &L) != EOF){
        if(L=='E') {
            E[M-30]++;
        }
        else {
            D[M-30]++;
        }
	}
	for(i=0; i<=31; i++){ 
        if(D[i]<E[i])
            total += D[i];
        else
            total += E[i];
    }
    printf("%d\n", total);
	return 0;
}