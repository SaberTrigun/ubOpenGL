#include "texture.h"


namespace UB
{

Texture::Texture() : width(0), height(0), nrChannels(0), data(nullptr)
{}


Texture::Texture(int _width, int _height, int _nrChannels, std::string _pathToFile, unsigned char* _data) :
    , width(_width)
    , height(_height)
    , nrChannels(_nrChannels)
    , pathToFile(_pathToFile)
    , data(_data)
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
