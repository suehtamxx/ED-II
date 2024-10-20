#include "universidade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0 é erro, 1 é que deu certo

//Criar árvores e lista
arv_notas *criar_arv_notas()
{
    return NULL;
}
arv_matri *criar_arv_matricula()
{
    return NULL;
}
arv_dis *criar_arv_disciplina()
{
    return NULL;
}
arv_curso *criar_arv_curso()
{
    return NULL;
}
l_aluno * criar_lista_aluno()
{
    return NULL;
}
//------------------------------------------------------------------------------

//Criar os nós das árvores e lista
arv_notas *alocar_no_notas()
{
    arv_notas *novo_no;
    novo_no = (arv_notas*)malloc(sizeof(arv_notas));

    if (novo_no != NULL)
    {
        novo_no->esq = NULL;
        novo_no->dir = NULL;

        strcpy(novo_no->info.cod_dis, "");  
        strcpy(novo_no->info.semestre, "");      
        novo_no->info.nota_final = 0;  
    }
    
    return novo_no;
}
arv_matri *alocar_no_matricula()
{
    arv_matri *novo_no;
    novo_no = (arv_matri*)malloc(sizeof(arv_matri));

    if (novo_no != NULL)
    {
        novo_no->esq = NULL;
        novo_no->dir = NULL;

        strcpy(novo_no->info.cod_dis, "");   
    }
    
    return novo_no;
}
arv_dis *alocar_no_disciplina()
{
    arv_dis *novo_no;
    novo_no = (arv_dis*)malloc(sizeof(arv_dis));

    if (novo_no != NULL)
    {
        novo_no->esq = NULL;
        novo_no->dir = NULL;

        strcpy(novo_no->info.cod_dis, "");  
        strcpy(novo_no->info.nome, "");      
        novo_no->info.periodo = 0;  
        novo_no->info.carga_hr = 0;  
    }
    
    return novo_no;
}
arv_curso *alocar_no_curso()
{
    arv_curso *novo_no;
    novo_no = (arv_curso*)malloc(sizeof(arv_curso));

    if (novo_no != NULL)
    {
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        novo_no->info.arv_dis = criar_arv_disciplina();

        strcpy(novo_no->info.nome, "");      
        strcpy(novo_no->info.cod_curso, "");  
        novo_no->info.qtd_periodos = 0;  
    }
    
    return novo_no;
}
l_aluno *alocar_no_aluno()
{
    l_aluno *novo_no;
    novo_no = (l_aluno*)malloc(sizeof(l_aluno));
    if (novo_no != NULL)
    {
        novo_no->prox = NULL;
        novo_no->info.arv_notas = criar_arv_notas();
        novo_no->info.arv_matricula = criar_arv_matricula();

        strcpy(novo_no->info.cod_curso, "");  
        strcpy(novo_no->info.matricula, "");      
        strcpy(novo_no->info.nome, "");      
    }
    
    return novo_no;
}
//------------------------------------------------------------------------------

//Preencher as structs
arv_notas *cadastrar_notas(arv_notas **notas, arv_matri *matricula)
{
    strcpy((*notas)->info.cod_dis, matricula->info.cod_dis);

    printf("Informe o periodo cursado (Ex: 2024.2): ");
    scanf(" %[^\n]", (*notas)->info.semestre);

    printf("Informe a nota do aluno: ");
    scanf(" %f", &(*notas)->info.nota_final);
    
    return *notas;
}
arv_matri *cadastrar_matricula(arv_matri **no, arv_dis *disciplina)
{
    strcpy((*no)->info.cod_dis, disciplina->info.cod_dis);

    return (*no);
}
arv_dis *cadastrar_disciplina(arv_dis **no, arv_curso *curso)
{
    int i = 0, ch = 0, qtd = curso->info.qtd_periodos;

    printf("Informe o nome da disciplina: ");
    scanf(" %[^\n]", (*no)->info.nome);

    printf("Informe o codigo da disciplina: ");
    scanf(" %[^\n]", (*no)->info.cod_dis);

    printf("Informe o periodo da disciplina no curso: ");
    while (i < 1 || i > qtd)
        scanf(" %d", &i);
    
    (*no)->info.periodo = i;
    
    printf("Informe a carga horaria da disciplina: ");
    while(ch < 30 || ch > 90 || ch % 15 != 0)
        scanf(" %d", &ch);
    

    (*no)->info.carga_hr = ch;


    return (*no);
}
arv_curso *cadastrar_curso(arv_curso **no)
{
    printf("Informe o nome do curso: ");
    scanf(" %[^\n]", (*no)->info.nome);
    
    printf("Informe o codigo do curso: ");
    scanf(" %[^\n]", (*no)->info.cod_curso);

    printf("Informe a quantidade de periodos do curso: ");
    scanf(" %d", &(*no)->info.qtd_periodos);

    return (*no);
}
l_aluno *cadastrar_aluno(l_aluno **no, arv_curso *curso)
{
    printf("Informe o nome do aluno:\n");
    scanf(" %[^\n]", (*no)->info.nome);

    printf("Informe a matricula:\n");
    scanf(" %s", (*no)->info.matricula);

    strcpy((*no)->info.cod_curso, curso->info.cod_curso);

    return (*no);
}
//------------------------------------------------------------------------------

//Inserir nas árvores e lista
int inserir_arv_notas(arv_notas **notas, arv_notas *no)
{
    int inseriu = 1;

    if(*notas == NULL)
        *notas = no;

    else if(strcmp(no->info.cod_dis, (*notas)->info.cod_dis) > 0)
        inseriu = inserir_arv_notas(&((*notas)->dir), no);

        else if(strcmp(no->info.cod_dis, (*notas)->info.cod_dis) < 0)
            inseriu = inserir_arv_notas(&((*notas)->esq), no);
    
            else inseriu = 0;

    return inseriu;
}
int inserir_arv_matricula(arv_matri **matricula, arv_matri *no)
{
    int inseriu = 1;

    if (*matricula == NULL)
        *matricula = no;

    else if(strcmp(no->info.cod_dis, (*matricula)->info.cod_dis) < 0)
        inseriu = inserir_arv_matricula(&((*matricula)->esq), no);

    else if (strcmp(no->info.cod_dis, (*matricula)->info.cod_dis) > 0)
        inseriu = inserir_arv_matricula(&((*matricula)->dir), no);

        else inseriu = 0;
    
    return inseriu;
}
int inserir_arv_disciplina(arv_dis **disciplina, arv_dis *no)
{
    int inseriu = 1;

    if(*disciplina == NULL) 
        *disciplina = no;

    else if(strcmp(no->info.cod_dis, (*disciplina)->info.cod_dis) < 0)
        inseriu = inserir_arv_disciplina(&((*disciplina)->esq), no);
        
        else if(strcmp(no->info.cod_dis, (*disciplina)->info.cod_dis) > 0)
            inseriu = inserir_arv_disciplina(&((*disciplina)->dir), no);
                
            else inseriu = 0;
        
    return inseriu;
}
int inserir_arv_curso(arv_curso **curso, arv_curso *no)
{
    int inseriu = 1;

    if (*curso == NULL) 
        *curso = no;

    else if (strcmp(no->info.cod_curso, (*curso)->info.cod_curso) < 0) 
        inseriu = inserir_arv_curso(&((*curso)->esq), no);

        else if (strcmp(no->info.cod_curso, (*curso)->info.cod_curso) > 0)
            inseriu = inserir_arv_curso(&((*curso)->dir), no);
            
            else inseriu = 0;
    
    return inseriu;
}
int inserir_lista_aluno(l_aluno **aluno, l_aluno *no)
{
    int inseriu = 0;

    // Verifica se a lista está vazia ou se o novo aluno deve ser o primeiro
    if (*aluno == NULL || strcmp(no->info.nome, (*aluno)->info.nome) < 0) 
    {
        no->prox = *aluno;
        *aluno = no;
        inseriu = 1;
    } else{
        // Percorre a lista para encontrar a posição correta para o novo aluno
        l_aluno *atual = *aluno;
        while (atual->prox != NULL && strcmp(no->info.nome, atual->prox->info.nome) > 0) 
        {
            atual = atual->prox; // Move para o próximo aluno
        }

        no->prox = atual->prox;
        atual->prox = no;
        inseriu = 1;
        }
    // Insere o novo nó na posição correta

    return inseriu; // Retorna 1 se a inserção foi bem-sucedida
}
//------------------------------------------------------------------------------

//Imprimir o nó da árvore e lista
void imprimir_nota(arv_notas *no)
{
    printf("Semestre: %s | ", no->info.semestre);
    printf("Nota Final: %f |", no->info.nota_final);
    printf("Codigo da Disciplina: %s |", no->info.cod_dis);
    printf("\n");
}
//void imprimir_matricula(arv_matri *no);
void imprimir_disciplina(arv_dis *no)
{
    printf("Codigo: %s | ", no->info.cod_dis);
    printf("Nome: %s | ", no->info.nome);
    printf("Periodo da disciplina no curso: %d | ", no->info.periodo);
    printf("Carga Horaria: %d ", no->info.carga_hr);
    printf("\n");
}
void imprimir_curso(arv_curso *no)
{
    printf("Codigo: %s | ", no->info.cod_curso);
    printf("Nome: %s | ", no->info.nome);
    printf("Quantidade de periodos: %d", no->info.qtd_periodos);
    printf("\n");
}
void imprimir_aluno(l_aluno *no)
{
    printf("Nome: %s | ", no->info.nome);
    printf("Matricula: %s | ", no->info.matricula);
    printf("Codigo do curso: %s ", no->info.cod_curso);
    printf("\n");
}
//------------------------------------------------------------------------------

//Imprimir as árvores e lista (in-ordem)
void imprimir_arv_disciplina(arv_dis *raiz)
{
    if (raiz != NULL)
    {
        imprimir_arv_disciplina(raiz->esq);
        imprimir_disciplina(raiz);
        imprimir_arv_disciplina(raiz->dir);
    }   
}
void imprimir_arv_curso(arv_curso *raiz)
{
    if (raiz != NULL)
    {
        imprimir_arv_curso(raiz->esq);
        imprimir_curso(raiz);
        imprimir_arv_curso(raiz->dir);
    }   
}

void imprimir_alunos_disciplina(l_aluno *no, arv_dis *disciplina)
{
    if(no != NULL)
    {
        if(no->info.arv_matricula != NULL && strcmp(no->info.arv_matricula->info.cod_dis, disciplina->info.cod_dis) == 0)
            imprimir_aluno(no);
        
        imprimir_alunos_disciplina(no->prox, disciplina);
    }
}
void imprimir_alunos_curso(arv_curso *curso, l_aluno *no)
{ 
    if(no != NULL)
    {
        if(strcmp(no->info.cod_curso, curso->info.cod_curso) == 0)
            imprimir_aluno(no);
        
        imprimir_alunos_curso(curso, no->prox);
    }
}
//------------------------------------------------------------------------------

//Buscar nós nas árvores e lista
arv_matri *buscar_matricula(arv_matri *no, char *busca)
{
    arv_matri *novo_no;
    novo_no = NULL;

    if (no != NULL)
    {
        if (strcmp(busca, no->info.cod_dis) > 0)
            novo_no = buscar_matricula(no->dir, busca);
        
        else if (strcmp(busca, no->info.cod_dis) < 0)
            novo_no = buscar_matricula(no->esq, busca);
        
            else novo_no = no;
    }

    return novo_no;
}
arv_dis *buscar_disciplina(arv_dis *no, char *busca)
{
    arv_dis *novo_no;
    novo_no = NULL;

    if (no != NULL)
    {
        if (strcmp(busca, no->info.cod_dis) > 0)
            novo_no = buscar_disciplina(no->dir, busca);
        
        else if (strcmp(busca, no->info.cod_dis) < 0)
            novo_no = buscar_disciplina(no->esq, busca);
        
            else novo_no = no;
    }

    return novo_no;
}
arv_curso *buscar_curso(arv_curso *no, char *busca)
{
    arv_curso *novo_no;
    novo_no = NULL;

    if(no != NULL)
    {
        if(strcmp(busca, no->info.cod_curso) > 0)
            novo_no = buscar_curso(no->dir, busca);

        else if(strcmp(busca, no->info.cod_curso) < 0)
            novo_no = buscar_curso(no->esq, busca);
            
            else novo_no = no;
    } 

    return novo_no;
}
l_aluno *buscar_aluno(l_aluno *aluno, char *busca)
{
    l_aluno *novo_no;
    novo_no = NULL;

    if (aluno != NULL)
    {
        if (strcmp(busca, aluno->info.matricula) == 0)
            novo_no = aluno;

        else novo_no = buscar_aluno(aluno->prox, busca);
    }

    return novo_no;
}

void buscar_disciplina_periodo(arv_dis *no, int *busca)
{
    if(no != NULL)
    {
        buscar_disciplina_periodo(no->esq, busca);

        if(no->info.periodo == *busca)
            imprimir_disciplina(no);

        buscar_disciplina_periodo(no->dir, busca);
    }
}
void buscar_disciplina_matricula(arv_matri *no, arv_dis *disciplina)
{
    if(no != NULL)
    {
        buscar_disciplina_matricula(no->esq, disciplina);

        if(strcmp(disciplina->info.cod_dis, no->info.cod_dis) == 0)
            imprimir_disciplina(disciplina);

        buscar_disciplina_matricula(no->dir, disciplina);

    }
}
void buscar_notas_periodo(arv_notas *no, char *busca)
{
    if(no != NULL)
    {
        buscar_notas_periodo(no->esq, busca);
        
        if(strcmp(busca, no->info.semestre) == 0)
            imprimir_nota(no);

        buscar_notas_periodo(no->dir, busca);
    }
}
void buscar_notas_disciplina(arv_notas *no, arv_dis *disciplina)
{
    if(no != NULL)
    {
        buscar_notas_disciplina(no->esq, disciplina);

        if(strcmp(no->info.cod_dis, disciplina->info.cod_dis) == 0)
        {
            printf("Nota: %.2f | ", no->info.nota_final);
            printf("Periodo da disciplina no curso: %d | ", disciplina->info.periodo);
            printf("Carga Horaria: %d ", disciplina->info.carga_hr);
            printf("\n");
        }

        buscar_notas_disciplina(no->dir, disciplina);
    }
}
//------------------------------------------------------------------------------

//Verificar se o nó é folha
int e_folha_matricula(arv_matri *no)
{
    int verifica = 0;

    if (no->dir == NULL && no->esq == NULL)
        verifica = 1;
        
    return verifica;
}
//------------------------------------------------------------------------------

//Verificar se o nó tem um filho
arv_matri *so_um_filho_matricula(arv_matri *no)
{
    arv_matri *aux;

    if(no->dir == NULL && no->esq != NULL)
        aux = no->esq;
    else if(no->dir != NULL && no->esq == NULL)
        aux = no->dir;
    
    return aux;
}
//------------------------------------------------------------------------------

//Buscar o menor filho
arv_matri *menor_filho_matricula(arv_matri *no)
{
    while (no != NULL && no->esq != NULL)
        no = no->esq;
    
    return no;
}
//------------------------------------------------------------------------------

//Remover nós nas árvores e lista
int remover_disciplina_matricula(arv_matri **raiz, arv_dis *no)
{
    int removeu = 1, verificacao;
    arv_matri *aux;
    arv_matri *end_filho, *end_menor_filho;

    if((*raiz) != NULL)
    {
        if(strcmp((*raiz)->info.cod_dis, no->info.cod_dis) == 0)
        {
            verificacao = e_folha_matricula(*raiz);
            
            if(verificacao == 1)
            {
                aux = *raiz;
                *raiz = NULL;
                free(aux);
            }
            else if ((end_filho = so_um_filho_matricula(*raiz)) != NULL)
            {
                aux = *raiz;
                *raiz = end_filho;
                free(aux);
            }
                else
                {
                    end_menor_filho = menor_filho_matricula((*raiz)->dir);
                    aux = *raiz;
                    (*raiz)->info = end_menor_filho->info;
                    removeu = remover_disciplina_matricula(&(*raiz)->dir, no);
                } 
        }
        else if(strcmp(no->info.cod_dis, (*raiz)->info.cod_dis) < 0)
                    removeu = remover_disciplina_matricula(&((*raiz)->esq), no);        
            else 
                removeu = remover_disciplina_matricula(&((*raiz)->dir), no);
                
    }
    else removeu = 0;
    
    return removeu;
}
//------------------------------------------------------------------------------
   


// int remover_disciplina(arv_dis **raiz, arv_dis *no)
// {
//     int removeu = 1, verificacao;
//     arv_dis *aux;
//     arv_dis *end_filho, *end_menor_filho;

//     if((*raiz) != NULL)
//     {
//         if((*raiz)->info.cod_dis == no->info.cod_dis)
//         {
//             verificacao = e_folha(*raiz);
            
//             if(verificacao == 1)
//             {
//                 aux = *raiz;
//                 *raiz = NULL;
//                 free(aux);
//             }
//             else 
//                 if ((end_filho = so_um_filho(*raiz)) != NULL)
//                 {
//                     aux = *raiz;
//                     *raiz = NULL;
//                     free(aux);
//                 }
//                 else
//                 {
//                     end_menor_filho = menor_filho((*raiz)->dir);
//                     aux = *raiz;
//                     (*raiz)->info = end_menor_filho->info;
//                     removeu = remover_disciplina(&(*raiz)->dir, end_menor_filho);
//                 } 
//                 else 
//                         if(strcmp(no->info.cod_dis, (*disciplina)->info.cod_dis) < 0)
//                             removeu = remover_disciplina(&((*disciplina)->esq), no);
                    
//                         else 
//                             if(strcmp(no->info.cod_dis, (*disciplina)->info.cod_dis) > 0)
//                                 removeu = remover_disciplina(&((*disciplina)->dir), no);
                
//         }
    
//     }
//     else inseriu = 0;
    
//     return inseriu;
    
// }

//Liberar memória
void liberar_arv_notas(arv_notas *raiz) 
{
    if (raiz != NULL) 
    {
        liberar_arv_notas(raiz->esq);
        liberar_arv_notas(raiz->dir);
        free(raiz);
    }
}
void liberar_arv_matricula(arv_matri *raiz) 
{
    if (raiz != NULL) 
    {
        liberar_arv_matricula(raiz->esq);
        liberar_arv_matricula(raiz->dir);
        free(raiz);
    }
}
void liberar_arv_disciplina(arv_dis *raiz) 
{
    if (raiz != NULL) 
    {
        liberar_arv_disciplina(raiz->esq);
        liberar_arv_disciplina(raiz->dir);
        free(raiz);
    }
}
void liberar_arv_curso(arv_curso *raiz) 
{
    if (raiz != NULL) 
    {
        liberar_arv_curso(raiz->esq);
        liberar_arv_curso(raiz->dir);
        liberar_arv_disciplina(raiz->info.arv_dis);
        free(raiz);
    }
}
void liberar_lista_alunos(l_aluno *cabeca) 
{
    l_aluno *atual = cabeca;
    l_aluno *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        liberar_arv_matricula(atual->info.arv_matricula);
        liberar_arv_notas(atual->info.arv_notas);
        free(atual);
        atual = proximo;
    }
}