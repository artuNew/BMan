#include <QDebug>
#include <QPainter>

#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * Constructor
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mWindowSize(800, 600),
    mKeys()
{
    ui->setupUi(this);
    this->resize(mWindowSize);
    this->setWindowTitle("Bomberman");

    // Connect signal with slot, ESC hooked up to exit
    // educational purposes only, here the same could be done simpler
    this->connect(&mHero, SIGNAL(exit()),
                  this, SLOT(close()));

    // Print out for debugging
    qDebug() << "App started";
}

/*
 * Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Paint event handler
 */
void MainWindow::paintEvent(QPaintEvent *e)
{
    render();
}

/*
 * This renders the world
 */
void MainWindow::render()
{
    QPainter p(this);

    // Background
    p.setBrush(Qt::blue);
    p.drawRect(QRect(QPoint(0,0), mWindowSize));

    // Hero
    p.setBrush(QBrush(mHero.getColor()));
    p.drawEllipse(
                mHero.getPosition(),
                mHero.getSize().width(),
                mHero.getSize().height()
                );

}

/*
 * Key press event handler
 */
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    mKeys.insert(static_cast<Qt::Key>(e->key()));
    mHero.handleKeyPress(mKeys);

    // TODO: AD: why is it stuttering here while pressing arrow and updating?
    // I don't know - AD
    this->update();
}


/*
 * Key release event handler
 */
void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    mKeys.remove(static_cast<Qt::Key>(e->key()));

    qDebug() << e->key() << " key has been released";
}

// slots
/*
 * Closes the app
 */
void MainWindow::close()
{
    qDebug() << "Bye!"; // Co to znaczy?

    // Exit with return code 0 (success)
    QApplication::quit();
}
