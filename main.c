#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct {
    long int matricula;
    char CPF[12];
    char nome[200];
    double nota[5];
    double media;
    unsigned int faltas;
    double percFaltas;
    char situacao[50];
} aluno;

typedef struct {
    aluno aluno[30];
} turma;

void menuPrincipal();
void menuEncerramento ();
void menuCadastroTurma(turma *turma, int n, char *nome);
void listarTurma (char *nome);
void excluirTurma (char *nome);
void cadastrarAluno (int n, char *nome);

int main () {
    menuPrincipal();
}

void menuPrincipal () {
    char opcao;
    do {
        system("cls");

        //Opções
        printf("\n\t> SELECIONE UMA OPCAO <\n\n");
        printf("\t [1]  Cadastrar uma Turma\n");
        printf("\t [2]  Cadastrar um Aluno\n");
        printf("\t [3]  Buscar por um Aluno\n");
        printf("\t [4]  Exibir uma Turma\n");
        printf("\t [5]  Excluir uma Turma\n");
        printf("\n\t(PRECIONE [s] PARA SAIR)");
        printf("\n\t(PRECIONE [ENTER] PARA CONFIRMAR)\n\n");
        scanf("\n%c", &opcao);

        switch (opcao) {
        case '1': {
            //Cadastar uma Turma
            system("cls");

            int n;
            char nomeArq[N];

            printf("> DIGITE UM NOME PARA A TURMA: ");
            scanf("%s", nomeArq);
            printf("> NUMERO DE ALUNOS: ");
            scanf("%d", &n);

            turma turma[n];
            menuCadastroTurma(turma, n, nomeArq);
            break;
        }
        case '2': {
            //Cadastar um Aluno
            int n;
            char nomeArq[N];

            printf("> DIGITE O NOME DA TURMA: ");
            scanf("%s", nomeArq);
            printf("> NUMERO DE ALUNOS A SEREM CADASTRADO: ");
            scanf("%d", &n);

            cadastrarAluno(n, nomeArq);
            break;
        }
        case '3': {
            //Buscar por um Aluno (não terminada)
            printf("\n\tDISPONIVEL EM BREVE! :)\n");
            menuEncerramento();

            /*
            char nomeArq[N];
            printf("> DIGITE O NOME DA TURMA: ");
            scanf("%s", nomeArq);
            listarAluno (nomeArq);
            */
        }
        case '4': {
            //Listar dados da uma Turma
            char nomeArq[N];

            printf("> DIGITE O NOME DA TURMA: ");
            scanf("%s", nomeArq);

            listarTurma (nomeArq);
            break;
        }
        case '5': {
            //Excluir dados de uma Turma
            char nomeArq[N];

            printf("> DIGITE O NOME DA TURMA: ");
            scanf("%s", nomeArq);

            excluirTurma (nomeArq);
            break;
        }
        case 's': {
            //Terminar execução
            exit(1);
        }
        default:
            printf("OPCAO INVALIDA!\n");
            system("pause");
        }
    } while (opcao!='1'||opcao!='2'||opcao!='3'||opcao!='4'||opcao!='5');
}

//Menu de encerramento de ação
void menuEncerramento () {
    char opcao;
    while (scanf("%c", &opcao)!='m') {
        printf("\t(DIGITE [m] PARA VOLTAR AO MENU PRINCIPAL)\n");
        printf("\t(DIGITE [s] PARA ENCERRAR O PROGRAMA)\n\n");
        scanf("%c", &opcao);

        switch (opcao) {
        case 'm':
            menuPrincipal();
            break;
        case 's':
            exit(1);
            break;
        default:
            printf("\tOPCAO INVALIDA!\n");
        }
        system("cls");
    }
}

//Função de Cadastrar turma
void menuCadastroTurma(turma *turma, int n, char *nome) {
    int i, j, cont = 0;
    FILE *arq;

    //Verificar arquivo
    arq = fopen(nome, "w+");
    if (arq==NULL) {
        printf("\tERRO AO ABRIR ARQUIVO :/\n");
        menuEncerramento();
    }
    fprintf(arq, "TURMA: %s\n", nome);

    //Cadastrar aluno na Turma
    for(i=0; i<1; i++) {
        for(j=0; j<n; j++) {
            system("cls");
            printf("> PREENCHA OS CAMPOS ABAIXO <\n");
            fputs("\n[DADOS ALUNO]:\n", arq);

            //Nome do aluno
            printf("NOME DO ALUNO %d: ", j+1);
            getchar();
            scanf("%[^\n]", turma[i].aluno[j].nome);
            fprintf(arq, "NOME: %s\n", turma[i].aluno[j].nome);

            //CPF do aluno
            printf("CPF DO ALUNO %d: ", j+1);
            scanf("\n%s", turma[i].aluno[j].CPF);
            fprintf(arq, "CPF: %s\n", turma[i].aluno[j].CPF);

            //Número de matrícula do aluno
            printf("NUMERO DE MATRICULA DO ALUNO: ");
            scanf("%ld", &turma[i].aluno[j].matricula);
            fprintf(arq, "MATRICULA: %ld\n", turma[i].aluno[j].matricula);

            //Faltas do aluno
            printf("NUMERO DE FALTAS DO ALUNO %d: ", j+1);
            scanf("%d", &turma[i].aluno[j].faltas);

            //Notas do aluno
            printf("PRIMEIRA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 1: %.2lf\n", turma[i].aluno[j].nota[cont]);
            cont++;

            printf("SEGUNDA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 2: %.2lf\n", turma[i].aluno[j].nota[cont]);
            cont++;

            printf("TERCEIRA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 3: %.2lf\n", turma[i].aluno[j].nota[cont]);
            cont++;

            printf("QUARTA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 4: %.2lf\n", turma[i].aluno[j].nota[cont]);
            cont++;

            printf("QUINTA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 5: %.2lf\n", turma[i].aluno[j].nota[cont]);
            
            //Percentual de Faltas do aluno
            turma[i].aluno[j].percFaltas = turma[i].aluno[j].faltas*100/128;
            fprintf(arq, "PERCENTUAL DE FALTAS: %.2lf%%\n", turma[i].aluno[j].percFaltas);

            //Média Final do aluno
            turma[i].aluno[j].media = (turma[i].aluno[j].nota[cont]+turma[i].aluno[j].nota[cont-1]+turma[i].aluno[j].nota[cont-2]+turma[i].aluno[j].nota[cont-3]+turma[i].aluno[j].nota[cont-4])/5;
            fprintf(arq, "NOTA FINAL: %.2lf\n", turma[i].aluno[j].media);

            //Situação do aluno
            if(turma[i].aluno[j].media>=6.00&&turma[i].aluno[j].percFaltas<25.00) {
                strcpy(turma[i].aluno[j].situacao, "APROVADO");
            } else if(turma[i].aluno[j].media<6.00&&turma[i].aluno[j].percFaltas<25.00) {
                strcpy(turma[i].aluno[j].situacao, "REPROVADO POR NOTA");
            } else if(turma[i].aluno[j].media>=6.00&&turma[i].aluno[j].percFaltas>=25.00) {
                strcpy(turma[i].aluno[j].situacao, "REPROVADO POR FREQUENCIA");
            } else {
                strcpy(turma[i].aluno[j].situacao, "REPROVADO POR NOTA E FREQUENCIA");
            }
            fprintf(arq, "SITUACAO: %s\n", turma[i].aluno[j].situacao);
            cont = 0;
        }
    }

    fclose(arq);

    //Voltar ao menu principal/encerrar
    printf("\n\tTURMA CRIADA COM SUCESSO! :)\n");
    menuEncerramento ();
}

//Função para listar Turma
void listarTurma (char *nome) {
    system("cls");
    char c;
    FILE *arq;

    //Verificar arquivo
    arq = fopen(nome, "r");
    if (arq==NULL) {
        printf("\tERRO AO ABRIR ARQUIVO :/\n");
        menuEncerramento();
    }

    //Imprimir Turma caracter por caracter
    while(c!=EOF) {
        c = fgetc(arq);
        printf("%c", c);
    }

    fclose(arq);

    //Voltar ao menu principal/encerrar
    printf("\n\tTURMA [%s] LISTADA ACIMA.\n", nome);
    menuEncerramento ();
}

//Função para excluir Turma
void excluirTurma (char *nome) {
    //Excluir Turma
    int i = remove(nome);

    if(i!=0) {
        printf("\n\tNAO FOI POSSIVEL EXCLUIR A TURMA. :/\n");
    } else {
        printf("\n\tTURMA EXCLUIDA COM SUCESSO! :)\n");
    }
    
    //Voltar ao menu principal/encerrar
    menuEncerramento ();
}

//Função para cadastar aluno em uma Turma
void cadastrarAluno (int n, char *nome) {
    int i, j, cont = 0;
    turma turma[n];
    FILE *arq;
    
    //Verificar arquivo
    arq = fopen(nome, "a");
    if(arq==NULL) {
        printf("\tERRO AO ABRIR ARQUIVO :/");
        menuEncerramento();
    }

    //Cadastar aluno
    for(i=0; i<1; i++) {
        for(j=0; j<n; j++) {
            system("cls");
            printf("> PREENCHA OS CAMPOS ABAIXO <\n");
            fputs("\n[DADOS ALUNO]:\n", arq);

            //Nome do aluno
            printf("NOME DO ALUNO %d: ", j+1);
            getchar();
            scanf("%[^\n]", turma[i].aluno[j].nome);
            fprintf(arq, "NOME: %s\n", turma[i].aluno[j].nome);

            //CPF do aluno
            printf("CPF DO ALUNO %d: ", j+1);
            scanf("\n%s", turma[i].aluno[j].CPF);
            fprintf(arq, "CPF: %s\n", turma[i].aluno[j].CPF);

            //Número de matrícula do aluno
            printf("NUMERO DE MATRICULA DO ALUNO: ");
            scanf("%ld", &turma[i].aluno[j].matricula);
            fprintf(arq, "MATRICULA: %ld\n", turma[i].aluno[j].matricula);

            //Faltas do aluno
            printf("NUMERO DE FALTAS DO ALUNO %d: ", j+1);
            scanf("%d", &turma[i].aluno[j].faltas);

            //Notas do aluno
            printf("PRIMEIRA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 1: %.2lf\n", turma[i].aluno[j].nota[cont]);
            cont++;

            printf("SEGUNDA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 2: %.2lf\n", turma[i].aluno[j].nota[cont]);
            cont++;

            printf("TERCEIRA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 3: %.2lf\n", turma[i].aluno[j].nota[cont]);
            cont++;

            printf("QUARTA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 4: %.2lf\n", turma[i].aluno[j].nota[cont]);
            cont++;

            printf("QUINTA NOTA DO ALUNO %d: ", j+1);
            scanf("%lf", &turma[i].aluno[j].nota[cont]);
            fprintf(arq, "NOTA 5: %.2lf\n", turma[i].aluno[j].nota[cont]);
            
            //Percentual de faltas do aluno
            turma[i].aluno[j].percFaltas = turma[i].aluno[j].faltas*100/128;
            fprintf(arq, "PERCENTUAL DE FALTAS: %.2lf%%\n", turma[i].aluno[j].percFaltas);

            //Nota Final do aluno
            turma[i].aluno[j].media = (turma[i].aluno[j].nota[cont]+turma[i].aluno[j].nota[cont-1]+turma[i].aluno[j].nota[cont-2]+turma[i].aluno[j].nota[cont-3]+turma[i].aluno[j].nota[cont-4])/5;
            fprintf(arq, "NOTA FINAL: %.2lf\n", turma[i].aluno[j].media);

            //Situação do aluno
            if(turma[i].aluno[j].media>=6.00&&turma[i].aluno[j].percFaltas<25.00) {
                strcpy(turma[i].aluno[j].situacao, "APROVADO");
            } else if(turma[i].aluno[j].media<6.00&&turma[i].aluno[j].percFaltas<25.00) {
                strcpy(turma[i].aluno[j].situacao, "REPROVADO POR NOTA");
            } else if(turma[i].aluno[j].media>=6.00&&turma[i].aluno[j].percFaltas>=25.00) {
                strcpy(turma[i].aluno[j].situacao, "REPROVADO POR FREQUENCIA");
            } else {
                strcpy(turma[i].aluno[j].situacao, "REPROVADO POR NOTA E FREQUENCIA");
            }
            fprintf(arq, "SITUACAO: %s\n", turma[i].aluno[j].situacao);
            cont = 0;
        }
    }

    fclose(arq);
}

//Função de buscar aluno (em desenvolvimento)
void listarAluno (char *nome) {
    int i;
    char c[8], aluno[200], ponto[2], busca[208];
    FILE *arq;

    //Verificar arquivo
    arq = fopen(nome, "r");
    if(arq == NULL) {
        printf("\tERRO AO ABRIR ARQUIVO :/\n");
        menuEncerramento();
    }
    printf("> DIGITE O NOME DO ALUNO: ");
    scanf("%[^\n]", aluno);
    
    strcpy(ponto,".");
    strcpy(busca, "NOME: ");
    
    //Imprimir dados
    while(!feof(arq)) {
        fgets(c, 208, arq);
        strcat(busca, c);
        if(strcmp(aluno, busca)==0) {
            printf("[DADOS DO ALUNO]\n");
            for (i=0; i<12; i++) {
                printf("%s", busca);
            }

            if(strcmp(busca, ponto)==0){
                break;
            }
        }
    }

    fclose(arq);
    printf("\n/t[%s] LISTADA ACIMA\n", nome);
    menuEncerramento();
}
