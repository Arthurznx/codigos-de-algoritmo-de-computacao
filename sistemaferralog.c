#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

#define MAQUINAS 3
#define TURNOS 3

/* Struct da atividade "O Inspetor de Qualidade" */
struct Ferramenta {
    int id;
    char nome[50];
    float peso_gramas;
    int aprovado;   /* 0 = nao auditada, 1 = aprovada, 2 = reprovada */
};

/* Recebe uma COPIA da struct (sem ponteiros), altera a copia e devolve via return */
struct Ferramenta auditar_peso(struct Ferramenta f)
{
    if (f.peso_gramas >= 490.0f && f.peso_gramas <= 510.0f) {
        f.aprovado = 1;
    } else {
        f.aprovado = 2;
    }
    return f;
}

/* Painel de producao: matriz 3x3 (linhas = maquinas, colunas = turnos) */
void painel_producao(void)
{
    // Matriz: 3 Linhas (Maquinas) e 3 Colunas (Turnos)
    int producao[3][3] = {
        {10, 15, 20},  // Maquina 0 (Manha, Tarde, Noite)
        {5,  10, 5},   // Maquina 1 (Manha, Tarde, Noite)
        {20, 20, 30}   // Maquina 2 (Manha, Tarde, Noite)
    };
    int total_pecas = 0;

    const char *turnos[TURNOS] = {"Manha", "Tarde", "Noite"};

    int linha, coluna;
    int total_maquina;

    printf("\n======================================================\n");
    printf("        PAINEL DE PRODUCAO - FERRALOG (3x3)\n");
    printf("======================================================\n\n");

    printf("%-12s", "");
    for (coluna = 0; coluna < TURNOS; coluna++) {
        printf("%-10s", turnos[coluna]);
    }
    printf("%-10s\n", "Subtotal");
    printf("------------------------------------------------------\n");

    /* FOR DUPLO: o laco de fora percorre as maquinas (linhas),
       o de dentro percorre os turnos (colunas) */
    for (linha = 0; linha < MAQUINAS; linha++) {
        total_maquina = 0;
        printf("Maquina %-4d", linha);

        for (coluna = 0; coluna < TURNOS; coluna++) {
            printf("%-10d", producao[linha][coluna]);
            total_maquina += producao[linha][coluna];
            total_pecas += producao[linha][coluna];
        }

        printf("%-10d\n", total_maquina);
    }

    printf("------------------------------------------------------\n");
    printf("TOTAL GERAL DA FABRICA: %d pecas\n", total_pecas);
    printf("======================================================\n");
}

/* Tela inicial: mensagem de abertura + animacao de loading */
void exibir_abertura(void)
{
    int i;

    printf("Iniciando o sistema...\n");
    printf("Progresso: [");
    for (i = 1; i <= 20; i++) {
        printf("#");
        Sleep(100);
    }
    printf("] 100%%\n\n");
    Sleep(500);
    system("cls");
}

/* Mostra o menu, le a opcao digitada e devolve o numero via return */
int exibir_menu(void)
{
    int opcao;

    printf("======================================================\n");
    printf("         SISTEMA FERRALOG - INVENTARIO\n");
    printf("======================================================\n");

    printf("\nBem-vindo ao controle logistico de ferramentas.\n");

    printf("\nSelecione uma opcao no menu abaixo:\n");
    printf("\n[1] Cadastrar nova ferramenta");
    printf("\n[2] Consultar ferramenta por setor");
    printf("\n[3] Verificar status da garantia");
    printf("\n[4] Sair do sistema");
    printf("\n[5] Cadastro em lote");
    printf("\n[6] Painel de producao (Matriz 3x3)");
    printf("\n[7] Inspetor de Qualidade (Martelo M1)\n");
    printf("======================================================\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}

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

    exibir_abertura();

    do {
        opcao_menu = exibir_menu();

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

            case 5: {
                int qntd_lote = 0;

                printf("----- Cadastro em Lote -----\n");
                printf("Quantas ferramentas deseja adicionar neste Lote?\n");
                scanf("%d", &qntd_lote);

                for (i = 1; i <= qntd_lote; i++) {
                    printf("\n Ferramenta %d de %d \n", i, qntd_lote);

                    printf("Nome da ferramenta: \n");
                    scanf("%s", nome);

                    printf("Valor de compra: \n");
                    scanf("%f", &valor_compra);

                    /* Registro dentro do laco: cada ferramenta e confirmada */
                    printf("Registro OK: '%s' cadastrada por R$ %.2f.\n", nome, valor_compra);
                }

                printf("\n Processamento do lote finalizado. Retornando ao menu... \n");
                break;
            }

            case 6:
                painel_producao();
                printf("\nPressione ENTER para voltar ao menu...");
                getchar();   /* consome o ENTER pendente do scanf */
                getchar();   /* espera o ENTER do usuario */
                system("cls");
                break;

            case 7: {
                /* FERRALOG - O Inspetor de Qualidade */
                struct Ferramenta martelo;

                martelo.id = 10;
                strcpy(martelo.nome, "Martelo M1");
                martelo.peso_gramas = 0.0f;
                martelo.aprovado = 0;   /* comeca em 0 (nao auditado) */

                printf("\n----- Inspetor de Qualidade -----\n");
                printf("Ferramenta: %s (id: %d)\n", martelo.nome, martelo.id);
                printf("Digite o peso aferido na balanca (em gramas): ");
                scanf("%f", &martelo.peso_gramas);

                /* O Pulo do Gato: a funcao devolve a copia alterada
                   e ela sobrescreve a variavel original */
                martelo = auditar_peso(martelo);

                if (martelo.aprovado == 1) {
                    printf("\nVeredito: APROVADO (%.1fg dentro da margem de 490g a 510g)\n",
                           martelo.peso_gramas);
                } else {
                    printf("\nVeredito: REPROVADO (%.1fg fora da margem de 490g a 510g)\n",
                           martelo.peso_gramas);
                }

                printf("\nPressione ENTER para voltar ao menu...");
                getchar();   /* consome o ENTER pendente do scanf */
                getchar();   /* espera o ENTER do usuario */
                system("cls");
                break;
            }

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao_menu != 4);

    return 0;
}
