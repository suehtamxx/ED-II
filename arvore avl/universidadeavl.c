#include "universidadeavl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0 é erro, 1 é que deu certo

//Criar árvores e lista
arv_notas_avl *criar_arv_notas()
{
    return NULL;
}
arv_matri_avl *criar_arv_matricula()
{
    return NULL;
}
arv_dis_avl *criar_arv_disciplina()
{
    return NULL;
}
arv_curso_avl *criar_arv_curso()
{
    return NULL;
}
l_aluno * criar_lista_aluno()
{
    return NULL;
}
//------------------------------------------------------------------------------

//Criar os nós das árvores e lista
arv_notas_avl *alocar_no_notas()
{
    arv_notas_avl *novo_no;
    novo_no = (arv_notas_avl *)malloc(sizeof(arv_notas_avl));

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
arv_matri_avl *alocar_no_matricula()
{
    arv_matri_avl *novo_no;
    novo_no = (arv_matri_avl*)malloc(sizeof(arv_matri_avl));

    if (novo_no != NULL)
    {
        novo_no->esq = NULL;
        novo_no->dir = NULL;

        strcpy(novo_no->info.cod_dis, "");  
    }
    
    return novo_no;
}
arv_dis_avl *alocar_no_disciplina()
{
    arv_dis_avl *novo_no;
    novo_no = (arv_dis_avl*)malloc(sizeof(arv_dis_avl));

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
arv_curso_avl *alocar_no_curso()
{
    arv_curso_avl *novo_no;
    novo_no = (arv_curso_avl*)malloc(sizeof(arv_curso_avl));

    if (novo_no != NULL)
    {
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        novo_no->info.arv_dis_avl = criar_arv_disciplina();

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
        novo_no->info.arv_notas_avl = criar_arv_notas();
        novo_no->info.arv_matricula = criar_arv_matricula();

        strcpy(novo_no->info.cod_curso, "");  
        strcpy(novo_no->info.matricula, "");      
        strcpy(novo_no->info.nome, "");      
    }
    
    return novo_no;
}
//------------------------------------------------------------------------------
//Calcula balanceamento e altura da arvore
int fator_balanceamento_notas(arv_notas_avl **no)
{   
    int fb = 0;
    int alt_esq = 0;
    int alt_dir = 0;

    if(*no != NULL)
    {
        if((*no)->esq != NULL)
            alt_esq = (*no)->esq->alt;
        if((*no)->dir != NULL)
            alt_dir = (*no)->dir->alt;
        fb = alt_esq - alt_dir;
    }
    return fb;
}
int fator_balanceamento_matricula(arv_matri_avl **no)
{   
    int fb = 0;
    int alt_esq = 0;
    int alt_dir = 0;

    if(*no != NULL)
    {
        if((*no)->esq != NULL)
            alt_esq = (*no)->esq->alt;
        if((*no)->dir != NULL)
            alt_dir = (*no)->dir->alt;
        fb = alt_esq - alt_dir;
    }
    return fb;
}
int fator_balanceamento_disciplina(arv_dis_avl **no)
{   
    int fb = 0;
    int alt_esq = 0;
    int alt_dir = 0;

    if(*no != NULL)
    {
        if((*no)->esq != NULL)
            alt_esq = (*no)->esq->alt;
        if((*no)->dir != NULL)
            alt_dir = (*no)->dir->alt;
        fb = alt_esq - alt_dir;
    }
    return fb;
}
int fator_balanceamento_curso(arv_curso_avl **no)
{   
    int fb = 0;
    int alt_esq = 0;
    int alt_dir = 0;

    if(*no != NULL)
    {
        if((*no)->esq != NULL)
            alt_esq = (*no)->esq->alt;
        if((*no)->dir != NULL)
            alt_dir = (*no)->dir->alt;
        fb = alt_esq - alt_dir;
    }
    return fb;
}

void rotacao_esquerda_notas(arv_notas_avl **no)
{
    arv_notas_avl *aux;
    aux = NULL;

    aux = (*no)->dir;
    (*no)->dir = aux->esq;
    aux->esq = (*no);
    (*no) = aux;
}
void rotacao_esquerda_matricula(arv_matri_avl **no)
{
    arv_matri_avl *aux;
    aux = NULL;

    aux = (*no)->dir;
    (*no)->dir = aux->esq;
    aux->esq = (*no);
    (*no) = aux;
}
void rotacao_esquerda_disciplina(arv_dis_avl **no)
{
    arv_dis_avl *aux;
    aux = NULL;

    aux = (*no)->dir;
    (*no)->dir = aux->esq;
    aux->esq = (*no);
    (*no) = aux;
}
void rotacao_esquerda_curso(arv_curso_avl **no)
{
    arv_curso_avl *aux;
    aux = NULL;

    aux = (*no)->dir;
    (*no)->dir = aux->esq;
    aux->esq = (*no);
    (*no) = aux;
}

void rotacao_direita_notas(arv_notas_avl **no)
{
    arv_notas_avl *aux;
    aux = NULL;

    aux = (*no)->esq;
    (*no)->esq = aux->dir;
    aux->dir = (*no);
    (*no) = aux;
}
void rotacao_direita_matricula(arv_matri_avl **no)
{
    arv_matri_avl *aux;
    aux = NULL;

    aux = (*no)->esq;
    (*no)->esq = aux->dir;
    aux->dir = (*no);
    (*no) = aux;
}
void rotacao_direita_disciplina(arv_dis_avl **no)
{
    arv_dis_avl *aux;
    aux = NULL;

    aux = (*no)->esq;
    (*no)->esq = aux->dir;
    aux->dir = (*no);
    (*no) = aux;
}
void rotacao_direita_curso(arv_curso_avl **no)
{
    arv_curso_avl *aux;
    aux = NULL;

    aux = (*no)->esq;
    (*no)->esq = aux->dir;
    aux->dir = (*no);
    (*no) = aux;
}

void balanceamento_notas(arv_notas_avl **no)
{
    int fb;
    fb = fator_balanceamento_notas(no);
    if(fb == -2)
    {
        if(fator_balanceamento_notas(&(*no)->dir) > 0)
            rotacao_direita_notas(&((*no)->dir));
        rotacao_esquerda_notas(no);
    }else if(fb == 2)
    {
        if(fator_balanceamento_notas(&(*no)->esq) < 0)
            rotacao_esquerda_notas(&((*no)->esq));
        rotacao_direita_notas(no);
    }
}
void balanceamento_matricula(arv_matri_avl **no)
{
    int fb;
    fb = fator_balanceamento_matricula(no);
    if(fb == -2)
    {
        if(fator_balanceamento_matricula(&(*no)->dir) > 0)
            rotacao_direita_matricula(&((*no)->dir));
        rotacao_esquerda_matricula(no);
    }else if(fb == 2)
    {
        if(fator_balanceamento_matricula(&(*no)->esq) < 0)
            rotacao_esquerda_matricula(&((*no)->esq));
        rotacao_direita_matricula(no);
    }
}
void balanceamento_disciplina(arv_dis_avl **no)
{
    int fb;
    fb = fator_balanceamento_disciplina(no);
    if(fb == -2)
    {
        if(fator_balanceamento_disciplina(&(*no)->dir) > 0)
            rotacao_direita_disciplina(&((*no)->dir));
        rotacao_esquerda_disciplina(no);
    }else if(fb == 2)
    {
        if(fator_balanceamento_disciplina(&(*no)->esq) < 0)
            rotacao_esquerda_disciplina(&((*no)->esq));
        rotacao_direita_disciplina(no);
    }
}
void balanceamento_curso(arv_curso_avl **no)
{
    int fb;
    fb = fator_balanceamento_curso(no);
    if(fb == -2)
    {
        if(fator_balanceamento_curso(&(*no)->dir) > 0)
            rotacao_direita_curso(&((*no)->dir));
        rotacao_esquerda_curso(no);
    }else if(fb == 2)
    {
        if(fator_balanceamento_curso(&(*no)->esq) < 0)
            rotacao_esquerda_curso(&((*no)->esq));
        rotacao_direita_curso(no);
    }
}

void atualizar_altura_notas(arv_notas_avl **no)
{   
    int alt_esq = 0;
    int alt_dir = 0;
    if(*no != NULL)
    {
        alt_esq = (*no)->esq ? (*no)->esq->alt : -1;
        alt_dir = (*no)->dir ? (*no)->dir->alt : -1;
        (*no)->alt = (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
    }
}
void atualizar_altura_matricula(arv_matri_avl **no)
{   
    int alt_esq = 0;
    int alt_dir = 0;
    if(*no != NULL)
    {
        alt_esq = (*no)->esq ? (*no)->esq->alt : -1;
        alt_dir = (*no)->dir ? (*no)->dir->alt : -1;
        (*no)->alt = (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
    }
}
void atualizar_altura_disciplina(arv_dis_avl **no)
{   
    int alt_esq = 0;
    int alt_dir = 0;
    if(*no != NULL)
    {
        alt_esq = (*no)->esq ? (*no)->esq->alt : -1;
        alt_dir = (*no)->dir ? (*no)->dir->alt : -1;
        (*no)->alt = (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
    }
}
void atualizar_altura_curso(arv_curso_avl **no)
{   
    int alt_esq = 0;
    int alt_dir = 0;
    if(*no != NULL)
    {
        alt_esq = (*no)->esq ? (*no)->esq->alt : -1;
        alt_dir = (*no)->dir ? (*no)->dir->alt : -1;
        (*no)->alt = (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
    }
}

//------------------------------------------------------------------------------
//Preencher as structs
arv_notas_avl *cadastrar_notas(arv_notas_avl **notas, arv_matri_avl *matricula)
{
    strcpy((*notas)->info.cod_dis, matricula->info.cod_dis);

    printf("\nInforme o periodo cursado (Ex: 2024.2): ");
    scanf(" %[^\n]", (*notas)->info.semestre);

    printf("Informe a nota do aluno: ");
    scanf(" %f", &(*notas)->info.nota_final);
    
    return *notas;
}
arv_matri_avl *cadastrar_matricula(arv_matri_avl **no, arv_dis_avl *disciplina)
{
    strcpy((*no)->info.cod_dis, disciplina->info.cod_dis);

    return (*no);
}
arv_dis_avl *cadastrar_disciplina(arv_dis_avl **no, arv_curso_avl *curso)
{
    int i = 0, ch = 0, qtd = curso->info.qtd_periodos;

    printf("\nInforme o nome da disciplina: ");
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
arv_curso_avl *cadastrar_curso(arv_curso_avl **no)
{
    printf("\nInforme o nome do curso: ");
    scanf(" %[^\n]", (*no)->info.nome);
    
    printf("Informe o codigo do curso: ");
    scanf(" %[^\n]", (*no)->info.cod_curso);

    printf("Informe a quantidade de periodos do curso: ");
    scanf(" %d", &(*no)->info.qtd_periodos);

    return (*no);
}
l_aluno *cadastrar_aluno(l_aluno **no, arv_curso_avl *curso)
{
    printf("\nInforme o nome do aluno: ");
    scanf(" %[^\n]", (*no)->info.nome);

    printf("Informe a matricula: ");
    scanf(" %[^\n]", (*no)->info.matricula);

    strcpy((*no)->info.cod_curso, curso->info.cod_curso);

    return (*no);
}
//------------------------------------------------------------------------------

//Inserir nas árvores e lista
int inserir_arv_notas(arv_notas_avl **notas, arv_notas_avl *no)
{
    int inseriu = 1;

    if(*notas == NULL)
        *notas = no;

    else { 
            if(strcmp(no->info.cod_dis, (*notas)->info.cod_dis) > 0)
                inseriu = inserir_arv_notas(&((*notas)->dir), no);

            else if(strcmp(no->info.cod_dis, (*notas)->info.cod_dis) < 0)
                inseriu = inserir_arv_notas(&((*notas)->esq), no);

            else inseriu = 0;
    }

    balanceamento_notas(notas);
    atualizar_altura_notas(notas);

    return inseriu;
}
int inserir_arv_matricula(arv_matri_avl **matricula, arv_matri_avl *no)
{
    int inseriu = 1;

    if (*matricula == NULL)
        *matricula = no;

    else {
            if(strcmp(no->info.cod_dis, (*matricula)->info.cod_dis) < 0)
                inseriu = inserir_arv_matricula(&((*matricula)->esq), no);

            else if (strcmp(no->info.cod_dis, (*matricula)->info.cod_dis) > 0)
                inseriu = inserir_arv_matricula(&((*matricula)->dir), no);
            
            else inseriu = 0;
    }
    
    balanceamento_matricula(matricula);
    atualizar_altura_matricula(matricula);
    
    return inseriu;
}
int inserir_arv_disciplina(arv_dis_avl **disciplina, arv_dis_avl *no)
{
    int inseriu = 1;

    if(*disciplina == NULL) 
        *disciplina = no;

    else {
            if(strcmp(no->info.cod_dis, (*disciplina)->info.cod_dis) < 0)
                inseriu = inserir_arv_disciplina(&((*disciplina)->esq), no);
            
            else if(strcmp(no->info.cod_dis, (*disciplina)->info.cod_dis) > 0)
                inseriu = inserir_arv_disciplina(&((*disciplina)->dir), no);
                
            else inseriu = 0;
    }
        
    balanceamento_disciplina(disciplina);
    atualizar_altura_disciplina(disciplina);           
    return inseriu;
}
int inserir_arv_curso(arv_curso_avl **curso, arv_curso_avl *no)
{
    int inseriu = 1;

    if (*curso == NULL) 
        *curso = no;

    else {
            if (strcmp(no->info.cod_curso, (*curso)->info.cod_curso) < 0) 
                inseriu = inserir_arv_curso(&((*curso)->esq), no);

            else if (strcmp(no->info.cod_curso, (*curso)->info.cod_curso) > 0)
                inseriu = inserir_arv_curso(&((*curso)->dir), no);
            
            else inseriu = 0;
    }

    balanceamento_curso(curso);
    atualizar_altura_curso(curso);      
    
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
void imprimir_nota(arv_notas_avl *no)
{
    printf("\nSemestre: %s | ", no->info.semestre);
    printf("Nota Final: %.1f |", no->info.nota_final);
    printf("Codigo da Disciplina: %s |", no->info.cod_dis);
}
//void imprimir_matricula(arv_matri_avl *no);
void imprimir_disciplina(arv_dis_avl *no)
{
    printf("Codigo: %s | ", no->info.cod_dis);
    printf("Nome: %s | ", no->info.nome);
    printf("Periodo: %d | ", no->info.periodo);
    printf("Carga Horaria: %d ", no->info.carga_hr);
    printf("\n");
}
void imprimir_curso(arv_curso_avl *no)
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
void imprimir_arv_disciplina(arv_dis_avl *raiz)
{
    if (raiz != NULL)
    {
        imprimir_arv_disciplina(raiz->esq);
        imprimir_disciplina(raiz);
        imprimir_arv_disciplina(raiz->dir);
    }   
}
void imprimir_arv_curso(arv_curso_avl *raiz)
{
    if (raiz != NULL)
    {
        imprimir_arv_curso(raiz->esq);
        imprimir_curso(raiz);
        imprimir_arv_curso(raiz->dir);
    }   
}
void imprimir_lista_aluno(l_aluno *no)
{
    if (no != NULL)
    {
        imprimir_aluno(no);
        imprimir_lista_aluno(no->prox);
    } 
}

void imprimir_alunos_disciplina(l_aluno *no, arv_dis_avl *disciplina)
{
    if(no != NULL)
    {
        if(no->info.arv_matricula != NULL && strcmp(no->info.arv_matricula->info.cod_dis, disciplina->info.cod_dis) == 0)
            imprimir_aluno(no);
        
        imprimir_alunos_disciplina(no->prox, disciplina);
    }
}
void imprimir_alunos_curso(arv_curso_avl *curso, l_aluno *no)
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
arv_matri_avl *buscar_matricula(arv_matri_avl *no, char *busca)
{
    arv_matri_avl *novo_no;
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
arv_dis_avl *buscar_disciplina(arv_dis_avl *no, char *busca)
{
    arv_dis_avl *novo_no;
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
arv_curso_avl *buscar_curso(arv_curso_avl *no, char *busca)
{
    arv_curso_avl *novo_no;
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

void buscar_disciplina_periodo(arv_dis_avl *no, int *busca)
{
    if(no != NULL)
    {
        buscar_disciplina_periodo(no->esq, busca);

        if(no->info.periodo == *busca)
            imprimir_disciplina(no);

        buscar_disciplina_periodo(no->dir, busca);
    }
}
void buscar_disciplina_matricula(arv_matri_avl *no, arv_dis_avl *disciplina)
{
    if(no != NULL)
    {
        buscar_disciplina_matricula(no->esq, disciplina);

       arv_dis_avl *dis_encontrada;
       dis_encontrada = buscar_disciplina(disciplina, no->info.cod_dis);

        if (dis_encontrada != NULL)
            imprimir_disciplina(dis_encontrada);
    
        buscar_disciplina_matricula(no->dir, disciplina);
    }
}
void buscar_notas_periodo(arv_notas_avl *no, char *busca)
{
    if(no != NULL)
    {
        buscar_notas_periodo(no->esq, busca);
        
        if(strcmp(busca, no->info.semestre) == 0)
            imprimir_nota(no);

        buscar_notas_periodo(no->dir, busca);
    }
}
void buscar_notas_disciplina(arv_notas_avl *no, arv_dis_avl *disciplina)
{
    if(no != NULL)
    {
        buscar_notas_disciplina(no->esq, disciplina);

        if(strcmp(no->info.cod_dis, disciplina->info.cod_dis) == 0)
        {
            printf("\nNota: %.1f | ", no->info.nota_final);
            printf("Periodo: %d | ", disciplina->info.periodo);
            printf("Carga Horaria: %d ", disciplina->info.carga_hr);
        }

        buscar_notas_disciplina(no->dir, disciplina);
    }
}
int buscar_alunos_matriculados(l_aluno *no, char *disciplina)
{
    int encontrou = 0;
    l_aluno *atual;
    atual = no;

    while(atual != NULL)
    {
        if(atual->info.arv_matricula != NULL)
        {
            if(buscar_matricula(atual->info.arv_matricula, disciplina) != NULL)
                encontrou = 1;

        }

        atual = atual->prox;
    }

    return encontrou;
} 
//------------------------------------------------------------------------------

//Histórico
void vetor_disciplinas(arv_dis_avl *no, char disciplinas[][20], int periodos[], int *contador)
{
    if (no != NULL) 
    {
        vetor_disciplinas(no->esq, disciplinas, periodos, contador);

        strcpy(disciplinas[*contador], no->info.cod_dis);
        periodos[*contador] = no->info.periodo;
        (*contador)++;

        vetor_disciplinas(no->dir, disciplinas, periodos, contador);
    }
}
void preencher_notas(arv_notas_avl *no, char disciplinas[][20], float notas[], int contador)
{
    if (no != NULL) 
    {
        preencher_notas(no->esq, disciplinas, notas, contador);

        for (int i = 0; i < contador; i++) 
        {
            if (strcmp(no->info.cod_dis, disciplinas[i]) == 0) 
            {
                notas[i] = no->info.nota_final;
            }
        }

        preencher_notas(no->dir, disciplinas, notas, contador);
    }
}
void imprimir_disciplina_nota(char *disciplina, float nota)
{
    printf("\nDisciplina: %s | Nota: %.2f", disciplina, nota);
}
void historico_aluno(l_aluno *aluno, arv_curso_avl *curso)
{
    arv_curso_avl *no_curso;
    no_curso = buscar_curso(curso, aluno->info.cod_curso);

    if (no_curso != NULL)
    {    
        imprimir_curso(no_curso);

        char disciplinas[100][20]; 
        int periodos[100]; 
        float notas[100]; 
        int contador = 0;

        vetor_disciplinas(no_curso->info.arv_dis_avl, disciplinas, periodos, &contador);

        // Inicializa o array de notas com um valor padrão (-1.0)
        for (int i = 0; i < contador; i++) 
        {
            notas[i] = -1.0;
        }

        // Preenche o array de notas sem usar break
        preencher_notas(aluno->info.arv_notas_avl, disciplinas, notas, contador);

        // Exibir histórico organizado por período
        for (int p = 1; p <= 12; p++) 
        { 
            for (int i = 0; i < contador; i++) 
            {
                if (periodos[i] == p && notas[i] != -1.0) 
                    imprimir_disciplina_nota(disciplinas[i], notas[i]);
            }
        }
    }
}


//Verificar se o nó é folha
int e_folha_matricula(arv_matri_avl *no)
{
    int verifica = 0;

    if (no->dir == NULL && no->esq == NULL)
        verifica = 1;
        
    return verifica;
}
int e_folha_disciplina(arv_dis_avl *no)
{
    int verifica = 0;

    if (no->dir == NULL && no->esq == NULL)
        verifica = 1;
        
    return verifica;
}
//------------------------------------------------------------------------------

//Verificar se o nó tem um filho
arv_matri_avl *so_um_filho_matricula(arv_matri_avl *no)
{
    arv_matri_avl *aux;

    if(no->dir == NULL && no->esq != NULL)
        aux = no->esq;
    else if(no->dir != NULL && no->esq == NULL)
        aux = no->dir;
    
    return aux;
}
arv_dis_avl *so_um_filho_disciplina(arv_dis_avl *no)
{
    arv_dis_avl *aux;

    if(no->dir == NULL && no->esq != NULL)
        aux = no->esq;
    else if(no->dir != NULL && no->esq == NULL)
        aux = no->dir;
    
    return aux;
}
//------------------------------------------------------------------------------

//Buscar o menor filho
arv_matri_avl *menor_filho_matricula(arv_matri_avl *no)
{
    while (no != NULL && no->esq != NULL)
        no = no->esq;
    
    return no;
}
arv_dis_avl *menor_filho_disciplina(arv_dis_avl *no)
{
    while (no != NULL && no->esq != NULL)
        no = no->esq;
    
    return no;
}
//------------------------------------------------------------------------------

//Remover nós nas árvores e lista
int remover_disciplina_matricula(arv_matri_avl **raiz, arv_dis_avl *no)
{
    int removeu = 1, verificacao;
    arv_matri_avl *aux;
    arv_matri_avl *end_filho, *end_menor_filho;

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
    
    balanceamento_matricula(raiz);
    atualizar_altura_matricula(raiz);           
    }
    else removeu = 0;
    
    return removeu;
}
int remover_disciplina(arv_dis_avl **raiz, arv_dis_avl *no)
{
    int removeu = 1, verificacao;
    arv_dis_avl *aux;
    arv_dis_avl *end_filho, *end_menor_filho;

    if((*raiz) != NULL)
    {
        if(strcmp((*raiz)->info.cod_dis, no->info.cod_dis) == 0)
        {
            verificacao = e_folha_disciplina(*raiz);
            
            if(verificacao == 1)
            {
                aux = *raiz;
                *raiz = NULL;
                free(aux);
            }
            else if ((end_filho = so_um_filho_disciplina(*raiz)) != NULL)
            {
                aux = *raiz;
                *raiz = end_filho;
                free(aux);
            }
                else
                {
                    end_menor_filho = menor_filho_disciplina((*raiz)->dir);
                    aux = *raiz;
                    (*raiz)->info = end_menor_filho->info;
                    removeu = remover_disciplina(&(*raiz)->dir, no);
                } 
        }
        else if(strcmp(no->info.cod_dis, (*raiz)->info.cod_dis) < 0)
                    removeu = remover_disciplina(&((*raiz)->esq), no);        
            else 
                removeu = remover_disciplina(&((*raiz)->dir), no);
    balanceamento_disciplina(raiz);
    atualizar_altura_disciplina(raiz);            
    }
    else removeu = 0;
    
    return removeu;
}
int remover_disciplina_curso(arv_dis_avl **raiz, arv_dis_avl *disciplina, l_aluno *aluno)
{
    int removeu = 1, verificacao;

    verificacao = buscar_alunos_matriculados(aluno, disciplina->info.cod_dis);
    if(verificacao == 0)
        removeu = remover_disciplina(raiz, disciplina);
    
        else removeu = 0;

    return removeu;
}
//------------------------------------------------------------------------------
//Liberar memória
void liberar_arv_notas(arv_notas_avl *raiz) 
{
    if (raiz != NULL) 
    {
        liberar_arv_notas(raiz->esq);
        liberar_arv_notas(raiz->dir);
        free(raiz);
    }
}
void liberar_arv_matricula(arv_matri_avl *raiz) 
{
    if (raiz != NULL) 
    {
        liberar_arv_matricula(raiz->esq);
        liberar_arv_matricula(raiz->dir);
        free(raiz);
    }
}
void liberar_arv_disciplina(arv_dis_avl *raiz) 
{
    if (raiz != NULL) 
    {
        liberar_arv_disciplina(raiz->esq);
        liberar_arv_disciplina(raiz->dir);
        free(raiz);
    }
}
void liberar_arv_curso(arv_curso_avl *raiz) 
{
    if (raiz != NULL) 
    {
        liberar_arv_curso(raiz->esq);
        liberar_arv_curso(raiz->dir);
        liberar_arv_disciplina(raiz->info.arv_dis_avl);
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
        liberar_arv_notas(atual->info.arv_notas_avl);
        free(atual);
        atual = proximo;
    }
}