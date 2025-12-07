#include <stdio.h>

//Movimento Torre para a direita usando a recursividade
void moverTorre (int casas) {
  if (casas == 0) return;
  printf ("Direita\n");
  moverTorre (casas - 1); //chama e dimui um número
}

//Movimento Rainha para a esquerda com recursividade
void moverRainha (int casas) {
  if (casas == 0) return;
  printf("Esquerda\n");
  moverRainha (casas - 1);
}

//Movimento Bispo recursividade e aninhado
void moverBispo (int casas) {
  if (casas == 0) return;

  //Loop aninhados
  for (int v=0; v < 1; v++) {
    for (int h = 0; h < 1; h++) {
      printf ("Cima, Direita\n");
    }
  }
  moverBispo (casas - 1);
}

int main () {

  //Quantidade de Casas para mover
  int Casastorre = 5;
  int Casasbispo = 5;
  int Casasrainha = 8;
  int i = 0;
  int j = 0;
  int casasCima = 2;
  int casasDireita = 1;

  //Movimentação
  printf ("Movimento da Torre\n");
  moverTorre(Casastorre);

  printf ("\n");

  //Movimentação
  printf ("Movimento da Rainha\n");
  moverRainha(Casasrainha);

  printf("\n");

  //Movimentação
  printf("Movimento do Bispo\n");
  moverBispo(Casasbispo);

  printf("\n");



  // Movimentação do Cavalo com Loops COmplexos
  printf ("Movimento do Cavalo\n");

  //loops complexos
  for (i = 0; i < casasCima + 1; i++) {

    for (j = 0; j < casasDireita + 2; j++) {

      if (i < casasCima && j == 0) {
        printf ("Cima\n");
        continue; //continua no loop interno
      }
      if (i == casasCima && j == casasDireita) {
        printf ("Direita\n");
        break; //encerra o interno
      }
    }
  }

 return 0;
}

