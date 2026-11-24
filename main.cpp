#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to convert letter grades into grade points
double getGradePoint(string grade)
{
    if (grade == "A+")
        return 4.00;
    else if (grade == "A")
        return 3.75;
    else if (grade == "B+")
        return 3.50;
    else if (grade == "B")
        return 3.00;
    else if (grade == "C+")
        return 2.50;
    else if (grade == "C")
        return 2.00;
    else if (grade == "D")
        return 1.00;
    else if (grade == "F")
        return 0.00;
    else
        return -1.00;
}

int main()
{
    // Welcome screen
    cout << "====================================" << endl;
    cout << "         CGPA CALCULATOR            " << endl;
    cout << "====================================" << endl;

    int numCourses;

    cout << "\nEnter the number of courses (1-10): ";
    cin >> numCourses;

    // Validate number of courses
    if (cin.fail() || numCourses < 1 || numCourses > 10)
    {
        cout << "Invalid number of courses!" << endl;
        return 1;
    }

    // Arrays to store course information
    string courseNames[10];
    string grades[10];
    int creditHours[10];
    double gradePoints[10];

    double totalWeightedPoints = 0;
    int totalCreditHours = 0;

    // Collect course information
    for (int i = 0; i < numCourses; i++)
    {
        cout << "\n========== Course " << i + 1 << " ==========" << endl;

        cout << "Enter course name: ";
        cin >> ws;
        getline(cin, courseNames[i]);

        cout << "Enter grade (A+, A, B+, B, C+, C, D, F): ";
        cin >> grades[i];

        // Validate grade
        gradePoints[i] = getGradePoint(grades[i]);

        while (gradePoints[i] == -1.00)
        {
            cout << "Invalid grade! Please enter a valid grade: ";
            cin >> grades[i];
            gradePoints[i] = getGradePoint(grades[i]);
        }

        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        // Validate credit hours
        while (cin.fail() || creditHours[i] <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid credit hours! Enter again: ";
            cin >> creditHours[i];
        }

        // Calculate weighted points
        totalWeightedPoints += gradePoints[i] * creditHours[i];

        totalCreditHours += creditHours[i];
    }

    // Calculate GPA
    double gpa = totalWeightedPoints / totalCreditHours;

    // Display course summary
    cout << "\n====================================" << endl;
    cout << "           COURSE SUMMARY           " << endl;
    cout << "====================================" << endl;

    cout << fixed << setprecision(2);

    for (int i = 0; i < numCourses; i++)
    {
        cout << "\nCourse: " << courseNames[i] << endl;
        cout << "Grade: " << grades[i] << endl;
        cout << "Grade Points: " << gradePoints[i] << endl;
        cout << "Credit Hours: " << creditHours[i] << endl;
    }

    // Display final result
    cout << "\n====================================" << endl;
    cout << "          FINAL GPA RESULT          " << endl;
    cout << "====================================" << endl;

    cout << "Total Credit Hours: " << totalCreditHours << endl;
    cout << "Total Weighted Points: " << totalWeightedPoints << endl;
    cout << "Your Semester GPA is: " << gpa << endl;

    cout << "\nThank you for using the CGPA Calculator!" << endl;

    return 0;
}