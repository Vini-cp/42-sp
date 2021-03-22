#include "../include/cub.h"

static  void    put_map(px, py, char *str)
{
    int i;
    int j;

    i = px;
    j = pj;
    while (i < px + 6)
    {
        while (j < py + 6)
        {
            mlx_pixel_put(g_mlx, g_win, i, j, str);
            j++;
        }
        i++;
    }
}

void    draw_map()
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 8)
    {
        while (j < 8)
        {
            if (map[i][j] == 1)
                put_map((i * 8) + 1, (j * 8) + 1, "0x00FFFFFF\0");
            else
                put_map((i * 8) + 1, (j * 8) + 1, "0x00000000\0");
            j++;
        }
    }
}
