// start.cpp
#include "start.h"
#include "screen.h"

BITMAP *buffer;

void start_program()
{
    srand((int)time(0)); // randomize seed
    allegro_init();
    install_keyboard();
    install_timer();
    set_color_depth(32);
    //set_gfx_mode(GFX_AUTODETECT_WINDOWED,VX,VY,0,0);
    set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 1440, 900, 0, 0);
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    //buffer = create_bitmap(VX, VY);
    clear_keybuf();
}


int** create_matrix()
{
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == nullptr)
    {
        std::cerr << "Error al asignar memoria para las filas\n";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == nullptr)
        {
            std::cerr << "Error al asignar memoria para las columnas\n";
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

void initialize_matrix(int** matrix)
{
    int temp[10][6] =
    {
        {0, 5, 10, 16, 21, 0},
        {0, 8, 11, 13, 21, 1},
        {0, 7, 12, 14, 21, 2},
        {0, 3, 13, 18, 21, 3},
        {0, 4, 14, 17, 21, 4},
        {0, 3, 15, 18, 21, 5},
        {0, 1, 16, 20, 21, 6},
        {0, 8, 17, 13, 21, 7},
        {0, 2, 18, 19, 21, 8},
        {0, 5, 19, 16, 21, 9}
    };

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}

void free_matrix(int** matrix)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
void TimeControl(int startTime)
{
    // Control de tiempo
    int elapsedTime = clock() - startTime;
    if (elapsedTime < FRAME_TIME)
        rest(FRAME_TIME - elapsedTime);
}

void menu()
{
 ShowIntro();


}
