#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    setlocale(LC_NUMERIC, "C");

    int opcao;
    char nome[50];
    int qr_code;
    float valor_compra;
    int tem_garantia;

    printf("Iniciando o sistema...\n");
    Sleep(5000);
    system("cls");
    printf("======================================================\n         SISTEMA FERRALOG - INVENTARIO      \n======================================================\n");

    printf("\nBem-vindo ao controle logístico de ferramentas.\n");

    printf("\nSelecione uma opção no menu abaixo:\n");
    printf("\n[1] Cadastrar nova ferramenta");
    printf("\n[2] Consultar ferramenta por setor");
    printf("\n[3] Verificar status da garantia");
    printf("\n[4] Sair do sistema\n");
    printf("======================================================\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("sistema log...\n");
            Sleep(2000);
            system("cls");
            Sleep(3000);
            printf("BEM VINDO AO SISTEMA LOG\n");

            printf("qual é o nome da ferramenta: ");
            scanf("%s", nome);

            printf("qual é o seu qr code: ");
            scanf("%d", &qr_code);

            printf("digite o valor da compra: ");
            scanf("%f", &valor_compra);

            printf("a ferramenta possui garantia? (1-Sim / 0-Nao): ");
            scanf("%d", &tem_garantia);

            if (valor_compra > 0) {
                printf("\nO nome da ferramenta é: %s \n", nome);
                printf("seu qrcode é: %d\n", qr_code);
                printf("seu recibo é: %.2f\n", valor_compra);

                if (valor_compra > 1000.0 && tem_garantia == 0) {
                    printf("ALERTA DE ALTO RISCO: Ferramenta cara e sem garantia!\n");
                } else {
                    printf("Risco financeiro normal.\n");
                }
            } else {
                printf("Erro, valor inválido!\n");
            }
            break;

        case 2:
            printf("Modulo em desenvolvimento\n");
            break;

        case 3:
            printf("Modulo em desenvolvimento\n");
            break;

        case 4:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
