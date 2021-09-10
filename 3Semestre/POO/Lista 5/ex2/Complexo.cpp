#include "Complexo.h"
#include <stdlib.h>
#include <math.h>

float * Complexo::soma(Complexo * c){
	float * resultado;
	resultado = (float *) malloc(2 * sizeof(float));
	resultado[0] = this->real + c->real;
	resultado[1] = this->imaginario + c->imaginario;
	
	return resultado;
} 

float * Complexo::subtracao(Complexo * c){
	float * resultado;
	resultado = (float *) malloc(2 * sizeof(float));
	resultado[0] = this->real - c->real;
	resultado[1] = this->imaginario - c->imaginario;
	
	return resultado;
} 

float * Complexo::multiplicacao(Complexo * c){
	float * resultado;
	resultado = (float *) malloc(2 * sizeof(float));
	resultado[0] = (this->real * c->real) - (this->imaginario * c->imaginario);
	resultado[1] = (this->real * c->imaginario) + (this->imaginario * c->real);
	
	return resultado;
} 

float Complexo::modulo(){
	float resultado;
	
	resultado = sqrt(pow(this->real, 2) + pow(this->imaginario, 2));	
	
	return resultado;
} 

Complexo::Complexo(float real, float imaginario){
	this->real = real;
	this->imaginario = imaginario;
}
