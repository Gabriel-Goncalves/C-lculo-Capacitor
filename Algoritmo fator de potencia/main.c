#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lab.h"

int main() {
	int potencia,tensao,frequencia,tipo,a;
	float fator,rendimento,angulo,complexa,aparente,reativa,novoFator,pConsumida,novoQ,Qc,Xc,cap,ind;
	
	printf("Digite a potencia \n");
	scanf("%d",&potencia);
	printf("Se potencia esta em HP digite 1 se em Watts digite 2 \n");
	scanf("%d",&a);
	if(a == 1){
		potencia = potencia*746;
	}	
	printf("\nDigite o fator de potencia inicial\n");
	scanf("%f",&fator);
	printf("\n1-Capacitivo(adiantado) 2-Indutivo(atrasado)\n");
	scanf("%d",&tipo);
	printf("\nDigite a tensao que o motor esta submetido\n");
	scanf("%d",&tensao);
	printf("\nDigite a porcentagem do rendimento do motor\n");
	scanf("%f",&rendimento);
	printf("\nDigite a frequencia em hz\n");
	scanf("%d",&frequencia);
	printf("\nDigite o novo valor do novo fator de potencia desejado\n");
	scanf("%f",&novoFator);
	pConsumida = potencia/(rendimento/100);
	
	angulo= calcularAngulo(fator);
	complexa= calcularPotenciaComplexa(pConsumida,fator);
	reativa= calcularPotenciaQ(complexa,angulo);
	novoQ= calcularNovoQ(pConsumida , novoFator);
	Qc = reativa - novoQ;
	Xc = calcularXc(tensao, Qc);
	//cap = calcularCapacitor(Qc,frequencia,tensao);
	
	
	if(tipo==1){
		ind= calcularIndutor(Qc,frequencia,tensao);
	}
	else if(tipo==2){
		cap = calcularCapacitor(Qc,frequencia,tensao);
	}
	
	printf("\n##################################################\n\n");
	
	printf("Potencia ativa: %.3f W \n",pConsumida);
	printf("Potencia reativa: %.3f VAR\n",reativa);
	printf("Potencia Complexa: %.3f VA\n",complexa);
	printf("Valor do Capacitor %f  F",cap);
	printf("\nCorrente para circuito nao compensado = %.3f A\n",calcularCorrenteN(complexa, tensao));
	printf("Corrente para circuito compensado = %.3f  A\n",calcularCorrenteC(pConsumida, novoQ, tensao));
	
	printf("\n##################################################\n\n");
	system("pause");

	return 0;
}
