#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H
//oi
//---------- Definição de structs ----------
//Notas
typedef struct info_notas
{
    char cod_dis[3];
    char semestre[10];
    float nota_final;
}Notas;

typedef struct arvore_notas
{
    Notas info;
    struct arvore_notas *esq, *dir;
    int alt;
}arv_notas_avl;

//Matriculas
typedef struct info_matricula
{
    char cod_dis[3];
}Matricula;

typedef struct arvore_matricula
{
    Matricula info;
    struct arvore_matricula *esq, *dir;
    int alt;
}arv_matri_avl;

//Disciplinas
typedef struct info_disciplina
{
    char nome[100];
    char cod_dis[3];
    int periodo;
    int carga_hr;
}Disciplina;

typedef struct arvore_disciplina
{
    Disciplina info;
    struct arvore_disciplina *esq, *dir;
    int alt;
}arv_dis_avl;

//Curso
typedef struct info_curso
{
    char nome[40];
    char cod_curso[5];
    int qtd_periodos;
    arv_dis_avl *arv_dis_avl;
}Curso;

typedef struct arvore_curso
{
    Curso info;
    struct arvore_curso *esq, *dir;
    int alt;
}arv_curso_avl;

//Aluno
typedef struct info_aluno
{
    char nome[50];
    char matricula[10];
    char cod_curso[5];
    arv_matri_avl *arv_matricula;
    arv_notas_avl *arv_notas_avl;
}Aluno;

typedef struct lista_alunos
{
   Aluno info;
   struct lista_alunos *prox;
}l_aluno;

//---------- Definição das Funções ----------
//Criar árvores e lista
arv_notas_avl *criar_arv_notas();
arv_matri_avl *criar_arv_matricula();
arv_dis_avl *criar_arv_disciplina();
arv_curso_avl *criar_arv_curso();
l_aluno * criar_lista_aluno();

//Criar os nós das árvores e lista
arv_notas_avl *alocar_no_notas();
arv_matri_avl *alocar_no_matricula();
arv_dis_avl *alocar_no_disciplina();
arv_curso_avl *alocar_no_curso();
l_aluno *alocar_no_aluno();

//balanceamento
int fator_balanceamento_notas(arv_notas_avl **no);
int fator_balanceamento_matricula(arv_matri_avl **no);
int fator_balanceamento_disciplina(arv_dis_avl **no);
int fator_balanceamento_curso(arv_curso_avl **no);

void rotacao_esquerda_notas(arv_notas_avl **no);
void rotacao_esquerda_matricula(arv_matri_avl **no);
void rotacao_esquerda_disciplina(arv_dis_avl **no);
void rotacao_esquerda_curso(arv_curso_avl **no);

void rotacao_direita_notas(arv_notas_avl **no);
void rotacao_direita_matricula(arv_matri_avl **no);
void rotacao_direita_disciplina(arv_dis_avl **no);
void rotacao_direita_curso(arv_curso_avl **no);

void balanceamento_notas(arv_notas_avl **no);
void balanceamento_matricula(arv_matri_avl **no);
void balanceamento_disciplina(arv_dis_avl **no);
void balanceamento_curso(arv_curso_avl **no);

void atualizar_altura_notas(arv_notas_avl **no);
void atualizar_altura_matricula(arv_matri_avl **no);
void atualizar_altura_disciplina(arv_dis_avl **no);
void atualizar_altura_curso(arv_curso_avl **no);

//Preencher as structs
arv_notas_avl *cadastrar_notas(arv_notas_avl **no, arv_matri_avl *matricula);
arv_matri_avl *cadastrar_matricula(arv_matri_avl **no, arv_dis_avl *disciplina);
arv_dis_avl *cadastrar_disciplina(arv_dis_avl **no, arv_curso_avl *curso);
arv_curso_avl *cadastrar_curso(arv_curso_avl **no);
l_aluno *cadastrar_aluno(l_aluno **no, arv_curso_avl *curso);

//Inserir nas árvores e lista
int inserir_arv_notas(arv_notas_avl **notas, arv_notas_avl *no);
int inserir_arv_matricula(arv_matri_avl **matricula, arv_matri_avl *no);
int inserir_arv_disciplina(arv_dis_avl **disciplina, arv_dis_avl *no);
int inserir_arv_curso(arv_curso_avl **curso, arv_curso_avl *no);
int inserir_lista_aluno(l_aluno **aluno, l_aluno *no);
//int inserir_nota(arv_notas_avl **notas, arv_notas_avl *no);
int inserir_arv_matricula(arv_matri_avl **matricula, arv_matri_avl *no);

//Imprimir o nó da árvore e lista
void imprimir_nota(arv_notas_avl *no);
//void imprimir_matricula(arv_matri_avl *no);
void imprimir_disciplina(arv_dis_avl *no);
void imprimir_curso(arv_curso_avl *no);
void imprimir_aluno(l_aluno *no);

//Imprimir as árvores e lista (in-ordem)
void imprimir_arv_disciplina(arv_dis_avl *no);
void imprimir_arv_curso(arv_curso_avl *no);
void imprimir_lista_aluno(l_aluno *no);

void imprimir_alunos_disciplina(l_aluno *no, arv_dis_avl *disciplina);
void imprimir_alunos_curso(arv_curso_avl *curso, l_aluno *no);

//Buscar nós nas árvores e lista
arv_matri_avl *buscar_matricula(arv_matri_avl *no, char *busca);
arv_dis_avl *buscar_disciplina(arv_dis_avl *no, char *busca);
arv_curso_avl *buscar_curso(arv_curso_avl *no, char *busca);
l_aluno *buscar_aluno(l_aluno *aluno, char *busca);

void buscar_disciplina_periodo(arv_dis_avl *no, int *busca);
void buscar_disciplina_matricula(arv_matri_avl *no, arv_dis_avl *disciplina);
void buscar_notas_periodo(arv_notas_avl *no, char *busca);
void buscar_notas_disciplina(arv_notas_avl *no, arv_dis_avl *disciplina);
int buscar_alunos_matriculados(l_aluno *no, char *disciplina);

//Histórico
void vetor_disciplinas(arv_dis_avl *no, char disciplinas[][20], int periodos[], int *contador);
void preencher_notas(arv_notas_avl *no, char disciplinas[][20], float notas[], int contador);
void imprimir_disciplina_nota(char *disciplina, float nota);
void historico_aluno(l_aluno *aluno, arv_curso_avl *curso);

//Verificar se o nó é folha
int e_folha_matricula(arv_matri_avl *no);
int e_folha_disciplina(arv_dis_avl *no);

//Verificar se o nó tem um filho
arv_matri_avl *so_um_filho_matricula(arv_matri_avl *no);
arv_dis_avl *so_um_filho_disciplina(arv_dis_avl *no);

//Buscar o menor filho
arv_matri_avl *menor_filho_matricula(arv_matri_avl *no);
arv_dis_avl *menor_filho_disciplina(arv_dis_avl *no);

//Remover nós nas árvores e lista
int remover_disciplina_matricula(arv_matri_avl **raiz, arv_dis_avl *no);
int remover_disciplina(arv_dis_avl **raiz, arv_dis_avl *no);
int remover_disciplina_curso(arv_dis_avl **raiz, arv_dis_avl *disciplina, l_aluno *aluno);

//Liberar memória
void liberar_arv_notas(arv_notas_avl *raiz);
void liberar_arv_matricula(arv_matri_avl *raiz);
void liberar_arv_disciplina(arv_dis_avl *raiz);
void liberar_arv_curso(arv_curso_avl *raiz);
void liberar_lista_alunos(l_aluno *cabeca);

#endif