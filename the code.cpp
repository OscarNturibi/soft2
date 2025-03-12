#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate grade based on percentage
char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 80) return 'B';
    else if (percentage >= 70) return 'C';
    else if (percentage >= 60) return 'D';
    else return 'F';  // Fail
}

int main() {
    string studentName;
    int numSubjects;
    
    cout << "Enter Student Name: ";
    getline(cin, studentName);
    
    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    // Validate number of subjects
    if (numSubjects <= 0) {
        cout << "Invalid number of subjects. Exiting...\n";
        return 1;
    }

    vector<float> marks(numSubjects);
    float total = 0, highest = 0, lowest = 100;

    // Input marks for each subject
    for (int i = 0; i < numSubjects; i++) {
        cout << "Enter marks for Subject " << (i + 1) << ": ";
        cin >> marks[i];

        // Ensure valid marks
        if (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid marks! Enter a value between 0 and 100.\n";
            i--; // Repeat input for this subject
            continue;
        }

        total += marks[i];

        // Track highest and lowest marks
        if (marks[i] > highest) highest = marks[i];
        if (marks[i] < lowest) lowest = marks[i];
    }

    float percentage = total / numSubjects;
    char grade = calculateGrade(percentage);

    // Display results
    cout << "\n===== University Grading System =====\n";
    cout << "Student: " << studentName << endl;
    cout << "Total Marks: " << total << " / " << (numSubjects * 100) << endl;
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;

    // Result status
//Student results
    if (grade == 'F')
        cout << "Status: Fail. Better luck next time!\n";
    else
        cout << "Status: Pass. Congratulations!\n";

    // Additional feedback
    if (highest == 100)
        cout << "Perfect score in at least one subject!\n";
    if (lowest < 40)
        cout << "Consider revisiting weak subjects for improvement.\n";

    return 0;
}
