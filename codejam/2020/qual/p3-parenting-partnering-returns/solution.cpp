#include <bits/stdc++.h>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

typedef tuple<int, int, int> Activity;

bool compareActs(Activity a, Activity b)
{
    return (get<1>(a) < get<1>(b));
}

// This is just checking if the graph is bipartite...
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int num_acts;
        cin >> num_acts;
        tuple<int, int, int> acts[num_acts];
        for (int j = 0; j < num_acts; ++j) {
            int start_time, end_time;
            cin >> start_time >> end_time;
            get<0>(acts[j]) = j;
            get<1>(acts[j]) = start_time;
            get<2>(acts[j]) = end_time;
        }

        sort(acts, acts + num_acts, compareActs);

        char assignments[num_acts];
        int currFinishTimeCam = 0, currFinishTimeJamie = 0;
        bool impossible = false;
        for (int j = 0; j < num_acts; ++j) {
            Activity act = acts[j];
            if (currFinishTimeCam < currFinishTimeJamie) {
                if (get<1>(act) >= currFinishTimeCam) {
                    assignments[get<0>(act)] = 'C';
                    currFinishTimeCam = get<2>(act);
                } else if (get<1>(act) >= currFinishTimeJamie) {
                    assignments[get<0>(act)] = 'J';
                    currFinishTimeJamie = get<2>(act);
                } else {
                    impossible = true;
                    break;
                }
            } else {
                if (get<1>(act) >= currFinishTimeJamie) {
                    assignments[get<0>(act)] = 'J';
                    currFinishTimeJamie = get<2>(act);
                } else if (get<1>(act) >= currFinishTimeCam) {
                    assignments[get<0>(act)] = 'C';
                    currFinishTimeCam = get<2>(act);
                } else {
                    impossible = true;
                    break;
                }
            }
        }
        cout << "Case #" << i << ": ";
        if (impossible) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        } else {
            for (int j = 0; j < num_acts; ++j) {
                cout << assignments[j];
            }
            cout << endl;
        }
    }
}
