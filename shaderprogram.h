#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <QOpenGLShaderProgram>

class ShaderProgram : public QObject
{
    Q_OBJECT

public:
    ShaderProgram(QString vertexFile, QString fragmentFile, QObject* parent = nullptr);
    ~ShaderProgram();

    void create();

    void bind();
    void release();

    QOpenGLShaderProgram* program() { return _program; }

public slots:
    void reload();

private:
    QString _vertexFile;
    QString _fragmentFile;
    QOpenGLShaderProgram* _program;
};

#endif // SHADERPROGRAM_H
