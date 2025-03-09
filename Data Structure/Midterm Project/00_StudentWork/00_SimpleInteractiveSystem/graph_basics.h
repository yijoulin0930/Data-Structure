//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//

#ifndef __MY_GRAPH_BASICS_H_
#define __MY_GRAPH_BASICS_H_
#include "../headers.h"
#include <string>
#include "../primitives/vector3d.h"
#include <vector>
using std::vector;

class GRAPH_NODE {
public:
    GRAPH_NODE( ) {
        r = 1.0;
        p = vector3(0.0, 0.0, 0.0);
    }
    vector3 p;  //position
    double r;   //radius    

    int id;     //unique ID
    int dynamicID; // in the active index array

    vector<int> edgeID;
    //
};

class GRAPH_EDGE {
public:
    int id;
    int dynamicID; 
    int nodeID[2];
};

#endif