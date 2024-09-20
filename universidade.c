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

    if (*curso != NULL) *curso == no;

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