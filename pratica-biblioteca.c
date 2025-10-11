#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Constantes globais
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100

struct Livro
{
  char nome[TAM_STRING];
  char autor[TAM_STRING];
  char editora[TAM_STRING];
  int edicao;
  int disponivel;
};

struct Emprestimo {
  int indiceLivro;
  char nomeUsuario[TAM_STRING];
};


void limparBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main (){
  struct Livro *biblioteca;
  struct Emprestimo *emprestimos;

  biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

  emprestimos = (struct Emprestimo *) calloc(MAX_EMPRESTIMOS, sizeof(struct Emprestimo));

  if (biblioteca == NULL || emprestimos == NULL){
    printf("Erro: Falha ao alocar memoria.\n");
    return 1;
  }

  int totalLivros = 0;
  int totalEmprestimos = 0;
  int opcao;

  do
  {
    /* Menu */
    printf("====================================\n");
    printf("    BIBLIOTECA - CADASTRO DE LIVROS\n");
    printf("====================================\n");
    printf("1 - Cadastrar novo livro\n");
    printf("2 - Listar Livros\n");
    printf("3 - Realizar emprestimos\n");
    printf("4 - Listar emprestimos\n");
    printf("0 - Sair\n");
    printf("------------------------------------\n");
    printf("Escolha sua opcao\n");
    scanf("%d", &opcao);
    limparBuffer();

    switch (opcao){
      case 1:
        printf("--- Cadastro de Novo Livro ---\n\n");

        if (totalLivros < MAX_LIVROS){
          printf("Digite o nome do livro: ");
          fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

          printf("Digite o autor: ");
          fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

          printf("digite a editora: ");
          fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

          biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
          biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
          biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

          printf("Digite a edicao: ");
          scanf("%d", &biblioteca[totalLivros].edicao);
          limparBuffer();
          //Torna o livro disponivel
          biblioteca[totalLivros].disponivel = 1;

          totalLivros++;
          printf("\nLivro cadastrado com sucesso!\n");
        } else {
          printf("Biblioteca cheia\n");
        }
      break;
      case 2:
        printf("--- Lista de Livros Cadastrados ---\n");
        if (totalLivros == 0){
        printf("Nenhum livro cadastrado\n");
        } else {
        for (int i = 0; i < totalLivros; i++){
          printf("-----------------------------------\n");
          printf("LIVRO %d \n", i + 1);
          printf("Nome: %s\n", biblioteca[i].nome);
          printf("Autor: %s\n", biblioteca[i].autor);
          printf("Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Emprestado");
        }
        printf("-------------------------------------------\n");
        }
        printf("\nPressione Enter para continuar...");
        getchar();
      break;

      case 3:
        printf("--- Realizar emprestimoo ---\n\n");
        
        if (totalEmprestimos >= MAX_EMPRESTIMOS){
          printf("Limite de empestimos atingidos\n");
        } else {
          printf("Livros disponveis:\n");
          int disponiveis = 0;
          for (int i = 0; i < totalLivros; i++){
            if (biblioteca[i].disponivel){
              printf("%d - %s\n", i + 1, biblioteca[i].nome);
              disponiveis++;
            }
          }
          
          if (disponiveis == 0){
            printf("Nenhum livro disponivel para emprestimo.\n");
          } else {
            printf("\nDigite o numero do livro que deseja emprestar:  ");
            int numLivro;
            scanf("%d", &numLivro);
            limparBuffer();

            int indice = numLivro - 1;
            
            //valida a escolha do usuario
            if (indice >= 0 && indice < totalLivros &&  biblioteca[indice].disponivel){
            printf("Digite o nome do usuario que esta pegando o livro: ");
            fgets(emprestimos[totalEmprestimos].nomeUsuario,  TAM_STRING, stdin);
            emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")];
            
            //Registra o emprestimo 
            emprestimos[totalEmprestimos].indiceLivro =   indice;
            
            //Atualiza o status do livro para indisponivel
            biblioteca[indice].disponivel = 0;

            totalEmprestimos++;
            printf("\nEmprestimo realizado com sucesso\n");
            } else {
              printf("\nNumero de livro indisponivel\n");
            }
          }
        }
        printf("\nPressione Enter para comtinuar...");
        getchar();
      break;

      case 4:
        printf("--- Listar Emprestimos ---\n\n");
        if (totalEmprestimos == 0){
          printf("Nenhum emprestimo realizado\n");
        } else {
          for (int i = 0; i < totalEmprestimos; i++){
            //Usa o indice armazenado no emprestimo para buscar o nome do livro
            int indiceLivro = emprestimos[i].indiceLivro;
            printf("EMPRESTIMO %d", i + 1);
            printf("Livros: %s\n", biblioteca[indiceLivro].nome);
            printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
          }
          printf("-----------------------------------\n");
        }
        printf("\nPressione Enter para continuar...");
        getchar();
      break;
      case 0:
      printf("\nSaindo do sistema...\n");
      break;

      default:
        printf("\nOpcao invalida\n");
        printf("\nPressione Enter para continuar...");
        getchar();
      break;
    }  
  } while (opcao != 0);

  free(biblioteca);
  free(emprestimos);

  printf("Memoria liberada com sucesso\n");

  return 0;
}