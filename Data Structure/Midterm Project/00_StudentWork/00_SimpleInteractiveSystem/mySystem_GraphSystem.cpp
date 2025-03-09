//********************************************
// Student Name			:
// Student ID			:
// Student Email Address:
//********************************************
//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include "mySystem_GraphSystem.h"
#include <time.h>
#include<cmath>

using namespace std;

#define GRAPH_FILE_NAME "graph.txt"

int Param::GRAPH_MAX_NUM_NODES = 10000;
int Param::GRAPH_MAX_NUM_EDGES = 10000;
int Param::Export_Count_DrawingFX = 300;

GRAPH_SYSTEM::GRAPH_SYSTEM( )
{
    mFlgAutoNodeDeletion = false;
    mExport_Count_DrawingFX = 0;

    initMemoryPool();
    createDefaultGraph();
}

void GRAPH_SYSTEM::initMemoryPool( )
{
    mMaxNumNodes = Param::GRAPH_MAX_NUM_NODES;
    mMaxNumEdges = Param::GRAPH_MAX_NUM_EDGES;

    mNodeArr_Pool = new GRAPH_NODE[mMaxNumNodes];
    mEdgeArr_Pool = new GRAPH_EDGE[mMaxNumEdges];

    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;
    mActiveNodeArr = new int[mMaxNumNodes];
    mActiveEdgeArr = new int[mMaxNumEdges];

    mFreeNodeArr = new int[mMaxNumNodes];
    mFreeEdgeArr = new int[mMaxNumEdges];
    //
    for ( int i = 0; i < mMaxNumNodes; ++i ) {
        mNodeArr_Pool[ i ].id = i;
    }
    for ( int i = 0; i < mMaxNumEdges; ++i ) {
        mEdgeArr_Pool[ i ].id = i;
    }
    //
    reset( );
}

void GRAPH_SYSTEM::reset( )
{
    stopAutoNodeDeletion();

    //mNumPoints_DoubleCircles = 0;

    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;

    mCurNumOfFreeNodes = mMaxNumNodes;
    mCurNumOfFreeEdges = mMaxNumEdges;

    for ( int i = 0; i < mCurNumOfFreeNodes; ++i ) {
        mFreeNodeArr[i] = mMaxNumNodes - i - 1;
    }
    for ( int i = 0; i < mCurNumOfFreeEdges; ++i ) {
        mFreeEdgeArr[i] = mMaxNumEdges - i - 1;
    }

    mPassiveSelectedNode = 0;
    mSelectedNode = 0;
}

GRAPH_NODE *GRAPH_SYSTEM::getFreeNode( ) 
{
    if ( mCurNumOfFreeNodes == 0 ) 
        return 0;

    --mCurNumOfFreeNodes;

    int id = mFreeNodeArr[ mCurNumOfFreeNodes ];
    GRAPH_NODE* n = &mNodeArr_Pool[id];

    mActiveNodeArr[mCurNumOfActiveNodes] = id;
    n->dynamicID = mCurNumOfActiveNodes;

    ++mCurNumOfActiveNodes;

    return n;
}

GRAPH_EDGE *GRAPH_SYSTEM::getFreeEdge( )
{
    if ( mCurNumOfFreeEdges == 0 )
        return 0;

    --mCurNumOfFreeEdges;

    int id = mFreeEdgeArr[ mCurNumOfFreeEdges ];
    GRAPH_EDGE* e = &mEdgeArr_Pool[id];

    mActiveEdgeArr[mCurNumOfActiveEdges] = id;
    e->dynamicID = mCurNumOfActiveEdges;

    ++mCurNumOfActiveEdges;
    return e;
}

void GRAPH_SYSTEM::createDefaultGraph( )
{
    cout << "here"<< endl;
    reset( );

    int n_0 = addNode( 0.0, 0.0, 0.0 );
    cout << "n_0:"<< n_0 << endl;

    int n_1 = addNode(5.0, 0.0, 0.0);
    cout << "n_1:" << n_1 << endl;

    int n_2 = addNode( 0.0, 0.0, 5.0 );
    cout << "n_2:"<< n_2 << endl;

    addEdge(n_0, n_1);
    addEdge(n_1, n_2);

}

void GRAPH_SYSTEM::createNet_Horizontal( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    vector<int> id;
}

void GRAPH_SYSTEM::createNet_Vertical( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    vector<int> id;
}

void GRAPH_SYSTEM::createRandomGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;

}

void GRAPH_SYSTEM::createRadialGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;

}

void GRAPH_SYSTEM::createRandomGraph_DoubleCircles(int n)
{
    reset( );

    //n = 36;
    float dx = 5.0;
    float dz = 5.0;
    float r = 15; // radius
    float d = 10; // layer distance
    float offset_x = 15.;
    float offset_z = 15.;
    int temp, point;

    vector<int> id;


    for (int i = 1; i <= 2; i++) {
        for (int j = 0; j < n; j++) {
            dx = offset_x + r * cos(2 * M_PI / n * j);
            dz = offset_z + r * sin(2 * M_PI / n * j);

            temp = addNode(dx, 0.0, dz);
            id.push_back(temp);
        }
        r += d;
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        point = i + (rand() % 5 - 2);

        if (point < 0)
            point += 2 * n;
        else if (point >= 0 && point < n)
            point += n;
        else if (point >= 2 * n)
            point -= n;

        addEdge(id[i], id[point]);
    }
    
}

void GRAPH_SYSTEM::createNet_Circular( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 15.;
    float offset_z = 15.;
    vector<int> id;
    //id.resize( n*(num_layers+1) );
    int temp;

    for (int i = 1; i <= num_layers + 1; i++){
        //add points
        for (int j = 1; j <= n; j++)
        {
            dx = offset_x + i * r * cos(2 * M_PI / n * j);
            dz = offset_z + i * r * sin(2 * M_PI / n * j);

            temp = addNode(dx, 0.0, dz);
            id.push_back(temp);
        }

        if (i != num_layers + 1)
        {
            for (int j = 0; j < n - 1; j++)
                addEdge(id[(i - 1) * n + j], id[(i - 1) * n + j + 1]);
            addEdge(id[(i - 1) * n + n - 1], id[(i - 1) * n]);
        }
    }

    //add edges
    for (int i = 1; i <= num_layers; i++)
        for (int j = 0; j < n; j++)
            addEdge(id[(i - 1) * n + j], id[i * n + j]);

}

void GRAPH_SYSTEM::createNet_Square( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 15.;
    float offset_z = 15.;
    int id[50][50];//©ñNodeªºid

    int x = 0, y = 0;
    
    //initializing
    for (x = 0; x < 50; x++)
        for (y = 0; y < 50; y++)
            id [x][y] = 0;

    //(x,y)index
    //(i,j)for counting the value
    x = 0;
    y = 0;

    int num = (num_layers - 1) / 2;
    int left_offset = -(num + 1) * r;
            
    //add points
    for (int i = num; i >= -num; i--){
        x++;
        y = 0;

        for (int j = 1; j <= num_layers; j++){
            y++;

            if ((x >= 5 && x <= 7) && (y >= 5 && y <= 7))
                continue;

            dx = offset_x+left_offset + j * r;
            dz = offset_z+i * r;
            id[x][y] = addNode(dx, 0.0, dz);
        }
    }

    //add edges
    for (int x = 1; x <= num_layers; x++)
        for (int y = 1; y < num_layers; y++) {
            if (x > 4 && x < 8 && y > 4 && y < 8)
                continue;
            else{
                if ((y + 1 == 5)&& x > 4 && x < 8)
                    continue;
                addEdge(id[x][y], id[x][y + 1]);
                addEdge(id[y][x], id[y + 1][x]);

            }
        }
}

void GRAPH_SYSTEM::createNet_RadialCircular( int n ) {

    reset( );

    float offset_x = 15.0;
    float offset_z = 15.0;
    float dx, dz;
    float r = 15; // radius
    vector<int> id;

    id.push_back(addNode(offset_x, 0.0, offset_x));

    for (int i = 0; i < n; i++) {
        dx = offset_x + r * cos(2 * M_PI / n * i);
        dz = offset_z + r * sin(2 * M_PI / n * i);

        int temp = addNode(dx, 0.0, dz);
        id.push_back(temp);
    }

    for (int i = 1; i <= n; i++)
        addEdge(id[0], id[i]);
}

int GRAPH_SYSTEM::addNode(float x, float y, float z, float r )
{
    GRAPH_NODE* g;
    g = getFreeNode();

    if (g == 0)
        return -1;

    g->p = vector3(x, y, z);
    g->r = r;
    g->edgeID.clear();

    return g->id;
}

int GRAPH_SYSTEM::addEdge( int nodeID_0, int nodeID_1 )
{
    GRAPH_EDGE* e;
    e = getFreeEdge();

    if (e == 0)
        return -1;

    e->nodeID[0] = nodeID_0;
    e->nodeID[1] = nodeID_1;

    mNodeArr_Pool[nodeID_0].edgeID.push_back(e->id);
    mNodeArr_Pool[nodeID_1].edgeID.push_back(e->id);

    return e->id;
}

void GRAPH_SYSTEM::askForInput( )
{
    cout << "GRAPH_SYSTEM" << endl;
    cout << "Key usage:" << endl;
    cout << "1: create a default graph" << endl;
    cout << "2: create a graph with 10x10 nodes. Connect the consecutive nodes horizontally" << endl;
    cout << "3: create a graph with 10x10 nodes. Connect the consecutive nodes vertically" << endl;
    cout << "4: create a graph with 10x10 nodes. Create 10 randomly generated edges" << endl;
    cout << "5: create a graph with 10x10 nodes. Create 10 randomly generated edges attached at a random node" << endl;
    cout << "Delete: delete a node and all the edges attached at it" << endl;
    cout << "Spacebar: unselect the selected node" << endl;
    cout << " " << endl;
    cout << "Use the mouse to select nodes and add edges" << endl;
    cout << "Click the left button to select/unselect or create an edge" << endl;
    cout << " " << endl;
    cout << "A selected node is highlighted as red." << endl;

}

GRAPH_NODE* GRAPH_SYSTEM::findNearestNode(double x, double z, double& cur_distance2) const
{

    GRAPH_NODE* n = &mNodeArr_Pool[0];
    GRAPH_NODE* min = &mNodeArr_Pool[0];
    cur_distance2 = 100000000000.0;
    double dist;

    for (int i = 0; i < mCurNumOfActiveNodes; ++i) {
        n = &mNodeArr_Pool[mActiveNodeArr[i]];

        dist = (n->p.x - x) * (n->p.x - x) + (n->p.z - z) * (n->p.z - z);
        dist = sqrt(dist);

        if (dist == 0)
            continue;

        if (dist < cur_distance2) {
            cur_distance2 = dist;
            min = n;
        }
    }

    return min;
}

void GRAPH_SYSTEM::clickAt(double x, double z)
{
    double cur_d2;
    GRAPH_NODE* n = findNearestNode(x, z, cur_d2);
    if (n == 0) {
        mSelectedNode = 0;
        return;
    }
    if (cur_d2 > n->r * n->r) {
        mSelectedNode = 0;
        return;

    }
    if (mSelectedNode == n) {
        mSelectedNode = 0;
        return;
    }
    if (mSelectedNode != 0) {
        addEdge(mSelectedNode->id, n->id);
        mSelectedNode = 0;
        return;
    }
    mSelectedNode = n;
}

void GRAPH_SYSTEM::deleteEdge(int edgeID)
{
    GRAPH_EDGE* e = &mEdgeArr_Pool[edgeID];
    int dynamicID = e->dynamicID;

    //remove edge from connected nodes
    removeEdgeFromNode(e, e->nodeID[0]);
    removeEdgeFromNode(e, e->nodeID[1]);

    //Assign it back to FE (FreeEdgeArr).
    mFreeEdgeArr[mCurNumOfFreeEdges] = e->id;
    mCurNumOfFreeEdges++;

    //delete it from AE(active edge array).
    GRAPH_EDGE* a = &mEdgeArr_Pool[mActiveEdgeArr[mCurNumOfActiveEdges - 1]];
    mActiveEdgeArr[dynamicID] = mActiveEdgeArr[mCurNumOfActiveEdges - 1];
    a->dynamicID = dynamicID;
    mCurNumOfActiveEdges--;
}

void GRAPH_SYSTEM::removeEdgeFromNode(const GRAPH_EDGE* e, int nodeID)
{
    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    int pos = 0;
    int id = e->id;
    int size = n->edgeID.size();

    //deleteing points
    for (int i = 0; i < size; i++) {
        if (n->edgeID[i] == id) {

            n->edgeID[i] = n->edgeID.back();
            n->edgeID.pop_back();
            break;
        }
    }
}
void GRAPH_SYSTEM::deleteEdgesOfNode(int nodeID)
{
    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    int tempEdgeId, tempNodeId;
    int size = n->edgeID.size();

    for (int i = 0; i < size; i++) {
        tempEdgeId = n->edgeID[i];
        GRAPH_EDGE* e = &mEdgeArr_Pool[tempEdgeId];

        deleteEdge(tempEdgeId);
    }
}

void GRAPH_SYSTEM::deleteNode(int nodeID) {
    if (mCurNumOfActiveNodes <= 0) return;

    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    int dynamicID = n->dynamicID;

    //Assign it to FN(FreeNodeArr)
    mFreeNodeArr[mCurNumOfFreeNodes] = n->id;
    mCurNumOfFreeNodes++;

    //delete it from AN(active node array).
    GRAPH_NODE* a = &mNodeArr_Pool[mActiveNodeArr[mCurNumOfActiveNodes - 1]];
    mActiveNodeArr[dynamicID] = mActiveNodeArr[mCurNumOfActiveNodes - 1];
    a->dynamicID = dynamicID;
    mCurNumOfActiveNodes--;

}

void GRAPH_SYSTEM::deleteSelectedNode() {
    if (mSelectedNode == 0) return;
    deleteNode(mSelectedNode->id);
    deleteEdgesOfNode(mSelectedNode->id);
    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

bool GRAPH_SYSTEM::isSelectedNode() const
{
    return mSelectedNode != 0;
}

void GRAPH_SYSTEM::getInfoOfSelectedPoint(double& r, vector3& p) const
{
    if (isSelectedNode() == false) return;
    r = mSelectedNode->r;
    p = mSelectedNode->p;

}



void GRAPH_SYSTEM::handleKeyPressedEvent(unsigned char key)
{

    switch (key) {
    case 127: // delete
        mFlgAutoNodeDeletion = false;
        deleteSelectedNode();
        break;
    case '1':
        mFlgAutoNodeDeletion = false;
        createDefaultGraph();
        mSelectedNode = 0;
        break;
    case '2':
        mFlgAutoNodeDeletion = false;
        createNet_Circular(12, 3);
        mSelectedNode = 0;

        break;
    case '3':
        mFlgAutoNodeDeletion = false;
        createNet_Square(3,11);
        mSelectedNode = 0;

        break;
    case '4':
        mFlgAutoNodeDeletion = false;
        createNet_RadialCircular(24);
        mSelectedNode = 0;

        break;
    case '5':
        mNumPoints_DoubleCircles = 24;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case '<':
        mNumPoints_DoubleCircles--;
        if (mNumPoints_DoubleCircles < 3)
            mNumPoints_DoubleCircles = 3;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case '>':
        mNumPoints_DoubleCircles++;
        if (mNumPoints_DoubleCircles > 36)
            mNumPoints_DoubleCircles = 36;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;

    case ' ':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        break;
    case 'd':
        mFlgAutoNodeDeletion = !mFlgAutoNodeDeletion;
        break;
    case 'e':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        exportGraph(GRAPH_FILE_NAME);
        break;
    }
}

void GRAPH_SYSTEM::handlePassiveMouseEvent(double x, double z)
{
    double cur_d2;
    GRAPH_NODE* n = findNearestNode(x, z, cur_d2);
    if (n == 0) return;
    if (cur_d2 > n->r * n->r) {
        mPassiveSelectedNode = 0;
        return;
    }
    mPassiveSelectedNode = n;
}

int GRAPH_SYSTEM::getNumOfNodes() const
{
    return mCurNumOfActiveNodes;
}

int GRAPH_SYSTEM::getNodeID(int nodeIndex) const
{
    int nodeID = mActiveNodeArr[nodeIndex];
    return nodeID;
}

int GRAPH_SYSTEM::getNodeInfo(int nodeIndex, double& r, vector3& p) const
{
    int nodeID = mActiveNodeArr[nodeIndex];
    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    r = 1.0;
    p = n->p;
    return nodeID;
}

int GRAPH_SYSTEM::getNumOfEdges() const
{
    return mCurNumOfActiveEdges;
}

int GRAPH_SYSTEM::getEdgeID(int edgeIndex) const
{
    int edgeID = mActiveEdgeArr[edgeIndex];
    return edgeID;
}

int GRAPH_SYSTEM::getNodeIDOfEdge(int edgeIndex, int nodeIndex) const
{
    int edgeID = mActiveEdgeArr[edgeIndex];
    GRAPH_EDGE* e = &mEdgeArr_Pool[edgeID];
    return e->nodeID[nodeIndex];
}

vector3 GRAPH_SYSTEM::getNodePositionOfEdge(int edgeIndex, int nodeIndex) const
{
    int edgeID = mActiveEdgeArr[edgeIndex];
    GRAPH_EDGE* e = &mEdgeArr_Pool[edgeID];
    GRAPH_NODE* n = &mNodeArr_Pool[e->nodeID[nodeIndex]];

    return n->p;
}

void GRAPH_SYSTEM::stopAutoNodeDeletion()
{
    mFlgAutoNodeDeletion = false;
}

//
// For every frame, update( ) function is called.
//
// 
void GRAPH_SYSTEM::update()
{
    if (!mFlgAutoNodeDeletion) {
        mFlgAutoNodeDeletion = false;
        return;
    }

    if (mCurNumOfActiveNodes <= 0) {
        mFlgAutoNodeDeletion = false;
        return;
    }

    //auto delete
    int index = mActiveNodeArr[mCurNumOfActiveNodes - 1];

    deleteNode(index);
    deleteEdgesOfNode(index);

    Sleep(250);


    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

//
// Export each node to the file steam fObj
// node_ID x y z
// The work flow
//
// Get the number of nodes
// For each node do
//    Get the node ID of the node
//    Get the radius and position of the node
//    Save the node information to the file stream
//
// Return
//
void GRAPH_SYSTEM::emitNodes(std::fstream* fObj) const
{
    //vector3 p;
    //double r;
    GRAPH_NODE* n;
    int num = getNumOfNodes();

    for (int i = 0; i < mCurNumOfActiveNodes; i++) {
        n = &mNodeArr_Pool[mActiveNodeArr[i]];

        *fObj << n->id << "\t" << n->r << "\t" << n->p.x << "\t" << n->p.y << "\t" << n->p.z << "\n";
    }

    return;
}

//
// Export each edge to the file stream fObj
// edge_ID node0_ID node1_ID
//
// The work flow
//
// Get the number of edges
// For each edge do
//    Get the edge ID of the edge
//    Get the node ID of the first node of the edge
//    Get the node ID of the second node of the edge
//    Save the edge information to the file stream
//
// Return
//
void GRAPH_SYSTEM::emitEdges(std::fstream* fObj) const
{
    GRAPH_EDGE* e;
    int num = getNumOfEdges();

    for (int i = 0; i < mCurNumOfActiveEdges; i++) {
        e = &mEdgeArr_Pool[mActiveEdgeArr[i]];

        *fObj << e->id << "\t" << e->nodeID[0] << "\t" << e->nodeID[1] << "\n";
    }

    return;
}

//
// The work flow
// Create a file stream object or pointer, fObj
// Use fObj to open a file for text output
// Check if the file is opened successfully
// If the file cannot be opened, show an error message and return
// Otherwise, go on to process the following steps.
// Get the number of nodes, n
// Get the number of edges, m
// Save n to fObj
// Save m to fObj
// Call emitNodes
// Call emitEdges
// Close the file
// Delete the object fObj if necessary
// Show a message
//
void GRAPH_SYSTEM::exportGraph(const std::string& fileName) const
{
    cout << "BEGIN GRAPH_SYSTEM::exportGraph" << endl;

    //////////////////////////////////////
    // DO NOT DELETE THE FOLLOWING LINE
    mExport_Count_DrawingFX = Param::Export_Count_DrawingFX;
    //////////////////////////////////////

    cout << "Filename:" << fileName << endl;
    fstream* fObj = new fstream;

    fObj->open(fileName, ios::out);

    if (!fObj) {
        cout << "ERROR" << "\n";
        return;
    }

    *fObj << mCurNumOfActiveNodes << "\n";
    *fObj << mCurNumOfActiveEdges << "\n";
    emitNodes(fObj);
    emitEdges(fObj);

    fObj->close();

    cout << "END GRAPH_SYSTEM::exportGraph" << endl;

}

