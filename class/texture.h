#ifndef UB_TEXTURE_H
#define UB_TEXTURE_H


#include "../stb_image/stb_image.h"
#include "../include/glad/glad.h"


namespace UB
{


class Texture
{
private:

    int             width;
    int             height;
    int             nrChannels;
    unsigned char*  data;
    const char* const pathToFile;

public:

    //Texture();
    Texture(const char* const pathToFile, const unsigned int formatType);

    void loadTextureFromFile(const char* const  pathToFile, const unsigned int formatType);

};










}
#endif // UB_TEXTURE_H
