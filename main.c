#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct lista {
  int vec[TAM];
  int ini;
  int n;
} Fila;

void showMenu() {
  printf("Menu:\n");
  printf("1 - Inserir valor no fim\n");
  printf("2 - Remover valor do início\n");
  printf("3 - Consultar valor do início\n");
  printf("4 - Verificar se a fila está cheia\n");
  printf("5 - Verificar se a fila está vazia\n");
  printf("0 - Sair\n");
  printf("Escolha uma opção: ");
}

Fila *criarFila(void);
void inserirFim(Fila *f, int valor);
void removerInicio(Fila *f);
void consultaInicio(Fila *f);

int filaVazia(Fila *f) { return (f->n == 0); }
int filaCheia(Fila *f) { return (f->n == TAM); }

int main(void) {
  Fila *f = criarFila();
  int op, valor;

  do {
    showMenu();
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf("Digite o valor a ser inserido: ");
      scanf("%d", &valor);
      inserirFim(f, valor);
      break;
    case 2:
      removerInicio(f);
      break;
    case 3:
      consultaInicio(f);
      break;
    case 4:
      if (filaCheia(f)) {
        printf("A fila está cheia\n");
      } else {
        printf("A fila não está cheia\n");
      }
      break;
    case 5:
      if (filaVazia(f)) {
        printf("A fila está vazia\n");
      } else {
        printf("A fila não está vazia\n");
      }
      break;
    default:
      printf("Opção inválida\n");
    }
  } while (op != 0);

  free(f);
  return 0;
}

Fila *criarFila(void) {
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->ini = 0;
  f->n = 0;
  return f;
}

void inserirFim(Fila *f, int valor) {
  if (filaCheia(f)) {
    printf("A fila está cheia\n");
    return;
  }
  int fim = (f->ini + f->n) % TAM;
  f->vec[fim] = valor;
  f->n++;
}

void removerInicio(Fila *f) {
  if (filaVazia(f)) {
    printf("A fila está vazia\n");
    return;
  }
  f->ini = (f->ini + 1) % TAM;
  f->n--;
}

void consultaInicio(Fila *f) {
  if (filaVazia(f)) {
    printf("A fila está vazia\n");
  } else {
    printf("Início da fila: %d\n", f->vec[f->ini]);
  }
}