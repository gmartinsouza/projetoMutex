#define SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

pthread_mutex_t semHorizontal, semVertical;
pthread_mutex_t _24, _23, _21, _20;
pthread_mutex_t _22;
pthread_mutex_t _42, _32, _12, _02;

int isLockedSemHorizontal = 1, isLockedSemVertical = 1;

int getRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

void fecharSemHorizontal() {
    pthread_mutex_lock(&semHorizontal);
    isLockedSemHorizontal = 1;
}

void abrirSemHorizontal() {
    pthread_mutex_unlock(&semHorizontal);
    isLockedSemHorizontal = 0;
}

void fecharSemVertical() {
    pthread_mutex_lock(&semVertical);
    isLockedSemVertical = 1;
}

void abrirSemVertical() {
    pthread_mutex_unlock(&semVertical);
    isLockedSemVertical = 0;
}

void inicializarSemaforos() {
    pthread_mutex_init(&semHorizontal, NULL);
    pthread_mutex_init(&semVertical, NULL);
    pthread_mutex_init(&_24, NULL);
    pthread_mutex_init(&_23, NULL);
    pthread_mutex_init(&_21, NULL);
    pthread_mutex_init(&_20, NULL);

    pthread_mutex_init(&_22, NULL);

    pthread_mutex_init(&_42, NULL);
    pthread_mutex_init(&_32, NULL);
    pthread_mutex_init(&_12, NULL);
    pthread_mutex_init(&_02, NULL);

    fecharSemHorizontal();
    fecharSemVertical();
}

char ruas[5][5][10] = {
    {"    ", "    ", "↑  ↑", "    ", "    "},
    {"    ", "    ", "    ", "    ", "    "},
    {"←  ←", "    ", "    ", "    ", "←  ←"},
    {"    ", "    ", "    ", "    ", "    "},
    {"    ", "    ", "↑  ↑", "    ", "    "},
};

void* transitoINTERFACE(){
    while(1){
        if (!isLockedSemHorizontal && !isLockedSemVertical) {
            printf("\n\n");
            printf("                      rua 01\n");
            printf("                    +        +\n");
            printf("                    |  %s  |\n", ruas[0][2]);
            printf("                    +--------+\n");
            printf("                    |  %s  |\n", ruas[1][2]);
            printf("       +-----+------+--------+------+-----+\n");
            printf("rua 04  %s | %s |  %s  \033[32m|\033[39m %s | %s  rua 02\n", ruas[2][0], ruas[2][1], ruas[2][2], ruas[2][3], ruas[2][4]);
            printf("       +-----+------+\033[32m--------\033[39m+------+-----+\n");
            printf("                    |  %s  |\n", ruas[3][2]);
            printf("                    +--------+\n");
            printf("                    |  %s  |\n", ruas[4][2]);
            printf("                    +        +\n");
            printf("                      rua 03\n\n\n");
            usleep(199000);
            system("clear");
        } else if (!isLockedSemHorizontal && isLockedSemVertical) {
            printf("\n\n");
            printf("                      rua 01\n");
            printf("                    +        +\n");
            printf("                    |  %s  |\n", ruas[0][2]);
            printf("                    +--------+\n");
            printf("                    |  %s  |\n", ruas[1][2]);
            printf("       +-----+------+--------+------+-----+\n");
            printf("rua 04  %s | %s |  %s  \033[32m|\033[39m %s | %s  rua 02\n", ruas[2][0], ruas[2][1], ruas[2][2], ruas[2][3], ruas[2][4]);
            printf("       +-----+------+\033[31m--------\033[39m+------+-----+\n");
            printf("                    |  %s  |\n", ruas[3][2]);
            printf("                    +--------+\n");
            printf("                    |  %s  |\n", ruas[4][2]);
            printf("                    +        +\n");
            printf("                      rua 03\n\n\n");
            usleep(199000);
            system("clear");
        } else if (isLockedSemHorizontal && !isLockedSemVertical) {
            printf("\n\n");
            printf("                      rua 01\n");
            printf("                    +        +\n");
            printf("                    |  %s  |\n", ruas[0][2]);
            printf("                    +--------+\n");
            printf("                    |  %s  |\n", ruas[1][2]);
            printf("       +-----+------+--------+------+-----+\n");
            printf("rua 04  %s | %s |  %s  \033[31m|\033[39m %s | %s  rua 02\n", ruas[2][0], ruas[2][1], ruas[2][2], ruas[2][3], ruas[2][4]);
            printf("       +-----+------+\033[32m--------\033[39m+------+-----+\n");
            printf("                    |  %s  |\n", ruas[3][2]);
            printf("                    +--------+\n");
            printf("                    |  %s  |\n", ruas[4][2]);
            printf("                    +        +\n");
            printf("                      rua 03\n\n\n");
            usleep(199000);
            system("clear");
        } else if (isLockedSemHorizontal && isLockedSemVertical) {
            printf("\n\n");
            printf("                      rua 01\n");
            printf("                    +        +\n");
            printf("                    |  %s  |\n", ruas[0][2]);
            printf("                    +--------+\n");
            printf("                    |  %s  |\n", ruas[1][2]);
            printf("       +-----+------+--------+------+-----+\n");
            printf("rua 04  %s | %s |  %s  \033[31m|\033[39m %s | %s  rua 02\n", ruas[2][0], ruas[2][1], ruas[2][2], ruas[2][3], ruas[2][4]);
            printf("       +-----+------+\033[31m--------\033[39m+------+-----+\n");
            printf("                    |  %s  |\n", ruas[3][2]);
            printf("                    +--------+\n");
            printf("                    |  %s  |\n", ruas[4][2]);
            printf("                    +        +\n");
            printf("                      rua 03\n\n\n");
            usleep(199000);
            system("clear");
        }
    }
}

void *carroHorizontalStringDirecaoAleatoria(void *arg) {
    char *nomeCarro = (char *)arg;

    int direcao = getRandomNumber(1, 2);

    pthread_mutex_lock(&_24);
    strcpy(ruas[2][4], nomeCarro);
    usleep(500000);

    pthread_mutex_lock(&_23);
    strcpy(ruas[2][3], nomeCarro);
    strcpy(ruas[2][4], "←  ←");
    pthread_mutex_unlock(&_24);
    usleep(500000);

    if (isLockedSemHorizontal) {
        abrirSemHorizontal();
    }

    if (!isLockedSemVertical) {
        fecharSemVertical();
    }

    pthread_mutex_lock(&_22);
    strcpy(ruas[2][2], nomeCarro);
    strcpy(ruas[2][3], "    ");
    pthread_mutex_unlock(&_23);
    usleep(500000);

    if (direcao == 1) {


        pthread_mutex_lock(&_21);
        strcpy(ruas[2][1], nomeCarro);
        strcpy(ruas[2][2], "    ");
        pthread_mutex_unlock(&_22);
        if (!isLockedSemHorizontal) {
            fecharSemHorizontal();
        }
        usleep(500000);


        pthread_mutex_lock(&_20);
        strcpy(ruas[2][0], nomeCarro);
        strcpy(ruas[2][1], "    ");
        pthread_mutex_unlock(&_21);
        usleep(500000);

        strcpy(ruas[2][0], "←  ←");
        pthread_mutex_unlock(&_20);
        usleep(500000);
        pthread_exit(0);
    } else {


        pthread_mutex_lock(&_12);
        strcpy(ruas[1][2], nomeCarro);
        strcpy(ruas[2][2], "    ");
        pthread_mutex_unlock(&_22);
        if (!isLockedSemHorizontal) {
            fecharSemHorizontal();
        }
        usleep(500000);


        pthread_mutex_lock(&_02);
        strcpy(ruas[0][2], nomeCarro);
        strcpy(ruas[1][2], "    ");
        pthread_mutex_unlock(&_12);
        usleep(500000);

        strcpy(ruas[0][2], "↑  ↑");
        pthread_mutex_unlock(&_02);
        usleep(500000);
        pthread_exit(0);
    }
}

void *carroVerticalStringDirecaoAleatoria(void *arg) {
    char *nomeCarro = (char *)arg;

    int direcao = getRandomNumber(1, 2);

    pthread_mutex_lock(&_42);
    strcpy(ruas[4][2], nomeCarro);
    usleep(500000);

    pthread_mutex_lock(&_32);
    strcpy(ruas[3][2], nomeCarro);
    strcpy(ruas[4][2], "↑  ↑");
    pthread_mutex_unlock(&_42);
    usleep(500000);

    if (isLockedSemVertical) {
        abrirSemVertical();
    }
    
    if (!isLockedSemHorizontal) {
        fecharSemHorizontal();
    }

    pthread_mutex_lock(&_22);
    strcpy(ruas[2][2], nomeCarro);
    strcpy(ruas[3][2], "    ");
    pthread_mutex_unlock(&_32);
    usleep(500000);

    if (direcao == 1) {


        pthread_mutex_lock(&_12);
        strcpy(ruas[1][2], nomeCarro);
        strcpy(ruas[2][2], "    ");
        pthread_mutex_unlock(&_22);
        if (!isLockedSemVertical) {
            fecharSemVertical();
        }
        usleep(500000);


        pthread_mutex_lock(&_02);
        strcpy(ruas[0][2], nomeCarro);
        strcpy(ruas[1][2], "    ");
        pthread_mutex_unlock(&_12);
        usleep(500000);
        
        strcpy(ruas[0][2], "↑  ↑");
        pthread_mutex_unlock(&_02);
        usleep(500000);
        pthread_exit(0);
    } else {


        pthread_mutex_lock(&_21);
        strcpy(ruas[2][1], nomeCarro);
        strcpy(ruas[2][2], "    ");
        pthread_mutex_unlock(&_22);
        if (!isLockedSemVertical) {
            fecharSemVertical();
        }
        usleep(500000);


        pthread_mutex_lock(&_20);
        strcpy(ruas[2][0], nomeCarro);
        strcpy(ruas[2][1], "    ");
        pthread_mutex_unlock(&_21);
        usleep(500000);

        strcpy(ruas[2][0], "←  ←");
        pthread_mutex_unlock(&_20);
        usleep(500000);
        pthread_exit(0);
    }
}

int main() {

    int numCarroAtual = 1;

    pthread_t t1, t2;

    pthread_create(&t1, NULL, transitoINTERFACE, NULL);

    inicializarSemaforos();
    srand(time(0));
    
    while(1) {

        int qtdCarrosHorizontais = getRandomNumber(1, 2);
        int qtdCarrosVerticais = getRandomNumber(1, 2);
        
        int qtdCarrosTotal = qtdCarrosHorizontais + qtdCarrosVerticais;

        char nomesCarros[qtdCarrosTotal][SIZE];
        
        for(int i = 0; i < qtdCarrosTotal; i++) {
            sprintf(nomesCarros[i], "C%03d", numCarroAtual);
            numCarroAtual++;
            if (numCarroAtual >= 1000) {
                numCarroAtual = 1;
            }
        }

        pthread_t carrosHorizontais[qtdCarrosHorizontais];
        pthread_t carrosVerticais[qtdCarrosVerticais];

        int indice = 0;

        for (int i = 0; i < qtdCarrosHorizontais; i++) {
            pthread_create(&carrosHorizontais[i], NULL, carroHorizontalStringDirecaoAleatoria, &nomesCarros[indice]);
            usleep(500000);
            indice++;
        }

        for (int i = 0; i < qtdCarrosVerticais; i++) {
            pthread_create(&carrosVerticais[i], NULL, carroVerticalStringDirecaoAleatoria, &nomesCarros[indice]);
            usleep(500000);
            indice++;
        }

        for (int i = 0; i < qtdCarrosHorizontais; i++) {
            pthread_join(carrosHorizontais[i], NULL);
        }

        for (int i = 0; i < qtdCarrosVerticais; i++) {
            pthread_join(carrosVerticais[i], NULL);
        }
    }
    return 0;
}
