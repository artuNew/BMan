#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSet>

#include "character.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Slots and signals for educational purposes here only
    // Used to communicate between objects
public slots:
    void close();

signals:

private:
    Ui::MainWindow *ui;
    QSize mWindowSize;
    Character mHero;

    QSet<Qt::Key> mKeys;

    virtual void paintEvent(QPaintEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);
    void render();
};

#endif // MAINWINDOW_H
