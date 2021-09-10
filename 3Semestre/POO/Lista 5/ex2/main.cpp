#include <stdio.h>
#include <stdlib.h>
#include "Complexo.h"
#include<iostream>

using namespace std;

int main(){
	
	float * n1, * n2, * resultado;

	Complexo c1((float)4,(float)2.5);
    Complexo c2((float)1.8,(float)2);
	
	resultado = c1.soma(&c2);
	
	cout << resultado;
	
	free(resultado);
	
	return 0;
}
