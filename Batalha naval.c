#include <stdio.h>


#define TAM 10 //tamanho do tabuleiro
#define Navio 3 // valor que representa o navio
#define TAM_Nav 3 // tamanho fixo do navio

int main () {

// criando o tabuleiro e matrizes

int tabuleiro [TAM][TAM];
int cone[5][5];
int cruz[5][5];
int oct[5][5];

//preenche todas as posições com 0 (água)
for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
        tabuleiro [i][j] = 0;
    }
}

//Criar os navios (como vetores de partes)

int navioHorizontal[TAM_Nav] = {Navio, Navio, Navio};
int navioVertical[TAM_Nav] = {Navio, Navio, Navio};
int navioDiagonal[TAM_Nav] = {Navio, Navio, Navio};
int navioDiagonal2[TAM_Nav] = {Navio, Navio, Navio};

// definindo coordenadas

int linhaH = 2; //linha inicial do navio horizontal
int colunaH = 6; //coluna inicial 

int linhaV = 6; //linha inicial do navio vertical
int colunaV = 7; // coluna inicial

int linhaD = 3; //linha inicial do navio diagonal
int colunaD = 3; //linha coluna inicial

int linhaD2 = 0; // linha inicial do navio diagonal 2
int colunaD2 = 9; // linha inicial do navio diagonal 2

// --- Validação horizontal ---
if (colunaH + TAM_Nav > TAM) {
    printf ("Erro: Navio Horizontal sairia do tabuleiro\n");
return 1;
}

//--- validação vertical ---
if (linhaV + TAM_Nav > TAM) {
    printf ("Erro: Navio vertical sairia do tabuleiro\n");
return 1;
}

// --- validação diagonaL ---
if (linhaD + TAM_Nav > TAM || colunaD + TAM_Nav > TAM) {
    printf("Erro: Navio Diagonal sairia do tabuleiro\n");
return 1;
}

// --- validação diagonal 2 ---
if (linhaD2 + TAM_Nav > TAM || colunaD2 - (TAM_Nav - 1) < 0) {
    printf ("Erro: Navio Diagonal 2 sairia do tabuleiro\n");
return 1;
}

// Verificando sobreposição
for (int i = 0; i < TAM_Nav; i++) {
    if (tabuleiro[linhaH][colunaH + i] == Navio || tabuleiro[linhaV + i][colunaV] == Navio) {
        printf("Erro: Navios se sobrepôem\n");
        return 1;
    }
}
 
//posicionando os navios

//horizontal
for (int i = 0; i < TAM_Nav; i++) {
    tabuleiro [linhaH][colunaH + i] = navioHorizontal[i];
}

//vertical
for (int i = 0; i < TAM_Nav; i++) {
    tabuleiro [linhaV + i][colunaV] = navioVertical[i];
}

//diagonal
for (int i = 0; i < TAM_Nav; i++) {
    tabuleiro [linhaD + i][colunaD + i] = navioDiagonal[i];
}

//diagonal 2
for (int i = 0; i < TAM_Nav; i++) {
    tabuleiro [linhaD2 + i][colunaD2 - i] = navioDiagonal2[i];
}

// criação das matrizes

//Cone
int center = 2;

for (int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {

        if (j >= center - 1 && j <= center + i)
         cone [i][j] = 1;
    else
         cone [i][j] = 0;
    }
}

//cruz
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {

        if (i == center || j == center)
           cruz[i][j] = 1;
        else
           cruz[i][j] = 0;
    }
}

//octaedro
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {

        int di = i - center;
        if (di < 0) di = -di;

        int dj = j - center;
        if (dj < 0) dj = -dj;

        int dist = di + dj;

        if(dist <= 2)
         oct[i][j] = 1;

         else
         oct[i][j] = 0;
    }
}

//efeito matrizes

int efeito [5][5];
  
int escolha;

printf("Escolha a habilidade (1-cone, 2-cruz ou 3-octaedro):\n");
scanf("%d", &escolha);

if (escolha == 1) {
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    efeito[i][j] = cone[i][j];
}

else if (escolha == 2) {
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    efeito[i][j] = cruz[i][j];
}

else if (escolha == 3) {
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    efeito[i][j] = oct [i][j];
}

//Coordenadas de origem 

int x, y;

printf("Digite a linha onde a habilidade será aplicado (0 a 9):\n");
scanf ("%d", &x);

printf("Digite a coluna onde a habilidade será aplicado (0 a 9): \n");
scanf("%d", &y);

for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {

        if (efeito[i][j] == 1) {

            int tx = x + (i - center);
            int ty = y + (j - center);

            if (tx >= 0 && tx < TAM && ty >= 0 && ty < TAM) {
                if (efeito [tx][ty] == 1 && tabuleiro[tx][ty] != Navio) {
                    tabuleiro [tx][ty] = 5; //area afetada
                }
            }


        }
    }
}

//Sobscrever Navios
for (int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {

        //só funciona se o efeito ta ativo
        if (efeito[i][j] == 1) {

            int tx = x + (i - 2); // 2 é o centro da matriz 5x5
            int ty = y + (j - 2);

            //limites tabuleiro
            if (tx >= 0 && tx < TAM && ty >= 0 && ty < TAM) {

                if (tabuleiro[tx][ty] !=Navio) {
                    tabuleiro[tx][ty] = 5; //ara afetada
                }
            }
        }
    }
}


//Exibição

printf(" TABULEIRO BATALHA NAVAL\n");

for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
        printf ("%d", tabuleiro[i][j]);
    }
    printf("\n");
}

return 0;

}
