/*  This program discounts the weight of grades as the number
*   of wrong answers increases. This program is useful for grading tests that have a "snowball" effect — where
*   getting one answer wrong makes it more likely to get further answers wrong. This grading scale also
*   helps to give weight to good faith efforts and prevents tanking a students grade, as the lowest possible
*   score typically occurs at 45.
*
*   The #wrong is printed in the first column, then the regular unweighted score, then the weighted score is printed.
*   The values can then be exported into an excel sheet for quick reference or use in the "find-replace" function.
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TOTAL 50// Change the total number of questions here to anything from 1-100

int main(void)
{
// Each number wrong should count for progressively less. Uses a for loop to progressively lower the weighting for each number wrong
// In other words, instead of each point wrong being worth 2 pts, each number will be worth 2*.xx pts, where .xx is a percentage

    int wrong;
    int i;

    printf("\n#Wrong\tReg\tWeighted\n"); // Print column headings

    // weight each consecutive point less up to the number wrong.
    for (wrong = 0; wrong <= TOTAL; wrong++)
    {
        // reinitialize each time in order to reset the total.
        float final = TOTAL;

        for (i = 0; i < wrong; i++)
        {
            // convert i to float in order to to use it in the following division assignment to weight
            float subt = (float)i;

            float weight = ((TOTAL - subt) / TOTAL);

            final -= weight;
        } // End nested for loop

        final /= TOTAL;
        final *= 100;

        int number = 100 - (wrong * (100 / TOTAL) ) ;

        printf("%i\t%i\t%i\n", wrong, number, (int)final );

    } // End for loop

    printf("\n");
    return 0;

} // End Main