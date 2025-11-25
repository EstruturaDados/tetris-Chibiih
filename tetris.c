#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.
    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.

    #define MAX 5

typedef struct {
    char nome;
    int id;
} Peca;

//fila circular

typedef struct {
    Peca itens[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int filaCheia(Fila *f) {
    return f->tamanho == MAX;
}

int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

//gerando novas peças
Peca gerarPeca() {
static int contadorID = 0;
char tipos[4] = {'I', 'O', 'T', 'L'};

Peca p;
p.nome = tipos[rand() % 4];
p.id = contadorID++;

return p;
}

//enqueue
void enfileirar(Fila *f, Peca p) {
if (filaCheia(f)) {
printf("A fila está cheia! Não é possível inserir nova peça.\n");
return;
}

f->fim = (f->fim + 1) % MAX;
f->itens[f->fim] = p;
f->tamanho++;

printf("Peça [%c %d] inserida com sucesso!\n", p.nome, p.id);
}

//dequeue
Peca desenfileirar(Fila *f) {
if (filaVazia(f)) {
printf("A fila está vazia! Não há peças para jogar.\n");
Peca vazia = {'-', -1};
return vazia;
}

Peca removida = f->itens[f->inicio];
f->inicio = (f->inicio + 1) % MAX;
f->tamanho--;

printf("Peça [%c %d] jogada!\n", removida.nome, removida.id);
return removida;
}

//exibindo a fila
void exibirFila(Fila *f) {
printf("\nFila de peças:\n");
if (filaVazia(f)) {
printf("[vazia]\n");
return;
}

int idx = f->inicio;
    for (int i = 0; i < f->tamanho; i++) {
        Peca p = f->itens[idx];
        printf("[%c %d] ", p.nome, p.id);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Fila fila;
    inicializarFila(&fila);

    // Inicializar com 5 peças
    for (int i = 0; i < MAX; i++) {
        enfileirar(&fila, gerarPeca());
    }

    int opcao;

    do {
        exibirFila(&fila);

        printf("\nOpções:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                desenfileirar(&fila);
                break;
            case 2:
                enfileirar(&fila, gerarPeca());
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}


    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


