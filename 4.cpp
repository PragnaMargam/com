// 4.Implement operator precedence parser

#include <bits/stdc++.h>
using namespace std;

// Function f to exit from the loop
// if given condition is not true
void f()
{
    cout << "Not operator grammar" << endl;
    exit(0);
}

int main()
{
    char grm[20][20], c;
    int i, n, j = 2, flag = 0;

    // Taking number of productions from user
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> grm[i];

    for (i = 0; i < n; i++)
    {
        c = grm[i][2];

        while (c != '\0')
        {

            if (grm[i][3] == '+' || grm[i][3] == '-' || grm[i][3] == '*' || grm[i][3] == '/')
                flag = 1;
            else
            {
                flag = 0;
                f();
            }

            if (c == '$')
            {
                flag = 0;
                f();
            }

            c = grm[i][++j];
        }
    }

    if (flag == 1)
        cout << "Operator grammar" << endl;

    return 0;
}

// https://www.geeksforgeeks.org/operator-grammar-and-precedence-parser-in-toc/
//Input :3
// A=A*A
// B=AA
// A=$

// Output : Not operator grammar
