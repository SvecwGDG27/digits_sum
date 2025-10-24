#include <stdio.h>

int sumDigits(long long n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    long long num;
    scanf("%lld", &num);
    if (num < 0) num = -num;
    printf("%d", sumDigits(num));
    return 0;
}
