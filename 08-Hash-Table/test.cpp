#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <set>
#include "OpenAddressing.hpp"
#include <map>
void SieveOfEratosthenes(vector<bool> &prime, int n)
{
    fill(prime.begin(), prime.end(), true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
}
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <set>
#include "GenerateData.hpp"
#include "GenerateReport.hpp"
#include "GenerateResult.hpp"
using namespace chrono;
int main()
{
    // freopen("output.in", "w", stdout);
    int N = 1000003;
    vector<bool> prime(N + 1);
    SieveOfEratosthenes(prime, N);
    // cin >> n;
    // Inputs
    for (int n = 1; n <= N; n++)
    {
        if (prime[n])
        {
            cout << n << endl;
            vector<vector<string>> all_data_set;
            vector<vector<string>> all_search_set_before;
            vector<vector<string>> all_search_set_after;
            vector<vector<string>> all_deleted_set;
            // Outputs
            vector<vector<double>> all_time_before(4, vector<double>(6));
            vector<vector<double>> all_time_after(4, vector<double>(6));
            vector<vector<double>> all_probes_before(4, vector<double>(6));
            vector<vector<double>> all_probes_after(4, vector<double>(6));
            // Functions
            generateData(all_data_set, all_search_set_before, all_search_set_after, all_deleted_set, n);
            generateResult(all_data_set, all_search_set_before, all_search_set_after, all_deleted_set, all_time_before, all_time_after, all_probes_before, all_probes_after, n);
            // generateReport(all_time_before, all_time_after, all_probes_before, all_probes_after, n);
        }
    }
}