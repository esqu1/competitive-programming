#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string input;
        cin >> input;
        string output;
        int nesting_length = 0;
        for (int j = 0; j < input.length(); ++j) {
            int c = input.at(j) - '0';
            int diff = c - nesting_length;
            for (int k = 0; k < abs(diff); ++k) {
                if (diff < 0) {
                    // then we're previously at a higher depth; add )
                    output.append(")");
                } else if (diff > 0) {
                    output.append("(");
                }
            }
            output.append(input.substr(j, 1));
            nesting_length = c;
        }
        for (int j = 0; j < input.at(input.length() - 1) - '0'; ++j) {
            output.append(")");
        }
        cout << "Case #" << i << ": " << output << endl;
    }
}
