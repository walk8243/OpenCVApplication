#include <iostream>
#include "func.h"
#include "opencv.h"

using namespace std;

int main(int argc, char** argv)
{
    bool debugFlag = false;
    string refFilepath;
    string targetFilepath;
    for (int i = 0; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "-D")
        {
            debugFlag = true;
            cout << "デバッグモードで実行します" << endl;
        }
        else if (check_option(arg, "ref"))
        {
            refFilepath = arg.substr(6);
        }
        else if (check_option(arg, "target"))
        {
            targetFilepath = arg.substr(9);
        }
    }
    cout << "ref   : " + refFilepath << endl;
    cout << "target: " + targetFilepath << endl;

    return isSameImage(refFilepath, targetFilepath, debugFlag) ? 0 : 1;
}
