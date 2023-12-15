#ifndef REGISTRO_H
#define REGISTRO_H

typedef struct {
    char nome[50];
    int matricula;
    float notas[7];
    int faltas[7];
} aluno;

void inserir(aluno a);
void remover(int matricula);
void listar();
int procurar(int matricula);
void escrever_novo_aluno(aluno a);
void aprovados();
void reprovados();
void listagemDeTodosAlunos();


#endif
