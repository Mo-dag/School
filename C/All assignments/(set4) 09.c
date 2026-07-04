#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHECK_IF_EPS_EQUAL(v1, v2) printf(fabs((v1)-(v2)) < 0.0001 ? "ok\n" : "not ok\n")

// Structure for a point in 3D
typedef struct Point3D {
    double x;
    double y;
    double z;
} point3d_t;

// Structure for a triangle in 3d
typedef struct Triangle3D {
    point3d_t pts[3];   // Lines between points implicit
} triangle3d_t;

// Distance between two points
double distance(point3d_t *p1, point3d_t *p2);
    
// Area of triangle formed by three points
double area(triangle3d_t *triangle);


int main() {
    point3d_t p1 = {0, 0, 0};
    point3d_t p2 = {1, 0, 0};
    point3d_t p3 = {0, 1, 0};
    point3d_t p4 = {0, 0, 1};
    point3d_t p5 = {1, 1, 1};

    CHECK_IF_EPS_EQUAL(distance(&p1, &p2), 1); // Structures always passed ass addresses
    CHECK_IF_EPS_EQUAL(distance(&p1, &p3), 1);
    CHECK_IF_EPS_EQUAL(distance(&p1, &p4), 1);
    CHECK_IF_EPS_EQUAL(distance(&p1, &p5), sqrt(3));

    triangle3d_t triangle1 = {{p1, p2, p3}};
    CHECK_IF_EPS_EQUAL(area(&triangle1), 0.5);
    triangle3d_t triangle2 = {{p1, p2, p3}};
    CHECK_IF_EPS_EQUAL(area(&triangle2), 0.5);

    return 0;
}

// Use arrow operator (->) to access members of structure from addresses
double distance(point3d_t *p1, point3d_t *p2) {
    // TODO : d = √(x2-x1)²+(y2-y1)²+(z2-z1)²
    double d;
    double x,y,z;
    x = p2->x - p1->x;
    y = p2->y - p1->y;
    z = p2->z - p1->z;
    d=sqrt(x*x+y*y+z*z);

    return d;    
}

// Use Herons formula
double area(triangle3d_t *triangle) {
    // TODO
    double s,Area;
    double a,b,c;
    a = distance(&triangle->pts[0],&triangle->pts[1]);
    b = distance(&triangle->pts[1],&triangle->pts[2]);
    c = distance(&triangle->pts[2],&triangle->pts[0]);

    s = (a+b+c)*0.5;
    Area = sqrt(s*(s-a)*(s-b)*(s-c));
    return Area;
}
