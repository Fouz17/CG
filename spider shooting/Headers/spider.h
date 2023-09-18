#define SPIDER 1


#ifndef HEADER
#include "Headers.h"
#endif

class Spider
{
public:
    RGBApixmap pix[2];
    enum State
    {
        DIE
    } state;
    float pos_X, pos_Y;

public:
    bool isMoving;
    float spiderSpeed;
    float theta;
    float rateOfChange;

    Spider();
    Spider(Point2 pos);
    void changePosition(float dx, float dy);
    void die();
    void render();
};

Spider::Spider() {}

Spider::Spider(Point2 pos)
{
    isMoving = true;
    spiderSpeed = 2.0f; // Adjust spider's speed as needed
    theta = 0.0;
    rateOfChange = 1.0;
    this->pos_X = pos.getX();
    this->pos_Y = pos.getY();

    string fname[2] = {"Images/spider.bmp", "Images/mak3.bmp"}; // Replace with actual image filenames
    for (int i = 0; i < 2; i++)
    {
        pix[i].readBMPFile(fname[i], 1);
        pix[i].setChromaKey(192, 192, 192);
    }
}

void Spider::die() {}

void Spider::changePosition(float dx, float dy)
{
    this->pos_X += dx;
    this->pos_Y += dy;
}

void Spider::render()
{
    glRasterPos2f(this->pos_X, this->pos_Y);
    if (this->isMoving)
    {
        pix[0].mDraw();
    }
    else
    {
        pix[1].mDraw();
    }
}