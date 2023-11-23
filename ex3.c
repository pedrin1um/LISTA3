#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[9];
    char dia[15];
    scanf("%s", placa);
    scanf("%s", dia);

    if (!((strlen(placa) == 8 && placa[3] == '-') || (strlen(placa) == 7 && isdigit(placa[3])))) {
        printf("Placa invalida\n");
        return 0;
    }

    // verifica se o dia da semana está no formato correto
    
    char *dias[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    int i, dia_valido = 0;
    for (i = 0; i < 7; i++) {
        if (strcmp(dia, dias[i]) == 0) {
            dia_valido = 1;
            break;
        }
    }
    if (!dia_valido) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    // verifica se a placa pode circular no dia da semana que foi informado
    
    int ultimo_digito = placa[strlen(placa) - 1] - '0';
    if ((i == 0 && (ultimo_digito == 0 || ultimo_digito == 1)) ||
        (i == 1 && (ultimo_digito == 2 || ultimo_digito == 3)) ||
        (i == 2 && (ultimo_digito == 4 || ultimo_digito == 5)) ||
        (i == 3 && (ultimo_digito == 6 || ultimo_digito == 7)) ||
        (i == 4 && (ultimo_digito == 8 || ultimo_digito == 9))) {
        printf("%s nao pode circular %s\n", placa, dia);
    } else if (i < 5) {
        printf("%s pode circular %s\n", placa, dia);
    } else {
        printf("Nao ha proibicao no fim de semana\n");
    }

    return 0;
}
