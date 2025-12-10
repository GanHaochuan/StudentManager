#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    bool ud =0;
    string op;
    double x1=0,y1=0,x2,y2;
    PenStyle pen={1 , "black"};
    while(!input.eof()){
        input>>op;
        op=toLowerCase(op);
        if(op=="penup")
            ud=0;
        else if(op=="pendown")
            ud=1;
        else if(op=="moverel"){
            double a,b;
            input>>a>>b;
            x2=x2+a;
            y2=y2+b;
            if(ud)
                drawLine(x1,y1,x2,y2,pen);
            x1=x2;y1=y2;
        }
        else if(op=="moveabs"){
            input>>x2>>y2;
            if(ud)
                drawLine(x1,y1,x2,y2,pen);
        }
        else if(op=="penwidth")
            input>>pen.width;
        else if(op=="pencolor")
            input>>pen.color;
    }
}
