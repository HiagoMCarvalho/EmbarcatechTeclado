# Embarcatech - Teclado Matricial

Este projeto implementa a funcionalidade de um teclado matricial utilizando o Raspberry Pi Pico W, e a extensão WOWKI para simulação dos componentes que foram o circuito. O código é desenvolvido em C para sistemas embarcados e integra um teclado matricial com LEDs e buzzer para feedback visual e sonoro.

## Estrutura do Projeto

- **teclado.c**: Contém a lógica principal do teclado, incluindo inicialização, loop de execução e manipulação de eventos.
- **diagram.json**: Arquivo que contém a estrutura da simulação do WOKWI.
- **wokwi.toml**: Arquivo para definir o caminho do .elf e .uf2 usado para a simulação.
- **CMakeLists.txt**: Definição dos processos de compilação e requisitos necessários.
- **pico_sdk_import.cmake**: Arquivo com as configurações de importação do Pico SDK.

## Requisitos

- **Raspberry Pi Pico W**: Placa de desenvolvimento baseada no microcontrolador RP2040.
- **Teclado Matricial**: Um teclado matricial genérico 4x4 com teclas alfanuméricas.
- **Um led RGB**: Um led ou um conjunto de três leds que possam simular o funcionamento de um led RGB.
- **Buzzer**: Um buzzer para emissão de sons.
- **Compilador ARM GCC**: Necessário para compilar o código C para a arquitetura ARM Cortex-M0+ do Pico W.
- **Pico SDK**: SDK oficial para o Raspberry Pi Pico W, necessário para desenvolvimento e compilação.
- **WOWKI**: Biblioteca ou conjunto de ferramentas para simulação do hardware específico do projeto.

## Equipe
- **Hiago Moura**
- **Elmer Carvalho**
- **Ikaro Silva**
- **Ana Luisa**
- **Breno Fernandes**

## Vídeo demonstrativo 
<https://drive.google.com/file/d/1zR8qCuJtz5sHhGOcixcrWR7Z8XBkQjW_/view?usp=sharing>