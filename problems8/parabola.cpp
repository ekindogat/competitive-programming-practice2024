    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {

        // formula: -x^2 + bx + c

        long n, q;
        cin >> n >> q;

        vector<vector<long>> parabolas;
        vector<long> queries;
        vector<long long> results;
        for (int i = 0; i < n; i++)
        {
            vector<long> coef;
            long coef1, coef2;
            cin >> coef1 >> coef2;
            coef.push_back(coef1);
            coef.push_back(coef2);
            parabolas.push_back(coef);
        }
        for (long i = 0; i < q; i++)
        {
            long x;
            cin >> x;
            queries.push_back(x);
        }
        long p_index = 0;
        for (long i = 0; i < q; i++)
        {
            long x = queries[i];
            for (long p = 0; p < n; p++)
            {
                long long res = (-1 * x * x) + (x * parabolas[p][0]) + (parabolas[p][1]);

                results.push_back(res);
                if (results[p_index] < res)
                    p_index = p;
            }
            cout << p_index + 1 << "\n";
        }
        cin.get();
        cin.get();
        return 0;
    }