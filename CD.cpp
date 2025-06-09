#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char banda[30];
    char genero[30];
    int ano;
    int quantidade;
    
} CD;

CD cds[10];

int numCD = 0;

void cadastrarCD();
void consultarCD();
void pesquisarGenero();
void venderCD();


int main () {
    int opcao;

    do {
        printf("\033[1;35m");
        printf("---------------SOM e ARTE---------------\n");
        printf("\033[0m");
        printf("[1] - Cadastrar CD\n");
        printf("[2] - Consultar por ID\n");
        printf("[3] - Pesquisar por genero\n");
        printf("[4] - Vender CD\n");
        printf("[0] - Sair\n");
        printf("\033[1;35m");
        printf("----------------------------------------\n");
        printf("\033[0m");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);

        getchar(); 
        system("cls");

        switch (opcao) {
            case 1:
                cadastrarCD();
                break;
            case 2:
                consultarCD();
                break;
            case 3:
                pesquisarGenero();
                break;
            case 4:
                venderCD();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        
		
		}

    } while (opcao != 0);

    return 0;
}



void cadastrarCD() {
    
    printf("\033[1;35m");
    printf("----------------------------------------\n");
    printf("\033[0m");
    printf("ID: ");
    scanf("%d", &cds[numCD].id);
    printf("Banda: ");
    scanf("%s", cds[numCD].banda);
    printf("Genero: ");
    scanf("%s", cds[numCD].genero);
    printf("Ano: ");
    scanf("%d", &cds[numCD].ano);
    printf("Quantidade em estoque: ");
    scanf("%d", &cds[numCD].quantidade);
	printf("\033[1;35m");
    printf("----------------------------------------\n");
    printf("\033[0m");
    
	
	numCD++;

    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
    system("cls");
}


void consultarCD() {
    int id;
	int i;
	int encontrado = 0;
	
	
	printf("\033[1;35m");
    printf("---------------------Consultar CD-------------------\n");
    printf("\033[0m");
    printf("Digite o ID: ");
    scanf("%d", &id);


    for (i = 0; i < numCD; i++) {
        if (cds[i].id == id) {
            printf("ID:  %d\n", cds[i].id);
            printf("Banda:  %s\n", cds[i].banda);
            printf("Genero:  %s\n", cds[i].genero);
            printf("Ano:  %d\n", cds[i].ano);
            printf("Quantidade em estoque:  %d\n", cds[i].quantidade);
            encontrado = 1;
            
			
			break;
       
	   
	    }
    }

    if (encontrado == 0) {
        printf("cd nao foi encontrado, verifique se tem no estoque\n");
    }
	printf("\033[1;35m");
    printf("---------------------------------------------------\n");
    printf("\033[0m");
	
	
	
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
    system("cls");
}

void pesquisarGenero() {
    char generoBuscado[100];
    int i;  
    int j;
    int iguais;
    int encontrou = 0;

    printf("\033[1;35m");
    printf("-----------------Pesquisar Pelo genero-------------\n");
    printf("\033[0m");
    
    printf("Por qual genero voce quer procurar: ");
    scanf("%s", generoBuscado);

    for (i = 0; i < numCD; i++) {
        iguais = 0; 
        
        for (j = 0; j < 100; j++) {
            if (generoBuscado[j] != cds[i].genero[j]) {
                iguais = 1;
                break;
            }
        }

        if (iguais == 1) {
            printf("CD encontrado:\n");
            printf("ID:  %d\n", cds[i].id);
            printf("Banda:  %s\n", cds[i].banda);
            printf("Genero:  %s\n", cds[i].genero);
            printf("Ano:  %d\n", cds[i].ano);
            printf("Quantidade:  %d\n", cds[i].quantidade);
            encontrou = 1;

            printf("\033[1;35m");
            printf("---------------------------------------------------\n");
            printf("\033[0m");
        }
    }

    if (encontrou == 0) {
        printf("Nao possui cd com esse genero\n");

        printf("\033[1;35m");
        printf("---------------------------------------------------\n");
        printf("\033[0m");
    }


    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
    system("cls");
    
    
}



void venderCD() {
    int id;
	int i;
	int quantidade; 
	int encontrado = 0;

    printf("Digite o ID do CD que voce quer: ");
    scanf("%d", &id);

    for (i = 0; i < numCD; i++) {
        
		if (cds[i].id == id) {
            encontrado = 1;

            if (cds[i].quantidade == 0) {
                printf("Não possuimos esse CD\n");
                
        	}	 
			else {
                printf("Quantidade que deseja vender: ");
                scanf("%d", &quantidade);

            if (quantidade <= cds[i].quantidade) {
                    cds[i].quantidade -= quantidade;
					
                    printf("Venda feita com sucesso\n");
                } 
					else {
                   		 printf("Nao tem no estoque essa quantidade\n");
                }
            }
            break;
}
}

    if (encontrado == 0) {
        printf("CD nao foi encontrado\n");
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
    system("cls");
}