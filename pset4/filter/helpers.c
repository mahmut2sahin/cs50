#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp;
            tmp.rgbtBlue = image[i][j].rgbtBlue;
            tmp.rgbtGreen = image[i][j].rgbtGreen;
            tmp.rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][(width - 1) - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][(width - 1) - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][(width - 1) - j].rgbtRed;
            image[i][(width - 1) - j].rgbtBlue = tmp.rgbtBlue;
            image[i][(width - 1) - j].rgbtGreen = tmp.rgbtGreen;
            image[i][(width - 1) - j].rgbtRed = tmp.rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                tmp[i][j].rgbtRed = round((image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed +
                                           image[i][j].rgbtRed) / 4.0);
                tmp[i][j].rgbtGreen = round((image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen +
                                             image[i][j].rgbtGreen) / 4.0);
                tmp[i][j].rgbtBlue = round((image[i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue +
                                            image[i][j].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j == width - 1)
            {
                tmp[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                            image[i][j].rgbtBlue) / 4.0);
                tmp[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                             image[i][j].rgbtGreen) / 4.0);
                tmp[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                           image[i][j].rgbtRed) / 4.0);
            }
            else if (i == height - 1 && j == 0)
            {
                tmp[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                            image[i][j].rgbtBlue) / 4.0);
                tmp[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                             image[i][j].rgbtGreen) / 4.0);
                tmp[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                           image[i][j].rgbtRed) / 4.0);
            }
            else if (i == height - 1 && j == width - 1)
            {
                tmp[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                                            image[i][j].rgbtBlue) / 4.0);
                tmp[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                                             image[i][j].rgbtGreen) / 4.0);
                tmp[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed +
                                           image[i][j].rgbtRed) / 4.0);
            }
            else if (i == 0)
            {
                tmp[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue +
                                            image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue) / 6.0);
                tmp[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen +
                                             image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen) / 6.0);
                tmp[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed +
                                           image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed) / 6.0);
            }
            else if (j == 0)
            {
                tmp[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue +
                                            image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue) / 6.0);
                tmp[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen +
                                             image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen) / 6.0);
                tmp[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed +
                                           image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed) / 6.0);
            }
            else if (i == height - 1)
            {
                tmp[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                                            image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j].rgbtBlue) / 6.0);
                tmp[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                             image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j].rgbtGreen) / 6.0);
                tmp[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                                           image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i][j].rgbtRed) / 6.0);
            }
            else if (j == width - 1)
            {
                tmp[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                                            image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue) / 6.0);
                tmp[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen +
                                             image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen) / 6.0);
                tmp[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed +
                                           image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed) / 6.0);
            }
            else
            {
                tmp[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                            image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                            image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue) / 9.0);
                tmp[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                             image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                             image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen) / 9.0);
                tmp[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                           image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                           image[i][j - 1].rgbtRed + image[i][j].rgbtRed) / 9.0);
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        int rgbtBlue;
        int rgbtGreen;
        int rgbtRed;
    }
    gmatrix;

    gmatrix tmpgx[height][width];
    gmatrix tmpgy[height][width];
    gmatrix tmpg[height][width];

    int gx[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
    int gy[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                tmpgx[i][j].rgbtBlue = image[i][j].rgbtBlue * gx[1][1] + image[i][j + 1].rgbtBlue * gx[1][2] +
                                       image[i + 1][j].rgbtBlue * gx[2][1] + image[i + 1][j + 1].rgbtBlue * gx[2][2];

                tmpgx[i][j].rgbtGreen = image[i][j].rgbtGreen * gx[1][1] + image[i][j + 1].rgbtGreen * gx[1][2] +
                                        image[i + 1][j].rgbtGreen * gx[2][1] + image[i + 1][j + 1].rgbtGreen * gx[2][2];

                tmpgx[i][j].rgbtRed = image[i][j].rgbtRed * gx[1][1] + image[i][j + 1].rgbtRed * gx[1][2] +
                                      image[i + 1][j].rgbtRed * gx[2][1] + image[i + 1][j + 1].rgbtRed * gx[2][2];

                tmpgy[i][j].rgbtBlue = image[i][j].rgbtBlue * gy[1][1] + image[i][j + 1].rgbtBlue * gy[1][2] +
                                       image[i + 1][j].rgbtBlue * gy[2][1] + image[i + 1][j + 1].rgbtBlue * gy[2][2];

                tmpgy[i][j].rgbtGreen = image[i][j].rgbtGreen * gy[1][1] + image[i][j + 1].rgbtGreen * gy[1][2] +
                                        image[i + 1][j].rgbtGreen * gy[2][1] + image[i + 1][j + 1].rgbtGreen * gy[2][2];

                tmpgy[i][j].rgbtRed = image[i][j].rgbtRed * gy[1][1] + image[i][j + 1].rgbtRed * gy[1][2] +
                                      image[i + 1][j].rgbtRed * gy[2][1] + image[i + 1][j + 1].rgbtRed * gy[2][2];
            }
            else if (i == 0 && j == width - 1)
            {
                tmpgx[i][j].rgbtBlue = image[i][j - 1].rgbtBlue * gx[1][0] + image[i][j].rgbtBlue * gx[1][1] +
                                       image[i + 1][j - 1].rgbtBlue * gx[2][0] + image[i + 1][j].rgbtBlue * gx[2][1];

                tmpgx[i][j].rgbtGreen = image[i][j - 1].rgbtGreen * gx[1][0] + image[i][j].rgbtGreen * gx[1][1] +
                                        image[i + 1][j - 1].rgbtGreen * gx[2][0] + image[i + 1][j].rgbtGreen * gx[2][1];

                tmpgx[i][j].rgbtRed = image[i][j - 1].rgbtRed * gx[1][0] + image[i][j].rgbtRed * gx[1][1] +
                                      image[i + 1][j - 1].rgbtRed * gx[2][0] + image[i + 1][j].rgbtRed * gx[2][1];

                tmpgy[i][j].rgbtBlue = image[i][j - 1].rgbtBlue * gy[1][0] + image[i][j].rgbtBlue * gy[1][1] +
                                       image[i + 1][j - 1].rgbtBlue * gy[2][0] + image[i + 1][j].rgbtBlue * gy[2][1];

                tmpgy[i][j].rgbtGreen = image[i][j - 1].rgbtGreen * gy[1][0] + image[i][j].rgbtGreen * gy[1][1] +
                                        image[i + 1][j - 1].rgbtGreen * gy[2][0] + image[i + 1][j].rgbtGreen * gy[2][1];

                tmpgy[i][j].rgbtRed = image[i][j - 1].rgbtRed * gy[1][0] + image[i][j].rgbtRed * gy[1][1] +
                                      image[i + 1][j - 1].rgbtRed * gy[2][0] + image[i + 1][j].rgbtRed * gy[2][1];
            }
            else if (i == height - 1 && j == 0)
            {
                tmpgx[i][j].rgbtBlue = image[i - 1][j].rgbtBlue * gx[0][1] + image[i - 1][j + 1].rgbtBlue * gx[0][2] +
                                       image[i][j].rgbtBlue * gx[1][1] + image[i][j + 1].rgbtBlue * gx[1][2];

                tmpgx[i][j].rgbtGreen = image[i - 1][j].rgbtGreen * gx[0][1] + image[i - 1][j + 1].rgbtGreen * gx[0][2] +
                                        image[i][j].rgbtGreen * gx[1][1] + image[i][j + 1].rgbtGreen * gx[1][2];

                tmpgx[i][j].rgbtRed = image[i - 1][j].rgbtRed * gx[0][1] + image[i - 1][j + 1].rgbtRed * gx[0][2] +
                                      image[i][j].rgbtRed * gx[1][1] + image[i][j + 1].rgbtRed * gx[1][2];

                tmpgy[i][j].rgbtBlue = image[i - 1][j].rgbtBlue * gy[0][1] + image[i - 1][j + 1].rgbtBlue * gy[0][2] +
                                       image[i][j].rgbtBlue * gy[1][1] + image[i][j + 1].rgbtBlue * gy[1][2];

                tmpgy[i][j].rgbtGreen = image[i - 1][j].rgbtGreen * gy[0][1] + image[i - 1][j + 1].rgbtGreen * gy[0][2] +
                                        image[i][j].rgbtGreen * gy[1][1] + image[i][j + 1].rgbtGreen * gy[1][2];

                tmpgy[i][j].rgbtRed = image[i - 1][j].rgbtRed * gy[0][1] + image[i - 1][j + 1].rgbtRed * gy[0][2] +
                                      image[i][j].rgbtRed * gy[1][1] + image[i][j + 1].rgbtRed * gy[1][2];
            }
            else if (i == height - 1 && j == width - 1)
            {
                tmpgx[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue * gx[0][0] + image[i - 1][j].rgbtBlue * gx[0][1] +
                                       image[i][j - 1].rgbtBlue * gx[1][0] + image[i][j].rgbtBlue * gx[1][1];

                tmpgx[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen * gx[0][0] + image[i - 1][j].rgbtGreen * gx[0][1] +
                                        image[i][j - 1].rgbtGreen * gx[1][0] + image[i][j].rgbtGreen * gx[1][1];

                tmpgx[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed * gx[0][0] + image[i - 1][j].rgbtRed * gx[0][1] +
                                      image[i][j - 1].rgbtRed * gx[1][0] + image[i][j].rgbtRed * gx[1][1];

                tmpgy[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue * gy[0][0] + image[i - 1][j].rgbtBlue * gy[0][1] +
                                       image[i][j - 1].rgbtBlue * gy[1][0] + image[i][j].rgbtBlue * gy[1][1];

                tmpgy[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen * gy[0][0] + image[i - 1][j].rgbtGreen * gy[0][1] +
                                        image[i][j - 1].rgbtGreen * gy[1][0] + image[i][j].rgbtGreen * gy[1][1];

                tmpgy[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed * gy[0][0] + image[i - 1][j].rgbtRed * gy[0][1] +
                                      image[i][j - 1].rgbtRed * gy[1][0] + image[i][j].rgbtRed * gy[1][1];
            }
            else if (i == 0)
            {
                tmpgx[i][j].rgbtBlue = image[i][j - 1].rgbtBlue * gx[1][0] + image[i][j].rgbtBlue * gx[1][1] +
                                       image[i][j + 1].rgbtBlue * gx[1][2] + image[i + 1][j - 1].rgbtBlue * gx[2][0] + image[i + 1][j].rgbtBlue * gx[2][1] +
                                       image[i + 1][j + 1].rgbtBlue * gx[2][2];

                tmpgx[i][j].rgbtGreen = image[i][j - 1].rgbtGreen * gx[1][0] + image[i][j].rgbtGreen * gx[1][1] +
                                        image[i][j + 1].rgbtGreen * gx[1][2] + image[i + 1][j - 1].rgbtGreen * gx[2][0] + image[i + 1][j].rgbtGreen * gx[2][1] +
                                        image[i + 1][j + 1].rgbtGreen * gx[2][2];

                tmpgx[i][j].rgbtRed = image[i][j - 1].rgbtRed * gx[1][0] + image[i][j].rgbtRed * gx[1][1] +
                                      image[i][j + 1].rgbtRed * gx[1][2] + image[i + 1][j - 1].rgbtRed * gx[2][0] + image[i + 1][j].rgbtRed * gx[2][1] +
                                      image[i + 1][j + 1].rgbtRed * gx[2][2];

                tmpgy[i][j].rgbtBlue = image[i][j - 1].rgbtBlue * gy[1][0] + image[i][j].rgbtBlue * gy[1][1] +
                                       image[i][j + 1].rgbtBlue * gy[1][2] + image[i + 1][j - 1].rgbtBlue * gy[2][0] + image[i + 1][j].rgbtBlue * gy[2][1] +
                                       image[i + 1][j + 1].rgbtBlue * gy[2][2];

                tmpgy[i][j].rgbtGreen = image[i][j - 1].rgbtGreen * gy[1][0] + image[i][j].rgbtGreen * gy[1][1] +
                                        image[i][j + 1].rgbtGreen * gy[1][2] + image[i + 1][j - 1].rgbtGreen * gy[2][0] + image[i + 1][j].rgbtGreen * gy[2][1] +
                                        image[i + 1][j + 1].rgbtGreen * gy[2][2];

                tmpgy[i][j].rgbtRed = image[i][j - 1].rgbtRed * gy[1][0] + image[i][j].rgbtRed * gy[1][1] +
                                      image[i][j + 1].rgbtRed * gy[1][2] + image[i + 1][j - 1].rgbtRed * gy[2][0] + image[i + 1][j].rgbtRed * gy[2][1] +
                                      image[i + 1][j + 1].rgbtRed * gy[2][2];
            }
            else if (j == 0)
            {
                tmpgx[i][j].rgbtBlue = image[i - 1][j].rgbtBlue * gx[0][1] +
                                       image[i - 1][j + 1].rgbtBlue * gx[0][2] + image[i][j].rgbtBlue * gx[1][1] +
                                       image[i][j + 1].rgbtBlue * gx[1][2] + image[i + 1][j].rgbtBlue * gx[2][1] +
                                       image[i + 1][j + 1].rgbtBlue * gx[2][2];

                tmpgx[i][j].rgbtGreen = image[i - 1][j].rgbtGreen * gx[0][1] +
                                        image[i - 1][j + 1].rgbtGreen * gx[0][2] + image[i][j].rgbtGreen * gx[1][1] +
                                        image[i][j + 1].rgbtGreen * gx[1][2] + image[i + 1][j].rgbtGreen * gx[2][1] +
                                        image[i + 1][j + 1].rgbtGreen * gx[2][2];

                tmpgx[i][j].rgbtRed = image[i - 1][j].rgbtRed * gx[0][1] +
                                      image[i - 1][j + 1].rgbtRed * gx[0][2] + image[i][j].rgbtRed * gx[1][1] +
                                      image[i][j + 1].rgbtRed * gx[1][2] + image[i + 1][j].rgbtRed * gx[2][1] +
                                      image[i + 1][j + 1].rgbtRed * gx[2][2];

                tmpgy[i][j].rgbtBlue = image[i - 1][j].rgbtBlue * gy[0][1] +
                                       image[i - 1][j + 1].rgbtBlue * gy[0][2] + image[i][j].rgbtBlue * gy[1][1] +
                                       image[i][j + 1].rgbtBlue * gy[1][2] + image[i + 1][j].rgbtBlue * gy[2][1] +
                                       image[i + 1][j + 1].rgbtBlue * gy[2][2];

                tmpgy[i][j].rgbtGreen = image[i - 1][j].rgbtGreen * gy[0][1] +
                                        image[i - 1][j + 1].rgbtGreen * gy[0][2] + image[i][j].rgbtGreen * gy[1][1] +
                                        image[i][j + 1].rgbtGreen * gy[1][2] + image[i + 1][j].rgbtGreen * gy[2][1] +
                                        image[i + 1][j + 1].rgbtGreen * gy[2][2];

                tmpgy[i][j].rgbtRed = image[i - 1][j].rgbtRed * gy[0][1] +
                                      image[i - 1][j + 1].rgbtRed * gy[0][2] + image[i][j].rgbtRed * gy[1][1] +
                                      image[i][j + 1].rgbtRed * gy[1][2] + image[i + 1][j].rgbtRed * gy[2][1] +
                                      image[i + 1][j + 1].rgbtRed * gy[2][2];
            }
            else if (i == height - 1)
            {
                tmpgx[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue * gx[0][0] + image[i - 1][j].rgbtBlue * gx[0][1] +
                                       image[i - 1][j + 1].rgbtBlue * gx[0][2] + image[i][j - 1].rgbtBlue * gx[1][0] + image[i][j].rgbtBlue * gx[1][1] +
                                       image[i][j + 1].rgbtBlue * gx[1][2];

                tmpgx[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen * gx[0][0] + image[i - 1][j].rgbtGreen * gx[0][1] +
                                        image[i - 1][j + 1].rgbtGreen * gx[0][2] + image[i][j - 1].rgbtGreen * gx[1][0] + image[i][j].rgbtGreen * gx[1][1] +
                                        image[i][j + 1].rgbtGreen * gx[1][2];

                tmpgx[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed * gx[0][0] + image[i - 1][j].rgbtRed * gx[0][1] +
                                      image[i - 1][j + 1].rgbtRed * gx[0][2] + image[i][j - 1].rgbtRed * gx[1][0] + image[i][j].rgbtRed * gx[1][1] +
                                      image[i][j + 1].rgbtRed * gx[1][2];

                tmpgy[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue * gy[0][0] + image[i - 1][j].rgbtBlue * gy[0][1] +
                                       image[i - 1][j + 1].rgbtBlue * gy[0][2] + image[i][j - 1].rgbtBlue * gy[1][0] + image[i][j].rgbtBlue * gy[1][1] +
                                       image[i][j + 1].rgbtBlue * gy[1][2];

                tmpgy[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen * gy[0][0] + image[i - 1][j].rgbtGreen * gy[0][1] +
                                        image[i - 1][j + 1].rgbtGreen * gy[0][2] + image[i][j - 1].rgbtGreen * gy[1][0] + image[i][j].rgbtGreen * gy[1][1] +
                                        image[i][j + 1].rgbtGreen * gy[1][2];

                tmpgy[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed * gy[0][0] + image[i - 1][j].rgbtRed * gy[0][1] +
                                      image[i - 1][j + 1].rgbtRed * gy[0][2] + image[i][j - 1].rgbtRed * gy[1][0] + image[i][j].rgbtRed * gy[1][1] +
                                      image[i][j + 1].rgbtRed * gy[1][2];
            }
            else if (j == width - 1)
            {
                tmpgx[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue * gx[0][0] + image[i - 1][j].rgbtBlue * gx[0][1] +
                                       image[i][j - 1].rgbtBlue * gx[1][0] + image[i][j].rgbtBlue * gx[1][1] +
                                       image[i + 1][j - 1].rgbtBlue * gx[2][0] + image[i + 1][j].rgbtBlue * gx[2][1];

                tmpgx[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen * gx[0][0] + image[i - 1][j].rgbtGreen * gx[0][1] +
                                        image[i][j - 1].rgbtGreen * gx[1][0] + image[i][j].rgbtGreen * gx[1][1] +
                                        image[i + 1][j - 1].rgbtGreen * gx[2][0] + image[i + 1][j].rgbtGreen * gx[2][1];

                tmpgx[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed * gx[0][0] + image[i - 1][j].rgbtRed * gx[0][1] +
                                      image[i][j - 1].rgbtRed * gx[1][0] + image[i][j].rgbtRed * gx[1][1] +
                                      image[i + 1][j - 1].rgbtRed * gx[2][0] + image[i + 1][j].rgbtRed * gx[2][1];

                tmpgy[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue * gy[0][0] + image[i - 1][j].rgbtBlue * gy[0][1] +
                                       image[i][j - 1].rgbtBlue * gy[1][0] + image[i][j].rgbtBlue * gy[1][1] +
                                       image[i + 1][j - 1].rgbtBlue * gy[2][0] + image[i + 1][j].rgbtBlue * gy[2][1];

                tmpgy[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen * gy[0][0] + image[i - 1][j].rgbtGreen * gy[0][1] +
                                        image[i][j - 1].rgbtGreen * gy[1][0] + image[i][j].rgbtGreen * gy[1][1] +
                                        image[i + 1][j - 1].rgbtGreen * gy[2][0] + image[i + 1][j].rgbtGreen * gy[2][1];

                tmpgy[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed * gy[0][0] + image[i - 1][j].rgbtRed * gy[0][1] +
                                      image[i][j - 1].rgbtRed * gy[1][0] + image[i][j].rgbtRed * gy[1][1] +
                                      image[i + 1][j - 1].rgbtRed * gy[2][0] + image[i + 1][j].rgbtRed * gy[2][1];
            }
            else
            {
                tmpgx[i][j].rgbtBlue = 0;
                tmpgx[i][j].rgbtGreen = 0;
                tmpgx[i][j].rgbtRed = 0;

                tmpgy[i][j].rgbtBlue = 0;
                tmpgy[i][j].rgbtGreen = 0;
                tmpgy[i][j].rgbtRed = 0;
                for (int k = -1; k < 2; k++)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        tmpgx[i][j].rgbtBlue += image[i + k][j + m].rgbtBlue * gx[k + 1][m + 1];
                        tmpgx[i][j].rgbtGreen += image[i + k][j + m].rgbtGreen * gx[k + 1][m + 1];
                        tmpgx[i][j].rgbtRed += image[i + k][j + m].rgbtRed * gx[k + 1][m + 1];

                        tmpgy[i][j].rgbtBlue += image[i + k][j + m].rgbtBlue * gy[k + 1][m + 1];
                        tmpgy[i][j].rgbtGreen += image[i + k][j + m].rgbtGreen * gy[k + 1][m + 1];
                        tmpgy[i][j].rgbtRed += image[i + k][j + m].rgbtRed * gy[k + 1][m + 1];
                    }
                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (round(sqrt((tmpgx[i][j].rgbtBlue) * (tmpgx[i][j].rgbtBlue) + (tmpgy[i][j].rgbtBlue) * (tmpgy[i][j].rgbtBlue))) > 255)
            {
                tmpg[i][j].rgbtBlue = 255;
            }
            else
            {
                tmpg[i][j].rgbtBlue = round(sqrt((tmpgx[i][j].rgbtBlue) * (tmpgx[i][j].rgbtBlue) + (tmpgy[i][j].rgbtBlue) *
                                                 (tmpgy[i][j].rgbtBlue)));
            }

            if (round(sqrt((tmpgx[i][j].rgbtGreen) * (tmpgx[i][j].rgbtGreen) + (tmpgy[i][j].rgbtGreen) * (tmpgy[i][j].rgbtGreen))) > 255)
            {
                tmpg[i][j].rgbtGreen = 255;
            }
            else
            {
                tmpg[i][j].rgbtGreen = round(sqrt((tmpgx[i][j].rgbtGreen) * (tmpgx[i][j].rgbtGreen) + (tmpgy[i][j].rgbtGreen) *
                                                  (tmpgy[i][j].rgbtGreen)));
            }

            if (round(sqrt((tmpgx[i][j].rgbtRed) * (tmpgx[i][j].rgbtRed) + (tmpgy[i][j].rgbtRed) * (tmpgy[i][j].rgbtRed))) > 255)
            {
                tmpg[i][j].rgbtRed = 255;
            }
            else
            {
                tmpg[i][j].rgbtRed = round(sqrt((tmpgx[i][j].rgbtRed) * (tmpgx[i][j].rgbtRed) + (tmpgy[i][j].rgbtRed) *
                                                (tmpgy[i][j].rgbtRed)));
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmpg[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmpg[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmpg[i][j].rgbtRed;
        }
    }
    return;
}
