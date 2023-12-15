#include "registro.h"
#include <stdio.h>

void inserir(aluno a) {
    escrever_novo_aluno(a);
}

void escrever_novo_aluno(aluno a) {
    FILE *arq;
    arq = fopen("arquivoAlunos.txt", "a");
    if (arq == NULL) {
        printf("ERRO! Nao foi possivel abrir o arquivo\n");

    } else {
        // media do aluno e quantidade de faltas
        int i, quantFaltas=0;
        float soma = 0.0, media;
        for(i=0; i<7;i++){
            soma += a.notas[i];
            quantFaltas += a.faltas[i];
        }
        media = soma / 7;
        fprintf(arq,"\n%d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %d %.2f  %s",a.matricula,a.notas[0],a.notas[1],a.notas[2],a.notas[3],
                a.notas[4],a.notas[5],a.notas[6],quantFaltas, media, a.nome);
        fclose(arq);
    }
}

void remover(int matricula) {
    FILE *arq_entrada = fopen("arquivoAlunos.txt", "r");
    if (arq_entrada == NULL) {
        printf("ERRO! Nao foi possivel abrir o arquivo para leitura\n");
        return;
    }

    FILE *arq_temporario = fopen("arquivoAlunosTemp.txt", "w");
    if (arq_temporario == NULL) {
        printf("ERRO! Nao foi possivel abrir o arquivo temporário para escrita\n");
        fclose(arq_entrada);
        return;
    }

    int matricula_atual, qtd_faltas;
    float notas[7], media;
    char nome[50];

    int flag = 0;

    while (fscanf(arq_entrada, "%d %f %f %f %f %f %f %f %d %f %[^\n]", &matricula_atual, &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5],
                  &notas[6], &qtd_faltas, &media, nome) == 11) {
        if (matricula_atual == matricula) {
            flag++;
        } else {
            fprintf(arq_temporario, "%d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %d %.2f %s\n", matricula_atual, notas[0], notas[1], notas[2],
                     notas[3], notas[4], notas[5], notas[6], qtd_faltas, media, nome);
        }
    }

    // Verifica se o usuário existe com o uso de flag
    if (flag == 0) {
        printf("ERRO! Usuario nao existe!\n");
    } else {
        printf("Usuario removido com sucesso!\n");
    }

    fclose(arq_entrada);
    fclose(arq_temporario);
    remove("arquivoAlunos.txt");
    rename("arquivoAlunosTemp.txt", "arquivoAlunos.txt");
}

int procurar(int matricula) {
    FILE *arq = fopen("arquivoAlunos.txt", "r");
    if (arq == NULL) {
        printf("ERRO! Nao foi possível abrir o arquivo para leitura\n");
        return -1;
    }

    int matricula_atual, qtd_faltas;
    float notas[7], media;
    char nome[50];

    int i =1;
    int flag = 0;
       while (fscanf(arq,"%d %f %f %f %f %f %f %f %d %f %[^\n]",&matricula_atual,&notas[0],&notas[1],&notas[2],&notas[3],
                     &notas[4],&notas[5],&notas[6],&qtd_faltas, &media,nome)==11) {
         if(matricula_atual == matricula){
            printf("%d\n", i);
            printf("Matricula: %d\n", matricula);
            printf("Nome: %s\n", nome);
            printf("Media: %.2f\n", media);
            printf("Faltas: %d\n", qtd_faltas);
            printf("Notas: %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n\n",notas[0],notas[1],notas[2],notas[3],notas[4],notas[5],notas[6]);
            i++;
            flag++;
         }
        }

    fclose(arq);

    // Verificar se o usuário existia com o uso de flag
    if (flag == 0) {
        printf("ERRO! Usuario nao existe!\n");
        return -1;
    }

    return 0;
}

// FIM DA PROCURA DO ALUNO

// LISTAGEM DE TODOS O ALUNOS, APROVADOS OU  REPROVADOS

void listagemDeTodosAlunos(){

   FILE *arq = fopen("arquivoAlunos.txt", "r");

   if(arq){
        int matricula, qtd_faltas;
        float notas[7], media;
        char nome[50];

        printf("\nLista de Alunos:\n");
        printf("\n");
        int i=1;

        while (fscanf(arq,"%d %f %f %f %f %f %f %f %d %f %[^\n]",&matricula,&notas[0],&notas[1],&notas[2],&notas[3],&notas[4],
                          &notas[5],&notas[6],&qtd_faltas, &media,nome)==11) {
            printf("%d\n", i);
            printf("Matricula: %d\n", matricula);
            printf("Nome: %s\n", nome);
            printf("Media: %.2f\n", media);
            printf("Faltas: %d\n", qtd_faltas);
            printf("Notas: %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n\n",notas[0],notas[1],notas[2],notas[3],notas[4],notas[5],notas[6]);
            i++;
        }

   }else{
       printf("Erro ao abrir arquivo!\n");
        fclose(arq);
   }
  fclose(arq);
}

void aprovados(){

    FILE *arq = fopen("arquivoAlunos.txt", "r");

    if(arq){

        int matricula, qtd_faltas;
        float notas[7], media;
        char nome[50];

         printf("\nLista de Alunos aprovados\n");
         printf("\n");

         while (fscanf(arq,"%d %f %f %f %f %f %f %f %d %f %[^\n]",&matricula,&notas[0],&notas[1],&notas[2],&notas[3],&notas[4],
                       &notas[5],&notas[6],&qtd_faltas,&media,nome) ==11) {
           if(media >= 7.0){
            printf("Matricula: %d\n", matricula);
            printf("Nome: %s\n", nome);
            printf("Media: %.2f\n", media);
            printf("Faltas: %d\n", qtd_faltas);
            printf("Notas: %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n\n", notas[0], notas[1], notas[2], notas[3], notas[4], notas[5], notas[6]);

          }
         }

    }else{
       printf("ERRO ao abrir arquivo\n");
       fclose(arq);
    }

    fclose(arq);
}

void reprovados(){

   FILE *arq = fopen("arquivoAlunos.txt", "r");

   if(arq){
        int matricula, qtd_faltas;
        float notas[7], media;
        char nome[50];

        printf("Lista de alunos reprovados: \n");
        printf("\n");

        while (fscanf(arq,"%d %f %f %f %f %f %f %f %d %f %[^\n]",&matricula,&notas[0],&notas[1],&notas[2],&notas[3],
                          &notas[4],&notas[5],&notas[6],&qtd_faltas,&media,nome)==11) {
              if (media < 7.0){
                 printf("Matricula: %d\n", matricula);
                 printf("Nome: %s\n", nome);
                 printf("Media: %.2f\n", media);
                 printf("Faltas: %d\n", qtd_faltas);
                 printf("Notas: %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n\n", notas[0], notas[1], notas[2], notas[3], notas[4], notas[5], notas[6]);

              }
           }


   }else{

     fclose(arq);
   }
   fclose(arq);
}

void listar() {

        // Pedir ao usuário quais alunos ele quer ver:

        int  op;
        printf("Digite a a opcao desejada: \n");
        printf("1 - Todos os alunos\n2 - Alunos aprovados \n3 - Alunos reprovados\n");
        scanf("%d", &op);

        switch(op){
         case 1:
             listagemDeTodosAlunos();
             break;
         case 2:
             aprovados();
             break;
         case 3:
             reprovados();
             break;
         default:
             printf("Opcao invalida\n");
             break;
         }
}
 // FIM DA LISTAGEM DOS ALUNOS REPROVADOS E APROVADOS
