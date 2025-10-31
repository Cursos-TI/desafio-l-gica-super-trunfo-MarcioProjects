#include <stdio.h>
#include <string.h>

// Definição da struct para representar uma carta
typedef struct {
    char estado[3]; // Ex: "SP"
    char codigo[10]; // Ex: "SP-001"
    char cidade[50]; // Ex: "São Paulo"
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

/**
 * @brief Calcula a densidade populacional e o PIB per capita para uma carta.
 * 
 * @param carta Ponteiro para a carta a ser calculada.
 */
void calcular_atributos_derivados(Carta *carta) {
    // Evita divisão por zero para a densidade populacional
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }
    
    // Evita divisão por zero para o PIB per capita
    if (carta->populacao > 0) {
        carta->pib_per_capita = carta->pib / (float)carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
}

/**
 * @brief Exibe o resultado da comparação entre duas cartas com base em um atributo.
 * 
 * @param atributo_nome Nome do atributo usado na comparação.
 * @param valor1 Valor do atributo na Carta 1.
 * @param valor2 Valor do atributo na Carta 2.
 * @param vencedor_nome Nome da cidade da carta vencedora.
 */
void exibir_resultado(const char *atributo_nome, float valor1, float valor2, const char *vencedor_nome, const char *cidade1_nome, const char *cidade2_nome) {
    printf("\nComparacao de cartas (Atributo: %s):\n", atributo_nome);
    printf("Carta 1 - %s: %.2f\n", cidade1_nome, valor1);
    printf("Carta 2 - %s: %.2f\n", cidade2_nome, valor2);
    printf("Resultado: Carta 1 (%s) venceu!\n", vencedor_nome);
}

int main() {
    // 1. Receber os dados de duas cartas pré-definidas
    Carta carta1 = {
        .estado = "SP",
        .codigo = "SP-001",
        .cidade = "São Paulo",
        .populacao = 12396372,
        .area = 1521.11,
        .pib = 763800000000.0,
        .pontos_turisticos = 20
    };

    Carta carta2 = {
        .estado = "RJ",
        .codigo = "RJ-001",
        .cidade = "Rio de Janeiro",
        .populacao = 6775561,
        .area = 1200.22,
        .pib = 358300000000.0,
        .pontos_turisticos = 30
    };

    // 2. Calcular Densidade Populacional e PIB per capita
    calcular_atributos_derivados(&carta1);
    calcular_atributos_derivados(&carta2);

    printf("--- Dados das Cartas ---\n");
    printf("Carta 1 - %s (%s):\n", carta1.cidade, carta1.estado);
    printf("  Populacao: %d\n", carta1.populacao);
    printf("  Area: %.2f km2\n", carta1.area);
    printf("  Densidade Populacional: %.2f hab/km2\n", carta1.densidade_populacional);
    printf("  PIB: %.2f\n", carta1.pib);
    printf("  PIB Per Capita: %.2f\n", carta1.pib_per_capita);
    printf("  Pontos Turisticos: %d\n\n", carta1.pontos_turisticos);

    printf("Carta 2 - %s (%s):\n", carta2.cidade, carta2.estado);
    printf("  Populacao: %d\n", carta2.populacao);
    printf("  Area: %.2f km2\n", carta2.area);
    printf("  Densidade Populacional: %.2f hab/km2\n", carta2.densidade_populacional);
    printf("  PIB: %.2f\n", carta2.pib);
    printf("  PIB Per Capita: %.2f\n", carta2.pib_per_capita);
    printf("  Pontos Turisticos: %d\n\n", carta2.pontos_turisticos);

    // 3. Comparar um atributo escolhido (PIB) e determinar a carta vencedora
    // Neste caso, a carta com o maior PIB vence.
    printf("--- Comparacao de Atributo ---\n");
    printf("Atributo escolhido para comparacao: PIB\n");
    
    if (carta1.pib > carta2.pib) {
        exibir_resultado("PIB", carta1.pib, carta2.pib, carta1.cidade, carta1.cidade, carta2.cidade);
    } else if (carta2.pib > carta1.pib) {
        exibir_resultado("PIB", carta1.pib, carta2.pib, carta2.cidade, carta1.cidade, carta2.cidade);
    } else {
        printf("\nComparacao de cartas (Atributo: PIB):\n");
        printf("Carta 1 - %s: %.2f\n", carta1.cidade, carta1.pib);
        printf("Carta 2 - %s: %.2f\n", carta2.cidade, carta2.pib);
        printf("Resultado: Empate!\n");
    }

    // Exemplo de comparacao com Densidade Populacional (menor valor vence)
    printf("\n--- Outra comparacao (Densidade Populacional) ---\n");
    
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        exibir_resultado("Densidade Populacional", carta1.densidade_populacional, carta2.densidade_populacional, carta1.cidade, carta1.cidade, carta2.cidade);
    } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
        exibir_resultado("Densidade Populacional", carta1.densidade_populacional, carta2.densidade_populacional, carta2.cidade, carta1.cidade, carta2.cidade);
    } else {
        printf("\nComparacao de cartas (Atributo: Densidade Populacional):\n");
        printf("Carta 1 - %s: %.2f\n", carta1.cidade, carta1.densidade_populacional);
        printf("Carta 2 - %s: %.2f\n", carta2.cidade, carta2.densidade_populacional);
        printf("Resultado: Empate!\n");
    }

    return 0;
}
