#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "manipulator.h"
#include "point.h"


double dist(const Manipulator& M, const Point& p) {
    double x1 = M.GetX();
    double y1 = M.GetY();
    double x2 = p.X;
    double y2 = p.Y;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void printPoints (Manipulator& M1, Manipulator& M2, std::string& strM1, std::string& strM2) {
     std::ostringstream ss;
     ss.str("");
     ss << "{" << M1.GetX() << ", " << M1.GetY() << "} ";
     strM1 += ss.str();
     ss.str("");
     ss << "{" << M2.GetX() << ", " << M2.GetY() << "} ";
     strM2 += ss.str();
}


int main()
{

    std::string path = "points.txt";
    std::ifstream fin;
    fin.open(path);

    Manipulator M1(0, 0, 8);
    Manipulator M2(2, 1, 10);

    if (!fin.is_open()){
         std::cout << "File not open" << std::endl;
    }
    else {
         std::string str;
         str = "";
         std::cout << "File open \n" << std::endl;
         double x, y;
         char comma;
         int i = 0;
         std::vector<Point> points;
         std::string strM1, strM2;

         while (!fin.eof()) {
             getline(fin, str, '}');
             if (!str.empty())
             {
             str += '}';
             size_t start = str.find('{') + 1;
             size_t end = str.find('}');
             size_t size = end - start;
             str = str.substr(start, size);
             ++i;
             std::istringstream iss(str);
             iss  >> x >> comma >> y;
             points.push_back({x,y});
             if (dist(M1, points.back()) <= M1.GetR() && dist(M2, points.back()) <= M2.GetR()) {

                 if(dist(M1, points.back()) > dist(M2, points.back())) {
                        M2.SetX(points.back().X);
                        M2.SetY(points.back().Y);
                        printPoints(M1, M2, strM1, strM2);
                 }
                 else {
                         M1.SetX(points.back().X);
                         M1.SetY(points.back().Y);
                         printPoints(M1, M2, strM1, strM2);
                 }

             } else if (dist(M1, points.back()) <= M1.GetR()) {
                 M1.SetX(points.back().X);
                 M1.SetY(points.back().Y);
                 printPoints(M1, M2, strM1, strM2);

             } else if (dist(M2, points.back()) <= M2.GetR()) {
                 M2.SetX(points.back().X);
                 M2.SetY(points.back().Y);
                 printPoints(M1, M2, strM1, strM2);
             }

             else {
                printPoints(M1, M2, strM1, strM2);
             }
             }
         }
             std::cout << "\n Manipulator 1:\t" << strM1 << "\n" << "\n Manipulator 2:\t" << strM2 << "\n" << std::endl;
    }
   fin.close();
    return 0;
}
