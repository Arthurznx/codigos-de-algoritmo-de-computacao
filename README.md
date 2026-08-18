# codigos-de-algoritmo-de-computacao
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{   printf("Iniciando o sistema...\n");
    sleep(5);
    system("cls");
    printf("======================================================\n         SISTEMA FERRALOG - INVENTARIO      \n======================================================\n");

    printf("\nBem-vindo ao controle logistico de ferramentas.\n");

    printf("\nSelecione uma opcao no menu abaixo:\n");
    printf("\n[1] Cadastrar nova ferramenta");
    printf("\n[2] Consultar ferramenta por setor");
    printf("\n[3] Verificar status da garantia");
    printf("\n[4] Sair do sistema\n");
    printf("======================================================\n");
    printf("Digite a opcao desejada: \n");
    printf("======================================================\n");
    return 0;
}

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main () {

printf("sistema log.....\n");
sleep(2);
system("cls");
Sleep(3);
printf("BEM VINDO AO SISTEMA LOG\n");


 char nome[50];
 int qr_code;
 float valor_compra;
printf("qual e o nome da ferramneta:");
scanf("%s",&nome);

printf("qual e o seu qr code:");
scanf("%d", &qr_code);

printf("digite e o valor da compra:");
scanf("%f",&valor_compra);

printf("seu nome e %s\n",nome);
printf("seu qrcode e %d\n",qr_code);
printf("seu recibo e %f",valor_compra);
return 0;
}
