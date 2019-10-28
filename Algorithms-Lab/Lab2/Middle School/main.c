#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    if (a > b)
        gcd(b, a);
    int fact = 2;
    int gcd = 1;
    int z = a;

    for (fact = 2; fact <= z; ++fact)
    {
        while(a%fact == 0 && b%fact == 0){
            gcd = gcd * fact;
            b = b/fact;
            a = a/fact;
            if (a == 0 || b == 0)
            {
                return gcd;
            }
        }
    }
    return gcd;
}

int main(){
    printf("%d\n", gcd(66, 96));
}