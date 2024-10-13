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
        printf("\n1. Cadastrar Curso"); //ok
        printf("\n2. Cadastrar Disciplina"); //ok
        printf("\n3. Cadastrar Matricula");
        printf("\n4. Cadastrar Aluno");
        printf("\n5. Imprimir Curso");
        printf("\n6. Imprimir Disciplina");
        printf("\n7. Imprimir Aluno");
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
            }
            break;

        case 3:
        printf("\n- Cadastrando Matricula do Aluno:\n");
        
        imprimir_arv_curso(arvCurso);
        printf("\nInforme o codigo do curso: ");
        scanf(" %[^\n]", busca);
            
        noCurso = buscar_curso(arvCurso, busca);

        if (noCurso != NULL)
        {
            imprimir_arv_dis(noCurso->info.dis);
            printf("\nInforme o codigo da disciplina: ");
            scanf(" %[^\n]", busca);

            noDis = buscar_disciplina(noCurso->info.dis, busca);

            if (noDis != NULL)
            {
                imprimir_alunos_curso(noCurso, lAluno); //não está printando a partir da segunda vez
                printf("\nInforme o codigo do aluno: ");
                scanf(" %[^\n]", busca);
            
                noAluno = buscar_aluno(lAluno, busca);
                //printf("certo\n");
                if (noAluno != NULL)
                {
                    //printf("certo2\n");
                    noMatri = alocar_no_matricula();

                    if (noMatri != NULL)
                    {
                        //printf("certo3");
                        noMatri = cadastrar_matricula(&noMatri, noDis);

                        verificacao = inserir_arv_matricula(&(noAluno->info.arv_matricula), noMatri);
                        if (verificacao == 1) printf("\nCadastro da matricula realizado com sucesso!\n");
                        else printf("\nErro ao cadastrar disciplina!\n");
                    }
                    else printf("\nErro ao alocar matricula (cadastrar matricula)!\n");
                }
            }            
        }
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
            printf("\n- Imprimindo Cursos:\n");
            imprimir_arv_curso(arvCurso);
            break;

        case 6:
            printf("\n- Imprimindo Disciplinas:\n");
            
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);

            noCurso = buscar_curso(arvCurso, busca);
            if(noCurso != NULL)
                imprimir_arv_dis(arvCurso->info.dis);
            break;

        case 7:
            printf("\n- Imprimindo Alunos:\n");
            imprimir_lista_aluno(lAluno);
            break;
         case 8:
        //é oq falei no whats, faz a busca da disciplina dai passa como parametro pra conseguir usar la dentro da funcao.
            printf("Cadastrando notas:\n");
            imprimir_arv_dis(arvDis);

            printf("Informe a disciplina:\n");
            scanf(" %[^\n]", busca);

            noDis = buscar_disciplina(arvDis, busca);
            if(noDis != NULL)
            {
                
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