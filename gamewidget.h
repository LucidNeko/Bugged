#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_3_Core>

#include "time.h"

class GameWidget : public QOpenGLWidget, protected QOpenGLFunctions_4_3_Core
{
    Q_OBJECT

public:
    GameWidget(QWidget* parent = nullptr);
    ~GameWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    void update(const Time& time);
    void render(const Time& time);

    void cleanup();

private:
    Time _timeLastFrame;
};

#endif // GAMEWIDGET_H
