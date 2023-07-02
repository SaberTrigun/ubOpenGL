#ifndef UB_TEXTURE_H
#define UB_TEXTURE_H


#include "../stb_image/stb_image.h"

namespace UB
{


class Texture
{
private:
    int             width;
    int             height;
    int             nrChannels;
    char*           pathToFile;
    unsigned char*  data;
public:
    Texture();

    void loadTextureFromFile(char* pathToFile);
};



























}
#endif // UB_TEXTURE_H
