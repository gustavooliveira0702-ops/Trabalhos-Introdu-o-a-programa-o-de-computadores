#include <stdio.h>

int main() {

    //declaração de variaveis
    char estado1 [30], codigo1[4], cidade1[30];
    int ponto_turistico1;
    float area1, pib1, densidade_populacional1, Pib_per_capita1, super_poder1;
    unsigned long int populacao1;

    //declaração de variaveis do segundo estado
    char estado2[30], codigo2[4], cidade2[30];
    int ponto_turistico2;
    float area2, pib2, densidade_populacional2, Pib_per_capita2, super_poder2;
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

   //calculo de PIB per capita
    Pib_per_capita1 = pib1 / populacao1;
    Pib_per_capita2 = pib2 / populacao2;

   //saída de dados calculados
   printf("Densidade Populacional do Estado 1: %.2f habitantes/km²\n", densidade_populacional1);
   printf("PIB per capita do Estado 1: %.2f\n", Pib_per_capita1);

   printf("Densidade Populacional do Estado 2: %.2f habitantes/km²\n", densidade_populacional2);
   printf("PIB per capita do Estado 2: %.2f\n", Pib_per_capita2);

//----Batalha de Cartas----

   //Somando os super poderes

 float inverso1 = 1.0 / densidade_populacional1;
 float inverso2 = 1.0 / densidade_populacional2;

super_poder1 = populacao1 + ponto_turistico1 + area1 + pib1 + Pib_per_capita1 + inverso1;
super_poder2 = populacao2 + ponto_turistico2 + area2 + pib2 + Pib_per_capita2 + inverso2;

//declaração de variaveis para resultados da batalha
   char *resul_populacao, *resul_area, *resul_Pib, *resul_turistico, *resul_densidade, *resul_pib_capita, *resul_super_poder;

char *vencedor1 = "Carta 1 vence a batalha!";
char *vencedor2 = "Carta 2 vence a batalha!";

   //comparações de cada atributo

   resul_populacao = (populacao1 > populacao2) ? vencedor1 : vencedor2;
   resul_area = (area1 > area2) ? vencedor1 : vencedor2;
   resul_Pib = (pib1 > pib2) ? vencedor1 : vencedor2;
   resul_turistico = (ponto_turistico1 > ponto_turistico2) ? vencedor1 : vencedor2;
   resul_super_poder = (super_poder1 > super_poder2) ? vencedor1 : vencedor2;
   resul_pib_capita = (Pib_per_capita1 > Pib_per_capita2) ? vencedor1 : vencedor2;
   resul_densidade = (densidade_populacional1 < densidade_populacional2) ? vencedor1 : vencedor2;
   printf ("\n--- Resultados da Batalha de Cartas ---\n");
   
   printf("Resultado da População: %s\n", resul_populacao);
   printf("Resultado da Área: %s\n", resul_area);
   printf("Resultado do PIB: %s\n", resul_Pib);
   printf("Resultado dos Pontos Turísticos: %s\n", resul_turistico);
   printf("Resultado da Densidade Populacional: %s\n", resul_densidade);
   printf("Resultado do PIB per capita: %s\n", resul_pib_capita);
   printf("Resultado do Super Poder: %s\n", resul_super_poder);


      return 0;

}