#include <iostream>
#include <vector>
#include <cassert>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills_greedy(int dist, const int tank, const vector<int>& stops) {

    int number_of_stops{0};

    int tank_current{tank};

    vector<int> stops_Dist;

    stops_Dist.push_back(0);

    for (size_t i = 0; i < stops.size(); i++)
    {
        if (i == 0)
        {
            stops_Dist.push_back(stops[i]);
        }
        else
        {
            stops_Dist.push_back(stops[i]);   
        }
    }
    stops_Dist.push_back(dist);


    for (size_t i = 0; i < stops_Dist.size(); i++)
    {
        if (i > 0)
        {
            if (stops_Dist[i] - stops_Dist[i - 1] > tank)
            {
                return -1;
            }

            tank_current -= stops_Dist[i] - stops_Dist[i - 1];
        }

        if (i == stops_Dist.size() - 1)
        {
            break;
        }
        
        if (tank_current < stops_Dist[i + 1] - stops_Dist[i])
        {
            tank_current = tank;
            number_of_stops++;
        } 
    }

    return number_of_stops;
}



int compute_min_refills(int dist, const int tank, const vector<int>& stops) {
    // write your code here
    int number_of_stops{0};

    int tank_current{tank};

    vector<int> stops_Dist;

    if (dist - stops[stops.size() - 1] > tank)
    {
        return -1;
    }
    else if (tank > dist)
    {
        return 0;
    }
    else
    {
        for (size_t i = 0; i < stops.size(); i++)
        {
            if (i == 0)
            {
                if (stops[i] > tank)
                {
                    return -1;
                }
                else
                    stops_Dist.push_back(stops[i]);
            }
            else
            {
                if (stops[i] - stops[i - 1] > tank)
                {
                    return -1;
                }
                else
                {
                    stops_Dist.push_back(stops[i] - stops[i - 1]);
                }
            }
        }

        for (size_t i = 0; i < stops_Dist.size(); i++)
        {
            if (i == stops_Dist.size() - 1)
            {
                tank_current = tank_current - stops_Dist[i];
                if (tank_current - (dist - stops[i]) < 0)
                {
                    // refill
                    tank_current = tank;
                    number_of_stops++;
                }
            }
            else
            {
                tank_current = tank_current - stops_Dist[i];
                if (tank_current - stops_Dist[i + 1] < 0)
                {
                    // refill
                    tank_current = tank;
                    number_of_stops++;
                }
            }
            
        }
        return number_of_stops;
    }
}

void testSolution() {
    assert(compute_min_refills_greedy(950, 400, {200, 375, 550, 750}) == 2);
    assert(compute_min_refills_greedy(10, 3, {1, 2 , 5, 9}) == -1);
    assert(compute_min_refills_greedy(200, 250, {100, 150}) == 0);
    assert(compute_min_refills_greedy(700, 200, {100, 200, 300, 400}) == -1);

}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills_greedy(d, m, stops) << "\n";

    // testSolution();

    return 0;
}
