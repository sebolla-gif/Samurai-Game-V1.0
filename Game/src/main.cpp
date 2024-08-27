/*
 *  Samurai Game V1.0
 *
 *  Autor: Sebastian Vaccaro
 *  Año: 2024
 *
 *  Este programa crea un juego 2D en C++ usando Allegro.
 *  Permite manejar gráficos, personajes y disparos, con estados y movimientos definidos.
 *  Renderiza imágenes BMP con transparencia, muestra el juego en pantalla completa
 *  y sincroniza verticalmente.
 */

#include "start.h"
#include "map.h"
#include "characters.h"
#include "shot.h"
#include "screen.h"

// Programa principal del juego
int main(void)
{
    float GRAVITY = 9;
    // Inicializa el programa y crea la matriz del jugador
    start_program();
    int** matrix_player_1 = create_matrix();
    initialize_matrix(matrix_player_1);

    // Crea el personaje del jugador
    Character player_1("player1.bmp", matrix_player_1, 0, VY - 128, 128, 128, 10, 10);

    // Carga recursos y muestra el menú
    load_resources();
    menu();

    // Actualiza la pantalla
    update_screen(buffer);

    // Bucle principal del juego
    while (true)
    {
        int startTime = clock(); // Inicio del clock

        // Muestra el mapa y actualiza la lógica del jugador
        ShowMap();
        player_1.play();
        player_1.update(GRAVITY);

        // Actualiza la pantalla
        update_screen(buffer);
        TimeControl(startTime);

        // Verifica si se ha presionado la tecla ESC para salir del juego
        if (key[KEY_ESC])
            break;
    }

    // Liberar recursos
    free_matrix(matrix_player_1);
    destroy_bitmap(player_1.player);
    destroy_bitmap(buffer);
    player_1.components.clear();
    destroy_all_maps();
    allegro_exit();
    player_1.~Character();
    return 0;
}

END_OF_MAIN();

