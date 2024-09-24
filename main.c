#include "universidade.h"
#include "universidade.c"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int op = 0, erro;
    
    arv_curso *noc;
    arv_dis *nod;
    l_aluno *noa;

    noc = NULL;
    nod = NULL;
    noa = NULL;

    arv_curso *arv_curso;
    arv_dis *arv_dis;
    l_aluno *l_aluno;
    
    arv_curso = criar_arv_curso(); 
    arv_dis = criar_arv_dis();
    l_aluno = criar_list_aluno();

    do
    {
        printf("\n1. Cadastrar Curso");
        printf("\n2. Cadastrar Disciplina");
        printf("\n3. Cadastrar Aluno");
        printf("\n0. Sair");
        printf("\nEscolha uma opcao: ");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            noc = cadastrar_curso();
            erro = inserir_arv_curso(&arv_curso, noc);

            if (erro == 1) printf("\nCadastro do curso realizado com sucesso!");
            else printf("\nErro ao cadastrar curso!");

            break;
        case 2:
            nod = cadastrar_disciplina(arv_curso);
            erro = inserir_arv_dis(&arv_dis, nod);

            if (erro == 1) printf("\nCadastro da disciplina realizado com sucesso!");
            else printf("\nErro ao cadastrar disciplina!");
            break;
        case 3:
            noa = cadastrar_aluno(arv_curso);
            erro = inserir_aluno(&l_aluno, noa);

            if (erro == 1) printf("\nCadastro de aluno realizado com sucesso!");
            else printf("\nErro ao cadastrar aluno!");
            break;
        
        default:
            printf("\nOpcao invalida!");
            break;
        }
    } while (op != 0);
    


    return 0;
}

