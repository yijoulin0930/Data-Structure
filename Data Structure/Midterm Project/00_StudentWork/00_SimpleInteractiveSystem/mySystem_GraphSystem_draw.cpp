//
// Prof. Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//
#include "mySystem_GraphSystem.h"
#include "../headers.h"
#include <string>
#include "../../openGLbasic/opengl_stuff.h"
#include <iostream>
using namespace std;

void GRAPH_SYSTEM::drawEdges( ) const
{
    glColor3f(0.0, 0.0, 1.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    for ( int i = 0; i < mCurNumOfActiveEdges; ++i ) {
        int id = mActiveEdgeArr[ i ];
        const GRAPH_EDGE *edge = &mEdgeArr_Pool[id];
        int n_0 = edge->nodeID[ 0 ];
        int n_1 = edge->nodeID[ 1 ];

        const vector3 &p0 = mNodeArr_Pool[n_0].p;
        const vector3 &p1 = mNodeArr_Pool[n_1].p;
        glVertex3f( p0.x, p0.y, p0.z );
        glVertex3f( p1.x, p1.y, p1.z );

    }
    glEnd();
    glLineWidth(1.0);
}


void GRAPH_SYSTEM::drawNodes( ) const
{
    glColor3f(1.0, 0.75, 0.0);
    glLineWidth(2.0);
    for ( int i = 0; i < mCurNumOfActiveNodes; ++i ) {
        int id = mActiveNodeArr[ i ];

        const GRAPH_NODE *node = &mNodeArr_Pool[id];
        const vector3 &p = node->p;
        double r = node->r;
        ogl_drawSimpleSolidCircleXZ(p.x, p.y, p.z, r, 12);
    }
    glLineWidth(1.0);
}

void GRAPH_SYSTEM::drawSelectedNode( ) const
{
    if ( mPassiveSelectedNode ) {
        glColor3f(0.0, 0.5, 1.0);

        vector3 p = mPassiveSelectedNode->p;
        double r = mPassiveSelectedNode->r;
        ogl_drawSimpleSolidCircleXZ(
            p.x, 
            p.y -1.0, 
            p.z, 
            r, 
            12);

    }

    if ( mSelectedNode == 0 ) return;
    glColor3f(1.0, 0.0, 0.0);

    ogl_drawSimpleSolidCircleXZ(
        mSelectedNode->p.x, 
        mSelectedNode->p.y -1.0, 
        mSelectedNode->p.z, 
        mSelectedNode->r, 
        12);
}

void GRAPH_SYSTEM::drawEdges_Indirect( ) const
{
    int numEdges = getNumOfEdges( );

    glColor3f(0.0, 0.8, 0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    for ( int i = 0; i < numEdges; ++i ){
        vector3 p0 = getNodePositionOfEdge( i, 0 );
        vector3 p1 = getNodePositionOfEdge( i, 1 );
        glVertex3f( p0.x, p0.y, p0.z );
        glVertex3f( p1.x, p1.y, p1.z );
    }
    glEnd();
    glLineWidth(1.0);
}

void GRAPH_SYSTEM::drawNodes_Indirect( ) const
{
    float color_f = 1.0;
    if (mExport_Count_DrawingFX>0) {
        color_f = mExport_Count_DrawingFX/(float)Param::Export_Count_DrawingFX;
        color_f = sin(color_f*4*3.14);
        --mExport_Count_DrawingFX;
    }
    int numEdges = getNumOfNodes( );
    glColor3f(0.5*color_f, 0.5*color_f, 0.5);
    glLineWidth(2.0);
    for ( int i = 0; i < numEdges; ++i ) {
        double r;
        vector3 p;
        getNodeInfo( i, r, p );

        ogl_drawSimpleSolidCircleXZ(p.x, p.y, p.z, r, 12);
    }
    glLineWidth(1.0);
}

void GRAPH_SYSTEM::drawSelectedNode_Indirect( ) const
{
    if ( mPassiveSelectedNode ) {
        glColor3f(0.0, 0.5, 1.0);

        vector3 p = mPassiveSelectedNode->p;
        double r = mPassiveSelectedNode->r;
        ogl_drawSimpleSolidCircleXZ(
            p.x, 
            p.y -1.0, 
            p.z, 
            r, 
            12);

    }
    if ( isSelectedNode( ) == false ) return;
    glColor3f(1.0, 0.0, 0.0);

    vector3 p;
    double r;
    getInfoOfSelectedPoint( r, p );
    ogl_drawSimpleSolidCircleXZ(
        p.x, 
        p.y -1.0, 
        p.z, 
        r, 
        12);
}

void GRAPH_SYSTEM::draw( ) const
{
    drawEdges_Indirect( );
    drawNodes_Indirect( );
    drawSelectedNode_Indirect( );
}
