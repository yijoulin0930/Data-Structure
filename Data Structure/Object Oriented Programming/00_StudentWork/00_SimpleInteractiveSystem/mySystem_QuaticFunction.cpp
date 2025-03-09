//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//
#include "mySystem_QuaticFunction.h"
#include <iostream>

using namespace std;

QUARTIC_FUNCTION::QUARTIC_FUNCTION()
{
    x0 = -100.0;
    x1 = 100.0;
    mNumSamples = 400;

    c = d = 0.5;
    a = 1.0;
    b = -0.5;
    e = 0.0;
}

void QUARTIC_FUNCTION::increase(double dv)
{
    b += dv;
}

void QUARTIC_FUNCTION::decrease(double dv)
{
    b -= dv;

}


bool QUARTIC_FUNCTION::handleKeyEvent(unsigned char key)
{
    float dv_b = 0.0002;
    float dv_c = 0.002;
    float dv_d = 0.02;
    float k = 0.002;
    bool flg_handled = false;
    switch (key) {
    case '1':
        a = 1.0 * k;
        b = -1.0 * k;
        c = 2 * k;
        d = 15 * k;
        e = 100.0 * k;
        flg_handled = true;
        break;
    case '2':
        a = -1.0 * k;
        b = -5.0 * k;
        c = 2 * k;
        d = 15 * k;
        e = 0 * k;
        flg_handled = true;
        break;
    case '3':
        a = 1.0 * k;
        b = 1.0 * k;
        c = -20 * k;
        d = 15 * k;
        e = 300.0 * k;
        flg_handled = true;
        break;
    case '4':
        a = 1.0 * k;
        b = 5.0 * k;
        c = 20 * k;
        d = -35 * k;
        e = -100 * k;
        break;
    case 'v':
        b -= dv_b;
        flg_handled = true;
        break;
    case 'b':
        b += dv_b;
        flg_handled = true;

        break;
    case 'n':
        c -= dv_c;
        flg_handled = true;

        break;
    case 'm':
        c += dv_c;
        flg_handled = true;

        break;
    case ',':
        d -= dv_d;
        flg_handled = true;

        break;
    case '.':
        d += dv_d;
        flg_handled = true;

        break;
    case 'i':
    case 'I':
        askForInput();
        flg_handled = true;
        break;
    }

    return flg_handled;
}

void QUARTIC_FUNCTION::askForInput()
{
    //
    //Show the system name
    //Ask to input the range of x in [-100, 100]
    //Ask to input the number of sample points
    //
    cout << "QUARTIC_FUNCTION" << endl;

    cout << "ax^4 + bx^4 + cx^2 + dx + e" << endl;

    cout << "Input the range of x in [-100, 100]:" << endl;

    cout << "Input x0 and x1[-100,100]:" << endl;
    cout << "Input x0: ";
    while (true) {
        cin >> x0;

        if (x0 >= -100)
            break;
    }

    cout << "Input x1: ";
    while (true) {
        cin >> x1;

        if (x1 <= 100)
            break;
    }

    cout << "Input the number of sample points inside the interval [2, 500]: ";
    cin >> mNumSamples;
}

void QUARTIC_FUNCTION::getRangeOfX(double& x0, double& x1) const
{
    //Return the range of x in x0 and x1.
    x0 = this->x0;
    x1 = this->x1;
}

int QUARTIC_FUNCTION::getNumOfSamples() const
{
    //Return the number of samples
    return mNumSamples;
}

double QUARTIC_FUNCTION::getValue(double x) const
{
    //Compute ax^4 + bx^3 + cx^2 + dx + e
    //i.e., compute the value a*x*x*x*x + b*x*x*x + c*x*x + d*x + e
    //return a*x*x*x*x + b*x*x*x + c*x*x + d*x + e;
    return a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
}
// CODE: 2020/07/14. Do not delete this line.