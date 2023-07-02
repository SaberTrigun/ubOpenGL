#include "texture.h"


namespace UB
{

    Texture::Texture() : width(0), height(0), nrChannels(0), pathToFile(nullptr), data(nullptr)
    {}


    void Texture::loadTextureFromFile(char* pathToFile)
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
