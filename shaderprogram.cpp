#include "shaderprogram.h"

ShaderProgram::ShaderProgram(QString vertexFile, QString fragmentFile, QObject* parent)
    : QObject(parent),
      _vertexFile(vertexFile),
      _fragmentFile(fragmentFile),
      _program(nullptr)
{
}

ShaderProgram::~ShaderProgram()
{
    delete _program;
}

void ShaderProgram::create()
{
    reload();
}

void ShaderProgram::reload()
{
    QOpenGLShaderProgram* newProgram = new QOpenGLShaderProgram();
    newProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, _vertexFile);
    newProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, _fragmentFile);
    newProgram->link();

    if(newProgram->isLinked())
    {
        delete _program;
        _program = newProgram;
    }
    else
    {
        qDebug() << "Failed to create shader: " << _vertexFile << " | " << _fragmentFile;
    }
}

void ShaderProgram::bind()
{
    _program->bind();
}

void ShaderProgram::release()
{
    _program->release();
}
