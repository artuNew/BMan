#ifndef CHARACTER_H
#define CHARACTER_H

#include <QColor>
#include <QPoint>
#include <QSize>
#include <QKeyEvent>
#include <QWidget>

class Character : public QWidget
{
    Q_OBJECT

public:
    Character(QWidget *parent = 0);
    virtual ~Character();

    // methods
    void changeColor();
    void handleKeyPress(QSet<Qt::Key> _keys);

    // getters
    QColor getColor() { return (mColor); }
    QPoint getPosition() {return (mPosition); }
    QSize getSize() { return (mSize); }
    qint16 getSpeed() { return (mSpeed); }

public slots:

signals:
    void exit();

protected:

    // TODO: AD figure out why this ["is"? - AD] not working here
    // but only in QMainWindow, keyboard key press event not received
    // here despite that it is QWidget class

    // methods
//    virtual void keyPressEvent(QKeyEvent *e);

    // Ty pisałeś te komentarze? Dlaczego po angielsku? Bo taki jest zwyczaj? - AD
private:
    // data
    QColor mColor;
    QPoint mPosition;
    QSize mSize;
    qint16 mSpeed;
};

#endif // CHARACTER_H
