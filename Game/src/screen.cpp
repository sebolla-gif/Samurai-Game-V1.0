#include "screen.h"
#include "start.h"

BITMAP *mount;
BITMAP *moon;
BITMAP *light;
BITMAP *sea;
BITMAP *cloud;
BITMAP *title;
BITMAP *press;

void load_resources()
{
    mount = load_bitmap("Mount.bmp", nullptr);

    moon = load_bitmap("moon.bmp", nullptr);

    sea = load_bitmap("sea.bmp", nullptr);

    light = load_bitmap("light.bmp", nullptr);

    cloud = load_bitmap("cloud.bmp", nullptr);

    title = load_bitmap("samuraiV1.0.bmp", nullptr);

    press = load_bitmap("press.bmp", nullptr);

    if (!sea || !light || !moon || !title || !press || !cloud || !buffer)
    {
        allegro_message("Error loading bitmaps");
        return;
    }

}

void update_screen(BITMAP* buffer)
{
    if (!buffer || !screen)
    {
        allegro_message("Buffer or screen is NULL");
        return;
    }

    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    vsync(); // Sincronización de pantalla
/*
    // Mostrar en pantalla
    blit(buffer, screen, 0, 0, 0, 0, VX, VY);
    vsync(); // Sincronización de pantalla
    blit(buffer, screen, 0, 0, 0, 0, VX, VY);
    */
}

void ShowMap()
{
    if (!mount || !buffer)
    {
        allegro_message("Mount or buffer is NULL");
        return;
    }
    stretch_blit(mount, buffer, 0, 0, mount->w, mount->h, 0, 0, SCREEN_W, SCREEN_H);
    //masked_blit(mount, buffer, 0, 0, 0, 0, VX, VY);
}

void ShowIntro(){
    int water_x = 0;
    float wave_phase = 0.0f;

    while (true)
    {
        int startTime = clock();

        int water_y = WAVE_AMPLITUDE * std::sin(wave_phase);

        masked_stretch_blit(sea, buffer, 0, 0, sea->w, sea->h, water_x, water_y, SCREEN_W, SCREEN_H);

        masked_stretch_blit(sea, buffer, 0, 0, sea->w, sea->h, water_x - sea->w, water_y, SCREEN_W, SCREEN_H);

        masked_stretch_blit(light, buffer, 0, 0, light->w, light->h, 0, 0, SCREEN_W, SCREEN_H);

        masked_stretch_blit(moon, buffer, 0, 0, moon->w, moon->h, 0, 0, SCREEN_W, SCREEN_H);

        masked_blit(press, buffer, 0, 0, 700, 480, press->w, press->h);

        masked_stretch_blit(cloud, buffer, 0, 0, cloud->w, cloud->h, 0, 0, SCREEN_W, SCREEN_H);

        masked_blit(title, buffer, 0, 0, 100, 100, title->w, title->h);

        if (!sea || !light || !moon || !title || !press || !cloud || !buffer)
        {
            allegro_message("Error bitmaps is NULL");
            return;
        }
        water_x += WATER_SPEED;
        if (water_x >= sea->w)
        {
            water_x = 0;
        }

        wave_phase += WAVE_FREQUENCY;

        update_screen(buffer);

        TimeControl(startTime);

        if (key[KEY_ENTER])
            break;
    }
}

void destroy_all_maps()
{

    destroy_bitmap(mount);
    destroy_bitmap(moon);
    destroy_bitmap(light);
    destroy_bitmap(sea);
    destroy_bitmap(cloud);
    destroy_bitmap(title);
    destroy_bitmap(press);

}

