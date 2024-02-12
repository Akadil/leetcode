#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> myStudents;
        std::stack<int> mySandwiches;
        int             size = students.size();

        for (int i = 0; i < size; ++i) {
            myStudents.push(students[i]);
            mySandwiches.push(sandwiches[size - 1 - i]);
        }

        /*
            hypothesis:
                1. is it possible to have different preferences?
                    No, because if there are different type of sandwiches,
                    then you can still iterate to take this student


            Results:
                1. At the end, every student should have the same taste, and
                    left sandwich should be different
                2. Once no preference detected, set deatch cycle, and count
                    number of people left
        
        */

        bool    isDeathCycle = false;
        int     counter = -1;

        while (mySandwiches.size() != 0 && counter != 0) {
            if (myStudents.front() == mySandwiches.top()) {
                myStudents.pop();
                mySandwiches.pop();

                // Monitor the death cycle
                if (counter != -1) {                // Untie the death cycle
                    counter = -1;
                    isDeathCycle = false;
                }
            } else {
                myStudents.push(myStudents.front());
                myStudents.pop();
                
                // Monitor the death cycle
                if (counter == -1) {                // Activate the death cycle
                    isDeathCycle = true;
                    counter = myStudents.size() - 1;
                }
                else {                              // Bomb ticking
                    counter--;
                }
            }
        }

        return (myStudents.size());
    }
};