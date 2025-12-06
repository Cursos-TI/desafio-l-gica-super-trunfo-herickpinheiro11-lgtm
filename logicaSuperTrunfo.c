#include <stdio.h>

// ------------------ FUNÇÃO AUXILIAR ------------------
char* nomeAtributo(int x) {
    switch(x) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
    }
    return "";
}

// ------------------------- MAIN -------------------------
int main() {

    int op1, op2;

    // Cartas pré-definidas no código
    char nomeCidade1[20] = "Brasil";
    int populacao1 = 214000000;
    float area1 = 8516000;
    float pib1 = 1.9; // trilhões
    int pontosTuristicos1 = 10;
    float Dpopulacional1 = populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000000) / populacao1;

    char nomeCidade2[20] = "Argentina";
    int populacao2 = 46000000;
    float area2 = 2780000;
    float pib2 = 0.5; // trilhões
    int pontosTuristicos2 = 5;
    float Dpopulacional2 = populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000000) / populacao2;

    // -------- MENU 1 --------
    printf("\n====== Escolha o PRIMEIRO atributo ======\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &op1);

    if (op1 < 1 || op1 > 6) {
        printf("Opção inválida!\n");
        return 0;
    }

    // -------- MENU 2 (DINÂMICO) --------
    printf("\n====== Escolha o SEGUNDO atributo ======\n");

    for (int i = 1; i <= 6; i++) {
        if (i == op1) continue;

        printf("%d - %s\n", i, nomeAtributo(i));
    }

    printf("Opção: ");
    scanf("%d", &op2);

    if (op2 == op1 || op2 < 1 || op2 > 6) {
        printf("Opção inválida!\n");
        return 0;
    }

    // -------- Resgate dos valores --------
    float v1a1 = 0, v1a2 = 0, v2a1 = 0, v2a2 = 0;

    // atributo 1
    switch (op1) {
        case 1: v1a1 = populacao1; v1a2 = populacao2; break;
        case 2: v1a1 = area1; v1a2 = area2; break;
        case 3: v1a1 = pib1; v1a2 = pib2; break;
        case 4: v1a1 = pontosTuristicos1; v1a2 = pontosTuristicos2; break;
        case 5: v1a1 = Dpopulacional1; v1a2 = Dpopulacional2; break;
        case 6: v1a1 = pibPerCapita1; v1a2 = pibPerCapita2; break;
    }

    // atributo 2
    switch (op2) {
        case 1: v2a1 = populacao1; v2a2 = populacao2; break;
        case 2: v2a1 = area1; v2a2 = area2; break;
        case 3: v2a1 = pib1; v2a2 = pib2; break;
        case 4: v2a1 = pontosTuristicos1; v2a2 = pontosTuristicos2; break;
        case 5: v2a1 = Dpopulacional1; v2a2 = Dpopulacional2; break;
        case 6: v2a1 = pibPerCapita1; v2a2 = pibPerCapita2; break;
    }

    // -------- Comparação --------
    int ganho1 = 0, ganho2 = 0;

    // atributo 1
    if (op1 == 5) { // densidade -> menor vence
        if (v1a1 < v1a2) ganho1++;
        else if (v1a2 < v1a1) ganho2++;
    } else {
        if (v1a1 > v1a2) ganho1++;
        else if (v1a2 > v1a1) ganho2++;
    }

    // atributo 2
    if (op2 == 5) {
        if (v2a1 < v2a2) ganho1++;
        else if (v2a2 < v2a1) ganho2++;
    } else {
        if (v2a1 > v2a2) ganho1++;
        else if (v2a2 > v2a1) ganho2++;
    }

    // somas finais
    float soma1 = v1a1 + v2a1;
    float soma2 = v1a2 + v2a2;

    // -------- Exibição --------
    printf("\n=========== RESULTADO ===========\n");
    printf("Comparando %s x %s\n\n", nomeCidade1, nomeCidade2);

    printf("%s:\n  %s → %.2f\n  %s → %.2f\n\n",
           nomeAtributo(op1), nomeCidade1, v1a1, nomeCidade2, v1a2);

    printf("%s:\n  %s → %.2f\n  %s → %.2f\n\n",
           nomeAtributo(op2), nomeCidade1, v2a1, nomeCidade2, v2a2);

    printf("Soma dos atributos:\n  %s: %.2f\n  %s: %.2f\n\n",
           nomeCidade1, soma1, nomeCidade2, soma2);

    printf("Resultado final: ");
    if (soma1 > soma2) printf("%s venceu!\n", nomeCidade1);
    else if (soma2 > soma1) printf("%s venceu!\n", nomeCidade2);
    else printf("Empate!\n");

    printf("=================================\n");

    return 0;
}
