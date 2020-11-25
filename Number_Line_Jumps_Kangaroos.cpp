/*
You are choreographing a circus show with various animals. For one act, you are given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).

    The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
You have to figure out a way to get both kangaroos at the same location at the same time as part of the show. If it is possible, return YES, otherwise return NO.

Function Description

Complete the function kangaroo in the editor below. It should return YES if they reach the same position at the same time, or NO if they don't.

kangaroo has the following parameter(s):

    x1, v1: integers, starting position and jump distance for kangaroo 1
    x2, v2: integers, starting position and jump distance for kangaroo 2

Input Format

A single line of four space-separated integers denoting the respective values of x1,v1 , x2, and v2.

Output Format

Print YES if they can land on the same location at the same time; otherwise, print NO.

Note: The two kangaroos must land at the same location after making the same number of jumps.

Sample Input 0

0 3 4 2

Sample Output 0

YES


Solution :
          we know :      velocity = distance/ time
                                               here, time --> no. of jumps.
                           v = d/j
                        => d= v*j
             for Kangaroo 1:   distance covered = starting_point + (velocity * no. of jumps) 
                                                => x1 + (v1 * j)            --------------------------------- (1)
             for Kangaroo 2:   distance covered = starting_point + (velocity * no. of jumps) 
                                                => x2 + (v2 * j)              ----------------------------------(2)
                              comparing equation 1 and 2
                              
                              x1+(v1 * j) = x2+ (v2 * j)
                              (v2 *j) - (v1 * j) = (x1 - x2)
                              j(v2 - v1)=(x1 - x2)
                          ____________________________    
                         |          (x1 - x2)         |
                         |     j =  ------------      |           <=== Find modulus : if(remainder==0 then yes) else NO.
                         |           (v2 - v1)        |
                         |____________________________|
                                                                where : v1 > v2   [[[[[[[[[ I M P O R T A N T ]]]]]]]]]]]
                         
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the kangaroo function below.
string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1 > v2) {                                              //Because as per constraints x2 > x1 if x1 is behind of x2 then it must be run fast than x2 to catch k2. 
            
            int remainder = (x1 - x2) % (v2 - v1);                // MAIN LOGIC
              
            if (remainder == 0) {
                return "YES";
            }
        }
        return "NO";

}
                        // INPUT HERE
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string x1V1X2V2_temp;
    getline(cin, x1V1X2V2_temp);

    vector<string> x1V1X2V2 = split_string(x1V1X2V2_temp);

    int x1 = stoi(x1V1X2V2[0]);

    int v1 = stoi(x1V1X2V2[1]);

    int x2 = stoi(x1V1X2V2[2]);

    int v2 = stoi(x1V1X2V2[3]);

    string result = kangaroo(x1, v1, x2, v2);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
 
