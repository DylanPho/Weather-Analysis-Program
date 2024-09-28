/*
 * Created by: Dylan Phoutthavong
 * Course: ELEC 1520
 * Date: December 15th, 2022
 * Description: This is the course final project that performs various analyses 
 * on weather data, such as total precipitation, total snowfall, and temperature 
 * statistics over a given period of time.
 */

 #include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>

using namespace std;

// Function prototypes for various analyses
void analysisByYear(int analysis);
void analysesByEveryMonth(int analysis);
void analysesByOneMonth(int analysis);
int TotalDaysInAYear(int year);
int TotalDaysOfMonth(int month, int year);
int TotalDaysOfAMonthInYears(int month, int startYear, int endYear);

// Analysis functions for precipitation
void analyzePrecipitationByYear(int startYear, int endYear);
void analyzePrecipitationByAllMonths(int startYear, int endYear);
void analyzePrecipitationByOneMonth(int month1, int startYear, int endYear);

// Analysis functions for snowfall
void analyzeSnowfallByYear(int startYear, int endYear);
void analyzeSnowfallByAllMonths(int startYear, int endYear);
void analyzeSnowfallByOneMonth(int month1, int startYear, int endYear);

// Analysis functions for temperatures
void analyzeAvgMinMaxTempByYear(int startYear, int endYear);
void analyzeAvgMinMaxTempByAllMonths(int startYear, int endYear);
void analyzeAvgMinMaxTempByOneMonth(int month1, int startYear, int endYear);
void analyzeAvgMidDayTempByYear(int startYear, int endYear);
void analyzeAvgMidDayTempByAllMonths(int startYear, int endYear);
void analyzeAvgMidDayTempByOneMonth(int month1, int startYear, int endYear);
void analyzeMinTempByYear(int startYear, int endYear);
void analyzeMinTempByAllMonths(int startYear, int endYear);
void analyzeMinTempByOneMonth(int month1, int startYear, int endYear);

int main() {
    int period; // Holds the period of analysis chosen by the user
    int analysis; // Holds the type of analysis chosen by the user

    // Prompt user for the type of analysis
    cout << "\nWhat analysis would you like to do?\n";
    cout << "1.  - Total precipitation\n";
    cout << "2.  - Total snowfall\n";
    cout << "3. Average maximum and/or minimum temperature\n";
    cout << "4. Average temperature at mid-day\n";
    cout << "5. Mininum/Maximum temperature\n";
    cout << "Enter choice: ";
    cin >> analysis;

    // Prompt user to select the time period for analysis
    cout << "\nEnter the period of time for this analysis you've chosen\n";
    cout << "1. By Year (1908-2022)\n";
    cout << "2. By Every Month in Years (Ex. January-December data from 2002-2022)\n";
    cout << "3. By One Month in Years (Ex: October data from 2002-2022)\n";
    cout << "Enter choice: ";
    cin >> period;

    // Call the appropriate function based on the period selected
    if (period == 1)
        analysisByYear(analysis);
    else if (period == 2)
        analysesByEveryMonth(analysis);
    else if (period == 3)
        analysesByOneMonth(analysis);
}

// Function to handle analysis by year
void analysisByYear(int analysis) {
    int startYear;
    int endYear;

    // Prompt user for the range of years
    cout << "Enter startYear: ";
    cin >> startYear;
    cout << "Enter endYear: ";
    cin >> endYear;

    // Call appropriate analysis function based on the user's choice
    if (analysis == 1)
        analyzePrecipitationByYear(startYear, endYear);
    else if (analysis == 2)
        analyzeSnowfallByYear(startYear, endYear);
    else if (analysis == 3)
        analyzeAvgMinMaxTempByYear(startYear, endYear);
    else if (analysis == 4)
        analyzeAvgMidDayTempByYear(startYear, endYear);
    else if (analysis == 5)
        analyzeMinTempByYear(startYear, endYear);
}

// Function to handle analysis by every month in the specified years
void analysesByEveryMonth(int analysis) {
    int startYear;
    int endYear;

    // Prompt user for the range of years
    cout << "Enter startYear: ";
    cin >> startYear;
    cout << "Enter endYear: ";
    cin >> endYear;

    // Call appropriate analysis function based on the user's choice
    if (analysis == 1)
        analyzePrecipitationByAllMonths(startYear, endYear);
    else if (analysis == 2)
        analyzeSnowfallByAllMonths(startYear, endYear);
    else if (analysis == 3)
        analyzeAvgMinMaxTempByAllMonths(startYear, endYear);
    else if (analysis == 4)
        analyzeAvgMidDayTempByAllMonths(startYear, endYear);
    else if (analysis == 5)
        analyzeMinTempByAllMonths(startYear, endYear);
}

// Function to handle analysis for a specific month in the specified years
void analysesByOneMonth(int analysis) {
    int startYear;
    int endYear;
    int month1;

    // Prompt user for the month and range of years
    cout << "Enter a month number (1-12): ";
    cin >> month1;
    cout << "Enter startYear: ";
    cin >> startYear;
    cout << "Enter endYear: ";
    cin >> endYear;

    // Call appropriate analysis function based on the user's choice
    if (analysis == 1)
        analyzePrecipitationByOneMonth(month1, startYear, endYear);
    else if (analysis == 2)
        analyzeSnowfallByOneMonth(month1, startYear, endYear);
    else if (analysis == 3)
        analyzeAvgMinMaxTempByOneMonth(month1, startYear, endYear);
    else if (analysis == 4)
        analyzeAvgMidDayTempByOneMonth(month1, startYear, endYear);
    else if (analysis == 5)
        analyzeMinTempByOneMonth(month1, startYear, endYear);
}

// Utility function to calculate the total number of days in a given year
int TotalDaysInAYear(int year) {
    // Leap year calculation
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 366;  // Leap year
            else
                return 365;
        } else
            return 366;  // Leap year
    } else
        return 365;
}

// Utility function to calculate the total number of days in a given month
int TotalDaysOfMonth(int month, int year) {
    int totalDays = 0;

    // Handle leap year condition for February
    if (month == 2) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            totalDays = 29;
        else
            totalDays = 28;
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        totalDays = 31;
    else
        totalDays = 30;

    return totalDays;
}

// Utility function to calculate the total number of days for a specific month over a range of years
int TotalDaysOfAMonthInYears(int month, int startYear, int endYear) {
    int totalDays = 0;

    // Calculate days in the specified month over a range of years
    for (int year = startYear; year <= endYear; year++)
        totalDays += TotalDaysOfMonth(month, year);

    return totalDays;
}

// The following functions perform specific analyses based on user choices
// For example, the 'analyzePrecipitationByYear' function reads weather data and calculates total precipitation by year.
// Each function reads the "weatherData.txt" file, processes data based on the analysis type, and outputs results to a file.

void analyzePrecipitationByYear(int startYear, int endYear) {
    map<int, double> tpByYear; // Stores total precipitation for each year

    fstream inputFile;
    inputFile.open("weatherData.txt"); // Open weather data file for reading

    if (inputFile.is_open()) {
        string line;
        string data;
        int data_counter; // Keeps track of data position in the line

        getline(inputFile, line); // Skip the header line

        while (getline(inputFile, line)) {
            data_counter = 1;
            int year;

            char *data_ptr = strtok(&line[0], "     "); // Tokenize the line by spaces
            while (data_ptr != NULL) {
                data = data_ptr;
                if (data_counter == 3) { // Year data
                    year = stoi(data);
                    if (!(year >= startYear && year <= endYear)) // Skip years outside range
                        break;
                    auto itr = tpByYear.find(year);
                    if (itr == tpByYear.end()) // Add year if not already in map
                        tpByYear.insert({year, 0});
                } else if (data_counter == 4) { // Rainfall data
                    auto itr = tpByYear.find(year);
                    if (itr != tpByYear.end())
                        itr->second += stod(data); // Accumulate rainfall data
                    break;
                }
                data_ptr = strtok(NULL, "     ");
                data_counter++;
            }
        }
        inputFile.close(); // Close the file
    } else
        cout << "Error found opening input file (weatherData.txt) ";

    // Write results to output file
    ofstream outputFile;
    string filename = "TotalPrecipitation(" + to_string(startYear) + " - " + to_string(endYear) + ")";
    outputFile.open(filename);
    for (auto itr = tpByYear.begin(); itr != tpByYear.end(); ++itr)
        outputFile << itr->first << "     " << itr->second << "\n";
    outputFile.close();
}

// Additional functions for analyzing snowfall, temperatures, and other metrics follow a similar structure as above.