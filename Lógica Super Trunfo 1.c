#include <stdio.h>

int main() {

    //declaração de variaveis
    char estado1 [30], codigo1[4], cidade1[30];
    int ponto_turistico1;
    float area1, pib1, densidade_populacional1, pib_per_capita1;
    unsigned long int populacao1;

    //declaração de variaveis do segundo estado
    char estado2[30], codigo2[4], cidade2[30];
    int ponto_turistico2;
    float area2, pib2, densidade_populacional2, pib_per_capita2;
    unsigned long int populacao2;

    //entrada de dados da primeira carta

    printf("Digite o estado (A-H): \n");
   scanf("%29s", estado1); 

printf("Digite o código de identificação (3 caracteres): \n");
   scanf("%3s", codigo1); 


printf("Digite uma cidade:\n");
   scanf ("%29s", cidade1); 

printf("Digite a população: \n ");
   scanf("%lu", &populacao1); 

printf("Digite o número de pontos turísticos: \n");
   scanf("%d", &ponto_turistico1); 

printf("Digite a área em km: \n");
   scanf("%f", &area1); 

printf("Digite o PIB do local: \n");
   scanf("%f", &pib1); 

   printf("\n Carta 1 registrada com sucesso!\n");

  //entrada de dados da segunda carta

  printf("Digite o estado (A-H): \n");
   scanf("%29s", estado2); 

printf("Digite o código de identificação (3 caracteres): \n");
   scanf("%3s", codigo2); 

printf("Digite uma cidade: \n");
   scanf ("%29s", cidade2); 

printf("Digite a população: \n");
   scanf("%lu", &populacao2); 

printf("Digite o número de pontos turísticos: \n");
   scanf("%d", &ponto_turistico2); 

printf("Digite a área em km: \n");
   scanf("%f", &area2); 

printf("Digite o PIB do local: \n");
   scanf("%f", &pib2); 

printf("\n Carta 2 registrada com sucesso!\n");

   //saída de dados da primeira carta

printf("\n--- Carta do Estado 1 ---\n");

 printf("Estado: %s\n", estado1);
 printf("Código de identificação: %s\n", codigo1);
 printf("Cidade: %s\n", cidade1);
 printf("População: %lu\n", populacao1);
 printf("Número de pontos turísticos: %d\n", ponto_turistico1);
 printf("Área (km): %.2f\n", area1);
 printf("PIB: %.2f\n", pib1);

   //saída de dados da segunda carta

printf("\n---Carta do Estado 2---\n");

printf("Estado: %s\n", estado2);
printf("Código de identificação: %s\n", codigo2);
printf("Cidade: %s\n", cidade2);
printf("População: %lu\n", populacao2);
printf("Número de pontos turísticos: %d\n", ponto_turistico2);
printf("Área (km): %.2f\n", area2);
printf("PIB: %.2f\n", pib2);

 //----Calculando densidade populacional e PIB per capita----

   //calculo de densidade populacional
    densidade_populacional1 = populacao1 / area1;
    densidade_populacional2 = populacao2 / area2;

    //calculo de pib per capita
    pib_per_capita1 = pib1 / populacao1;
    pib_per_capita2 = pib2 / populacao2;

   //saída de dados calculados
   printf("Densidade Populacional do Estado 1: %.2f habitantes/km²\n", densidade_populacional1);
   printf("PIB per capita do Estado 1: %.2f\n", pib_per_capita1);

   printf("Densidade Populacional do Estado 2: %.2f habitantes/km²\n", densidade_populacional2);
   printf("PIB per capita do Estado 2: %.2f\n", pib_per_capita2);

    //Criação menu interativo para comparar atributos
      printf("\nMenu de Comparação de Atributos:\n");
      printf("1. População\n");
      printf("2. Número de Pontos Turísticos\n");
      printf("3. Densidade Populacional\n");
      printf("4. PIB per capita\n");
      printf("5. Área\n");
   
      int opcao1;
      printf("Escolha um atributo para comparar (1-5): ");
      if (scanf("%d", &opcao1) != 1) {
          printf("Entrada inválida. Encerrando o programa.\n");
          return 1;
      }

   //escolha primeira opção

      float valor1 = 0.0f, valor2 = 0.0f;
      switch (opcao1) {
          case 1:
              valor1 = (float) populacao1;
              valor2 = (float) populacao2;
              break;
          case 2:
              valor1 = (float) ponto_turistico1;
              valor2 = (float) ponto_turistico2;
              break;
          case 3:
              /* comparar pela densidade diretamente (maior densidade = maior valor) */
              valor1 = densidade_populacional1;
              valor2 = densidade_populacional2;
              break;
          case 4:
              /* opção 4 corresponde a PIB per capita (conforme menu) */
              valor1 = pib_per_capita1;
              valor2 = pib_per_capita2;
              break;
          case 5:
              valor1 = area1;
              valor2 = area2;
              break;
          default:
              printf("Opção inválida. Encerrando o programa.\n");
              return 1;
      }
   
      if (valor1 > valor2) {
          printf("O Estado 1 (%s) tem maior valor no atributo escolhido.\n", estado1);
      } else if (valor2 > valor1) {
          printf("O Estado 2 (%s) tem maior valor no atributo escolhido.\n", estado2);
      } else {
          printf("Ambos os Estados têm valor igual no atributo escolhido.\n");
      }
   
      if (opcao1 == 3) {
          if (densidade_populacional1 < densidade_populacional2) {
              printf("O Estado 1 (%s) é o menos denso populacionalmente.\n", estado1);
          } else if (densidade_populacional2 < densidade_populacional1) {
              printf("O Estado 2 (%s) é o menos denso populacionalmente.\n", estado2);
          } else {
              printf("Ambos os Estados igualam na densidade populacional.\n");
          }
      }

//escolha da segunda opção
int opcao2;
printf ("Escolha agora uma segunda opção para comparar:\n");
        if (opcao1 != 1) printf ("1. População\n");
        if (opcao1 != 2) printf ("2. Pontos Turísticos\n");
        if (opcao1 != 3) printf ("3. Densidade Populacional\n");
        if (opcao1 != 4) printf ("4. PIB per capita\n");
        if (opcao1 != 5) printf ("5. Área\n");

        if (scanf("%d", &opcao2) != 1) {
            printf("Entrada inválida. Encerrando o programa.\n");
            return 1;
        }

        //impedir escolha igual
        if (opcao2 == opcao1) {
          printf ("Você não pode escolher a mesma opção\n");
          return 1;
        }

        if (opcao2 < 1 || opcao2 > 5) {
            printf("Opção inválida. Encerrando o programa.\n");
            return 1;
        }
         
//Valores segunda opção

float valor3 = 0.0f, valor4 = 0.0f;

switch (opcao2) {

   case 1: valor3 = (float) populacao1; valor4 = (float) populacao2; break;
   case 2: valor3 = (float) ponto_turistico1; valor4 = (float) ponto_turistico2; break;
   case 3: valor3 = densidade_populacional1; valor4 = densidade_populacional2; break;
   case 4: valor3 = pib_per_capita1; valor4 = pib_per_capita2; break;
   case 5: valor3 = area1; valor4 = area2; break;
   default:
       printf("Opção inválida. Encerrando o programa.\n");
       return 1;
}

//Soma e exibição de resultados

float soma1 = valor1 + valor3;
float soma2 = valor2 + valor4;

printf("---Soma de Atributos---\n");
printf("Soma da Carta 1: %.2f\n", soma1);
printf("Soma da Carta 2: %.2f\n", soma2);

if (soma1 > soma2) {
   printf ("O vencedor final é a Carta 1: (%s)\n", estado1);
} else if (soma2 > soma1) {
   printf ("O vencedor final é a Carta 2: (%s)\n", estado2);
} else {
   printf("Empate!\n");
}


   
 return 0;
    }
