#include "universidade.h"
#include "universidade.c"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int op = 0, verificacao;
    
    //Criando as árvores e lista
    arv_curso *arvCurso;
    arv_dis *arvDis;
    l_aluno *lAluno;
    arvCurso = criar_arv_curso(); 
    arvDis = criar_arv_dis();
    lAluno = criar_lista_aluno();
    
    //Criando os nós
    arv_curso *noCurso;
    arv_dis *noDis;
    l_aluno *noAluno;
    noCurso = NULL;
    noDis = NULL;
    noAluno = NULL;

    char busca[5];
    int comparacao = 0;
    do
    {
        printf("\n===== MENU =====");
        printf("\n1. Cadastrar Curso");
        printf("\n2. Cadastrar Disciplina");
        printf("\n3. Cadastrar Aluno");
        printf("\n4. Imprimir Curso");
        printf("\n5. Imprimir Disciplina");
        printf("\n6. Imprimir Aluno");
        printf("\n0. Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            printf("\n- Cadastrando Curso:\n");
            noCurso = alocar_no_curso(); //Criando um nó nulo
            if (noCurso != NULL)
            {
                noCurso = cadastrar_curso(&noCurso); //Mandando o nó nulo e recebendo ele preenchido
                
                verificacao = inserir_arv_curso(&arvCurso, noCurso);
                if (verificacao == 1) printf("\nCadastro do curso realizado com sucesso!");
                else printf("\nErro ao cadastrar curso!");
            }
            break;

        case 2:
            printf("\n- Cadastrando Disciplina:\n");
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso:\n");
            scanf(" %[^\n]", busca);
            //passando como parâmetro o codigo do curso e retornar o nó do curso que pertence a esse código
            comparacao = buscar_curso(arvCurso, busca);
            //printf("comparacao: %d ", comparacao);
                if(comparacao == 1)
                {
                    noDis = alocar_no_dis();
                        if (noDis != NULL)
                        {
                                noDis = cadastrar_disciplina(&noDis, arvCurso);

                                verificacao = inserir_arv_dis(&arvDis, noDis);
                                if (verificacao == 1) printf("\nCadastro da disciplina realizado com sucesso!");
                                else printf("\nErro ao cadastrar disciplina!");
                        }
                }
            break;

        case 3:
            //Fazer função de buscar os cursos
            //passando como parâmetro o codigo do curso e retornar o nó do curso que pertence a esse código
            if(arvCurso != NULL){
                printf("\n- Cadastrando Aluno:\n");
                imprimir_arv_curso(arvCurso);   
                    printf("Informe o codigo do curso:\n");
                    scanf("%s ", busca);
                    comparacao = buscar_curso(arvCurso, busca);
                    printf("comparacao: %d", comparacao);
                    
                    if(comparacao == 1){
                        noAluno = alocar_no_aluno();
                            if (noAluno != NULL)
                            {
                                noAluno = cadastrar_aluno(&noAluno, arvCurso);

                                verificacao = inserir_lista_aluno(&lAluno, noAluno);
                                if (verificacao == 1) printf("\nCadastro de aluno realizado com sucesso!");
                                else printf("\nErro ao cadastrar aluno!");
                            }
                        
                }
            }
            break;

        case 4:
            printf("\n- Imprimindo Cursos:\n");
            imprimir_arv_curso(arvCurso);
            break;

        case 5:
            printf("\n- Imprimindo Disciplinas:\n");
            imprimir_arv_dis(arvDis);
            break;

        case 6:
            printf("\n- Imprimindo Alunos:\n");
            imprimir_lista_aluno(lAluno);
            break;
        case 0:
                printf("Saindo...\n");
                break;
        
        default:
            printf("\nOpcao invalida!");
            break;
        }
    } while (op != 0);

    return 0;
}