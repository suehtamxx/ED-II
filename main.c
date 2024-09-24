#include "universidade.h"
#include "universidade.c"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int op = 0;
    
    arv_curso *noc;
    arv_dis *nod;
    l_aluno *noa;

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
            int *erro = 0;
        
            *erro = inserir_arv_curso(&arv_curso, noc);
            break;
        case 2:
            int *erro1 = 0;

            *erro1 = inserir_arv_dis(&arv_dis, nod);
            break;
        case 3:
            int *erro2 = 0;

            *erro2 = inserir_aluno(&l_aluno, noa);
            break;
        default:
            break;
        }
    } while (op != 0);
    


    return 0;
}

