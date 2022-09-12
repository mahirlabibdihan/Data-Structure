#include <iostream>
#include <vector>
#include <string>
#include "HashTable.hpp"
using namespace std;

void generateReport(vector<vector<double>> &all_time_before,
                    vector<vector<double>> &all_time_after,
                    vector<vector<double>> &all_probes_before,
                    vector<vector<double>> &all_probes_after,
                    int n)
{
    vector<string> labels = {"Separate Chaining", "Linear Probing", "Quadratic Probing", "Double Hashing"};
    cout << "N = " << n << endl;
    for (int type = hash_type::SEPARATE_CHAINING; type <= hash_type::DOUBLE_HASHING; type++)
    {
        for (int i = 0; i < 113; i++)
        {
            cout << '_';
        }
        cout << "\n";
        cout << "| ";
        for (int i = 0; i < 17; i++)
        {
            if (i < labels[type].length())
            {
                cout << labels[type][i];
            }
            else
            {
                cout << " ";
            }
        }
        printf(" | %-43s | %-43s |\n", "Before deletion", "After deletion");
        for (int i = 0; i < 113; i++)
        {
            if (i == 0 || i == 20 || i == 66 || i == 112)
            {
                cout << "|";
            }
            else
            {
                cout << '_';
            }
        }
        cout << "\n";

        printf("| %-17s | %-20s | %-20s | %-20s | %-20s |\n", "Load factor", "Avg search time (ns)", "Avg number of probes", "Avg search time (ns)", "Avg number of probes");
        for (int i = 0; i < 113; i++)
        {
            if (i == 0 || i == 20 || i == 43 || i == 66 || i == 89 || i == 112)
            {
                cout << "|";
            }
            else
            {
                cout << '_';
            }
        }
        cout << "\n";
        for (int load_factor = 4; load_factor < 10; load_factor++)
        {
            cout << "| ";
            printf("%-17g", load_factor * 0.1);
            cout << " | ";
            int idx = load_factor - 4;
            printf("%-20g", all_time_before[type][idx]);
            cout << " | ";
            if (type == hash_type::SEPARATE_CHAINING)
                printf("%-20s", "N/A");
            else
                printf("%-20g", all_probes_before[type][idx]);
            cout << " | ";
            printf("%-20g", all_time_after[type][idx]);
            cout << " | ";
            if (type == hash_type::SEPARATE_CHAINING)
                printf("%-20s", "N/A");
            else
                printf("%-20g", all_probes_after[type][idx]);
            cout << " |\n";
        }
        for (int i = 0; i < 113; i++)
        {
            if (i == 0 || i == 20 || i == 43 || i == 66 || i == 89 || i == 112)
            {
                cout << "|";
            }
            else
            {
                cout << '_';
            }
        }
        cout << "\n\n";
    }

    for (int load_factor = 4; load_factor < 10; load_factor++)
    {
        int idx = load_factor - 4;
        for (int i = 0; i < 113; i++)
        {
            cout << '_';
        }
        cout << "\n";
        printf("| %-12s %-2g  | %-43s | %-43s |\n", "Load factor:", load_factor * 0.1, "Before deletion", "After deletion");
        for (int i = 0; i < 113; i++)
        {
            if (i == 0 || i == 20 || i == 66 || i == 112)
            {
                cout << "|";
            }
            else
            {
                cout << '_';
            }
        }
        cout << "\n";
        printf("| %-17s | %-20s | %-20s | %-20s | %-20s |\n", "Method", "Avg search time (ns)", "Avg number of probes", "Avg search time (ns)", "Avg number of probes");
        for (int i = 0; i < 113; i++)
        {
            if (i == 0 || i == 20 || i == 43 || i == 66 || i == 89 || i == 112)
            {
                cout << "|";
            }
            else
            {
                cout << '_';
            }
        }
        cout << "\n";
        for (int type = hash_type::SEPARATE_CHAINING; type <= hash_type::DOUBLE_HASHING; type++)
        {
            cout << "| ";
            for (int i = 0; i < 17; i++)
            {
                if (i < labels[type].length())
                {
                    cout << labels[type][i];
                }
                else
                {
                    cout << " ";
                }
            }
            cout << " | ";
            printf("%-20g", all_time_before[type][idx]);
            cout << " | ";
            if (type == hash_type::SEPARATE_CHAINING)
                printf("%-20s", "N/A");
            else
                printf("%-20g", all_probes_before[type][idx]);
            cout << " | ";
            printf("%-20g", all_time_after[type][idx]);
            cout << " | ";
            if (type == hash_type::SEPARATE_CHAINING)
                printf("%-20s", "N/A");
            else
                printf("%-20g", all_probes_after[type][idx]);
            cout << " |\n";
        }
        for (int i = 0; i < 113; i++)
        {
            if (i == 0 || i == 20 || i == 43 || i == 66 || i == 89 || i == 112)
            {
                cout << "|";
            }
            else
            {
                cout << '_';
            }
        }
        cout << "\n\n";
    }
}