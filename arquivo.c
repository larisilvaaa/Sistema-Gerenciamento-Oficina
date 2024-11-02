#include <stdio.h>

int main() {
    FILE *file = fopen("cadastro.txt", "w");  // Abrir o arquivo para modo de escrita
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    
    // 2. Escrever no arquivo
    fprintf(file, "Escrevendo uma linha de texto no arquivo.\n");
    fprintf(file, "Outra linha de exemplo.\n");

    // 3. Fechar o arquivo
    fclose(file);

    printf("Dados escritos no arquivo com sucesso!\n");
   
    return 0;
}
