#include <stdio.h>
#include <locale.h>
#include <string.h>

void cadastro(char y[1][100], const char *arquivo) {
    fflush(stdin);
    int i;
    int arroba = 0;
	int ponto = 0;
    printf("\nDigite seu e-mail: ");
    gets(y[0]);
    
    for (i = 0; y[0][i] != '\0'; i++) {
        if (y[0][i] == '@') {
            arroba = 1; // A string contém o caractere
        }
        else {
        	if (y[0][i] == '.') {
        		ponto = 1;
			}
		}
    }
    
    if (arroba && ponto){
    	FILE *file = fopen(arquivo, "a"); 

    	if (file == NULL) {
        	printf("Não foi possível abrir o arquivo.\n");
        	return;
    	}

    	fprintf(file, "Adicionado o e-mail: %s\n", y[0]); 
    	fclose(file);
	}
	else {
		printf("E-mail inválido!");
		system("pause");
		return 0;
	}

    
}

void deletar(char y[1][100], const char *arquivo) {
    
    FILE *file = fopen(arquivo, "a"); 

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    fprintf(file, "Deletado o e-mail: %s\n", y[0]); 
    fclose(file);
    y[0][0] = '\0'; 
}

void visualizar(char x[1][100], const char *arquivo) {
    printf("Nome: %s \n", x[0]);
    FILE *file = fopen(arquivo, "a"); 

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    fprintf(file, "Opção selecionada: Visualizar\n");
    fprintf(file, "Resultado: %s\n", x[0]);

    fclose(file);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;
    char texto[1000] = ""; 

    arquivo = fopen("exemplo.txt", "a"); 

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "%s\n", texto);
    fclose(arquivo);

    printf("Dados escritos no arquivo com sucesso.\n");

    int op;
    char nome[1][100];

    do {
        system("cls");
        printf("****** Menu *******\n");
        printf("0 - Sair \n");
        printf("1 - Cadastrar um nome \n");
        printf("2 - Deletar o nome \n");
        printf("3 - Exibir todos os nomes \n");

        printf("\nEntre com a opção desejada: ");
        scanf("%d", &op);

        switch (op) {
            case 0:
                printf("\nFim do programa!!");
                break;
            case 1:
                cadastro(nome, "exemplo.txt");
                break;
            case 2:
                deletar(nome, "exemplo.txt");
                system("pause");
                break;
            case 3:
                visualizar(nome, "exemplo.txt");
                system("pause");
                break;
            default:
                printf("\nOpção inválida!\n");
                system("pause");
        }
    } while (op != 0);

    return 0;
}

