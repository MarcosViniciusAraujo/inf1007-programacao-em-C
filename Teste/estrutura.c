typedef struct data
{
     int dia;
     int mes;
     int ano;

} Data;

typedef struct Funcionario
{
     char nome[80];
     int idade;
     char sexo;
     char cpf[12];
     Data nascimento;
     int setor;
     float salario;
     char cargo[31];

} Funcionario;

int main()
{
     Funcionario f;

     printf("Nome: ");
     scanf("%s", &f.nome);

     printf("Idade: ");
     scanf("%d", &f.idade);

     printf("Sexo: ");
     scanf("%s", &f.sexo);

     printf("CPF: ");
     scanf("%s", &f.cpf);

     printf("data de nascimento: ");
     scanf("%d %d %d", &f.nascimento.dia, &f.nascimento.mes, &f.nascimento.ano);

     printf("Setor: ");
     scanf("%d", &f.setor);

     printf("Cargo: ");
     scanf("%s", &f.cargo);

     printf("Salario: ");
     scanf("%.2f", &f.salario);


     return 0;
}