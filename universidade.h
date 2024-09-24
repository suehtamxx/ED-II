//Structs
struct aluno
{
    char matricula[7];
    char nome[50];
    char cod_curso[5];
};

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

l_aluno *cadastrar_aluno(arv_curso *curso);
arv_curso *cadastrar_curso(); // criar um nó  na arvore curso
arv_dis *cadastrar_disciplina(arv_curso *curso);
void cadastrar_matricula(arv_matri matricula, struct lista_alunos *l_aluno);
void cadastrar_notas(arv_notas notas, arv_matri matricula, struct lista_alunos *l_aluno);

arv_curso *criar_arv_curso();
arv_dis *criar_arv_dis();
l_aluno * criar_list_aluno();

int inserir_arv_curso(arv_curso **curso, arv_curso *no);
int inserir_arv_dis(arv_dis **disciplina, arv_dis *no);
int inserir_aluno(l_aluno **aluno, l_aluno *no);
