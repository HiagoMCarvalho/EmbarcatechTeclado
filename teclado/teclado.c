#include <stdio.h>
#include "pico/stdlib.h"

#define rows 4
#define cols 4

#define led_verde 11
#define led_azul 12
#define led_vermelho 13
#define buzzer 21

const uint colunas[cols] = {4, 3, 2, 1};
const uint linhas[rows] = {8, 7, 6, 5};

const char teclas[rows][cols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

void init_pinos()
{
    // Inicializar as teclas como saída
    for (int l = 0; l < rows; l++)
    {
        gpio_init(linhas[l]);
        gpio_set_dir(linhas[l], GPIO_OUT);
        gpio_put(linhas[l], true);
    }

    // Inicializar as teclas como entrada
    for (int c = 0; c < cols; c++)
    {
        gpio_init(colunas[c]);
        gpio_set_dir(colunas[c], GPIO_IN);
        gpio_pull_up(colunas[c]);
    }

    // Inicializar o pino do buzzer como saída
    gpio_init(buzzer);
    gpio_set_dir(buzzer, GPIO_OUT);
    gpio_put(buzzer, false);

    // Inicializar o pino do led verde como saída
    gpio_init(led_verde);
    gpio_set_dir(led_verde, GPIO_OUT);
    gpio_put(led_verde, false);

    // Inicializar o pino do led azul como saída
    gpio_init(led_azul);
    gpio_set_dir(led_azul, GPIO_OUT);
    gpio_put(led_azul, false);

    // Inicializar o pino do led vermelho como saída
    gpio_init(led_vermelho);
    gpio_set_dir(led_vermelho, GPIO_OUT);
    gpio_put(led_vermelho, false);
}

char escanear_teclado()
{
    for (int row = 0; row < rows; row++)
    {
        gpio_put(linhas[row], false);

        for (int col = 0; col < cols; col++)
        {
            if (!gpio_get(colunas[col]))
            {
                sleep_ms(20); // Debouncing
                if (!gpio_get(colunas[col]))
                {
                    gpio_put(linhas[row], true);
                    return teclas[row][col];
                }
            }
        }
        gpio_put(linhas[row], true); // Desativar linha atual
    }
    return 0; // Nenhuma tecla pressionada
}

void tocar_buzzer(int duracao)
{
    int tempo = duracao;
    while (tempo > 0)
    {
        gpio_put(buzzer, true); // Liga o buzzer
        sleep_ms(0.5);            // Mantém ligado por 1ms
        tempo--;
        gpio_put(buzzer, false); // Desliga o buzzer
        sleep_ms(2);             // Aguarda 1ms antes de repetir
        tempo -= 3;
    }
}

void executar_tecla(char tecla)
{
    switch (tecla)
    {
    case 'A':
        gpio_put(led_vermelho, true);
        sleep_ms(500);

        gpio_put(led_vermelho, false);

        break;

    case 'B':
        gpio_put(led_azul, true);
        sleep_ms(500);

        gpio_put(led_azul, false);

        break;

    case 'C':
        gpio_put(led_verde, true);
        sleep_ms(500);

        gpio_put(led_verde, false);

        break;

    case 'D':
        gpio_put(led_vermelho, true);
        gpio_put(led_azul, true);
        gpio_put(led_verde, true);
        sleep_ms(500);

        gpio_put(led_vermelho, false);
        gpio_put(led_azul, false);
        gpio_put(led_verde, false);

        break;

    case '#':
        tocar_buzzer(1000);
        break;

    default:
        break;
    }
}

int main()
{
    stdio_init_all();
    init_pinos();

    while (true)
    {
        char teclaPressionada = escanear_teclado();

        if (teclaPressionada != 0)
        {
            executar_tecla(teclaPressionada);
        }
        sleep_ms(100);
    }
}
