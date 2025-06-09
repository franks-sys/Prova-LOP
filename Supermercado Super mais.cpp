#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	char nome[100];
    char descricao[100];
    int quantidade;
    
}  Produto;

Produto produto[10];


void registrarProduto();
void listarProduto();
void realizarCompra();


int numProduto = 0;


int main () {
    int opcao;

    do {
        printf("\033[1;35m");
        printf("---------------SuperMais Supermercado---------------\n");
        printf("\033[0m");
        printf("[1] -  Cadastrar Produto\n");
        printf("[2] -  Listar Produto\n");    
        printf("[3] -  Realizar Compra\n");
        printf("[0] -  Sair\n");
        printf("\033[1;35m");
        printf("---------------------------------------------\n");
        printf("\033[0m");
        printf("Selecione uma opcao : ");
        scanf("%d", &opcao);

        getchar(); 
        system("cls");

        switch (opcao) {
            case 1:
                registrarProduto();
                break;

            case 2:
                listarProduto();
                break;

            case 3:
                realizarCompra();
                break;

            case 0:
                printf("Saindo...\n\n");
                printf("Ate logo...\n");
                break;

            default:
                printf("Opcao invalida !\n");    
        }

    } while (opcao != 0);

    return 0;
}

void registrarProduto() {
   
   	
    printf("\033[1;35m");
    printf("---------------Nova Tarefa---------------\n");
    printf("\033[0m");

    printf("Nome: ");
    scanf(" %[^\n]", produto[numProduto].nome);

    printf("Descricao: ");
    scanf(" %[^\n]", produto[numProduto].descricao);

    printf("Quantidade: ");
    scanf(" %d", &produto[numProduto].quantidade);


	
    numProduto++;

    printf("\033[1;35m");
    printf("----------------------------------------\n");
    printf("\033[0m");

    printf("\n\nPress ENTER para continuar...");
    getchar();
    system("cls");
}

void listarProduto() {
    
	
	printf("\033[1;35m");
    printf("-----------Itens em Estoque-----------\n");
    printf("\033[0m");

    for (int i = 0; i < numProduto; i++) {
        printf("Nome     : %s\n", produto[i].nome);
        printf("Descricao: %s\n", produto[i].descricao);
        printf("Horario  : %d\n", produto[i].quantidade);
        
        printf("\033[1;35m");
        printf("---------------------------------------\n");
        printf("\033[0m");
    }

	printf("\n\nPress ENTER para continuar...");
    getchar();
    system("cls");
}

void realizarCompra() {
    
	int quantidade;


	printf("\033[1;35m");
    printf("-----------Itens em Estoque-----------\n");
    printf("\033[0m");
    
    
    
    if (numProduto == 0) {
        printf("nao tem produto cadastrado...\n");
    } 
	
	else {
        printf("Quantidade no estoque: %d\n", produto[0].quantidade);
        printf("Quantidade que voce quer comprar: ");
        scanf("%d", &quantidade);

        produto[0].quantidade -= quantidade;
    }
    
    printf("\033[1;35m");
    printf("--------------------------------------\n");
    printf("\033[0m");
    
    
    

    printf("\n\nPress ENTER para continuar...");
    getchar();
    system("cls");
}