#include <bits/stdc++.h>

using namespace std;

template <class T>
void addEdge(unordered_map<T, list<pair<T, int>>> &g, T v1, T v2, int wt, bool isdirected)
{
    g[v1].push_back(make_pair(v2, wt));

    if (!isdirected)
        g[v2].push_back(make_pair(v1, wt));
    else
    {
        if (g[v2].empty())
        {
            g[v2].push_back(make_pair(0, 0)); //node not directed to another node
            g[v2].pop_back();
        }
    }
}

template <class T>
void adjlist(unordered_map<T, list<pair<T, int>>> g)
{
    for (auto node : g)
    {
        cout << node.first << "->";
        for (auto nbr : node.second)
        {
            cout << "(" << nbr.first << "," << nbr.second << ") , ";
        }
        cout << endl;
    }
}

template <class T>
T findMin(unordered_map<T, list<pair<T, int>>> g, unordered_map<T, bool> is_min_d, unordered_map<T, int> d)
{
    int min = INT_MAX;
    T min_node = g.begin()->first;
    for (auto i : d)
    {
        if (i.second < min && !is_min_d[i.first])
        {
            min = i.second;
            min_node = i.first;
        }
    }
    return min_node;
}

template <class T>
unordered_map<T, int> dijkstra(unordered_map<T, list<pair<T, int>>> g, T s)
{
    unordered_map<T, int> d;
    unordered_map<T, bool> is_min_d; // all values are false(0) initially

    for (auto node : g)
        d[node.first] = INT_MAX;

    d[s] = 0;

    for (int i = 0; i < g.size() + 1; i++)
    {
        T min_node = findMin(g, is_min_d, d);
        is_min_d[min_node] = true;

        for (auto nbr : g[min_node])
        {
            if (d[min_node] + nbr.second < d[nbr.first])
                d[nbr.first] = d[min_node] + nbr.second;
        }
    }
    return d;
}

int main()
{
    unordered_map<char, list<pair<char, int>>> g;

    addEdge(g, 'A', 'B', 10, true);
    addEdge(g, 'A', 'C', 5, true);
    addEdge(g, 'C', 'B', 3, true);
    addEdge(g, 'C', 'E', 2, true);
    addEdge(g, 'E', 'D', 6, true);
    addEdge(g, 'B', 'D', 1, true);
    addEdge(g, 'C', 'D', 9, true);
    addEdge(g, 'E', 'A', 2, true);

    adjlist(g);
    unordered_map<char, int> ans = dijkstra(g, 'A');
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }
}
