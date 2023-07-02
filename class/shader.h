#ifndef UB_SHADER_H
#define UB_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../include/glad/glad.h"
#include "../include/glm/glm/glm.hpp"


namespace UB
{

enum Shader_Type {VERTEX, FRAGMENT, GEOMETRY};

class Shader
{
protected:
    unsigned int    typeShader;
    int             success;
    char            infoLog[512];
    char const*     shaderSrcPtr;
    std::string     shaderFilePath;
    std::string     shaderSrc;

public:

    Shader();
    Shader(const std::string& shaderFilePath, Shader_Type typeShaderIn);

    void loadCompileShaderFromFile(const std::string& shaderFilePath, Shader_Type typeShaderIn);

    void deleteShader(const Shader& shader);

    unsigned int getTypeShader() const;
};



class ShaderProgram : public Shader
{
protected:

    unsigned int shaderProgram;

public:
    //ShaderProgram();
    //ShaderProgram(Shader& vertex, Shader& fragment);

    void createProgram(const Shader& vertex, const Shader& fragment);

    unsigned int getID();

    void useProgram();

    void setInt(const std::string& name, const int value);

    void setVec3(const std::string& name, const glm::vec3 &value);

    void setVec3(const std::string& uniVar, float x, float y, float z);

    void setVec4(const std::string& uniVar, float x, float y, float z, float w);

    void setMat2(const std::string& uniVar, const glm::mat2 &mat);

    void setMat3(const std::string& uniVar, const glm::mat3 &mat);

    void setMat4(const std::string& uniVar, const glm::mat4 &mat);

    void setFloat(const std::string& uniVar, const float fVar);

};


}



#endif // UB_SHADER_H
