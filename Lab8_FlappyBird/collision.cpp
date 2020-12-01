/*
 * Author:		Étienne Ménard
 * Date:		29/11/2020
 * File:		collision.cpp
 * Description:	Défénition des méthodes de collision
 */

#include "collision.h"

 //où le sprite 1 sera le bird et le sprite 2 soit un land ou un pipe
bool collision::checkSpriteCollision(Sprite sprite1, Sprite sprite2) const
{
    Rect<float> rect1 = sprite1.getGlobalBounds(); //on crée un rectangle des
    Rect<float> rect2 = sprite2.getGlobalBounds(); //dimensions des sprites reçus

    return rect1.intersects(rect2); //true, ils entrent en contact, false sinon
}

// check les collision mais avec un scale qu'on peut modifier
bool collision::checkSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2) const
{
    sprite1.setScale(scale1, scale1);
    sprite2.setScale(scale2, scale2);

    Rect<float> rect1 = sprite1.getGlobalBounds();
    Rect<float> rect2 = sprite2.getGlobalBounds();

    return rect1.intersects(rect2);
}