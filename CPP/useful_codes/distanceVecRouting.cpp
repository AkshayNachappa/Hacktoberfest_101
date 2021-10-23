#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct node
{
    int dist[20];
    int from[20];
} route[10];

int main()
{
    int dm[20][20], no;

    cout << "Enter nodes : ";
    cin >> no;
    cout << "Enter the cost matrix :" << endl;
    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < no; j++)
        {
            cin >> dm[i][j];
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do
    {
        flag = 0;
        for (int i = 0; i < no; i++)
        {
            for (int j = 0; j < no; j++)
            {
                for (int k = 0; k < no; k++)
                {
                    if ((route[i].dist[j]) > (route[i].dist[k] + route[k].dist[j]))
                    {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < no; i++)
    {
        cout << "Router " << i + 1 << endl;
        cout << "| Destination | Distance |  Next  |" << endl;
        for (int j = 0; j < no; j++)
        {
            if (route[i].dist[j] == 0)
                cout << "| Node " << j + 1 << "      |"
                     << "\t" << route[i].dist[j] << "\t |"
                     << "  -  "
                     << "   | \n";
            else
                cout << "| Node " << j + 1 << "      |"
                     << "\t" << route[i].dist[j] << "\t |"
                     << " Node " << route[i].from[j] + 1 << " | \n";
        }
        cout << "\n\n";
    }
    getch();
    return 0;
}
