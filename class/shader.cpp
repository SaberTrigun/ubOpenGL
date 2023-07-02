#include "shader.h"


namespace UB
{

    Shader::Shader() : typeShader(0), success(0), shaderSrcPtr(nullptr)
    {}


    Shader::Shader(const std::string& shaderFilePath, Shader_Type typeShaderIn)
        { loadCompileShaderFromFile(shaderFilePath, typeShaderIn); }


    void Shader::loadCompileShaderFromFile(const std::string& shaderFilePath, Shader_Type typeShaderIn){
        switch(typeShaderIn)
        {
        case VERTEX:
            typeShader = glCreateShader(GL_VERTEX_SHADER);
            break;
        case FRAGMENT:
            typeShader = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        case GEOMETRY:
            typeShader = glCreateShader(GL_GEOMETRY_SHADER);
            break;
        }

        std::ifstream shaderStream(shaderFilePath, std::ios::in);

        if(shaderStream.is_open()){
            std::stringstream sstr;
            sstr << shaderStream.rdbuf();
            shaderSrc = sstr.str();
            shaderStream.close();
        }

        shaderSrcPtr = shaderSrc.c_str();
        glShaderSource(typeShader, 1, &shaderSrcPtr, NULL);
        glCompileShader(typeShader);
        glGetShaderiv(typeShader, GL_COMPILE_STATUS, &success);

        if(!success){
            glGetShaderInfoLog(typeShader, 512, NULL, infoLog);
            std::cout << "Error " << typeShaderIn << " compile..." << infoLog << std::endl;
        }
    }


    void Shader::deleteShader(const Shader& shader)
        { glDeleteShader(shader.typeShader) ;}


    unsigned int Shader::getTypeShader() const
        { return typeShader; }


    void ShaderProgram::createProgram(const Shader& vertex, const Shader& fragment){
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertex.getTypeShader());
        glAttachShader(shaderProgram, fragment.getTypeShader());
        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

        if(!success){
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "Error shaderProgram compile..." << infoLog << std::endl;
        }
    }


    unsigned int ShaderProgram::getID()
    {
        return shaderProgram;
    }


    void ShaderProgram::useProgram()
        { glUseProgram(shaderProgram); }


    void ShaderProgram::setInt(const std::string& name, const int value){
        glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
    }


    void ShaderProgram::setVec3(const std::string& name, const glm::vec3 &value){
        glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]);
    }


    void ShaderProgram::setVec3(const std::string& uniVar, float x, float y, float z){
        glUniform3f(glGetUniformLocation(shaderProgram, uniVar.c_str()), x, y, z);
    }
    void ShaderProgram::setVec4(const std::string& uniVar, float x, float y, float z, float w){
        glUniform4f(glGetUniformLocation(shaderProgram, uniVar.c_str()), x, y, z, w);
    }


    void ShaderProgram::setMat2(const std::string& uniVar, const glm::mat2 &mat){
        glUniformMatrix2fv(glGetUniformLocation(shaderProgram, uniVar.c_str()), 1, GL_FALSE, &mat[0][0]);
    }


    void ShaderProgram::setMat3(const std::string& uniVar, const glm::mat3 &mat){
        glUniformMatrix2fv(glGetUniformLocation(shaderProgram, uniVar.c_str()), 1, GL_FALSE, &mat[0][0]);
    }


    void ShaderProgram::setMat4(const std::string& uniVar, const glm::mat4 &mat){
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, uniVar.c_str()), 1, GL_FALSE, &mat[0][0]);
    }


    void ShaderProgram::setFloat(const std::string& uniVar, const float fVar){
        glUniform1f(glGetUniformLocation(shaderProgram, uniVar.c_str()), fVar);
    }



}
