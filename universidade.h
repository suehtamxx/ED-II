struct Alunos
{
    char matricula[7];
    char nome[50];
    char cod_curso[5];
};

struct Disciplina
{
    char cod_dis[3];
    char nome[50];
    int periodo = 0;
    int carga_hr;
};

struct Notas
{
    char cod_dis[3];
    char semestre[6];
    float nota_final;
};

struct Curso
{
    char cod_curso[5];
    char nome[30];
    int qtd_periodos = 0;
};

struct Matricula
{
    char cod_dis[3];
};

typedef struct arv_dis
{
    struct Disciplina info;
    struct arv_dis *esq, *dir;
};

typedef struct arv_curso
{
    struct Curso info;
    struct arv_curso *esq, *dir;
    struct arv_dis dis;
};

typedef struct arv_notas
{
    struct Notas info;
    struct arv_notas *esq, *dir;
};

typedef struct arv_matri
{
    struct Matricula info;
    struct arv_matri *esq, *dir;
};

typedef struct lista_alunos
{
   struct lista_alunos *prox;
   struct Alunos info;
   struct arv_notas notas;
   struct arv_matri matricula;
};

void cadastrar_aluno(arv_curso curso, lista_alunos *l_aluno);
void cadastrar_curso(arv_curso curso);
void cadastrar_disciplina(arv_curso curso, arv_dis disciplina);
void cadastrar_matricula(arv_matri matricula, lista_alunos *l_aluno);
void cadastrar_notas(arv_notas notas, arv_matri matricula, lista_alunos *l_aluno);