#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData(const string &inputFile, vector<double> &pathAngles, vector<double> &coefList);
double interpolation(double userAngle, const vector<double> &pathAngles, const vector<double> &coefList);
bool isOrdered(const vector<double> &dataVec);
void reorder(vector<double> &pathAngles, vector<double> &coefList);


int main(int argc, char *argv[]) {

    vector<double> pathAngles;
    vector<double> coefList;

    // check number of arguments passed in
    if (argc != 2) {

        cout << "Usage: myprog.exe inputFileName" << endl;
        return 1;   // error

    }

    // call function to read data from file
    readData(argv[1], pathAngles, coefList);

    // test values stored in vectors correctly
    for (unsigned i = 0; i < pathAngles.size(); ++i) {

        cout << pathAngles.at(i) << ' ' << coefList.at(i) << endl;

    }

    string prompt = "Yes";
    double userAngle = 0;

    // check user wants to enter flight ath angle
    while (prompt == "Yes") {

        // prompt user for flight path angle
        cout << "Flight path angle: " << endl;
        cin >> userAngle;

        // check reference data vector is not empty
        if (pathAngles.size() > 0) {

            // check user entered flight path angle is within bounds of data
            if (pathAngles.at(0) <= userAngle && userAngle <= pathAngles.at(pathAngles.size() - 1)) {

                // get coef of lift that corresponds to user entered flight path angle
                cout << "Coefficient of lift for " << userAngle << ": " << interpolation(userAngle, pathAngles, coefList) << endl;

            }
            // user entered flight path angle is out of bounds of data
            else {

                cout << "Data unavailable for flight path angle " << userAngle << "." << endl;

            }

        }
        // vector is empty
        else {

            cout << "No data unavailable for any flight path angles." << endl;
            
        }

        do {

            // prompt user
            cout << "Would you like to enter another flight path angle? (Yes/No)" << endl;
            cin >> prompt;

        // check for valid input
        } while (prompt != "Yes" && prompt != "No");

    }


    return 0;

}

// ************** main() end **************

void readData(const string &inputFile, vector<double> &pathAngles, vector<double> &coefList) {

    // create file stream
    ifstream inFS;
    // initialize helper variable
    double data = 0;


    // open file
    inFS.open(inputFile);

    // check if file opened correctly
    if (!inFS.is_open()) {

        cout << "Error opening " << inputFile << endl;

        exit(EXIT_FAILURE);   // error

    }

    // read in first path angle from file and enter conditional loop
    while (inFS >> data) {

        // append path angle stored in data from file to respective vector
        pathAngles.push_back(data);
        // read in next coefficient of lift from file
        inFS >> data;
        // append coefficient of lift stored in data from file to respective vector
        coefList.push_back(data);

    }

    // close file
    inFS.close();

    if (!isOrdered(pathAngles)) {

        reorder(pathAngles, coefList);

    }

}

double interpolation(double userAngle, const vector<double> &pathAngles, const vector<double> &coefList) {

    double coefMatch = 0;

    // iterated through path angles
    for (unsigned i = 0; i < pathAngles.size() - 1; ++i) {

        // check user angle is within bounds of index and next
        if (pathAngles.at(i) <= userAngle && userAngle <= pathAngles.at(i + 1)) {

            // user angle matches lower bound
            if (userAngle == pathAngles.at(i)) {

                coefMatch = coefList.at(i);

            }
            // user angle matches upper bound
            else if (userAngle == pathAngles.at(i + 1)) {

                coefMatch = coefList.at(i + 1);

            }
            // interpolation required
            else {

                coefMatch = coefList.at(i) + ((userAngle - pathAngles.at(i)) / (pathAngles.at(i + 1) - pathAngles.at(i))) * (coefList.at(i + 1) - coefList.at(i));
            
            }

        }

    }

    return coefMatch;

}

bool isOrdered(const vector<double> &dataVec) {

    bool ordered = true;

    // check vector is larger than 1 item (and not empty)
    if (dataVec.size() > 1) {

        for (unsigned i = 0; i < dataVec.size() - 1; ++i) {

            if (dataVec.at(i) > dataVec.at(i + 1)) {

                ordered = false;

            }

        }

    }

    return ordered;

}

void reorder(vector<double> &pathAngles, vector<double> &coefList) {

    double tempVal = 0.0;
    unsigned int indexMin = 0;

    if (pathAngles.size() > 1) {

        // iterate through vector
        for (unsigned i = 0; i < pathAngles.size() - 1; ++i) {

            indexMin = i;
            // locate index of smallest element
            for (unsigned j = i + 1; j < pathAngles.size(); ++j) {

                // 
                if (pathAngles.at(j) < pathAngles.at(indexMin)) {

                    indexMin = j;

                }

            }

            if (indexMin != i) {

                // swap min element with current element
                tempVal = pathAngles.at(i);
                pathAngles.at(i) = pathAngles.at(indexMin);
                pathAngles.at(indexMin) = tempVal;
                // match vector ordering
                tempVal = coefList.at(i);
                coefList.at(i) = coefList.at(indexMin);
                coefList.at(indexMin) = tempVal;

            }

        }

    }

}
