#include <stdio.h>

int main() {
  // Declaração das variáveis das Cartas
char estado1, estado2;
char codigo1[4], codigo2[4];
char nomeCidade1[50], nomeCidade2[50];
unsigned long int populacao1, populacao2;
float area1, area2;
float pib1, pib2;
int pontosTuristicos1, pontosTuristicos2;

// Inclusão das variáveis Densidade populacional e PIB per capita
float Dpopulacional1, Dpopulacional2;
float Pibpcap1, Pibpcap2;

int opcao;

 // ---------- Entrada dos dados da Carta 1 ----------
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da carta (ex: A01): ");
    scanf("%3s", codigo1);
    
    printf("Nome da cidade: ");
    scanf("%49s", nomeCidade1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

// Cálculos - Carta 1
   Dpopulacional1 = populacao1/area1;
   Pibpcap1 = (pib1 * 1000000000) / populacao1; // PIB em reais, não bilhões


    // ---------- Entrada dos dados da Carta 2 ----------
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da carta (ex: B03): ");
    scanf("%3s", codigo2);

    printf("Nome da cidade: ");
    scanf("%49s", nomeCidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos - Carta 2
    Dpopulacional2 = populacao2/area2;
    Pibpcap2 = (pib2 * 1000000000) / populacao2;


 //      Exibição dos dados da cidade
 printf("\n--------- FICHA DA CARTA 1 ---------\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", Dpopulacional1);
    printf("PIB per Capita: %.2f reais\n", Pibpcap1);

    printf("\n--------- FICHA DA CARTA 2 ---------\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", Dpopulacional2);
    printf("PIB per Capita: %.2f reais\n", Pibpcap2);


     // ----------- MENU INTERATIVO PARA ESCOLHER ATRIBUTO -----------
    printf("\n====== MENU DE COMPARAÇÃO ======\n");
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n\n");

    switch (opcao) {

        case 1: // População
            printf("Atributo escolhido: População\n");
            printf("%s: %lu habitantes\n", nomeCidade1, populacao1);
            printf("%s: %lu habitantes\n", nomeCidade2, populacao2);

            if (populacao1 > populacao2)
                printf("Vencedora: Carta 1 (%s)\n", nomeCidade1);
            else if (populacao2 > populacao1)
                printf("Vencedora: Carta 2 (%s)\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("Atributo escolhido: Área\n");
            printf("%s: %.2f km²\n", nomeCidade1, area1);
            printf("%s: %.2f km²\n", nomeCidade2, area2);

            if (area1 > area2)
                printf("Vencedora: Carta 1 (%s)\n", nomeCidade1);
            else if (area2 > area1)
                printf("Vencedora: Carta 2 (%s)\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo escolhido: PIB\n");
            printf("%s: %.2f bilhões\n", nomeCidade1, pib1);
            printf("%s: %.2f bilhões\n", nomeCidade2, pib2);

            if (pib1 > pib2)
                printf("Vencedora: Carta 1 (%s)\n", nomeCidade1);
            else if (pib2 > pib1)
                printf("Vencedora: Carta 2 (%s)\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos Turísticos
            printf("Atributo escolhido: Pontos Turísticos\n");
            printf("%s: %d pontos\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d pontos\n", nomeCidade2, pontosTuristicos2);

            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Vencedora: Carta 1 (%s)\n", nomeCidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Vencedora: Carta 2 (%s)\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade - MENOR vence!
            printf("Atributo escolhido: Densidade Demográfica (menor vence)\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, Dpopulacional1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, Dpopulacional2);

            if (Dpopulacional1 < Dpopulacional2)
                printf("Vencedora: Carta 1 (%s)\n", nomeCidade1);
            else if (Dpopulacional2 < Dpopulacional1)
                printf("Vencedora: Carta 2 (%s)\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 6: // PIB per capita
            printf("Atributo escolhido: PIB per Capita\n");
            printf("%s: %.2f reais\n", nomeCidade1, Pibpcap1);
            printf("%s: %.2f reais\n", nomeCidade2, Pibpcap2);

            if (Pibpcap1 > Pibpcap2)
                printf("Vencedora: Carta 1 (%s)\n", nomeCidade1);
            else if (Pibpcap2 > Pibpcap1)
                printf("Vencedora: Carta 2 (%s)\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }
return 0;
}
