#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lstduplamencad.h"

int main(){
	LstNum* l = inicializaLstNum();

	Numeros* numero1 = inicializatiponum("dener","rua de dener", 111);
	Numeros* numero2 = inicializatiponum("joao","rua de joao", 222);


	l = insere(l, numero1);
	l = insere(l, numero2);

	imprime(l);

	Numeros* retirado;
	retirado = retira(l, 000);
	if(retirado != NULL){
		imprime(l);
	}
	else{
		printf("\nNao foi possivel retirar o aluno de matricula 000 da lista\n");
	}
	
	libera(l);

	return 0;
}