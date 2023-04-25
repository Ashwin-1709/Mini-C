#include "symboltable.h"
#include "ast.h"

int main() {
    // int x = 11;
    // float y = 11.5;
    // char b = 'd';
    // int a[10] = {89, 41, 24};
    // float f[10] = {60.5 , 12.5};
    // char c[10] = "ok\n";
    // void *ok = (void *)&a;
    // int *new_h = vtoa(ok);
    // void *ok2 = (void *)&f;
    // float *fn = vtofa(ok2);
    // void *ok3 = (void *)&c;
    // printf("%d %d\n", vtoi((void *)&x), new_h[1]);
    // printf("%f %f\n", vtof((void *)&y), fn[1]);
    // printf("%c %s\n", vtoc((void *)&b), vtoca(ok3));

    table* parent = createTable();
    table *child = changeScope(parent);
    int x = 10, y = 1;
    insertvar("func" , 0 , (void *)&x , -1 , -1 , parent);
    printf("%d %d\n", searchTable(parent, "func") , searchTable(child,  "func"));
    insertvar("okabc" , 0 , (void *)&y , -1 , -1 , child);
    printf("%d %d\n", isDeclared("func", child), isDeclared("okabc", parent));
    char c = 'a';
    insertvar("c" , type("char"), (void *)&c , -1 , -1 , child);
    printf("%d %d\n", typevar(child, "c") , typevar(parent, "c"));
    printf("%s %s %s %s %s %s\n", retype(0), retype(1) , retype(2) , retype(3) , retype(9) , retype(-1));

    insertfunc("solve", 0, parent , 3 , 0 , 0 , 1);
    printf("%d\n", isDeclared("solve" , parent));

    // astNode* a = createNodeByLabel("S");
    // astNode* b = createNodeByLabel("id");
    // astNode* c = createNodeByLabel("func");
    // astNode* d = createNodeByLabel("P");
    // astNode* e = createNodeByLabel("x");
    // astNode* f = createNodeByLabel("f");
    // addNode(b , c);
    // addNode(d, e);
    // addNode(b , f);
    
    // addNode(a, d);
    // // addNode(a, b);
    // printf("%s\n", find_id(a));
    return 0;
}
