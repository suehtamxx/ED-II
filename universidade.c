#include "universidade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

arv_curso *cadastrar_curso()
{
    printf("\nCadastrando um curso: ");
    arv_curso *novo_curso = (arv_curso*)malloc(sizeof(arv_curso));
    if (novo_curso != NULL)
    {
        novo_curso->dir = NULL;
        novo_curso->esq = NULL;
        novo_curso->dis = NULL;

        printf("Informe o nome do curso: ");
        scanf(" %[^\n]", novo_curso->info.nome);

        printf("Informe a quantidade de periodos do curso: ");
        scanf(" %d", &novo_curso->info.qtd_periodos);

        printf("Informe o codigo do curso: ");
        scanf(" %[^\n]", novo_curso->info.cod_curso);
    }
    else printf("Erro ao alocar!\n");

    return novo_curso;
}

int inserir_arv_curso(arv_curso **curso, arv_curso *no)
{
    int inseriu = 1;

    if (*curso == NULL) *curso == no;

    else 
        if (strcmp(no->info.cod_curso, (*curso)->info.cod_curso) < 0) 
            inseriu = inserir_arv_curso(&((*curso)->esq), no);

        else 
            if (strcmp(no->info.cod_curso, (*curso)->info.cod_curso) > 0)
                inseriu = inserir_arv_curso(&((*curso)->dir), no);
            
            else
                inseriu = 0;
    
    return inseriu;
}

arv_dis *cadastrar_disciplina(arv_curso *curso)
{
    int i = 0;
    int ch = 0;
    
    arv_dis *nova_dis = (arv_dis*)malloc(sizeof(arv_dis));
    if(nova_dis != NULL)
    {
        nova_dis->dir = NULL;
        nova_dis->esq = NULL;

        printf("Informe o codigo da disciplina:\n");
        scanf(" %[^\n]", nova_dis->info.cod_dis);

        printf("Informe o nome da disciplina:\n");
        scanf(" %[^\n]", nova_dis->info.nome);

        printf("Informe o periodo da disciplina no curso:\n");
        while(i < 1 && i > curso->info.qtd_periodos)
            scanf(" %d", &i);
        nova_dis->info.periodo = i;
        
        printf("Informe a carga horaria da disciplina:\n");
        while(ch < 30 && ch > 90 && ch % 15 != 0)
            scanf(" %d", &ch);
        nova_dis->info.carga_hr = ch;
    }

    return nova_dis;
}

int inserir_arv_dis(arv_dis **disciplina, arv_dis *no)
{
    int inseriu = 1;

    if(*disciplina == NULL) *disciplina = no;

    else 
        if(strcmp(no->info.cod_dis, (*disciplina)->info.cod_dis) < 0)
            inseriu = inserir_arv_dis(&((*disciplina)->esq), no);
        else
            if(strcmp(no->info.cod_dis, (*disciplina)->info.cod_dis) > 0)
                inseriu = inserir_arv_dis(&((*disciplina)->dir), no);
            else inseriu = 0;
        
        return inseriu;
}

l_aluno *cadastrar_aluno(arv_curso *curso)
{
    l_aluno *novo_aluno = (l_aluno*)malloc(sizeof(l_aluno));
    if(novo_aluno != NULL)
    {
        novo_aluno->prox = NULL;
        novo_aluno->matricula = NULL;
        novo_aluno->notas = NULL;
        

        printf("Informe o nome do aluno:\n");
        scanf(" %[^\n]", novo_aluno->info.nome);

        printf("Informe a matricula:\n");
        scanf(" %[^\n]", novo_aluno->info.matricula);

        strcpy(novo_aluno->info.cod_curso, curso->info.cod_curso);
    }
}

int inserir_aluno(l_aluno **aluno, l_aluno *no)
{
    int inseriu = 1;

    if(*aluno == NULL) *aluno = no;

    else
        if(strcmp((*aluno)->info.nome, no->info.nome) < 0)
            inseriu = inserir_aluno(&((*aluno)->));
}