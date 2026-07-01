#include <stdio.h>
#include <stdlib.h>
#define tree_height 5
#define trunk_height 2 
// TODO Define an enumeration named 'tree_parts_t' with items
typedef enum {
    tree = '*', decoration = 'o',decoration_top = '+',trunk = '|'
}tree_parts_t;
// tree, decoration, decoration_top and trunk. Specify the characters 
// that correspond to these items.

// TODO Make a function that draws a decorated christmas tree,
// adding the relevant tree parts from the enumeration as arguments
// hint: look at set3/ex_xmas_tree/main.c
void draw(tree_parts_t t,tree_parts_t d, tree_parts_t dt);
void draw_trunk(tree_parts_t tk);
// TODO Make a function that draws the trunk of the tree,
// adding the relevent tree parts from the enumeration as arguments
// hint: look at set3/ex_xmas_tree/main.c

int main(){
    // TODO Define height of Christmas tree and trunk
    
    // TODO Plot the decorated Christmas tree
    draw(tree,decoration,decoration_top);
    draw_trunk(trunk);

    return 0;
}

void draw(tree_parts_t t,tree_parts_t d, tree_parts_t dt){
    int r = 0;
    int decor = 1;
    while(r < 5){
        int c = 0;
        while(c < tree_height -r -1){
            printf(" ");
            c++;
        }
        if(decor == 1){
            printf(" ");
            putchar(dt);
            printf("\n");
            decor = 0;
            continue;
        }
        putchar(d);
        while(c<tree_height +r){
            putchar(t);
            c++;
        }
        putchar(d);
        printf("\n");
        r++;
    }

};


void draw_trunk(tree_parts_t tk){
    int r = 0;
    while(r<trunk_height){
        int c = 0;
        while(c<tree_height){
            printf(" ");
            c++;
        }
        putchar(tk);
        printf("\n");
        r++;

    }
};
