#include <stdio.h>
#include <ctype.h>

// atof - returns double given a number string that is optionally signed. Also
// handles number strings in scientific notation that is optionally signed.
long double atof(char number_string[]);

int main()
{
    printf("%Lf\n", atof("32.4e12"));
    printf("%Lg\n", atof("  +32.4E+12"));
    printf("%Lf\n", atof("-32.4e-5"));
    printf("%Lf\n", atof("-.324E-3"));

    return 0;
}

long double atof(char s[])
{
    int i = 0, sign, power_count = 0;
    long double ret;
    while (isspace(s[i]))
        ++i;
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        ++i;
    for (ret = 0.0; isdigit(s[i]); ++i)
        ret = ret * 10 + s[i] - '0';
    if (s[i] == '.')
        ++i;
    for (; isdigit(s[i]); ++i)
    {
        ret = ret * 10 + s[i] - '0';
        --power_count;
    }
    if ((s[i] == 'e' || s[i] == 'E'))
    {
        int exp_sign = s[++i] == '-' ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            ++i;
        int exp;
        for (exp = 0; isdigit(s[i]); ++i)
            exp = exp * 10 + s[i] - '0';
        power_count += exp_sign * exp;
    }
    long power = 1;
    int count;
    count = power_count >= 0 ? power_count : -power_count;
    for (; count != 0; --count)
        power *= 10;
    return power_count >= 0 ? sign * ret * power : sign * ret / power;
}
