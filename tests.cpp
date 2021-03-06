#include <stdio.h>
#include <math.h>
#include "tests.h"

int main()
{

        make_test(0, 0, 0, 0, 0, INF_SOL);
        make_test(0, 0, 2.5, 0, 0, NO_SOL);
        make_test(0, -3.65, 0, 0, 0, ONE_SOL);
        make_test(0, 5, -10, 0, 2, ONE_SOL);
        make_test(2, 0, -9, -2.1213203, 2.1213203, TWO_SOL);
        make_test(5.63, 2.96, 1.3, 0, 0, NO_SOL);
        make_test(1, 2, 1, -1, 0, ONE_SOL);
        
        return 0;
}

void make_test(double coef_a, double coef_b, double coef_c, 
               double sol1, double sol2, num_of_solutions number_sols)
{
        quadra equation; 
        answer ans;

        equation.a_coef = coef_a;
        equation.b_coef = coef_b; 
        equation.c_coef = coef_c;

        ans.solution1 = sol1;
        ans.solution2 = sol2;
        ans.sol_num = number_sols;

        solve_equation(&equation);
        sort_solutions(&equation);
        test_msg(&equation, &ans, check(&equation, &ans));
}

bool check(quadra* equation, answer* ans)
{
        return (are_equal(ans->solution1, equation->solution1) &&
                are_equal(ans->solution2, equation->solution2) &&
                ans->sol_num == equation->sol_num);
}

void test_msg(quadra* equation, answer* ans, bool status)
{
        if (status)
        {
                printf("\x1b[32mOK\n\x1b[0m");

                return;
        }

        printf("\n\n\x1b[31mFAILURE\x1b[0m\n");

        printf("Expected:\n");
        printf("x1 = %lf, x2 = %lf, number of solutions: ", 
                ans->solution1, ans->solution2);
        
        if (ans->sol_num == NO_SOL)
                printf("0.\n");
        else if (ans->sol_num == ONE_SOL)
                printf("1.\n");
        else if (ans->sol_num == TWO_SOL)
                printf("2.\n");
        else 
                printf("Infinite.\n");

        printf("Recieved:\n");
        printf("x1 = %lf, x2 = %lf, number of solutions: ", 
                equation->solution1, equation->solution2);
        
        if (equation->sol_num == NO_SOL)
                printf("0.\n");
        else if (equation->sol_num == ONE_SOL)
                printf("1.\n");
        else if (equation->sol_num == TWO_SOL)
                printf("2.\n");
        else 
                printf("Infinite.\n");

        printf("\n");
}

