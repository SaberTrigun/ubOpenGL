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
    unsigned char*  data;
    std::string     pathToFile;

public:

    Texture();
    Texture(int _width, int _height, int _nrChannels, std::string _pathToFile, unsigned char* _data);

    void loadTextureFromFile(char* pathToFile);
};



























}
#endif // UB_TEXTURE_H
