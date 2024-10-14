#include "universidade.h"
#include "universidade.c"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int op = 0, verificacao;
    char busca[5];
    
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
    arv_matri *noMatri;

    do
    {
        printf("\n===== MENU =====");
        printf("\n1. Cadastrar Curso");
        printf("\n2. Cadastrar Disciplina");
        printf("\n3. Cadastrar Matricula");
        printf("\n4. Cadastrar Aluno");
        printf("\n5. Cadastrar Notas");
        printf("\n6. Imprimir Curso");
        printf("\n7. Imprimir Disciplina");
        printf("\n8. Imprimir Aluno");
        printf("\n9. Imprimir Disciplina Por Periodo");
        printf("\n10. Imprimir Disciplinas de Aluno");
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
                if (verificacao == 1) printf("\nCadastro do curso realizado com sucesso!\n");
                else printf("\nErro ao cadastrar curso!\n");
            }
            break;

        case 2:
            printf("\n- Cadastrando Disciplina:\n");

            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso:\n");
            scanf(" %[^\n]", busca);
            
            noCurso = buscar_curso(arvCurso, busca);
            if(noCurso != NULL)
            {
                noDis = alocar_no_dis();
                if (noDis != NULL)
                {
                    noDis = cadastrar_disciplina(&noDis, noCurso);

                    verificacao = inserir_arv_dis(&(noCurso->info.dis), noDis);
                    if (verificacao == 1) printf("\nCadastro da disciplina realizado com sucesso!\n");
                    else printf("\nErro ao cadastrar disciplina!\n");
                }
            }else printf("Curso nao encontrado!");
            break;

        case 3:
            printf("\n- Cadastrando Matricula do Aluno:\n");
            
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca);

            if (noCurso != NULL)
            {
                imprimir_alunos_curso(noCurso, lAluno);
                printf("\nInforme a matricula do aluno: ");
                scanf(" %[^\n]", busca);

                noAluno = buscar_aluno(lAluno, busca);
                
                if (noAluno != NULL)
                {
                    imprimir_arv_dis(noCurso->info.dis);
                    printf("\nInforme o codigo da disciplina: ");
                    scanf(" %[^\n]", busca);
                    
                    noDis = buscar_disciplina(noCurso->info.dis, busca);
                    
                    if (noDis != NULL)
                    {
                        noMatri = alocar_no_matricula();

                        if (noMatri != NULL)
                        {
                            noMatri = cadastrar_matricula(&noMatri, noDis);

                            verificacao = inserir_arv_matricula(&(noAluno->info.arv_matricula), noMatri);
                            if (verificacao == 1) printf("\nCadastro da matricula realizado com sucesso!\n");
                            else printf("\nErro ao cadastrar disciplina!\n");
                        }
                        else printf("\nErro ao alocar matricula (cadastrar matricula)!\n");
                    }else printf("\nDisciplina nao encontrada!\n");
                }else printf("\nAluno nao encontrado!\n");            
            }else printf("\nCurso nao encontrado!\n");

            break;

        case 4:
            if(arvCurso != NULL)
            {
                printf("\n- Cadastrando Aluno:\n");

                imprimir_arv_curso(arvCurso);   
                printf("\nInforme o codigo do curso: ");
                scanf(" %[^\n]", busca);

                noCurso = buscar_curso(arvCurso, busca);
                if(noCurso != NULL)
                {
                    noAluno = alocar_no_aluno();
                    if (noAluno != NULL)
                    {
                        noAluno = cadastrar_aluno(&noAluno, noCurso);

                        verificacao = inserir_lista_aluno(&lAluno, noAluno);
                        if (verificacao == 1) printf("\nCadastro de aluno realizado com sucesso!\n");
                        else printf("\nErro ao cadastrar aluno!\n");
                    }
                }
            }
            break;

        case 5:
            printf("Cadastrando notas:\n");
                imprimir_arv_curso(arvCurso);
                printf("Informe o codigo do curso: ");
                scanf(" %[^\n]", busca);
                
                noCurso = buscar_curso(arvCurso, busca);
                if(noCurso != NULL)
                {
                    imprimir_arv_dis(arvDis);

                    printf("Informe a disciplina:\n");
                    scanf(" %[^\n]", busca);

                    noDis = buscar_disciplina(arvDis, busca);
                    if(noDis != NULL)
                    {
                        
                    }
                }
                break;

         case 6:
            printf("\n- Imprimindo Cursos:\n");
            imprimir_arv_curso(arvCurso);
            break;

        case 7:
            printf("\n- Imprimindo Disciplinas:\n");
            
            imprimir_arv_curso(arvCurso);   
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);

            noCurso = buscar_curso(arvCurso, busca);
            if(noCurso != NULL)
                imprimir_arv_dis(noCurso->info.dis);
            break;

        case 8:
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca);

            if (noCurso != NULL)
                imprimir_alunos_curso(noCurso, lAluno);
            break;
        case 9:
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca);
            if(noCurso != NULL)
            {
                int buscaInt = 0;

                printf("Informe o periodo: ");
                while (buscaInt < 1 || buscaInt > noCurso->info.qtd_periodos)
                scanf(" %d", &buscaInt);
                
                buscar_disciplina_periodo(noCurso->info.dis, &buscaInt);
            }
            break;

        case 10:
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca);
            if(noCurso != NULL)
            {
                imprimir_alunos_curso(noCurso, lAluno);

                printf("\nInforme a matricula do Aluno: ");
                scanf(" %[^\n]", busca);

                noAluno = buscar_aluno(lAluno, busca);

                if (noAluno != NULL)
                {
                    buscar_disciplina_matricula(noAluno->info.arv_matricula, noCurso->info.dis);
                }
                
            }

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