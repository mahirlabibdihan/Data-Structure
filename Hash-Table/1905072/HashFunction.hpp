#include <string>
#include <set>
#include <iostream>
using namespace std;
// Hash1 :: PolynomialRollHashFunction
uint64_t hash1(string &s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    uint64_t hash_value = 0;
    uint64_t p_pow = 1;
    for (char c : s)
    {
        hash_value = (hash_value + c * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

// Jenkins Hash Function
uint64_t hash2(string &s, int mod)
{
    uint64_t hash_value = 0;
    const int n = s.size();
    for (int i = 0; i < n; i++)
    {
        hash_value = (hash_value + s[i]);
        hash_value = (hash_value + (hash_value << 10));
        hash_value = (hash_value ^ (hash_value >> 6));
    }
    hash_value = (hash_value + (hash_value << 3));
    hash_value = (hash_value ^ (hash_value >> 11));
    hash_value = (hash_value + (hash_value << 15));

    // return hash_value % mod; // Creates problem when result is 0
    // cout << (hash_value % (mod - 1)) + 1 << endl;
    return (hash_value % (mod - 1)) + 1;
}
void test_h1(int n)
{
    set<string> data;
    set<int> codes;
    while (data.size() < 100)
    {
        string s;
        for (int j = 0; j < 7; j++)
        {
            char c = 'a' + rand() % 26;
            s += c;
        }
        data.insert(s);
    }
    for (auto s : data)
    {
        int hash_code = hash1(s) % n;
        codes.insert(hash_code);
    }
    cout << "H1 is " << codes.size() << "% effective" << endl;
}
void test_h2(int n)
{
    set<string> data;
    set<int> codes;
    while (data.size() < 100)
    {
        string s;
        for (int j = 0; j < 7; j++)
        {
            char c = 'a' + rand() % 26;
            s += c;
        }
        data.insert(s);
    }
    for (auto s : data)
    {
        int hash_code = hash2(s, n) % n;
        // cout << hash_code << " " << endl;
        codes.insert(hash_code);
    }
    cout << "H2 is " << codes.size() << "% effective" << endl;
}