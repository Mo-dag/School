#include <stdio.h>

void draw_trunk(int tree_height, int trunk_height, char trunk);
void draw_tree(int tree_height, char tree,char decor);

int main() {
    
    char tree = '*';
    char trunk = '|';
    int trunk_height = 2;
    int tree_height = 5;
    char decor;
    
    // TODO use getchar to choose a decoration
    printf("Insert decoration : ");
    decor = getchar();
    // Plot the decorated Christmas tree
    draw_tree(tree_height, tree,decor);

    // Plot the trunk of the tree
    draw_trunk(tree_height, trunk_height, trunk);

    return 0;
}

void draw_trunk(int tree_height, int trunk_height, char trunk) {
    int r = 0;
    while(r < trunk_height) {
        int c = 0;
        while(c < tree_height) {
            printf(" ");
            c++;
        }
        putchar(trunk);
        printf("\n");
        r++;
    }
}

// TODO decorate your tree
// (you should edit this function,
//  so that the tree matches the
//  pattern in the example)
void draw_tree(int tree_height, char tree,char decor) {
    int r = 0;
    int decor_top = 1;    
    if(decor_top >0){
        int c=0;
        while(c<tree_height -r){
            printf(" ");
            c++; 
        }
        putchar(decor);
        printf("\n");
        decor_top = 0;
    }
    while(r < tree_height) {
        int c = 0;
        while(c < tree_height - r - 1) {
            printf(" ");
            c++;
        }
        putchar(decor);
        while(c < tree_height + r) {
            putchar(tree);
            c++;
        }
        putchar(decor);
        printf("\n");
        r++;
    }
}
