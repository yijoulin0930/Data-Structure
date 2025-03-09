//
// Prof. Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//
#include <iostream>
#include "mySystem_ImageEditor.h"

namespace {
    void drawDisk_TriangleFan(double x, double y, double r, int in_numSamples = 120)
    {
        int numSamples = in_numSamples;
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f( x, 0.0, y );
        for ( int i = 0; i < numSamples; ++i ) {
            double da = 1.0/(double) (numSamples-1)*3.141592654*2.0;

            double a = i*da;
            double x0 = x + r*cos(a);
            double y0 = y + r*sin(a);
            double x1 = x + r*cos(a+da);
            double y1 = y + r*sin(a+da);
            //glVertex3f( x, 0.0, y );


            glVertex3f( x0, 0.0, y0 );

            //glVertex3f( x1, 0.0, y1 );


        }
        glEnd( );
    }
};

void IMAGE_NODE::computeDrawPosition(
    int wImage,
    int hImage) {
    draw_x = (start_x+w/2)*sx;
    draw_y = hImage*sy-(start_y+h/2)*sy;
}

void IMAGE_NODE::drawDisk_TriangleFan( 
    int wImage,int hImage
    ) const
{
        glColor3f(r, g, b);
int numSamples = 12;
        numSamples += w*0.5;
        ::drawDisk_TriangleFan(
            draw_x,
            draw_y,
            radius, numSamples);
}

void IMAGE_SYSTEM::draw_Normal() const
{
    if (m_Image) {
        //std::cout << "IMAGE_SYSTEM::draw( )" << std::endl;
        m_Image->draw_VerticalFlip_XZ(0,0, 2, 2, 4);
    }
}

void IMAGE_SYSTEM::computeAverageColor(
    int start_x, int start_y, 
    int w, int h,
    float &r, float &g, float &b
    ) const 
{
    r = g = b = 0.0;
    if (w*h==0) return;
    for (int j = start_y; j < start_y + h; ++j) {
        for (int i = start_x; i < start_x + w; ++i ) {
            float pr, pg, pb;
            m_Image->getPixelColor(i, j, pr, pg, pb);
            r += pr;
            g += pg;
            b += pb;

        }
    }
    r /= w*h;
    g /= w*h;
    b /= w*h;

}

void IMAGE_SYSTEM::draw_Disks(
    int cur_depth, 
    int max_depth,
    int start_x, int start_y, 
    int w, int h,
    float sx, float sy
    ) const
{
    if (cur_depth == max_depth) {
        int wImage, hImage;
        m_Image->getInfo(wImage, hImage);
        float r, g, b;
        computeAverageColor(start_x, start_y, w, h, r, g, b);
        glColor3f(r, g, b);
        float radius = w/2;
        int numSamples = 12;
        numSamples += w*0.5;
        ::drawDisk_TriangleFan(
            (start_x+w/2)*sx,
            hImage*sy-(start_y+h/2)*sy,
            radius*(sx+sy)/2.0, numSamples);
    } else {
        draw_Disks(
            cur_depth+1, 
            max_depth,
            start_x, start_y,
            w/2, h/2, sx, sy);
        draw_Disks(
            cur_depth+1, 
            max_depth,
            start_x+w/2, start_y,
            w/2, h/2, sx, sy);
        draw_Disks(
            cur_depth+1, 
            max_depth,
            start_x, start_y+h/2,
            w/2, h/2, sx, sy);
        draw_Disks(
            cur_depth+1, 
            max_depth,
            start_x+w/2, start_y+h/2,
            w/2, h/2, sx, sy);
    }

}

void IMAGE_SYSTEM::draw_Disks(int max_depth) const{
    int w, h;
    m_Image->getInfo(w, h);
    float sx = 1;
    float sy = 1;
    //float sx = 2;
    //float sy = 2;
    draw_Disks(0, max_depth, 0, 0, w, h, sx, sy);
}

void IMAGE_SYSTEM::draw_Disks() const{
    draw_Disks(m_Depth);
}



void IMAGE_SYSTEM::draw_Disks_Dynamic( const IMAGE_NODE *node) const{
if (node==0) return;
//if (node->flg_explored == false) return;

if (node->flg_explored) {
    for (int i = 0; i < 4; ++i) {
        draw_Disks_Dynamic(node->children[i]);
    }
    return;
}
    int wImage, hImage;
        m_Image->getInfo(wImage, hImage);
node->drawDisk_TriangleFan(  wImage, hImage);
}


void IMAGE_SYSTEM::draw_Disks_Dynamic( ) const
{
    draw_Disks_Dynamic(m_ImageHierarchy);
}

void IMAGE_SYSTEM::draw( ) const
{
    //draw_Normal();
    //draw_Disks();
    draw_Disks_Dynamic();
}
