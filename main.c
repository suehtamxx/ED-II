#include "universidade.h"
#include "universidade.c"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int op = 0;

    arv_curso *arv_curso;
    arv_dis *arv_dis;
    l_aluno *l_aluno;

    arv_curso = criar_arv_curso(); 
    arv_dis = criar_arv_dis();
    l_aluno = criar_list_aluno();

    do
    {
        printf("\n1. Cadastrar Curso")
        printf("\n2. Cadastrar Disciplina")
        printf("\n3. Cadastrar Aluno")
    
        printf("\nEscolha uma opcao: ")
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            int erro = 0;

            erro = inserir_arv_curso()
            break;
        
        default:
            break;
        }
    } while (/* condition */);
    


    return 0;
}

