#include <vector>
#include <string>
#include <chrono>
#include "HashTable.hpp"
#include "OpenAddressing.hpp"
#include "ClosedAddressingRBT.hpp"
using namespace std;
using namespace chrono;

double getDifference(chrono::time_point<system_clock> start_time, chrono::time_point<system_clock> end_time)
{
    return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

void generateResult(vector<vector<string>> &all_data_set,
                    vector<vector<string>> &all_search_set_before,
                    vector<vector<string>> &all_search_set_after,
                    vector<vector<string>> &all_deleted_set,
                    vector<vector<double>> &all_time_before,
                    vector<vector<double>> &all_time_after,
                    vector<vector<double>> &all_probes_before,
                    vector<vector<double>> &all_probes_after,
                    int n)
{
    for (int type = hash_type::SEPARATE_CHAINING; type <= hash_type::DOUBLE_HASHING; type++)
    {
        // cout << type << endl;
        for (int load_factor = 4; load_factor < 10; load_factor++)
        {
            int idx = load_factor - 4;
            int n_word = n * load_factor * 0.1;
            int n_search = n_word * 0.1;
            int n_delete = n_word * 0.1;
            HashTable *ht;
            if (type == hash_type::SEPARATE_CHAINING)
            {
                ht = new ClosedAddressing(n, static_cast<hash_type>(type));
            }
            else
            {
                ht = new OpenAddressing(n, static_cast<hash_type>(type));
            }
            for (int i = 0; i < n_word; i++)
            {
                ht->insert(all_data_set[idx][i], i + 1);
            }
            ht->resetProbCount();
            {
                chrono::time_point<system_clock> start_time = chrono::high_resolution_clock::now();
                for (int i = 0; i < n_search; i++)
                {
                    ht->search(all_search_set_before[idx][i]);
                }
                chrono::time_point<system_clock> end_time = chrono::high_resolution_clock::now();
                all_time_before[type][idx] = getDifference(start_time, end_time) / n_search;
                all_probes_before[type][idx] = 1.0 * ht->getProbCount() / n_search;
            }

            for (int i = 0; i < n_delete; i++)
            {
                ht->remove(all_deleted_set[idx][i]);
            }
            ht->resetProbCount();
            {
                chrono::time_point<system_clock> start_time = chrono::high_resolution_clock::now();
                for (int i = 0; i < n_search; i++)
                {
                    ht->search(all_search_set_after[idx][i]);
                }
                chrono::time_point<system_clock> end_time = chrono::high_resolution_clock::now();
                all_time_after[type][idx] = getDifference(start_time, end_time) / n_search;
                all_probes_after[type][idx] = 1.0 * ht->getProbCount() / n_search;
            }
            delete ht;
        }
    }
}