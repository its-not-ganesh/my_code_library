#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int ret_index(vector<string> x, string inp)
{
    for (int i = 0; i < x.size(); ++i)
    {
        if (x[i] == inp)
            return i;
    }
    return -1;
}

vector<int> street_count(vector<vector<string>> route, vector<string> streets, vector<int> end_street)
{
    vector<int> res;
    for (int i = 0; i < streets.size(); ++i)
    {
        res.push_back(0);
    }

    for (int i = 0; i < route.size(); ++i)
    {
        vector<string> fin = route[i];
        for (int j = 0; j < fin.size(); j++)
        {
            int x = ret_index(streets, fin[j]);
            res[x]++;
        }
    }
    return res;
}
vector<vector<string>> incoming_roads_intersection(vector<int> end_points, vector<string> street_names, int intersections)
{
    vector<vector<string>> ips;
    for (int i = 0; i < intersections; ++i)
    {
        vector<string> x;
        for (int j = 0; j < end_points.size(); j++)
        {
            int f = end_points[j];
            if (f == i)
            {
                x.push_back(street_names[j]);
            }
        }
        ips.push_back(x);
    }

    return ips;
}

void easy_points() {}

int main()
{
    int d, inter, s, v, f;
    cin >> d >> inter >> s >> v >> f;
    vector<int> start_street, end_street, time_street, num_street;
    vector<string> name_street;
    vector<vector<string>> route, intersection_incoming_names;
    for (int i = 0; i < s; ++i)
    {
        int b, e, l;
        string name;
        cin >> b >> e >> name >> l;
        start_street.push_back(b);
        end_street.push_back(e);
        name_street.push_back(name);
        time_street.push_back(l);
    }

    for (int i = 0; i < v; i++)
    {
        int n;
        vector<string> name;
        cin >> n;
        string q;
        for (int j = 0; j < n; j++)
        {
            cin >> q;
            name.push_back(q);
        }
        route.push_back(name);
    }

    intersection_incoming_names = incoming_roads_intersection(end_street, name_street, inter);
    vector<int> counters;
    vector<int> fff = street_count(route, name_street, end_street);

    ofstream myfile;
    myfile.open("finals_output.txt");
    // cout << inter << endl;
    myfile << inter << endl;
    for (int i = 0; i < inter; i++)
    {
        myfile << i << endl;
        // cout << i << endl;
        vector<string> fig = intersection_incoming_names[i];
        int counter = 0;
        for (int j = 0; j < fig.size(); j++)
        {
            if (fff[j] == 0)
                counter++;
        }
        myfile << fig.size() - counter << endl;
        // cout << fig.size() << endl;
        for (int j = 0; j < fig.size(); j++)
        {
            if (fff[j] != 0)
            {
                myfile << fig[j];
                myfile << " ";
                myfile << (fff[j] / 2) + 1 << endl;
            }
        }
    }

    return 0;
}