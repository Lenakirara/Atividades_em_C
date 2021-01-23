#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tamanho 100

int main() {
	setlocale(LC_ALL, "portuguese");

	// declarando e inicializando vari�vies
	int c, numConta[tamanho] = { 0 }, KwConsumido[tamanho] = { 0 }, maiorConsumo = 0,
		menorConsumo = 0, totalCadastrado = 1, opcaoMenu;
	int altoConsumo = 170, quantosCadastros = 0;
	float mediaConsumo = 0, valorPagar = 0, valorKw = 1.75;
	// fazendo o menu com do while e switch
	do {
		//declarando e inicializando variaveis dento do do while
		int resulTotal = 0;
		int aux = 0;
		int counter = 0;

		// menu para cadastro e analise de informa��es
		printf("******************* MENU *********************\n");
		printf("**********************************************\n");
		printf("****    Sistema de consumo de energia     ****\n");
		printf("**********************************************\n");
		printf("****   Escolha uma das op��es do menu     ****\n");
		printf("* 1 - Cadastrar novo consumidor            ***\n");
		printf("* 2 - Consultar consumidor cadastrado      ***\n");
		printf("* 3 - Verificar maior consumo              ***\n");
		printf("* 4 - Verificar menor consumo              ***\n");
		printf("* 5 - Verificar m�dia de consummo          ***\n");
		printf("* 6 - Quantidade de consumo acima de 170kw ***\n");
		printf("* 7 - Sair                                 ***\n");
		printf("**********************************************\n");
		scanf_s("%d", &opcaoMenu);
		while ((c = getchar()) != '\n' && c != EOF) {}
		// iniciando as escolhas por meio de switvh - case
		switch (opcaoMenu)
		{
			// solicita cadastro de consumidores
		case 1:
			printf("\n\n");
			printf("**** Executando opera��o de cadastro de novo consumidor... * ***\n\n");
				printf("Quantos consumidores deseja cadastrar: ");
			scanf_s("%d", &quantosCadastros);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("\n\n");
			/*la�o para cadastrar a quantidade de consumidores solicitada
			armazenar a quantidade de dados cadastrados - caso apos uma solicita��o
			de cadastro e queira depois fazer cadastrar mais outros evitando
			que um sobreponha o outro*/
			int i;
			for (i = totalCadastrado; i < (quantosCadastros + totalCadastrado);
				i++) {
				// para n�o repetir numero de conta
				numConta[i] = i;
				printf("N�mero da conta do novo consumidor: %d\n", i);
				printf("Digite o numero de KW consumido: ");
				scanf_s("%d", &KwConsumido[i]);
				while ((c = getchar()) != '\n' && c != EOF) {}
				printf("\n");
			}
			totalCadastrado = totalCadastrado + quantosCadastros;
			// outro la�o dentro do case 1 - agora para somar os resultados de consumo(maior, menor e media)
				for (i = 1; i < totalCadastrado; i++)
				{
					// soma do total de pessoas cadastradas
					resulTotal = resulTotal + KwConsumido[i];
					// calculo para verificar o maior e o menor consumo
					aux = aux + 1;
					if (aux == 1) {
						maiorConsumo = KwConsumido[i];
						menorConsumo = KwConsumido[i];
					}
					else if (KwConsumido[i] > maiorConsumo) {
						maiorConsumo = KwConsumido[i];
					}
					else if (KwConsumido[i] < menorConsumo) {
						menorConsumo = KwConsumido[i];
					}
				}
			// media de consumo
			mediaConsumo = resulTotal / totalCadastrado;
			break;
			// op��o 2 - verificando o que foi cadastrado
		case 2:
			for (i = 1; i < totalCadastrado; i++) {
				// calculando o valor que o consumidor ir� pagar pela quantidade gasta de kw no mes.
					valorPagar = KwConsumido[i] * valorKw;
				printf("**** Executando informa��es sobre consumidor... ****\n\n");
				printf("Numero da conta: %d\n", numConta[i]);
				printf("Valor total de KW consumido no m�s: %d\n",
					KwConsumido[i]);
				printf("Valor total a pagar: R$%.2f\n\n", valorPagar);
				printf("****************************************\n\n");
			}
			break;
			// op��o 3 para verifica��o do maior consumo
		case 3:
			printf("**** Executando informa��es sobre maior consumo registrado... * ***\n\n");
				//la�o para verificar quem teve maior consumo
				for (i = 1; i < totalCadastrado; i++)
				{
					if (maiorConsumo == KwConsumido[i])
					{
						printf("Consumidor conta n� %d\n\n", numConta[i]);
						printf("Maior consumo: %d\n\n\n", maiorConsumo);
					}
				}
			break;

			// op��o 4 para verifica��o do menor consumo
		case 4:
			printf("**** Executando informa��es sobre menor consumo registrado.. * ***\n\n");
				//la�o para verificar quem teve menor consumo
				for (i = 1; i < totalCadastrado; i++)
				{
					if (menorConsumo == KwConsumido[i])
					{
						printf("Consumidor conta n� %d\n\n", numConta[i]);
						printf("Menor consumo: %d\n\n\n", menorConsumo);
					}
				}
			break;
			// op��o 5 - verificando media de consumo
		case 5:
			printf("**** Executando informa��es sobre media de consumo registrado... ****\n\n");
				printf("A Media de consumo foi de %.2f\n\n\n", mediaConsumo);
			break;
			// op��o 6 - verificando se ultrapassou consumo
		case 6:
			printf("**** Executando informa��es sobre consumo acima de 170KW...* ***\n\n\n");
				//la�o para verificar a quantidade consumidores que tiveram o consumo acima de 170kw
				for (i = 1; i < totalCadastrado; i++)
				{
					//if (altoConsumo < KwConsumido[i])
					if (KwConsumido[i] > altoConsumo)
					{
						counter = counter++;
					}
				}
			printf("O n�mero de consumidores que excedem 170KW: %d\n\n\n", counter);
			break;
			// op��o 7 para sair do programa
		case 7:
			exit(0);
			break;
			// caso seja digitado algum numero fora do menu - mensagem de erro!!
		default:
			printf("Op��o inv�lida!\n");
			printf("Por favor, digite as op��es do menu entre [1] e [7]\n\n\n");
			break;
		}
	} while (opcaoMenu != 7);
	system("pause");
	return 0;
}