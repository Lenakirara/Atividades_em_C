#include<stdio.h>
#include<stdlib.h>
#include<locale>

int main() {
	setlocale(LC_ALL, "Portuguese");
	// declarando e inicializando variavies
	float fem_sim = 0, fem_nao = 0, masc_sim = 0, masc_nao = 0, per_fem_sim, per_masc_nao;
	int c, cont = 0, sexo, sim = 0, nao = 0, tot_fem, tot_masc, resposta, total_entrevistados;
	printf("Informar a quantidade de pessoas entrevistadas: "); /*Solicitar quantidade de
	pessoas entrevistadas*/
	scanf_s("%d", &total_entrevistados);
	while ((c = getchar()) != '\n' && c != EOF) {}
	printf("\n");
	//Fazendo o laço de repetição para informar o sexo e a opção escolhida
	while (cont < total_entrevistados) {
		printf("Informe o sexo do entrevistado: [1] Feminino e[2] Masculino : ");
		scanf_s("%d", &sexo);
		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Informe a resposta do entrevistado: [1] Sim e [2] Não: ");
		scanf_s("%d", &resposta);
		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("\n\n");
		cont++;

		//Condicional para validar as opçoes escolhidas que foram dadas quanto ao sexo e resposta(sim ou nao)
			if (sexo == 1 && resposta == 1) {
				fem_sim++; sim++;
			}
			else if (sexo == 1 && resposta == 2) {
				fem_nao++; nao++;
			}
			else if (sexo == 2 && resposta == 1) {
				masc_sim++, sim++;
			}
			else if (sexo == 2 && resposta == 2) {
				masc_nao++, nao++;

			}
			else {
				printf("Opção invalida!");
				printf("\n");
			}
	}

	// efetuando o calcula da quantidade de resposta dadas
	//Quantidade de pessoas que foram entrevistadas (homens e mulheres)
	tot_fem = fem_sim + fem_nao;
	tot_masc = masc_sim + masc_nao;
	sim = fem_sim + masc_sim;
	nao = fem_nao + masc_nao;

	/*Percentual de mulheres que responderam sim e homens que responderam nãoPercentual
	de mulheres que responderam sim e homens que responderam não*/
	per_fem_sim = (fem_sim / 100);
	per_masc_nao = (masc_nao / 100);
	//impirmindo na tela os resultados
	printf("Número de pessoas que responderam sim: %d", sim);
	printf("\n");
	printf("Número de pessoas que responderam não: %d", nao);
	printf("\n");
	printf("Percentual de pessoas do sexo feminino que responderam sim: %.2f", per_fem_sim);
	printf("\n");
	printf("Percentual de pessoas do sexo masculino que responderam não: %.2f", per_masc_nao);
	printf("\n");
	printf("\n");
	system("pause");
	return 0;
}
