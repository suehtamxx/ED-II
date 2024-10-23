#include "universidade.h"
#include "universidade.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CURSOS 50000
#define NUM_DISCIPLINAS 100
void preencher_cursos(arv_curso **cursos) {
    for (int i = 0; i < NUM_CURSOS; i++) 
    {
        arv_curso *novo_curso;
        novo_curso = alocar_no_curso();
        snprintf(novo_curso->info.nome, sizeof(novo_curso->info.nome), "Curso %d", i);
        snprintf(novo_curso->info.cod_curso, sizeof(novo_curso->info.cod_curso), "C%d", i);
        novo_curso->info.qtd_periodos = (rand() % 8) + 1; // Periodos entre 1 e 8

        inserir_arv_curso(cursos, novo_curso);
    }
}
void preencher_cursos_des(arv_curso **cursos) {
    for (int i = NUM_CURSOS; i > 0; i--) 
    {
        arv_curso *novo_curso;
        novo_curso = alocar_no_curso();
        snprintf(novo_curso->info.nome, sizeof(novo_curso->info.nome), "Curso %d", i);
        snprintf(novo_curso->info.cod_curso, sizeof(novo_curso->info.cod_curso), "C%d", i);
        novo_curso->info.qtd_periodos = (rand() % 8) + 1; // Periodos entre 1 e 8

        inserir_arv_curso(cursos, novo_curso);
    }
}
void embaralhar(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
void preencher_cursos_aleatorio(arv_curso **cursos) {
    // Cria um array com os índices de 1 a NUM_CURSOS
    int indices[NUM_CURSOS];
    for (int i = 0; i < NUM_CURSOS; i++) {
        indices[i] = i + 1;
    }

    // Embaralha os índices para garantir que não se repitam
    embaralhar(indices, NUM_CURSOS);

    // Insere os cursos na árvore com os índices embaralhados
    for (int i = 0; i < NUM_CURSOS; i++) {
        arv_curso *novo_curso;
        novo_curso = alocar_no_curso();

        // Usa o índice embaralhado para preencher os cursos
        int idx = indices[i];

        snprintf(novo_curso->info.nome, sizeof(novo_curso->info.nome), "Curso %d", idx);
        snprintf(novo_curso->info.cod_curso, sizeof(novo_curso->info.cod_curso), "C%04d", idx);
        novo_curso->info.qtd_periodos = (rand() % 8) + 1; // Periodos entre 1 e 8

        // Insere o curso na árvore
        inserir_arv_curso(cursos, novo_curso);
    }
}

void preencher_disciplina(arv_curso **cursos)
{
    for(int i = 0; i < NUM_CURSOS; i++)
    {
        char contador[7];
        snprintf(contador, sizeof(contador), "C%d", i + 1);
        arv_curso *curso_atual;

        curso_atual = buscar_curso((*cursos), contador);

        if(curso_atual != NULL)
        {
            for(int j = 0; j < NUM_DISCIPLINAS; j++)
            {
                arv_dis *nova_dis;
                nova_dis = alocar_no_disciplina();

                snprintf(nova_dis->info.nome, sizeof(nova_dis->info.nome), "Disciplina %d", j);
                snprintf(nova_dis->info.cod_dis, sizeof(nova_dis->info.cod_dis), "D%d", j);
                nova_dis->info.periodo = (rand() % 8) + 1; // Periodos entre 1 e 8
                nova_dis->info.carga_hr = 60;

                inserir_arv_disciplina(&(curso_atual->info.arv_dis), nova_dis);
            }
        }
    }
}

void preencher_aluno(arv_curso *cursos, l_aluno **alunos)
{
    for(int i = 0; i < NUM_CURSOS; i++)
    {
        char contador[7];
        snprintf(contador, sizeof(contador), "C%d", i);

        arv_curso *curso_aluno;
        curso_aluno = buscar_curso(cursos, contador);
        if(curso_aluno != NULL)
        {
            l_aluno *novo_aluno;
            novo_aluno = alocar_no_aluno();
            
            snprintf(novo_aluno->info.nome, sizeof(novo_aluno->info.nome), "Aluno %d", i);
            snprintf(novo_aluno->info.matricula, sizeof(novo_aluno->info.matricula), "A%d", i);
            strcpy(novo_aluno->info.cod_curso, curso_aluno->info.cod_curso);

            inserir_lista_aluno(&(*alunos), novo_aluno);

            for(int j = 0; j < 5; j++)
            {
                char cont[6];
                snprintf(cont, sizeof(cont), "D%d", j);

                arv_dis *disciplina;
                disciplina = buscar_disciplina(curso_aluno->info.arv_dis, cont);
                if(disciplina != NULL)
                {
                    arv_notas *nova_nota;
                    nova_nota = alocar_no_notas();

                    nova_nota->info.nota_final = (rand() % 10) + 1;
                    strcpy(nova_nota->info.semestre, "2024.2");
                    strcpy(nova_nota->info.cod_dis, disciplina->info.cod_dis);

                    inserir_arv_notas(&(*alunos)->info.arv_notas, nova_nota);
                }
            }
        }
    }
}

void buscar_nota(arv_curso *cursos, l_aluno *alunos)
{
            //1° cod curso, 2° cod disciplina, 3° matricula aluno
            int c = 100;
            int d = 3;
            int a = 100;
            char buscaC[10];
            snprintf(buscaC, sizeof(buscaC), "C%d", c);
            char buscaD[10];
            snprintf(buscaD, sizeof(buscaD), "D%d", d);
            char buscaA[10];
            snprintf(buscaA, sizeof(buscaA), "A%d", a);
            //char busca[10];

            // scanf(" %[^\n]", busca);
            // while(getchar() != '\n');
            arv_curso *noCurso;
            arv_dis *noDis;
            l_aluno *noAluno;
            noCurso = buscar_curso(cursos, buscaC); //Buscando o curso escolhido
            if(noCurso != NULL)
            {
                // scanf(" %[^\n]", busca);
                // while(getchar() != '\n');
                
                noDis = buscar_disciplina(noCurso->info.arv_dis, buscaD); //Buscando a disciplina escolhido
                if(noDis != NULL)
                {
                    // scanf(" %[^\n]", busca);
                    // while(getchar() != '\n');

                    noAluno = buscar_aluno(alunos, buscaA); //Buscando a aluno escolhido
                    if(noAluno != NULL)
                        buscar_notas_disciplina(noAluno->info.arv_notas, noDis);
                    
                    else printf("\nAluno nao encontrado!\n");
                }
                else printf("\nDisciplina nao encontrada!\n");
            }
            else printf("\nCurso nao encontrado!\n");
            
}
int main(){
    arv_curso *cursos;
    l_aluno *alunos;
    alunos = criar_lista_aluno();
    cursos = criar_arv_curso();
    //arv_dis disciplina[NUM_DISCIPLINAS];

    // clock_t inicio_cursos = clock();
    // for(int i = 0; i < 30; i++)
    // {
    preencher_cursos(&cursos);
    preencher_disciplina(&cursos);
    preencher_aluno(cursos, &alunos);

    clock_t inicio_nota = clock();
    buscar_nota(cursos, alunos);
    clock_t fim_nota = clock();
    double tempo_busca = ((double) (fim_nota - inicio_nota)) / CLOCKS_PER_SEC;
    double tempo_milisegundos = (tempo_busca * 1000);
    double tempo_nanosegundos = (tempo_milisegundos * 1000);
    printf("Tempo de busca: %f\n", tempo_nanosegundos);

    //     i++;
    // }
    // clock_t fim_cursos = clock();

    // double tempo_insercao_cursos = ((double) (fim_cursos - inicio_cursos)) / CLOCKS_PER_SEC;
    // printf("Tempo de insercao: %f segundos\n", tempo_insercao_cursos);

    //preencher_disciplina(cursos);
    return 0;
}
