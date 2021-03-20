#include <mlx.h>

int     main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1024, 512, "Cub3D");
    for (int i = 100; i <= 300; i++)
    {
        for (int j = 100; j <= 300; j++)
            mlx_pixel_put(mlx, mlx_win, i, j, 0x00FFFFFF);
    }
    mlx_loop(mlx);
}
