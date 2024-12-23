/*
Nome dos integrantes:
Ana Luiza de Freitas Rodrigues
Júlia de Souza Ventura
Yuri Cardoso Viana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Definindo constantes para os limites máximos
#define MAX_PASSAGEIROS 100
#define MAX_TRIPULANTES 100
#define MAX_VOOS 100
#define MAX_ASSENTOS 100
#define MAX_RESERVAS 100

// Estrutura para armazenar informações de um passageiro
typedef struct {
    int codigo;
    char nome[100];
    char endereco[100];
    char telefone[100];
    int fidelidade; //0 - Não é fidelidade, 1 - É fidelidade
    int pontos_fidelidade;
} Passageiro;

// Estrutura para armazenar informações de um tripulante
typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
    int cargo; //1 - Piloto, 2 - Copiloto, 3 - Comissário
}Tripulacao;

// Estrutura para armazenar informações de um voo
typedef struct {
    int codigo_voo;
    char data_voo[20];
    char hora_voo[20];
    char origem[50];
    char destino[50];
    int codigo_aviao;
    int tarifa;
    int codigo_piloto;
    int codigo_copiloto;
    int codigo_comissario;
    int status; //Ativo ou Inativo
}Voo;

// Estrutura para armazenar informações de um assento
typedef struct {
    int numero_assento;
    int codigo_voo;
    int status; //Ocupado ou Livre
}Assento;

// Estrutura para armazenar informações de uma reserva
typedef struct {
    int codigo_voo;
    int numero_assento;
    int codigo_passageiro;
}Reserva;

// Função para cadastrar um passageiro
void cadastrarPassageiro(Passageiro passageiros[], int *qtdPassageiros) {
    Passageiro novoPassageiro;
    novoPassageiro.codigo = *qtdPassageiros + 1;
    printf("\n\t----------------------\n");
    printf("\tCadastro de Passageiro\n");
    printf("\t----------------------\n");
    printf("\tNome: ");
    scanf(" %[^\n]", novoPassageiro.nome);
    printf("\tEndereço: ");
    scanf(" %[^\n]", novoPassageiro.endereco);
    printf("\tTelefone: ");
    scanf(" %[^\n]", novoPassageiro.telefone);
    printf("\tFidelidade (0 - Não, 1 - Sim): ");
    scanf("%d", &novoPassageiro.fidelidade);

    passageiros[*qtdPassageiros] = novoPassageiro;
    (*qtdPassageiros)++;

    printf("\tPassageiro cadastrado com sucesso!\n\tCodigo do Passageiro: %d\n", novoPassageiro.codigo);
}

// Função para testar o cadastro de um passageiro
void testarCadastrarPassageiro() {
    Passageiro passageiros[MAX_PASSAGEIROS];
    int qtdPassageiros = 0;

    Passageiro novoPassageiro;
    novoPassageiro.codigo = qtdPassageiros + 1;
    strcpy(novoPassageiro.nome, "Passageiro teste");
    strcpy(novoPassageiro.endereco, "Rua teste");
    strcpy(novoPassageiro.telefone, "123456789");
    novoPassageiro.fidelidade = 1;

    passageiros[qtdPassageiros] = novoPassageiro;
    qtdPassageiros++;

    assert(passageiros[0].codigo == 1);
    assert(strcmp(passageiros[0].nome, "Passageiro teste") == 0);
    assert(strcmp(passageiros[0].endereco, "Rua teste") == 0);
    assert(strcmp(passageiros[0].telefone, "123456789") == 0);
    assert(passageiros[0].fidelidade == 1);

    printf("\tTeste de cadastro de passageiro passou!\n");

    printf("\t------------------------------\n");
    printf("\tDados do passageiro cadastrado:\n");
    printf("\tCódigo: %d\n", passageiros[0].codigo);
    printf("\tNome: %s\n", passageiros[0].nome);
    printf("\tEndereço: %s\n", passageiros[0].endereco);
    printf("\tTelefone: %s\n", passageiros[0].telefone);
    printf("\tFidelidade: %d\n", passageiros[0].fidelidade);
    printf("\t------------------------------\n");
    
}

// Função para cadastrar um tripulante
void cadastrarTripulacao(Tripulacao tripulantes[], int *qtdTripulantes) {
    Tripulacao novoTripulante;
    novoTripulante.codigo = *qtdTripulantes + 1;
    printf("\n\t----------------------\n");
    printf("\tCadastro de Tripulante\n");
    printf("\t----------------------\n");
    printf("\tNome: ");
    scanf(" %[^\n]", novoTripulante.nome);
    printf("\tTelefone: ");
    scanf(" %[^\n]", novoTripulante.telefone);
    printf("\tCargo (1 - Piloto, 2 - Copiloto, 3 - Comissário): ");
    scanf("%d", &novoTripulante.cargo);

    if (!(novoTripulante.cargo == 1 || novoTripulante.cargo == 2 || novoTripulante.cargo == 3)) {
        printf("\tCargo inválido! Insira novamente.\n");
        *qtdTripulantes = -1;
        return;
    }

    tripulantes[*qtdTripulantes] = novoTripulante;
    (*qtdTripulantes)++;

    printf("\tTripulante cadastrado com sucesso!\n\tCodigo do Tripulante: %d\n", novoTripulante.codigo);
}

// Função para testar o cadastro de um tripulante
void testarCadastrarTripulante() {
    Tripulacao tripulantes[MAX_TRIPULANTES];
    int qtdTripulantes = 0;

    Tripulacao novoTripulante;
    novoTripulante.codigo = qtdTripulantes + 1;
    strcpy(novoTripulante.nome, "Tripulante teste");
    strcpy(novoTripulante.telefone, "123456789");
    novoTripulante.cargo = 1;

    tripulantes[qtdTripulantes] = novoTripulante;
    qtdTripulantes++;

    assert(tripulantes[0].codigo == 1);
    assert(strcmp(tripulantes[0].nome, "Tripulante teste") == 0);
    assert(strcmp(tripulantes[0].telefone, "123456789") == 0);
    assert(tripulantes[0].cargo == 1);

    printf("\tTeste de cadastro de tripulante passou!\n");

    printf("\t------------------------------\n");
    printf("\tDados do tripulante cadastrado:\n");
    printf("\tCódigo: %d\n", tripulantes[0].codigo);
    printf("\tNome: %s\n", tripulantes[0].nome);
    printf("\tTelefone: %s\n", tripulantes[0].telefone);
    printf("\tCargo: %d\n", tripulantes[0].cargo);
    printf("\t------------------------------\n");
    
}


// Função para cadastrar um voo
void cadastrarVoo(Voo voos[], int *qtdVoos, Tripulacao tripulantes[], int qtdTripulantes) {
    Voo novoVoo;
    novoVoo.codigo_voo = *qtdVoos + 1;
    printf("\n\t----------------------\n");
    printf("\tCadastro de Voo\n");
    printf("\t----------------------\n");
    printf("\tData do Voo: ");
    scanf(" %[^\n]", novoVoo.data_voo);
    printf("\tHora do Voo: ");
    scanf(" %[^\n]", novoVoo.hora_voo);
    printf("\tOrigem: ");
    scanf(" %[^\n]", novoVoo.origem);
    printf("\tDestino: ");
    scanf(" %[^\n]", novoVoo.destino);
    printf("\tCodigo do Avião: ");
    scanf("%d", &novoVoo.codigo_aviao);
    printf("\tTarifa: ");
    scanf("%d", &novoVoo.tarifa);
    printf("\tCodigo do Piloto: ");
    fflush(stdout);
    scanf("%d", &novoVoo.codigo_piloto);
    printf("\tCodigo do Copiloto: ");
    fflush(stdout);
    scanf("%d", &novoVoo.codigo_copiloto);
    printf("\tCodigo do Comissário: ");
    fflush(stdout);
    scanf("%d", &novoVoo.codigo_comissario);

    int tripulacaoEncontrada = 0;
    for (int i = 0; i < qtdTripulantes; i++) {
        if (novoVoo.codigo_piloto == tripulantes[i].codigo || novoVoo.codigo_copiloto == tripulantes[i].codigo || novoVoo.codigo_comissario == tripulantes[i].codigo) {
            tripulacaoEncontrada = 1;
            break;
        }
    }

    if (!tripulacaoEncontrada) {
        printf("\tTripulação não encontrada! Insira novamente.\n");
        *qtdVoos = -1;
        return;
    }

    printf("\tStatus (1 - Ativo, 0 - Inativo): ");
    scanf("%d", &novoVoo.status);

    voos[*qtdVoos] = novoVoo;
    (*qtdVoos)++;

    printf("\tVoo cadastrado com sucesso!\n\tCodigo do Voo: %d\n", novoVoo.codigo_voo);
}

// Função para testar o cadastro de um voo
void testarCadastrarVoo() {
    Voo voos[MAX_VOOS];
    int qtdVoos = 0;

    Voo novoVoo;
    novoVoo.codigo_voo = qtdVoos + 1;
    strcpy(novoVoo.data_voo, "01/01/2021");
    strcpy(novoVoo.hora_voo, "12:00");
    strcpy(novoVoo.origem, "São Paulo");
    strcpy(novoVoo.destino, "Rio de Janeiro");
    novoVoo.codigo_aviao = 1;
    novoVoo.tarifa = 100;
    novoVoo.codigo_piloto = 1;
    novoVoo.codigo_copiloto = 2;
    novoVoo.codigo_comissario = 3;
    novoVoo.status = 1;

    voos[qtdVoos] = novoVoo;
    qtdVoos++;

    assert(voos[0].codigo_voo == 1);
    assert(strcmp(voos[0].data_voo, "01/01/2021") == 0);
    assert(strcmp(voos[0].hora_voo, "12:00") == 0);
    assert(strcmp(voos[0].origem, "São Paulo") == 0);
    assert(strcmp(voos[0].destino, "Rio de Janeiro") == 0);
    assert(voos[0].codigo_aviao == 1);
    assert(voos[0].tarifa == 100);
    assert(voos[0].codigo_piloto == 1);
    assert(voos[0].codigo_copiloto == 2);
    assert(voos[0].codigo_comissario == 3);
    assert(voos[0].status == 1);

    printf("\tTeste de cadastro de voo passou!\n");

    printf("\t------------------------------\n");
    printf("\tDados do voo cadastrado:\n");
    printf("\tCódigo: %d\n", voos[0].codigo_voo);
    printf("\tData: %s\n", voos[0].data_voo);
    printf("\tHora: %s\n", voos[0].hora_voo);
    printf("\tOrigem: %s\n", voos[0].origem);
    printf("\tDestino: %s\n", voos[0].destino);
    printf("\tCódigo do Avião: %d\n", voos[0].codigo_aviao);
    printf("\tTarifa: %d\n", voos[0].tarifa);
    printf("\tCódigo do Piloto: %d\n", voos[0].codigo_piloto);
    printf("\tCódigo do Copiloto: %d\n", voos[0].codigo_copiloto);
    printf("\tCódigo do Comissário: %d\n", voos[0].codigo_comissario);
    printf("\tStatus: %d\n", voos[0].status);
    printf("\t------------------------------\n");

}

// Função para cadastrar um assento
void cadastrarAssento(Assento assentos[], int *qtdAssentos, Voo voos[], int qtdVoos) {
    Assento novoAssento;
    novoAssento.numero_assento = *qtdAssentos + 1;
    printf("\n\t----------------------\n");
    printf("\tCadastro de Assento\n");
    printf("\t----------------------\n");
    printf("\tCodigo do Voo: ");
    fflush(stdout);
    scanf("%d", &novoAssento.codigo_voo);
    printf("\tStatus (1 - Ocupado, 0 - Livre): ");
    scanf("%d", &novoAssento.status);

    int vooEncontrado = 0;
    for (int i = 0; i < qtdVoos; i++) {
        if (novoAssento.codigo_voo == voos[i].codigo_voo) {
            vooEncontrado = 1;
            break;
        }
    }

    if (!vooEncontrado) {
        printf("\tVoo não encontrado! Insira novamente.\n");
        *qtdAssentos = -1;
        return;
    }

    assentos[*qtdAssentos] = novoAssento;
    (*qtdAssentos)++;

    printf("\tAssento cadastrado com sucesso!\n\tNúmero do Assento: %d\n", novoAssento.numero_assento);
}

// Função para testar o cadastro de um assento
void testarCadastrarAssento() {
    Assento assentos[MAX_ASSENTOS];
    int qtdAssentos = 0;

    Assento novoAssento;
    novoAssento.numero_assento = qtdAssentos + 1;
    novoAssento.codigo_voo = 1;
    novoAssento.status = 1;

    assentos[qtdAssentos] = novoAssento;
    qtdAssentos++;

    assert(assentos[0].numero_assento == 1);
    assert(assentos[0].codigo_voo == 1);
    assert(assentos[0].status == 1);

    printf("\tTeste de cadastro de assento passou!\n");

    printf("\t------------------------------\n");
    printf("\tDados do assento cadastrado:\n");
    printf("\tNúmero do Assento: %d\n", assentos[0].numero_assento);
    printf("\tCódigo do Voo: %d\n", assentos[0].codigo_voo);
    printf("\tStatus: %d\n", assentos[0].status);
    printf("\t------------------------------\n");

}

// Função para pesquisar um passageiro
void pesquisarPassageiro(Passageiro passageiros[], int qtdPassageiros) {
    int codigo;
    char nome[100];
    int opcao;
    printf("\n\t----------------------\n");
    printf("\tPesquisa de Passageiro\n");
    printf("\t----------------------\n");
    printf("\tPesquisar por (1) Código ou (2) Nome: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("\tCódigo do Passageiro: ");
        scanf("%d", &codigo);
        for (int i = 0; i < qtdPassageiros; i++) {
            if (passageiros[i].codigo == codigo) {
                printf("\tNome do Passageiro: %s\n", passageiros[i].nome);
                printf("\tEndereço: %s\n", passageiros[i].endereco);
                printf("\tTelefone: %s\n", passageiros[i].telefone);
                printf("\tFidelidade: %d\n", passageiros[i].fidelidade);
                return;
            }
        }
    } else if (opcao == 2) {
        printf("\tNome do Passageiro: ");
        scanf(" %[^\n]", nome);
        for (int i = 0; i < qtdPassageiros; i++) {
            if (strcmp(passageiros[i].nome, nome) == 0) {
                printf("\tCódigo do Passageiro: %d\n", passageiros[i].codigo);
                printf("\tEndereço: %s\n", passageiros[i].endereco);
                printf("\tTelefone: %s\n", passageiros[i].telefone);
                printf("\tFidelidade: %d\n", passageiros[i].fidelidade);
                return;
            }
        }
    }
    printf("\tPassageiro não encontrado!\n");

}

// Função para pesquisar um tripulante
void pesquisarTripulante(Tripulacao Tripulacao[], int qtdTripulantes) {
    int codigo;
    char nome[100];
    int opcao;
    printf("\n\t----------------------\n");
    printf("\tPesquisa de Tripulante\n");
    printf("\t----------------------\n");
    printf("\tPesquisar por (1) Código ou (2) Nome: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("\tCódigo do Tripulante: ");
        scanf("%d", &codigo);
        for (int i = 0; i < qtdTripulantes; i++) {
            if (Tripulacao[i].codigo == codigo) {
                printf("\tNome do Tripulante: %s\n", Tripulacao[i].nome);
                printf("\tTelefone: %s\n", Tripulacao[i].telefone);
                printf("\tCargo: %d\n", Tripulacao[i].cargo);
                return;
            }
        }
    } else if (opcao == 2) {
        printf("\tNome do Tripulante: ");
        scanf(" %[^\n]", nome);
        for (int i = 0; i < qtdTripulantes; i++) {
            if (strcmp(Tripulacao[i].nome, nome) == 0) {
                printf("\tCódigo do Tripulante: %d\n", Tripulacao[i].codigo);
                printf("\tTelefone: %s\n", Tripulacao[i].telefone);
                printf("\tCargo: %d\n", Tripulacao[i].cargo);
                return;
            }
        }
    }
    printf("\tTripulante não encontrado!\n");

}

// Função para salvar os voos em um arquivo
void salvarVooEmArquivo(Voo voos[], int qtdVoos) {
    FILE *arquivo = fopen("voos.txt", "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo de voos\n");
        return;
    }

    for (int i = 0; i < qtdVoos; i++) {
        fprintf(arquivo, "%d %s %s %s %s %d %d %d %d %d %d\n", voos[i].codigo_voo, voos[i].data_voo, voos[i].hora_voo, voos[i].origem, voos[i].destino, voos[i].codigo_aviao, voos[i].tarifa, voos[i].codigo_piloto, voos[i].codigo_copiloto, voos[i].codigo_comissario, voos[i].status);
    }

    fclose(arquivo);
}

void fazerReserva(Reserva reservas[], int *qtdReservas, Passageiro passageiros[], int qtdPassageiros, Voo voos[], int qtdVoos, Assento assentos[], int qtdAssentos) {
    Reserva novaReserva;
    novaReserva.codigo_voo = *qtdReservas + 1;
    printf("\n\t----------------------\n");
    printf("\tFazer Reserva\n");
    printf("\t----------------------\n");
    printf("\tCódigo do Passageiro: ");
    scanf("%d", &novaReserva.codigo_passageiro);

    int passageiroEncontrado = 0;
    for (int i = 0; i < qtdPassageiros; i++) {
        if (novaReserva.codigo_passageiro == passageiros[i].codigo) {
            passageiroEncontrado = 1;
            break;
        }
    }

    if (!passageiroEncontrado) {
        printf("\tPassageiro não encontrado! Insira novamente.\n");
        *qtdReservas = -1;
        return;


    }

    printf("\tNúmero do voo: ");
    scanf("%d", &novaReserva.codigo_voo);

    int vooEncontrado = 0;
    for (int i = 0; i < qtdVoos; i++) {
        if (novaReserva.codigo_voo == voos[i].codigo_voo) {
            vooEncontrado = 1;
            break;
        }
    }

    if (!vooEncontrado) {
        printf("\tVoo não encontrado! Insira novamente.\n");
        *qtdReservas = -1;
        return;
    }

    printf("\tNúmero do Assento: ");
    scanf("%d", &novaReserva.numero_assento);

    int assentoEncontrado = 0;
    for (int i = 0; i < qtdAssentos; i++) {
        if (novaReserva.numero_assento == assentos[i].numero_assento) {
            assentoEncontrado = 1;
            if (assentos[i].status == 1) {
                printf("\tAssento ocupado! Insira novamente.\n");
                *qtdReservas = -1;
                return;
            }
            else if (assentos[i].status == 0) {
                assentos[i].status = 1;
                break;
            }
            //
        }
    }

    if (!assentoEncontrado) {
        printf("\tAssento não encontrado! Insira novamente.\n");
        *qtdReservas = -1;
        return;
    }

    reservas[*qtdReservas] = novaReserva;
    (*qtdReservas)++;

    printf("\t------------------------------\n");
    printf("\tReserva feita com sucesso!\n\tCódigo da Reserva: %d\n", novaReserva.codigo_voo);

}

// Função para dar baixa em uma reserva
void darBaixaReserva(Reserva reservas[], int *qtdReservas, Voo voos[], int qtdVoos, Assento assentos[], int qtdAssentos) {
    int codigoReserva;
    printf("\n\t----------------------\n");
    printf("\tDar Baixa em Reserva\n");
    printf("\t----------------------\n");
    printf("\tCódigo da Reserva: ");
    scanf("%d", &codigoReserva);

    for (int i = 0; i < *qtdReservas; i++) {
        if (reservas[i].codigo_voo == codigoReserva) {
            printf("\tReserva encontrada!\n");
            printf("\tCódigo da Reserva: %d\n", reservas[i].codigo_voo);
            printf("\tCódigo do Passageiro: %d\n", reservas[i].codigo_passageiro);
            printf("\tNúmero do Assento: %d\n", reservas[i].numero_assento);
            printf("\n");

            for (int j = 0; j < qtdVoos; j++) {
                if (reservas[i].codigo_voo == voos[j].codigo_voo) {
                    assentos[j].status = 0;
                    break;
                }
            }

            FILE *arquivoTemp = fopen("assentos_temp.txt", "w");
            FILE *arquivoAssento = fopen("assentos.txt", "r");
            if (arquivoAssento == NULL) {
                perror("Erro ao abrir arquivo de assentos\n");
                return;
            }

            char linha[100];
            while (fgets(linha, 100, arquivoAssento) != NULL) {
                int numeroAssento;
                int codigoVoo;
                int status;
                sscanf(linha, "%d %d %d", &numeroAssento, &codigoVoo, &status);
                if (numeroAssento == reservas[i].numero_assento && codigoVoo == reservas[i].codigo_voo) {
                    fprintf(arquivoTemp, "%d %d %d\n", numeroAssento, codigoVoo, 0);
                } else {
                    fprintf(arquivoTemp, "%d %d %d\n", numeroAssento, codigoVoo, status);
                }
            }

            fclose(arquivoAssento);
            fclose(arquivoTemp);

            remove("assentos.txt");
            rename("assentos_temp.txt", "assentos.txt");

            FILE *arquivoReserva = fopen("reservas_temp.txt", "w");
            if (arquivoReserva == NULL) {
                perror("Erro ao abrir arquivo de reservas\n");
                return;
            }

            for (int j = 0; j < *qtdReservas; j++) {
                if (reservas[j].codigo_voo != codigoReserva) {
                    fprintf(arquivoReserva, "%d %d %d\n", reservas[j].numero_assento, reservas[j].codigo_voo, reservas[j].codigo_passageiro);
                }
            }
            fclose(arquivoReserva);

            printf("\t------------------------------\n");
            printf("\tReserva dada baixa com sucesso!\n");

            for (int j = i; j < *qtdReservas - 1; j++) {
                reservas[j] = reservas[j + 1];
            }
            (*qtdReservas)--;
            return;  
        }
    }
    printf("\tReserva nao encontrada!\n");

}

// Função para listar os voos de um passageiro
void listarVooPassageiro(Voo voos[], int qtdVoos, Passageiro passageiros[], int qtdPassageiros) {
    int codigoPassageiro;
    printf("\n\t-------------------------\n");
    printf("\tListar Voos do Passageiro\n");
    printf("\t-------------------------\n");
    printf("\tCódigo do Passageiro: ");
    fflush(stdout);
    scanf("%d", &codigoPassageiro);

    int passageiroEncontrado = 0;
    for (int i = 0; i < qtdPassageiros; i++) {
        if (passageiros[i].codigo == codigoPassageiro) {
            passageiroEncontrado = 1;
            break;
        }
    }

    if(!passageiroEncontrado) {
        printf("\tPassageiro não encontrado!\n");
        return;
    }

    for (int i = 0; i < qtdPassageiros; i++) {
        if (passageiros[i].codigo == codigoPassageiro) {
            for (int j = 0; j < qtdVoos; j++) {
                printf("\tVoo %d\n", voos[j].codigo_voo);
                printf("\tData: %s\n", voos[j].data_voo);
                printf("\tHora: %s\n", voos[j].hora_voo);
                printf("\tOrigem: %s\n", voos[j].origem);
                printf("\tDestino: %s\n", voos[j].destino);
                printf("\tTarifa: %d\n", voos[j].tarifa);
                printf("\n");
            }
            return;
        }
    }

    if (!passageiroEncontrado) {
        printf("\tPassageiro não encontrado!\n");
    }
}

// Função para salvar os dados em um arquivo
void salvarDados(Passageiro passageiro[], int qtdPassageiros, Tripulacao tripulantes[], int qtdTripulantes, Voo voos[], int qtdVoos, Assento assentos[], int qtdAssentos) {
    FILE *filePassageiros = fopen("passageiros.txt", "w");
    FILE *fileTripulantes = fopen("tripulantes.txt", "w");
    FILE *fileVoos = fopen("voos.txt", "w");
    FILE *fileAssentos = fopen("assentos.txt", "w");

    if (filePassageiros == NULL || fileTripulantes == NULL || fileVoos == NULL || fileAssentos == NULL) {
        perror("Erro ao abrir arquivo\n");
        return;
    }

    for (int i = 0; i < qtdPassageiros; i++) {
        fprintf(filePassageiros, "%d %s %s %s %d\n", passageiro[i].codigo, passageiro[i].nome, passageiro[i].endereco, passageiro[i].telefone, passageiro[i].fidelidade);
    }

    for (int i = 0; i < qtdTripulantes; i++) {
        fprintf(fileTripulantes, "%d %s %s %d\n", tripulantes[i].codigo, tripulantes[i].nome, tripulantes[i].telefone, tripulantes[i].cargo);
    }

    for (int i = 0; i < qtdVoos; i++) {
        fprintf(fileVoos, "%d %s %s %s %s %d %d %d %d %d %d\n", voos[i].codigo_voo, voos[i].data_voo, voos[i].hora_voo, voos[i].origem, voos[i].destino, voos[i].codigo_aviao, voos[i].tarifa, voos[i].codigo_piloto, voos[i].codigo_copiloto, voos[i].codigo_comissario, voos[i].status);
    }

    for (int i = 0; i < qtdAssentos; i++) {
        fprintf(fileAssentos, "%d %d %d\n", assentos[i].numero_assento, assentos[i].codigo_voo, assentos[i].status);
    }

    fclose(filePassageiros);
    fclose(fileTripulantes);
    fclose(fileVoos);
    fclose(fileAssentos);

}

// Função para carregar os dados de um arquivo
void carregarDados(Passageiro passageiros[], int *qtdPassageiros, Tripulacao tripulantes[], int *qtdTripulantes, Voo voos[], int *qtdVoos, Assento assentos[], int *qtdAssentos) {
    FILE *filePassageiros = fopen("passageiros.txt", "r");
    FILE *fileTripulantes = fopen("tripulantes.txt", "r");
    FILE *fileVoos = fopen("voos.txt", "r");
    FILE *fileAssentos = fopen("assentos.txt", "r");

    if (filePassageiros == NULL || fileTripulantes == NULL || fileVoos == NULL || fileAssentos == NULL) {
        perror("Erro ao abrir arquivo\n");
        return;
    }

    *qtdPassageiros = 0;
    *qtdTripulantes = 0;
    *qtdVoos = 0;
    *qtdAssentos = 0;

    while (fscanf(filePassageiros, "%d %s %s %s %d\n", &passageiros[*qtdPassageiros].codigo, passageiros[*qtdPassageiros].nome, passageiros[*qtdPassageiros].endereco, passageiros[*qtdPassageiros].telefone, &passageiros[*qtdPassageiros].fidelidade) == 5) {
        (*qtdPassageiros)++;
    }

    while (fscanf(fileTripulantes, "%d %s %s %d\n", &tripulantes[*qtdTripulantes].codigo, tripulantes[*qtdTripulantes].nome, tripulantes[*qtdTripulantes].telefone, &tripulantes[*qtdTripulantes].cargo) == 4) {
        (*qtdTripulantes)++;
    }

    while (fscanf(fileVoos, "%d %s %s %s %s %d %d %d %d %d %d\n", &voos[*qtdVoos].codigo_voo, voos[*qtdVoos].data_voo, voos[*qtdVoos].hora_voo, voos[*qtdVoos].origem, voos[*qtdVoos].destino, &voos[*qtdVoos].codigo_aviao, &voos[*qtdVoos].tarifa, &voos[*qtdVoos].codigo_piloto, &voos[*qtdVoos].codigo_copiloto, &voos[*qtdVoos].codigo_comissario, &voos[*qtdVoos].status) == 11) {
        (*qtdVoos)++;
    }

    while (fscanf(fileAssentos, "%d %d %d\n", &assentos[*qtdAssentos].numero_assento, &assentos[*qtdAssentos].codigo_voo, &assentos[*qtdAssentos].status) == 3) {
        (*qtdAssentos)++;
    }

    fclose(filePassageiros);
    fclose(fileTripulantes);
    fclose(fileVoos);
    fclose(fileAssentos);
}

// Função principal
int main() {
    Passageiro passageiros[MAX_PASSAGEIROS];
    Tripulacao tripulantes[MAX_TRIPULANTES];
    Voo voos[MAX_VOOS];
    Assento assentos[MAX_ASSENTOS];
    Reserva reservas[MAX_RESERVAS];

    int qtdPassageiros = 0;
    int qtdTripulantes = 0;
    int qtdVoos = 0;
    int qtdAssentos = 0;
    int qtdReservas = 0;

    carregarDados(passageiros, &qtdPassageiros, tripulantes, &qtdTripulantes, voos, &qtdVoos, assentos, &qtdAssentos);

    int opcao;
    int opcaoTeste;

    do {
        printf("\n\t--------------------------\n");
        printf("\tCompanhia Aérea Voo Seguro\n");
        printf("\t--------------------------\n");
        printf("\t1 - Cadastrar Passageiro\n");
        printf("\t2 - Cadastrar Tripulante\n");
        printf("\t3 - Cadastrar Voo\n");
        printf("\t4 - Cadastrar Assento\n");
        printf("\t5 - Pesquisar Passageiro\n");
        printf("\t6 - Pesquisar Tripulante\n");
        printf("\t7 - Fazer Reserva\n");
        printf("\t8 - Dar baixa em Reserva\n");
        printf("\t9 - Listar Voos do Passageiro\n");
        printf("\t10- Aba de testes\n");
        printf("\t0 - Salvar e Sair\n");
        
        while (scanf("%d", &opcao) != 1) {
            printf("\tOpção inválida! Insira novamente.\n");
            while (getchar() != '\n');

            printf("\tEscolha uma opcao: ");
        }

        switch (opcao) {
            case 1:
                cadastrarPassageiro(passageiros, &qtdPassageiros);
                salvarDados(passageiros, qtdPassageiros, tripulantes, qtdTripulantes, voos, qtdVoos, assentos, qtdAssentos);
                break;
            case 2:
                cadastrarTripulacao(tripulantes, &qtdTripulantes);
                salvarDados(passageiros, qtdPassageiros, tripulantes, qtdTripulantes, voos, qtdVoos, assentos, qtdAssentos);
                break;
            case 3:
                cadastrarVoo(voos, &qtdVoos, tripulantes, qtdTripulantes);
                salvarDados(passageiros, qtdPassageiros, tripulantes, qtdTripulantes, voos, qtdVoos, assentos, qtdAssentos);
                break;
            case 4:
                cadastrarAssento(assentos, &qtdAssentos, voos, qtdVoos);
                salvarDados(passageiros, qtdPassageiros, tripulantes, qtdTripulantes, voos, qtdVoos, assentos, qtdAssentos);
                break;
            case 5:
                pesquisarPassageiro(passageiros, qtdPassageiros);
                break;
            case 6:
                pesquisarTripulante(tripulantes, qtdTripulantes);
                break;
            case 7:
                fazerReserva(reservas, &qtdReservas, passageiros, qtdPassageiros, voos, qtdVoos, assentos, qtdAssentos);
                break;
            case 8:
                darBaixaReserva(reservas, &qtdReservas, voos, qtdVoos, assentos, qtdAssentos);
                break;
            case 9:
                listarVooPassageiro(voos, qtdVoos, passageiros, qtdPassageiros);
                break;
            case 10:
                printf("\t----------------------\n");
                printf("\tTestes\n");
                printf("\t----------------------\n");
                printf("\t1 - Testar cadastro de passageiro\n");
                printf("\t2 - Testar cadastro de tripulante\n");
                printf("\t3 - Testar cadastro de voo\n");
                printf("\t4 - Testar cadastro de assento\n");

                scanf("%d", &opcaoTeste);
                if (opcaoTeste == 1) {
                    testarCadastrarPassageiro();
                } 
                else if (opcaoTeste == 2) {
                    testarCadastrarTripulante();
                }
                else if (opcaoTeste == 3) {
                    testarCadastrarVoo();
                }
                else if (opcaoTeste == 4) {
                    testarCadastrarAssento();
                }
                else {
                    printf("\tOpção inválida! Insira novamente.\n");
                }
                break;

            case 0:
                salvarDados(passageiros, qtdPassageiros, tripulantes, qtdTripulantes, voos, qtdVoos, assentos, qtdAssentos);
                break;
            default:
                printf("\tOpção inválida! Insira novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;

}
