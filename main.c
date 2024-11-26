#include <stdio.h>

int nivel_bateria = 100; 
int creditos = 70;       

void imprimiMenu() {
    printf("=== Menu Principal ===\n");
    printf("Aperte 1 para ver nível de bateria\n");
    printf("Aperte 2 para ver mensagens\n");
    printf("Aperte 3 para ver histórico de ligação\n");
    printf("Aperte 4 para realizar ligação\n");
    printf("Aperte 5 para ver agenda\n");
    printf("Aperte 6 para ver créditos\n");
    printf("Aperte 7 para ver operadora\n");
    printf("Aperte 0 para sair\n");
    printf("Escolha uma opção: ");
}
void imprimiBateria() {
    printf("\n--- Nível de Bateria ---\n");
    printf("Nível atual: %d%\n", nivel_bateria);
    printf("Aperte 0 para voltar ao menu inicial.\n");
}
void imprimiMensagens() {
    printf("\n--- Mensagens ---\n");
 printf("1. Nome: João - Telefone: 988112233 - Mensagem: Oi, tudo bem? Vamos nos encontrar hoje?\n");
    printf("2. Nome: Maria - Telefone: 912345678 - Mensagem: Não esqueça da reunião às 14h!\n");
    printf("3. Nome: Pedro - Telefone: 977654321 - Mensagem: Você viu o jogo ontem? Foi incrível!\n");
    printf("4. Nome: Ana - Telefone: 966665555 - Mensagem: Me avisa quando chegar, por favor.\n");
    printf("5. Nome: Carlos - Telefone: 989876543 - Mensagem: Preciso falar com você. Quando pode?\n");
    printf("6. Nome: Julia - Telefone: 901234567 - Mensagem: Vamos ao cinema no fim de semana?\n");
    printf("7. Nome: Lucas - Telefone: 912223344 - Mensagem: Confirme se recebeu o e-mail, por favor.\n");
    printf("8. Nome: Fernanda - Telefone: 934567890 - Mensagem: Parabéns pelo seu aniversário! Muitas felicidades!\n");
    printf("9. Nome: Bruno - Telefone: 911112222 - Mensagem: Já terminou aquele projeto? Preciso dele.\n");
    printf("10. Nome: Laura - Telefone: 933445566 - Mensagem: Pode me ligar mais tarde? Precisamos conversar.\n");
    printf("Envie uma mensagem (gasta 1 crédito).\n");
    printf("Aperte 0 para voltar ao menu inicial.\n");
}

void imprimiLigacao() {
    printf("\n--- Histórico de Ligações ---\n");
    printf("1. Para: Ana - 5 segundos\n");
    printf("2. Para: Pedro - 5 segundos\n");
    printf("Aperte 0 para voltar ao menu inicial.\n");
}
void realizarLigacao() {
    if (creditos >= 2 && nivel_bateria > 0) {
        printf("\nRealizando ligação de 5 segundos...\n");
        
        for (volatile int i = 0; i < 100000000; i++); 
        nivel_bateria -= 1;
        printf("Ligação finalizada! Créditos restantes: %d. Bateria: %d%%\n", creditos, nivel_bateria);
    } else {
        printf("\nCréditos ou bateria insuficientes para realizar a ligação.\n");
    }
    printf("Aperte 0 para voltar ao menu inicial.\n");
}
void imprimiAgenda() {
    printf("\n--- Agenda ---\n");
    printf("1. Nome: João - Telefone: 988112233\n");
    printf("2. Nome: Maria - Telefone: 912345678\n");
    printf("3. Nome: Pedro - Telefone: 977654321\n");
    printf("4. Nome: Ana - Telefone: 966665555\n");
    printf("5. Nome: Carlos - Telefone: 989876543\n");
    printf("6. Nome: Julia - Telefone: 901234567\n");
    printf("7. Nome: Lucas - Telefone: 912223344\n");
    printf("8. Nome: Fernanda - Telefone: 934567890\n");
    printf("9. Nome: Bruno - Telefone: 911112222\n");
    printf("10. Nome: Laura - Telefone: 933445566\n");
}
void imprimiCreditos() {
    printf("\n--- Créditos ---\n");
    printf("Créditos disponíveis: %d\n", creditos);
    printf("Podem ser feitas %d ligação(ões) ou enviadas %d mensagem(ns).\n", creditos / 2, creditos);
    printf("Aperte 0 para voltar ao menu inicial.\n");
}
void imprimiOperadora() {
    printf("\n--- Operadora ---\n");
    printf("Operadora atual: Operadora Tim\n");
    printf("Aperte 0 para voltar ao menu inicial.\n");
}
int main() {
    int opcao = -1;
    int opcao2 = -1;
    while (opcao != 0) {
        imprimiMenu();
        scanf("%d", &opcao);
        if (opcao == 1) {
            imprimiBateria();
            scanf("%d", &opcao2);
        } else if (opcao == 2) {
            imprimiMensagens();
            scanf("%d", &opcao2);
            if (opcao2 != 0 && creditos > 0) {
                printf("Mensagem enviada com sucesso!\n");
                creditos -= 1;
                nivel_bateria -= 1;
            } else if (opcao2 != 0) {
                printf("Créditos insuficientes para enviar mensagem.\n");
            }
        } else if (opcao == 3) {
            imprimiLigacao();
            scanf("%d", &opcao2);
        } else if (opcao == 4) {
            realizarLigacao();
            scanf("%d", &opcao2);
        } else if (opcao == 5) {
            imprimiAgenda();
            scanf("%d", &opcao2);
        } else if (opcao == 6) {
            imprimiCreditos();
            scanf("%d", &opcao2);
        } else if (opcao == 7) {
            imprimiOperadora();
            scanf("%d", &opcao2);
        } else if (opcao == 0) {
            printf("Saindo do sistema...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
        if (nivel_bateria > 0) {
            nivel_bateria -= 1;
        }
        if (nivel_bateria <= 0) {
            printf("\nBateria descarregada. O sistema será encerrado.\n");
            break;
        }
    }
    return 0;
}