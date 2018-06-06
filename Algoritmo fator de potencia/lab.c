#include "lab.h"



float calcularAngulo(float x){
	float novo;
	novo= acos(x) * 57.3;
	return novo;
}

float calcularPotenciaComplexa(float w, float fp){
	float pot;
	pot = w/fp;
	return pot;
}

float calcularPotenciaQ(float s, float angulo){
	float q;
	q= s * sin(angulo/57.3);
	return q;
}

float calcularNovoQ(float p , float a){
	float Qn;
	float angulo = acos(a)*57.3;
	Qn = p * tan(angulo);
	return Qn;
}

float calcularXc(int tensao, float qc){
	float xc;
	xc= pow(tensao,2) / qc;
	return xc;
}

float calcularCapacitor(float qc, int frequencia, int tensao){
	float cap;
	cap= qc/(2*3.14*frequencia*pow(tensao,2));
	return cap;
}

float calcularIndutor(float qc, int frequencia, int tensao){
	float ind;
	ind= pow(tensao,2)/(2*3.14*frequencia*qc);
	return ind;
}

float calcularCorrenteN(float s, int tensao){
	float corrente;
	corrente = s/tensao;
	return corrente;
}

float calcularCorrenteC(float p, int q, int tensao){
	float corrente;
	corrente= (sqrt(pow(p,2)+pow(q,2)))/tensao;
	return corrente;
}

