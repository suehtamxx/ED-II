#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

//Structs
typedef struct aluno
{
    char matricula[7];
    char nome[50];
    char cod_curso[5];
}Aluno;

typedef struct disciplina
{
    char cod_dis[3];
    char nome[50];
    int periodo;
    int carga_hr;
}Disciplina;

typedef struct notas
{
    char cod_dis[3];
    char semestre[6];
    float nota_final;
}Notas;

typedef struct curso
{
    char cod_curso[5];
    char nome[30];
    int qtd_periodos;
}Curso;

typedef struct matricula
{
    char cod_dis[3];
}Matricula;

//Árvores
typedef struct arvore_disciplina
{
    Disciplina info;
    struct arvore_disciplina *esq, *dir;
}arv_dis;

typedef struct arvore_curso
{
    Curso info;
    arv_dis *dis;
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

//Lista
typedef struct lista_alunos
{
   Aluno info;
   arv_notas *notas;
   arv_matri *matricula;
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
// arv_matri cadastrar_matricula(arv_matri matricula, struct lista_alunos *l_aluno);
// arv_notas cadastrar_notas(arv_notas notas, arv_matri matricula, struct lista_alunos *l_aluno);
l_aluno *cadastrar_aluno(l_aluno **no, arv_curso *curso);

//Inserir nas árvores e lista
int inserir_arv_curso(arv_curso **curso, arv_curso *no);
int inserir_arv_dis(arv_dis **disciplina, arv_dis *no);
int inserir_lista_aluno(l_aluno **aluno, l_aluno *no);

//Imprimir as árvores e lista (in-ordem)
void imprimir_arv_curso(arv_curso *curso);
void imprimir_arv_dis(arv_dis *raiz);
void imprimir_lista_aluno(l_aluno *no);


//Buscar nós nas árvores e lista
int buscar_curso(arv_curso *no, char *busca);
int buscar_disciplina(arv_dis *no, char *busca);
int buscar_aluno(l_aluno *aluno, char *busca);

//Remover nós nas árvores e lista


//Liberar memória


#endif