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
    int n = 1000003;
    cin >> n;
    test_h1(n);
    test_h2(n);
    // Inputs
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
    generateReport(all_time_before, all_time_after, all_probes_before, all_probes_after, n);
}
