#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int obterValor(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}
int converterRomanoParaDecimal(char *num) {
    int resultado = 0;
    int i;

    for (i = 0; i < strlen(num); i++) {
        int s1 = obterValor(num[i]);

        if (i + 1 < strlen(num)) {
            int s2 = obterValor(num[i + 1]);

            if (s1 >= s2) {
                resultado = resultado + s1;
            } else {
                resultado = resultado + s2 - s1;
                i++;
            }
        } else {
            resultado = resultado + s1;
            i++;
        }
    }
    return resultado;
}
void imprimirBinario(int n) {
    if (n > 1) {
        imprimirBinario(n / 2);
    }
    printf("%d", n % 2);
}
void imprimirHexadecimal(int n) {
    char *hexaDeciNum = (char *)malloc(sizeof(char) * 100);
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        } else {
            hexaDeciNum[i] = temp + 87;
            i++;
        }
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexaDeciNum[j]);
    }
}
int main() {
    char numeroRomano[1000];
    scanf("%s", numeroRomano);

    int decimal = converterRomanoParaDecimal(numeroRomano);

    printf("%s na base 2: ", numeroRomano);
    imprimirBinario(decimal);
    printf("\n%s na base 10: %d\n", numeroRomano, decimal);
    printf("%s na base 16: ", numeroRomano);
    imprimirHexadecimal(decimal);
    printf("\n");

    return 0;
}
