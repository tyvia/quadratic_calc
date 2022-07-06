#define EPSILON 0.000001

struct quadra {
        double a_coef = 0;
        double b_coef = 0;
        double c_coef = 0;
        double solution1 = 0;
        double solution2 = 0;
        double discriminant_squared = 0;
};

int compare(double value1, double value2);
void scanner(struct quadra equation);
void solve(struct quadra equation);
void print_solution(struct quadra equation);

