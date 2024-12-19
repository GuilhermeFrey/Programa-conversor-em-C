#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void convesao_comprimento();
// void convesao_massa();
// void convesao_volume();
// void convesao_temperatura();
// void convesao_velocidade();
// void convesao_energia();
// void convesao_area();
// void convesao_tempo();
// void convesao_ArmDados();

int main()
{
  setlocale(LC_ALL, "Portuguese");
  int loop = 1;

  while (loop != 0)
  {
    printf("\nUnidade de Conversão\n");
    printf("1. Comprimento\n");
    printf("2. Massa\n");
    printf("3. Volume\n");
    printf("4. Temperatura\n");
    printf("5. Velocidade\n");
    printf("6. Potência\n");
    printf("7. Área\n");
    printf("8. Tempo\n");
    printf("9. Dados\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &loop);

    switch (loop)
    {
       case 1:
        convesao_comprimento();
       break;
      // case 2:
      //   convesao_massa();
      //   break;
      // case 3:
      //   convesao_volume();
      //   break;
      // case 4:
      //   convesao_temperatura();
      //   break;
      // case 5:
      //   convesao_velocidade();
      //   break;
      // case 6:
      //   convesao_energia();
      //   break;
      // case 7:
      //   convesao_area();
      //   break;
      // case 8:
      //   convesao_tempo();
      //   break;
      // case 9:
      //   convesao_ArmDados();
      //   break;
    case 0:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  }
  return 0;
}

void convesao_comprimento() {
    // Declaração de variáveis
    double valor, resultado;
    int origem, destino;

    // Fatores de conversão para metros
    double fatores_para_metros[] = {1000,1.0, 0.01, 0.001, 0.0254, 1609.34, 0.3048, 0.9144};
    char unidades[][15] = {"km","metros", "centimetros","milimetros", "polegadas", "milhas", "pes", "jardas"};
    int total_unidades = sizeof(fatores_para_metros) / sizeof(fatores_para_metros[0]);

    // Exibe as unidades disponíveis
    printf("\nUnidades disponíveis:\n");
    for (int i = 0; i < total_unidades; i++) {
        printf("%d. %s\n", i + 1, unidades[i]);
    }

    // Solicita o valor e as unidades de origem e destino
    printf("Escolha o número da unidade de origem: ");
    scanf("%d", &origem);

    printf("Escolha o número da unidade de destino: ");
    scanf("%d", &destino);

        printf("\nDigite o valor a ser convertido: ");
    scanf("%lf", &valor);

    // Verifica se as opções de origem e destino são válidas
    if (origem < 1 || origem > total_unidades || destino < 1 || destino > total_unidades) {
        printf("Opção inválida. Tente novamente.\n");
        return;
    }

    // Converte o valor para metros e depois para a unidade de destino
    double valor_em_metros = valor * fatores_para_metros[origem - 1];
    resultado = valor_em_metros / fatores_para_metros[destino - 1];

    // Exibe o resultado da conversão
    printf("\n%.4f %s é igual a %.4f %s\n", valor, unidades[origem - 1], resultado, unidades[destino - 1]);
}