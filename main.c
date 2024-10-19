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
    // arv_dis *arvDis;
    // arv_matri *arvMatri;
    // arv_notas *arvNotas;
    l_aluno *lAluno;
    arvCurso = criar_arv_curso(); 
    // arvDis = criar_arv_disciplina();
    // arvMatri = criar_arv_matricula();
    // arvNotas = criar_arv_notas();
    lAluno = criar_lista_aluno();
        
    //Criando os nós
    arv_curso *noCurso;
    arv_dis *noDis;
    l_aluno *noAluno;
    arv_matri *noMatri;

    do
    {
        printf("\n========  M E N U  ========");
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
        printf("\n11. Imprimir Notas de Aluno");
        printf("\n0. Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            printf("\n===== CADASTRANDO CURSO =====\n");

            noCurso = alocar_no_curso(); //Criando um nó nulo
            if (noCurso != NULL)
            {
                noCurso = cadastrar_curso(&noCurso); //Mandando o nó nulo e recebendo ele preenchido
                
                verificacao = inserir_arv_curso(&arvCurso, noCurso); //Inserindo na árvore o nó preenchido
                if (verificacao == 1) printf("\nCadastro do curso realizado com sucesso!\n");
                else printf("\nErro ao cadastrar curso!\n");
            }
            else printf("\nErro ao alocar no Curso!\n");

            break;

        case 2:
            printf("\n===== CADASTRANDO DISCIPLINA =====\n");

            printf("\n- Imprimindo cursos disponiveis:\n");
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
            
            noCurso = buscar_curso(arvCurso, busca); //Buscando o curso escolhido
            if(noCurso != NULL)
            {
                noDis = alocar_no_disciplina(); //Criando um nó nulo
                if (noDis != NULL)
                {
                    noDis = cadastrar_disciplina(&noDis, noCurso); //Mandando o nó nulo e recebendo ele preenchido

                    verificacao = inserir_arv_disciplina(&(noCurso->info.arv_dis), noDis); //Inserindo na árvore o nó preenchido
                    if (verificacao == 1) printf("\nCadastro da disciplina realizado com sucesso!\n");
                    else printf("\nErro ao cadastrar disciplina!\n");
                }
                else printf("\nErro ao alocar no disciplina!\n");
            }
            else printf("\nCurso nao encontrado!\n");
            
            break;

        case 3:
            printf("\n===== CADASTRANDO MATRICULA DO ALUNO =====\n");
            
            printf("\n- Imprimindo cursos disponiveis:\n");
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca); //Buscando o curso escolhido
            if (noCurso != NULL)
            {
                printf("\n- Imprimindo alunos do curso:\n");
                imprimir_alunos_curso(noCurso, lAluno);
                printf("\nInforme a matricula do aluno: ");
                scanf(" %[^\n]", busca);

                noAluno = buscar_aluno(lAluno, busca); //Buscando o aluno escolhido
                if (noAluno != NULL)
                {
                    printf("\n- Imprimindo disciplinas disponiveis:\n");
                    imprimir_arv_disciplina(noCurso->info.arv_dis);
                    printf("\nInforme o codigo da disciplina: ");
                    scanf(" %[^\n]", busca);
                    
                    noDis = buscar_disciplina(noCurso->info.arv_dis, busca); //Buscando o disciplina escolhido
                    if (noDis != NULL)
                    {
                        noMatri = alocar_no_matricula(); //Criando um nó nulo
                        if (noMatri != NULL)
                        {
                            noMatri = cadastrar_matricula(&noMatri, noDis); //Mandando o nó nulo e recebendo ele preenchido

                            verificacao = inserir_arv_matricula(&(noAluno->info.arv_matricula), noMatri); //Inserindo na árvore o nó preenchido
                            if (verificacao == 1) printf("\nCadastro da matricula realizado com sucesso!\n");
                            else printf("\nErro ao cadastrar disciplina!\n");
                        }
                        else printf("\nErro ao alocar matricula!\n");
                    }
                    else printf("\nDisciplina nao encontrada!\n");
                }
                else printf("\nAluno nao encontrado!\n");            
            }
            else printf("\nCurso nao encontrado!\n");

            break;

        case 4:
            printf("\n===== CADASTRANDO ALUNO =====\n");
            
            if(arvCurso != NULL)
            {
                printf("\n- Imprimindo cursos disponiveis:\n");
                imprimir_arv_curso(arvCurso);   
                printf("\nInforme o codigo do curso: ");
                scanf(" %[^\n]", busca);

                noCurso = buscar_curso(arvCurso, busca); //Buscando o curso escolhido
                if(noCurso != NULL)
                {
                    noAluno = alocar_no_aluno(); //Criando um nó nulo
                    if (noAluno != NULL)
                    {
                        noAluno = cadastrar_aluno(&noAluno, noCurso); //Mandando o nó nulo e recebendo ele preenchido 

                        verificacao = inserir_lista_aluno(&lAluno, noAluno); //Inserindo na árvore o nó preenchido
                        if (verificacao == 1) printf("\nCadastro de aluno realizado com sucesso!\n");
                        else printf("\nErro ao cadastrar aluno!\n");
                    }
                    else printf("\nErro ao alocar aluno!\n");
                }
                else printf("\nCurso nao encontrado!\n");
            }
            else printf("\nNenhum curso cadastrado! Cadastre um curso primeiro.\n");

            break;

        case 5:
            printf("\n===== CADASTRANDO NOTA =====\n");
            
            printf("\n- Imprimindo cursos disponiveis:\n");
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
            
            noCurso = buscar_curso(arvCurso, busca); //Buscando o curso escolhido
            if(noCurso != NULL)
            {
                printf("\n- Imprimindo disciplinas disponiveis:\n");
                imprimir_arv_disciplina(noCurso->info.arv_dis);
                printf("\nInforme o codigo da disciplina: ");
                scanf(" %[^\n]", busca);
                
                noDis = buscar_disciplina(noCurso->info.arv_dis, busca); //Buscando a disciplina escolhido
                if(noDis != NULL)
                {
                    printf("\n- Imprimindo alunos do curso:\n");
                    imprimir_alunos_disciplina(lAluno, noDis);
                    printf("Informe a matricula do aluno: ");
                    scanf(" %[^\n]", busca);

                    noAluno = buscar_aluno(lAluno, busca); //Buscando a aluno escolhido
                    if(noAluno != NULL)
                    {
                        noMatri = buscar_matricula(noAluno->info.arv_matricula, noDis->info.cod_dis); //Buscando a matricula
                        if(noMatri != NULL)
                        {
                            arv_notas *novaNota;
                            novaNota = alocar_no_notas(); //Criando um nó nulo

                            novaNota = cadastrar_notas(novaNota, *noMatri); //Mandando o nó nulo e recebendo ele preenchido 

                            verificacao = remover_disciplina_matricula(&noAluno->info.arv_matricula, noDis); //Removendo o nó da árvore
                            if(verificacao == 1) printf("\nDisciplina removida com sucesso!\n");
                            else printf("Erro ao remover disciplina!\n");

                            verificacao = inserir_arv_notas(&lAluno->info.arv_notas, novaNota); //Inserindo na árvore o nó preenchido
                            if(verificacao == 1) printf("\nNota cadastrada com sucesso\n!");
                            else printf("\nErro ao cadastrar nota!\n");
                        }
                        else printf("\nMatricula nao encontrada!\n");
                    }
                    else printf("\nAluno nao encontrado\n!");
                }
                else printf("\nDisciplina nao encontrada!\n");
            }
            else printf("\nCurso nao encontrado!\n");
            
            break;

         case 6:
            printf("\n===== IMPRIMINDO CURSOS =====\n");
            imprimir_arv_curso(arvCurso);
            break;

        case 7:
            printf("\n===== IMPRIMINDO DISCIPLINAS =====");
            
            printf("\n- Imprimindo cursos disponiveis:\n");
            imprimir_arv_curso(arvCurso);   
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);

            noCurso = buscar_curso(arvCurso, busca);//Buscando o curso escolhido
            if(noCurso != NULL)
            {
                printf("\n- Imprimindo disciplinas do curso:\n");
                imprimir_arv_disciplina(noCurso->info.arv_dis);
            }
            else printf("\nCurso nao encontrado!\n");
            
            break;

        case 8:
            printf("\n===== IMPRIMINDO ALUNOS =====\n");
            
            printf("\n- Imprimindo cursos disponiveis:\n");
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca); //Buscando o curso escolhido
            if (noCurso != NULL)
            {
                printf("\n- Imprimindo alunos do curso:\n");
                imprimir_alunos_curso(noCurso, lAluno);
            }
            else printf("\nCurso nao encontrado!\n");
            
            break;
            
        case 9:
            printf("\n===== IMPRIMINDO DISCIPLINAS P/ PERIODO =====\n");
            
            printf("\n- Imprimindo cursos disponiveis:\n");
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca); //Buscando o curso escolhido
            if(noCurso != NULL)
            {
                int buscaInt = 0;

                printf("\nInforme o periodo: ");
                while (buscaInt < 1 || buscaInt > noCurso->info.qtd_periodos)
                    scanf(" %d", &buscaInt);
                
                buscar_disciplina_periodo(noCurso->info.arv_dis, &buscaInt);
            }
            else printf("\nCurso nao encontrado!\n");

            break;

        case 10:
            printf("\n===== IMPRIMINDO DISCIPLINAS DO ALUNO =====\n");
            
            printf("\n- Imprimindo cursos disponiveis:\n");
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca); //Buscando o curso escolhido
            if(noCurso != NULL)
            {
                printf("\n- Imprimindo alunos do curso:\n");
                imprimir_alunos_curso(noCurso, lAluno);
                printf("\nInforme a matricula do aluno: ");
                scanf(" %[^\n]", busca);

                noAluno = buscar_aluno(lAluno, busca); //Buscando o aluno escolhido
                if (noAluno != NULL)
                {
                    printf("\nInforme o semestre: ");
                    scanf(" %[^\n]", busca);

                    buscar_notas_periodo(noAluno->info.arv_notas, busca); 
                }
                    
            }
            else printf("\nCurso nao encontrado!\n");

            break;

        case 11:
            printf("\n===== IMPRIMINDO NOTAS DO ALUNO =====\n");
            
            printf("\n- Imprimindo cursos disponiveis:\n");
            imprimir_arv_curso(arvCurso);
            printf("\nInforme o codigo do curso: ");
            scanf(" %[^\n]", busca);
                
            noCurso = buscar_curso(arvCurso, busca); //Buscando o curso escolhido
            if(noCurso != NULL)
            {
                printf("\n- Imprimindo alunos do curso %s:", noCurso->info.nome);
                imprimir_alunos_curso(noCurso, lAluno);
                printf("\nInforme a matricula do aluno: ");
                scanf(" %[^\n]", busca);

                noAluno = buscar_aluno(lAluno, busca);
                if (noAluno != NULL)
                {
                    printf("\nInforme o semestre: ");
                    scanf(" %[^\n]", busca);
                    buscar_notas_periodo(noAluno->info.arv_notas, busca);
                }
                else printf("\nAluno nao encontrado!\n");
            } 
            else printf("\nCurso nao encontrado!\n");

            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("\nOpcao invalida!");
            break;
        }
    } while (op != 0);

    liberar_arv_curso(arvCurso);
    liberar_lista_alunos(lAluno);
    
    return 0;
}
