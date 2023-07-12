#include "texture.h"
#include <iostream>
#include "../include/GLFW/glfw3.h"


namespace UB
{
#if 0
Texture::Texture() : width(0), height(0), nrChannels(0), data(nullptr)
{}
#endif


Texture::Texture(const char* const _pathToFile) : pathToFile(_pathToFile), width(0), height(0), nrChannels(0)
    {
        loadTextureFromFile(pathToFile);
    }


void Texture::loadTextureFromFile(const char* const pathToFile)
{
    data = stbi_load(pathToFile, &width, &height, &nrChannels, 0);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);
}





}
