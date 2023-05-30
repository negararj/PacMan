#include "gameobject.h"
#include "qpixmap.h"

GameObject::GameObject(ObjectType t, QPixmap pixmap) : QGraphicsPixmapItem(pixmap)
{
    type = t;
}

