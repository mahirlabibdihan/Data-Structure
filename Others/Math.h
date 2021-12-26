namespace Math {

    pair<double, double> fraction(double s)
    {
        double numerator = s , denominator = 1;

        int i, j;
        while (numerator - int(numerator) > .0000001)
        {
            numerator *= 10;
            denominator *= 10;
        }

        double temp = numerator;
        for (i = 2; i <= numerator ; i++)
        {
            if (fmod(numerator , i) == 0 && fmod(denominator , i) == 0)
            {
                numerator /= i;
                denominator /= i ;
            }
        }
        return {numerator, denominator};
    }

    double recursivePower(double x, int n)
    {
        if (n == 0) return 1;
        return x * recursivePower(x, n - 1);
    }

    double root(double n, double x)
    {
        double l = 0, r = n, m = 0;
        if (n <= 1) r = 1;
        while (r - l > .000000000001)
        {
            double temp = (l + r) / 2;
            if (m == temp)
            {
                break;
            }
            m = temp;
            (recursivePower(m, x) > n) ? r = m : l = m;
        }
        return m;
    }

    double power(double n, double pow)
    {
        pair<double, double> num(fraction(pow));
        n = recursivePower(n, num.first);
        if (num.second == 1) return n;
        else return root(n, num.second);
    }
}