#include <stdio.h>
#include <math.h>

int main(){
    float a, b, fn, nlg, power, regularity;

    printf("Enter value of a: ");
    scanf("%f", &a);
    printf("Enter value of b: ");
    scanf("%f", &b);
    printf("Enter exponent of f(n): n^");
    scanf("%f", &fn);

    if (a <= 0 || b <= 1) {
        printf("Invalid value of a or b!\n");
        return 1;
    }

    printf("\nPROBLEM: %.fT(n/%.f) + n^%.1f\n\n", a, b, fn);

    nlg = log(a) / log(b);

    if (nlg > fn) {
        printf("CASE: n^logb(a) = n^%.1f > f(n) = n^%.1f, therefore case 1 applies: \n", nlg, fn);
        printf("\nAnswer: T(n) = O(n^%.1f)\n", nlg);
    } else if (nlg == fn) {
        printf("CASE: n^logb(a) = n^%.1f = f(n) = n^%.1f, therefore case 2 applies: \n", nlg, fn);
        printf("\nAnswer: T(n) = O(n^%.1f log n)\n", nlg);
    } else if (nlg < fn) {
        power = pow(b, fn);
        regularity = a / power;

        printf("CASE: n^logb(a) = n^%.1f < f(n) = n^%.1f AND Regularity condition is %.2f < 1, therefore case 3 applies:\n", nlg, fn, regularity);
        printf("\nAnswer: T(n) = O(n^%.1f)\n", fn);
    } else {
        printf("Master Theorem does not apply.\n");
    }
}
