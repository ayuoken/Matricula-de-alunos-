#include <stdio.h>
#include "registro.h"
#include "registro.c"

int cadastrar_aluno() {

    aluno novo;

    // Vamos verificar se o aluno ja nao foi cadastrado
       getchar();
       printf("\nInforme a matricula do aluno\n");
       scanf("%d", &novo.matricula);
       getchar();

       FILE *arq = fopen("arquivoAlunos.txt", "w");
       if (arq == NULL) {
          printf("ERRO! Nao foi possivel abrir o arquivo para leitura\n");
          return -1;
       }
       int matricula, qtd_Faltas;
       float notas[7];
       char nome[50];
       while (fscanf(arq,"%d %f %f %f %f %f %f %f %[^\n]",&matricula,&notas[0],&notas[1],&notas[2],&notas[3],&notas[4],&notas[5],&notas[6],nome) ==9) {
            if(novo.matricula == matricula){
                printf("ERRO! Aluno ja cadastrado\n");
                return -1;
            }
        }


    // Fim da verificao do cadastro do aluno

    printf("\n\nInforme o nome do aluno\n");
    fgets(novo.nome, 50, stdin);

    printf("\n\nInforme as sete notas do aluno as faltas\n");
    int i;
    for(i =0; i<7;i++){
        printf("Digite a sua nota na %d disciplina: ", i+1);
        scanf("%f", &novo.notas[i]);
        printf("\nDigite a quantidade de faltas na %d disciplina: \n", i+1);
        scanf("%d", &novo.faltas[i]);

    }
    inserir(novo);

    printf("\nNovo aluno inserido!\n");
}


int main() {
    int op;

    do {
        printf("\n\nDigite a opcao desejada:\n1 - Cadastrar novo aluno\n2 - Remover aluno\n3 - Listar alunos\n4 - Procurar aluno\n-1 - Para encerrar\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                 cadastrar_aluno();
                 break;
            case 2: {
                 int matricula;
                 printf("\nInforme a matricula do aluno a ser removido:\n");
                 scanf("%d", &matricula);
               // while (getchar() != '\n');
                 getchar();
                 remover(matricula);
                 printf("Pressione Enter para continuar...");
                 getchar();
                 break;
                }
            case 3:
                 listar();
                 break;
            case 4:
                //Verificar o numero da matricula e passar por parametro
                 printf("Digite a matricula\n");
                 int mat;
                 scanf("%d", &mat);
                 procurar(mat);
                 break;
            default:
                if (op != -1) {
                    printf("\n\nEscolha uma opcao valida!!");
                }
        }
    } while (op != -1);
       return 0;
  }
