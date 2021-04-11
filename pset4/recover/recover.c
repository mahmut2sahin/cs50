#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *disk = fopen(argv[1], "r");
    if (disk == NULL)
    {
        printf("Counldn't open the file\n");
        return 2;
    }

    BYTE *buffer = malloc(512);
    char *filename = malloc(20);
    int i = -1;
    int a = 0;

    while (1)
    {
        if (fread(buffer, sizeof(BYTE), 512, disk) == 0)
        {
            break;
        }
        a++;

        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (i == -1)
            {
                i++;
                sprintf(filename, "%03d.jpg", i);
                FILE *image = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), 512, image);
                fclose(image);
            }
            else
            {
                i++;
                sprintf(filename, "%03d.jpg", i);
                FILE *image = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), 512, image);
                fclose(image);
            }
        }
        else
        {
            if (i == -1)
            {
            }
            else
            {
                FILE *image = fopen(filename, "a");
                fwrite(buffer, sizeof(BYTE), 512, image);
                fclose(image);
            }
        }
    }
    return 0;
}