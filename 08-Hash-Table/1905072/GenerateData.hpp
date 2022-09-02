#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
int random(int i) { return rand() % i; }
void generateData(vector<vector<string>> &all_data_set,
                  vector<vector<string>> &all_search_set_before,
                  vector<vector<string>> &all_search_set_after,
                  vector<vector<string>> &all_deleted_set,
                  int n)
{
    srand(time(NULL));
    for (int load_factor = 4; load_factor < 10; load_factor += 1)
    {
        // cout << "Hash table of size " << n << " created" << endl;
        int n_word = n * load_factor * 0.1;
        set<string> data;
        while (data.size() < n_word)
        {
            string s;
            for (int j = 0; j < 7; j++)
            {
                char c = 'a' + rand() % 26;
                s += c;
            }
            data.insert(s);
        }
        // cout << n_word << " words generated to insert" << endl;
        vector<string> dataset(data.begin(), data.end());
        all_data_set.push_back(dataset);
        random_shuffle(dataset.begin(), dataset.end(), random);
        // cout << "GENERATED" << endl;
        int n_search = n_word * 0.1;
        vector<string> search_set_before(n_search);
        for (int i = 0; i < n_search; i++)
        {
            search_set_before[i] = dataset[i];
        }
        all_search_set_before.push_back(search_set_before);
        // cout << n_search << " words selected to search" << endl;
        int n_delete = n_word * 0.1;
        vector<string> deleted_set(n_delete);
        random_shuffle(dataset.begin(), dataset.end(), random);
        for (int i = 0; i < n_delete; i++)
        {
            deleted_set[i] = dataset[i];
        }
        all_deleted_set.push_back(deleted_set);
        // cout << n_delete << " words selected to delete" << endl;
        random_shuffle(deleted_set.begin(), deleted_set.end(), random);
        vector<string> search_set_after(n_search);
        vector<string> not_deleted_set(n_word - n_delete);
        for (int i = n_delete; i < n_word; i++)
        {
            not_deleted_set[i - n_delete] = dataset[i];
        }
        random_shuffle(not_deleted_set.begin(), not_deleted_set.end(), random);
        for (int i = 0; i < n_search; i++)
        {
            if (i % 2 == 0)
            {
                search_set_after[i] = not_deleted_set[i / 2];
            }
            else
            {
                search_set_after[i] = deleted_set[i / 2];
            }
        }
        all_search_set_after.push_back(search_set_after);
    }
}