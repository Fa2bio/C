#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTA_1.h" // Bibliotecas criadas para armazenar a estrutura
#include "LISTA_2.h" // e as funções da lista.

///Protótipo das funções utilizadas

//LISTA_1
void carregaArquivo();
void escreveArquivo(lista *aluno, char* tipo);
void insereUm(lista * aluno);
int inserir();
int cadastrado(char nome[35], int k);
int chamada();
void listar();
char *digitarData();
void imprimeLista(lista* alunos);
void listarsituacao();


//LISTA_2
void escreveTodos(lista * alunos);
int buscar(char comp[35]);
int alterar(char comp[35], lista *alunos );
int deletar(char comp[35]);

//Arquivo
FILE* Abre(char caminho[30], char modo);
void Fechar(FILE *Arquivo);

int main(){
char nome[35]; //vetor char de tipo nome com limite de 35 caracteres
char a;

//inicio = ultimo = novo = NULL; // garante q todos os ponteiros seja inicializado como NULL
carregaArquivo();
    do{
        printf("\t\t======================================\n");
        printf("\t\t\|   CHAMADAS DE ALUNOS   |");
        printf("\n\t\t======================================\n\n\n\n");
        printf("\t\t- MENU -\n\n");
        printf("\t<1> - Adicionar Aluno\n");              ///  FUNÇÃO PRINTF
        printf("\t<2> - Iniciar chamada\n");              //imprime no cmd as opções de comando que a pessoa utilizará
        printf("\t<3> - Listar alunos\n");                //para executar o programa.
        printf("\t<4> - Listar situacao\n");
        printf("\t<5> - Pesquisar aluno\n");
        printf("\t<6> - Alterar\n");
        printf("\t<7> - Excluir aluno\n");
        printf("\t<8> - Ajuda");
        printf("\n\t<9> - Encerrar Programa\n\nEscolha uma Opcao: ");
        scanf(" %c", &a); //armazena no endereço de memória, um caracter digitado pelo usuário
        system("cls"); //essa função serve para limpar a tela
        switch(a){ ///Escolhe a variável 'a' e com base nesta escolha, entra nos case's.

            ///Cada case tem seu caso de acordo com a opção digitada no menu. O break, system pause e cls sempre se repetem.
            case '1' :
                if(inserir() == 1) {  //insere um dado, que se for igual a um (verdadeiro), dá um printf confirmando que o aluno
                    printf("\n\n - Aluno cadastrado com sucesso \n\n\n");  //foi cadastrado, senão, aparece a mensagem que nome
                }else {                                               //ou RA do aluno estão em uso
                    printf("\n\n -Nome ou matricula do aluno jah estao em uso.\n\n\n");
                }
                system("pause"); //essa função faz com que apareça na tela "Digite qualquer coisa para continuar"
                system("cls");
            break;
            case '2':
                printf("\t======================================================\n");
              printf("\t|                   LISTA DE CHAMADA                 |\n");
                printf("\t======================================================\n\n\n");
                chamada(); //função que iniciará a chamada, pedindo a situação de cada aluno que possui na lista.
                system("pause");
                system("cls");
            break;
            case '3':
                printf("\t======================================================\n");
              printf("\t|                     ALUNOS                         |\n");
                printf("\t======================================================\n\n\n");
                listar(); //função listar, ao confirmar a opção 3 os nomes dos alunos e seus respectivos RA's aparecem na tela
                system("pause");
                system("cls");
                break;
            case '4':
                listarsituacao(); //mesma função que listar, no entanto exibirá a situação de cada aluno(presente e ausente)
                system("pause");
                system("cls");
                break;
            case '5' :
                printf("Nome do aluno a ser buscado: ");
                fflush(stdin); //limpa o buffer do teclado
                gets(nome); //Função que receberá uma string e armazenará na variável nome.
                printf("\n\n");
                buscar(nome); //Esta função irá comparar se o nome digitado, pertence a lista de alunos. ela recebe um vetor de caracters(string) como parâmetro.
                system("pause");
                system("cls");
                break;
          case '6' :
                printf("Nome do aluno: ");
                fflush(stdin);
                gets(nome);
                alterar(nome, inicio); //função alterar, recebe a string com nome do aluno para ser modificada
                system("pause");
                system("cls");
                break;
            case '7' :
                printf("Nome do aluno que deseja excluir: ");
                fflush(stdin);
                gets(nome);
                if(deletar(nome) == 1){
                    printf("\n\n - Aluno excluido com sucesso. \n\n\n");
                }else{
                    printf("-O aluno nao foi encontrado ou nao esta cadastrado. . \n\n\n");
            }
            system("pause");
            system("cls");
            break;

            case '8':
                printf("\t======================================================\n");
              printf("\t|                      AJUDA                         |\n");
                printf("\t======================================================\n\n\n");
                ajuda();
                system("pause");
                system("cls");
            case '9':
                system("pause");
                exit(0);
            break;
            default:
                printf("\nOpcao Invalida! Tente Novamente!\n\n\n");
                system("pause");
                system("cls");

        }///end switch
    }while(a);///end do
}///end main
