#include "texture.h"
#include <iostream>
#include "../include/GLFW/glfw3.h"


namespace UB
{
#if 0
Texture::Texture() : width(0), height(0), nrChannels(0), data(nullptr)
{}
#endif


Texture::Texture(const char* const _pathToFile, const unsigned int formatType) : pathToFile(_pathToFile), width(0), height(0), nrChannels(0)
    {
        loadTextureFromFile(pathToFile, formatType);
    }


void Texture::loadTextureFromFile(const char* const pathToFile, const unsigned int formatType)
{
    data = stbi_load(pathToFile, &width, &height, &nrChannels, 0);

    stbi_set_flip_vertically_on_load(true);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, formatType, width, height, 0, formatType, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);
}





}
