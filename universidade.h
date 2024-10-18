#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

//---------- Definição de structs ----------
//Notas
typedef struct info_notas
{
    char cod_dis[3];
    char semestre[6];
    float nota_final;
}Notas;

typedef struct arvore_notas
{
    Notas info;
    struct arvore_notas *esq, *dir;
}arv_notas;

//Matriculas
typedef struct info_matricula
{
    char cod_dis[3];
}Matricula;

typedef struct arvore_matricula
{
    Matricula info;
    struct arvore_matricula *esq, *dir;
}arv_matri;

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
}arv_dis;

//Curso
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

//Aluno
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

//---------- Definição das Funções ----------
//Criar árvores e lista
arv_notas *criar_arv_notas();
arv_matri *criar_arv_matricula();
arv_dis *criar_arv_dis();
arv_curso *criar_arv_curso();
l_aluno * criar_lista_aluno();

//Criar os nós das árvores e lista
arv_notas *alocar_no_notas();
arv_matri *alocar_no_matricula();
arv_dis *alocar_no_dis();
arv_curso *alocar_no_curso();
l_aluno *alocar_no_aluno();

//Preencher as structs
arv_notas *cadastrar_notas(arv_notas *no, arv_matri matricula);
arv_matri *cadastrar_matricula(arv_matri **no, arv_dis *disciplina);
arv_dis *cadastrar_disciplina(arv_dis **no, arv_curso *curso);
arv_curso *cadastrar_curso(arv_curso **no);
l_aluno *cadastrar_aluno(l_aluno **no, arv_curso *curso);

//Inserir nas árvores e lista
int inserir_arv_notas(arv_notas **notas, arv_notas *no);
int inserir_arv_matricula(arv_matri **matricula, arv_matri *no);
int inserir_arv_dis(arv_dis **disciplina, arv_dis *no);
int inserir_arv_curso(arv_curso **curso, arv_curso *no);
int inserir_lista_aluno(l_aluno **aluno, l_aluno *no);

//Imprimir o nó da árvore e lista
void imprimir_nota(arv_notas *no);
void imprimir_matricula(arv_matri *no);
void imprimir_disciplina(arv_dis *no);
void imprimir_curso(arv_curso *no);
void imprimir_aluno(l_aluno *no);

//Imprimir as árvores e lista (in-ordem)
void imprimir_arv_curso(arv_curso *no);
void imprimir_arv_dis(arv_dis *no);
void imprimir_lista_aluno(l_aluno *no);
void imprimir_alunos_disciplina(l_aluno *no, arv_dis *disciplina);

//Buscar nós nas árvores e lista
arv_matri *buscar_matricula(arv_matri *no, char *busca);
arv_dis *buscar_disciplina(arv_dis *no, char *busca);
arv_curso *buscar_curso(arv_curso *no, char *busca);
l_aluno *buscar_aluno(l_aluno *aluno, char *busca);

void buscar_disciplina_periodo(arv_dis *no, int *busca);
void buscar_disciplina_matricula(arv_matri *no, arv_dis *disciplina);

//Verificar se o nó é folha
int e_folha_matricula(arv_matri *no);

//Verificar se o nó tem um filho
arv_matri *so_um_filho_matricula(arv_matri *no);

//Buscar o menor filho
arv_matri *menor_filho_matricula(arv_matri *no);


//Remover nós nas árvores e lista
int remover_disciplina_matricula(arv_matri **raiz, arv_dis *no);
int remover_disciplina(arv_dis **raiz, arv_dis *no);


//Liberar memória


#endif