#include <stdio.h>
#include <math.h>

int main() {
    float a, b, fn, nlg, power, regularity;

    //--- prompt user to input values for constants and exponent ---//
    printf("Enter value of a: ");
    scanf("%f", &a);
    printf("Enter value of b: ");
    scanf("%f", &b);
    printf("Enter exponent of f(n): n^");
    scanf("%f", &fn);

    //--- check if the inputs are valid for Master Theorem ---//
    if (a <= 0 || b <= 1) {
        printf("Invalid value of a or b!\n"); //--- a should be > 0, b should be > 1 ---//
        return 1; //--- terminate program due to invalid input ---//
    }

    //--- print the recurrence relation ---//
    printf("\nPROBLEM: %.fT(n/%.f) + n^%.1f\n\n", a, b, fn);

    //--- calculate log base b of a using change of base formula ---//
    nlg = log(a) / log(b);

    //--- case 1: n^logb(a) > f(n) ---//
    if (nlg > fn) {
        printf("CASE: n^logb(a) = n^%.1f > f(n) = n^%.1f, therefore case 1 applies: \n", nlg, fn);
        printf("\nAnswer: T(n) = O(n^%.1f)\n", nlg);
    }
    //--- case 2: n^logb(a) == f(n) ---//
    else if (nlg == fn) {
        printf("CASE: n^logb(a) = n^%.1f = f(n) = n^%.1f, therefore case 2 applies: \n", nlg, fn);
        printf("\nAnswer: T(n) = O(n^%.1f log n)\n", nlg);
    }
    //--- case 3: n^logb(a) < f(n) ---//
    else if (nlg < fn) {
    power = pow(b, fn); //--- calculate b^fn for regularity condition ---//
    regularity = a / power; //--- calculate the regularity condition value ---//

        if (regularity < 1) { //--- check if regularity condition is satisfied ---//
            printf("CASE: n^logb(a) = n^%.1f < f(n) = n^%.1f AND Regularity condition is %.2f < 1, therefore case 3 applies:\n", nlg, fn, regularity);
            printf("\nAnswer: T(n) = O(n^%.1f)\n", fn);
        } else {
            //--- regularity condition not satisfied ---//
            printf("Regularity condition is %.2f >= 1, so Master Theorem does not apply.\n", regularity);
        }
    }
    //--- if none of the cases match, theorem does not apply ---//
    else {
        printf("Master Theorem does not apply.\n");
    }
}
