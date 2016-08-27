#include "gamewidget.h"

#include "input.h"

#include <QDebug>

GameWidget::GameWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setFixedSize(640, 960);
    adjustSize();
}

GameWidget::~GameWidget()
{
    cleanup();
}

void GameWidget::initializeGL()
{
    initializeOpenGLFunctions();

    connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &GameWidget::cleanup);

    Input::create();
    installEventFilter(Input::instance());

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void GameWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GameWidget::paintGL()
{
    Time time = { 1.0f / 60.0f };

    update(time);
    render(time);

    QOpenGLWidget::update();
}

void GameWidget::update(const Time &time)
{

}

void GameWidget::render(const Time &time)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


}

void GameWidget::cleanup()
{

}
