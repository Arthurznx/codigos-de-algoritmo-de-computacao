#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    setlocale(LC_NUMERIC, "C");

    int opcao_menu;
    char nome[50];
    int qr_code;
    float valor_compra;
    int tem_garantia;
    int i;

    printf("Iniciando o sistema...\n");
    printf("Progresso: [");
    for (i = 1; i <= 20; i++){
        printf("#");
        Sleep(100);
    }
    printf("] 100%%\n\n");
    Sleep(500);
    system("cls");

    do {
        printf("======================================================\n         SISTEMA FERRALOG - INVENTARIO      \n======================================================\n");

        printf("\nBem-vindo ao controle logistico de ferramentas.\n");

        printf("\nSelecione uma opcao no menu abaixo:\n");
        printf("\n[1] Cadastrar nova ferramenta");
        printf("\n[2] Consultar ferramenta por setor");
        printf("\n[3] Verificar status da garantia");
        printf("\n[4] Sair do sistema\n");
        printf("======================================================\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao_menu);

        switch (opcao_menu) {
            case 1:
                printf("sistema log...\n");
                Sleep(2000);
                system("cls");
                Sleep(3000);
                printf("BEM VINDO AO SISTEMA LOG\n");

                printf("qual e o nome da ferramenta: ");
                scanf("%s", nome);

                printf("qual e o seu qr code: ");
                scanf("%d", &qr_code);

                printf("digite o valor da compra: ");
                scanf("%f", &valor_compra);

                printf("a ferramenta possui garantia? (1-Sim / 0-Nao): ");
                scanf("%d", &tem_garantia);

                if (valor_compra > 0) {
                    printf("O nome da ferramenta e %s: \n", nome);
                    printf("seu qrcode e: %d\n", qr_code);
                    printf("seu recibo e: %.2f\n", valor_compra);

                    if (valor_compra > 1000.0 && tem_garantia == 0) {
                        printf("ALERTA DE ALTO RISCO: Ferramenta cara e sem garantia!\n");
                    } else {
                        printf("Risco financeiro normal.\n");
                    }
                } else {
                    printf("Erro, valor invalido!\n");
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

            case 5:
                printf("----- Cadastro em Lote -----\n");
                int qntd_lote = 0;
                int i;

                printf("Quantas ferramentas deseja adicionar neste Lote?\n");
                scanf("%d", &qntd_lote);

                for(i = 1; i <= qntd_lote; i++) {
                    printf("\n Ferramenta %d de %d \n", i, qntd_lote);

                    printf("Nome da ferramenta: \n");
                    scanf("%s", nome);

                    printf("Valor de compra: \n");
                    scanf("%f", &valor_compra);
                    
                    }
                    printf("Registro OK: '%s' cadastrada por R$ %.2f.\n", nome, valor_compra);

                    printf("\n Processamento do lote finalizado. Retornando ao menu... \n");
                    break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao_menu != 4);

    return 0;
}

