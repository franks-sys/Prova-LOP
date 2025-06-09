#include <stdio.h>
#include <stdlib.h>

typedef struct {
    
	char nome[50];
    float preco;
    
} Pizza;

typedef struct {

    char nome[50];
    
} Cliente;


Pizza pizzas[10];

Cliente clientes[10];

int totalPizzas = 0;
int totalClientes = 0;
char nomeBusca[50];


void cadastrarPizza();
void cadastrarCliente();
void listarPizzas();
void listarClientes();
int clienteExiste();
void venderPizzas();

int main() {
    int opcao;

    do {
        printf("\033[1;35m");
        printf("---------------Nostra Pizza---------------\n");
        printf("\033[0m");

        printf("[ 1 ] - Cadastrar Pizza\n");
        printf("[ 2 ] - Cadastrar Cliente\n");
        printf("[ 3 ] - Listar Pizzas\n");
        printf("[ 4 ] - Listar Clientes\n");
        printf("[ 5 ] - Vender Pizzas\n");
        printf("[ 0 ] - Sair\n");
        printf("\033[1;35m");
        printf("-----------------------------------------\n");
        printf("\033[0m");        
    	printf("Escolha uma opcao: ");
		scanf("%d", &opcao);

        
        switch (opcao) {
            
			case 1: 
			cadastrarPizza(); 
			break;
            
			case 2: 
			cadastrarCliente(); 
			break;
            
			case 3: 
			listarPizzas(); 
			break;
            
			case 4: 
			listarClientes(); 
			break;
            
			case 5: 
			venderPizzas(); 
			break;
            
			case 0: 
			printf("Saindo...\n"); 
			break;
            
			default: 
			break;
        }

    } while (opcao != 0);

    return 0;
}

void cadastrarPizza() {
    
	printf("\033[1;35m");
    printf("---------------Cadastrar Pizza---------------\n");
    printf("\033[0m");

    printf("Nome da pizza: ");
    scanf(" %[^\n]", pizzas[totalPizzas].nome);
    printf("Preco da pizza: ");
    scanf("%f", &pizzas[totalPizzas].preco);

    totalPizzas++;

    printf("Pizza cadastrada com sucesso\n");

    printf("\033[1;35m");
    printf("--------------------------------------------\n");
    printf("\033[0m");
    
    	    
}

void cadastrarCliente() {
    
	printf("\033[1;35m");
    printf("------------------Cadastro Cliente---------------\n");
    printf("\033[0m");

    printf("Nome do cliente: ");
    scanf(" %[^\n]", clientes[totalClientes].nome);

    totalClientes++;

    printf("Cliente cadastrado com sucesso\n\n");

    printf("\033[1;35m");
    printf("------------------------------------------------\n");
    printf("\033[0m");
}

void listarPizzas() {
    
	printf("\033[1;35m");
    printf("---------------Pizzas Cadastradas---------------\n");
    printf("\033[0m");

    for (int i = 0; i < totalPizzas; i++) {
        printf("%d\n", i + 1);
        printf("%s\n", pizzas[i].nome);
        printf("R$%.2f\n", pizzas[i].preco);
    }

    printf("\033[1;35m");
    printf("------------------------------------------------\n");
    printf("\033[0m");
}

void listarClientes() {
    printf("\033[1;35m");
    printf("---------------Clientes Cadastrados---------------\n");
    printf("\033[0m");

    for (int i = 0; i < totalClientes; i++) {
        printf("%d\n", i + 1);
        printf("%s\n", pizzas[i].nome);
        printf("R$%.2f\n", pizzas[i].preco);
    }

    printf("\033[1;35m");
    printf("--------------------------------------------------\n");
    printf("\033[0m");
}


int clienteExiste() {
	int i;
	int j;
	
	
    printf("--------------------------------------------------\n");
    printf("\033[0m"); 
    for (int i = 0; i < totalClientes; i++) {
        int iguais = 1;
       
	    for (int j = 0; j < 50; j++) {
            if (nomeBusca[j] != clientes[i].nome[j]) {
                iguais = 0;
                break;
            }
        }
        
		if (iguais == 1) {
            return 1;
        }
    }
    printf("\033[1;35m");
    printf("--------------------------------------------------\n");
    printf("\033[0m");
    return 0;
}

void venderPizzas() {
    
    int i;
	int codigoPizza;
    int quantidade;
    float total = 0;

 	printf("\033[1;35m");
    printf("--------------------------------------------------\n");
    printf("\033[0m");
    
    printf("Nome do cliente: ");
    scanf(" %[^\n]", nomeBusca);

    if (clienteExiste() == 0) {
        printf("Cliente não cadastrado\n");
        return;
    }

    printf("Quantas pizzas voce deseja comprar ");
    scanf("%d", &quantidade);

    printf("Escolha os codigos das pizzas:\n");
    
	listarPizzas();

    printf("Pizzas compradas:\n");
    for (i = 0; i < quantidade; i++) {
        printf("Código da pizza %d: ", i + 1);
        scanf("%d", &codigoPizza);

        if (codigoPizza >= 1 && codigoPizza <= totalPizzas) {
            
			printf("%s\n", pizzas[codigoPizza - 1].nome);
            printf("R$%.2f\n",pizzas[codigoPizza - 1].preco);
            
			
			total += pizzas[codigoPizza - 1].preco;
        } 
		else {
            printf("codigo invalido\n");
        }
    }

    printf("Total a pagar: R$%.2f\n\n", total);
    
    printf("\033[1;35m");
    printf("--------------------------------------------------\n");
    printf("\033[0m");
	 
}