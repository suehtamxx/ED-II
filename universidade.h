#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

//Structs
typedef struct info_disciplina
{
    char nome[100];
    char cod_dis[3];
    int periodo;
    int carga_hr;
}Disciplina;

typedef struct info_notas
{
    char cod_dis[3];
    char semestre[6];
    float nota_final;
}Notas;

typedef struct info_matricula
{
    char cod_dis[3];
}Matricula;

typedef struct arvore_disciplina
{
    Disciplina info;
    struct arvore_disciplina *esq, *dir;
}arv_dis;

typedef struct info_curso
{
    char nome[40];
    char cod_curso[5];
    int qtd_periodos;
    arv_dis *dis;
}Curso;

typedef struct arvore_curso
{
    Curso info;
    struct arvore_curso *esq, *dir;
}arv_curso;

typedef struct arvore_notas
{
    Notas info;
    struct arvore_notas *esq, *dir;
}arv_notas;

typedef struct arvore_matricula
{
    Matricula info;
    struct arvore_matricula *esq, *dir;
}arv_matri;

typedef struct info_aluno
{
    char nome[50];
    char matricula[7];
    char cod_curso[5];
    arv_matri *arv_matricula;
    arv_notas *arv_notas;
}Aluno;

typedef struct lista_alunos
{
   Aluno info;
   struct lista_alunos *prox;
}l_aluno;

//Criar árvores e lista
arv_curso *criar_arv_curso();
arv_dis *criar_arv_dis();
arv_matri *criar_arv_matricula();
arv_notas *criar_arv_notas();
l_aluno * criar_lista_aluno();

//Criar os nós das árvores e lista
arv_curso *alocar_no_curso();
arv_dis *alocar_no_dis();
arv_matri *alocar_no_matricula();
arv_notas *alocar_no_notas();
l_aluno *alocar_no_aluno();

//Preencher as structs
arv_curso *cadastrar_curso(arv_curso **no);
arv_dis *cadastrar_disciplina(arv_dis **no, arv_curso *curso);
arv_matri *cadastrar_matricula(arv_matri **no, arv_dis *disciplina);
arv_notas *cadastrar_notas(arv_notas **notas, arv_matri matricula);
l_aluno *cadastrar_aluno(l_aluno **no, arv_curso *curso);

//Inserir nas árvores e lista
int inserir_arv_curso(arv_curso **curso, arv_curso *no);
int inserir_arv_dis(arv_dis **disciplina, arv_dis *no);
int inserir_lista_aluno(l_aluno **aluno, l_aluno *no);

//Imprimir as árvores e lista (in-ordem)
void imprimir_arv_curso(arv_curso *curso);
void imprimir_arv_dis(arv_dis *raiz);
void imprimir_lista_aluno(l_aluno *no);
void imprimir_alunos_disciplina(l_aluno *no, arv_dis *disciplina);
void imprimir_disciplina(arv_dis *no);

//Buscar nós nas árvores e lista
arv_curso *buscar_curso(arv_curso *no, char *busca);
arv_dis *buscar_disciplina(arv_dis *no, char *busca);
l_aluno *buscar_aluno(l_aluno *aluno, char *busca);
void buscar_disciplina_periodo(arv_dis *no, int *busca);
arv_matri *buscar_disciplina_matricula(arv_matri *no, arv_dis *disciplina);
arv_matri *buscar_matricula(arv_matri *no, char *busca);

//Remover nós nas árvores e lista
int e_folha_matricula(arv_matri *no);
arv_matri *so_um_filho_matricula(arv_matri *no);
arv_matri *menor_filho_matricula(arv_matri *no);
int remover_disciplina_matricula(arv_matri **raiz, arv_dis *no);
int remover_disciplina(arv_dis **raiz, arv_dis *no);


//Liberar memória


#endif