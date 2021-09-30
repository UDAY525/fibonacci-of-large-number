#include <stdio.h>
#define N 7000

// INITIALIZING STRINS 
char fib1[N], fib0[N], fibN[N];
int  carry = 0;
int k = N - 1;
void fibonacci(int n)
{
    if (n == 0)
    {
        printf("%d", 0);
        return;
    }
    else if (n == 1)
    {
        printf("%d", 1);
        return;
    }

    // INITITALIZING THE FIRST TWO SEQUENCES IN FIBONACCI
    fib1[N - 1] = 1;
    fib0[N - 1] = 0;

    // FIND REMAINING N-1 SEQUENCES IN FIBONACCI
    for (int i = 2; i <= n; i++)
    {
        for (int i = N - 1; i >= k; i--)
        {
    // ADDING EACH DIGIT FROM LAST TWO SEQUENCES
            int value = fib1[i] + fib0[i] + carry;
    // ASSIGN SINGLE DIGIT FROM VALUE AND CARRY REMAINIG
            fibN[i] = (value % 10);
            carry = value / 10;
            if (i == k && carry > 0)
                k--;
        }
    // FOR FINDING NEXT SEQUENCE ADJUST THE LAST TWO TERMS IN SEQUENCE
        for (int i = N - 1; i >= k; i--)
        {
            fib0[i] = fib1[i];
            fib1[i] = fibN[i];
        }
    }
    // NOW PRINT THE REQUIRED FIBONACCI TERM 
    for (int i = k; i < N; i++)
        printf("%d", fibN[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the required nth fibonacci number:\n");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
