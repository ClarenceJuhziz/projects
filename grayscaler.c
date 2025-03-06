#include <stdio.h>
#include <math.h>

int main()
{
    FILE *pic = fopen("myson.bmp", "rb");

    int exponent = 0;
    int width = 0;
    int height = 0;
    int color = 0;
    float sum = 0;

    fseek(pic, 0, SEEK_END);
    unsigned char buff[ftell(pic)]; // get image size THEN set a buffer with said size
    fseek(pic, 0, SEEK_SET);

    fread(buff, sizeof(buff), 1, pic);


    for(int i = 18; i < 22; i++) // function that gets width of the image
    {
        width += buff[i]*pow(16, exponent);
        exponent += 2;
    }

    exponent= 0;

    for(int i = 22; i < 26; i++) // function that gets height of the image
    {
        height += buff[i]*pow(16, exponent);
        exponent += 2;
    }

    for(int i = 0; i < 3 * (width * height); i++)
    {
        fseek(pic, 138 + i, 0);

        sum = buff[ftell(pic)] + buff[ftell(pic) + 1] + buff[ftell(pic) + 2]; // sum of all rgb values

        buff[ftell(pic)] = sum / 3;
        buff[ftell(pic) + 1] = sum / 3;
        buff[ftell(pic) + 2 ] = sum / 3;
    }

    FILE *picout = fopen("output.bmp", "w");

    fwrite(buff, 1, sizeof(buff), picout);

    fclose(pic);
    fclose(picout);

    return 0;
}
