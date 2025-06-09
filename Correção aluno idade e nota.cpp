#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	int idade;
	float nota;
	
}  Aluno;

Aluno alunos[3];

void listarAluno();

int main() {
	int i;
	
	for (int i = 0; i < 3; i++) {
	printf("Digite os dados do aluno %d: \n", i + 1);
	printf("Nome: ");
	scanf("%s", alunos[i].nome);
	printf("Idade: ");
	scanf("%d", &alunos[i].idade);
	printf("Nota: ");
	scanf("%f", &alunos[i].nota);
	
	system("cls");
	}
	
	listarAluno();
	
	return 0;
}

void listarAluno() {
	int i;
	
	for(int i = 0; i < 3; i++) {
	printf("--------------------------------------------------------------\n");
	printf("Aluno %d:\n", i + 1);
	printf("Nome: %s\n", alunos[i].nome);
	printf("Idade: %d\n", alunos[i].idade);
	printf("Nota: %.2f\n", alunos[i].nota);
	printf("--------------------------------------------------------------\n");
	
	}
}
