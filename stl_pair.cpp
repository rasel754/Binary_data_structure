#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pair<int, int> p;j
    // p = make_pair(2, 3);
    // shortcut of upper line
    // p={2,3};
    // cout << p.first << endl;
    // cout << p.second << endl;

    int n;
    cin >> n;
    // vector in pair
    vector<pair<int, int>>v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >>v[i].second;
    }

      for (int i = 0; i < n; i++)
    {
        cout<< v[i].first << " " << v[i].second<<endl;
    }

    return 0;
}