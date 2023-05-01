int func(int a, int b){
    int c = a * b;
    return c * 5;
}

main(){
    int a = 5;
    int x = func(a, 1);
    while(x > 0){
        printf("%d", x);
        x = x - 1;
    }
    return -1;
}
