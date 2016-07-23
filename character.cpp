#include "character.h"

/*
 * Constructor
 */
Character::Character(QWidget *parent) :
    QWidget(parent)
  , mColor(Qt::black)
  , mPosition(200,200)
  , mSize(20,20)
  , mSpeed(3)
{
}

/*
 * Destructor
 */
Character::~Character()
{
}

/*
 * This changes character color
 */
void Character::changeColor()
{
    if(mColor == QColor(Qt::black))
        mColor = QColor(Qt::green);
    else if (mColor == QColor(Qt::green))
        mColor = QColor(Qt::red);
    else
        mColor = QColor(Qt::black);
}

/*
 * Key press event handler
 *
 * @param _keys multiple keys that are pressed
 *
 * @return none
 */
void Character::handleKeyPress(QSet<Qt::Key> _keys)
{
        if(_keys.contains(Qt::Key_Up))
            mPosition.ry() -= mSpeed;

        if(_keys.contains(Qt::Key_Down))
            mPosition.ry() += mSpeed;

        if(_keys.contains(Qt::Key_Left))
            mPosition.rx() -= mSpeed;

        if(_keys.contains(Qt::Key_Right))
            mPosition.rx() += mSpeed;

        if(_keys.contains(Qt::Key_Space))
            changeColor();

        if(_keys.contains(Qt::Key_Escape))
            emit exit();
}
