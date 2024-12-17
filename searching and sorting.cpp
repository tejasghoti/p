{\rtf1\ansi\ansicpg1252\cocoartf2820
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
#include <string>\
using namespace std;\
\
struct Student \{\
    string name;\
    int rollNO;\
    float sgpa;\
    char grade;\
\};\
\
class SEIT \{\
    int n = 5;\
    Student students[5];\
\
public:\
    void input() \{\
        cout << "Enter the Details of The Students:\\n";\
        for (int i = 0; i < n; i++) \{\
            cout << "Name: ";\
            cin >> students[i].name;\
            cout << "Roll Number: ";\
            cin >> students[i].rollNO;\
            cout << "SGPA: ";\
            cin >> students[i].sgpa;\
            cout << "Grade: ";\
            cin >> students[i].grade;\
        \}\
    \}\
\
    void display() \{\
        cout << "----------------------------------------------------------------------------\\n";\
        cout << "                           Student Details                                    \\n";\
        cout << "----------------------------------------------------------------------------\\n";\
        cout << "Sr.no\\t|\\tName\\t|\\tRoll No\\t|\\tSGPA\\t|\\tGrade\\t\\n";\
        for (int i = 0; i < n; i++) \{\
            cout << i + 1 << "\\t|\\t" << students[i].name << "\\t|\\t" << students[i].rollNO << "\\t|\\t" << students[i].sgpa << "\\t|\\t" << students[i].grade << endl;\
        \}\
        cout << "----------------------------------------------------------------------------\\n";\
    \}\
\
    void seqSearch() \{\
        int key;\
        cout << "Enter the Roll Number to be Searched: ";\
        cin >> key;\
        bool found = false;\
        for (int i = 0; i < n; i++) \{\
            if (students[i].rollNO == key) \{\
                found = true;\
                cout << "Student Found\\nStudents Details...\\n";\
                cout << "Name: " << students[i].name << endl;\
                cout << "Roll Number: " << students[i].rollNO << endl;\
                cout << "SGPA: " << students[i].sgpa << endl;\
                cout << "Grade: " << students[i].grade << endl;\
                break;\
            \}\
        \}\
        if (!found) \{\
            cout << "ERROR! Student Not Found." << endl;\
        \}\
    \}\
\
    int binSearch(int key) \{\
        int low = 0, high = n - 1;\
        while (low <= high) \{\
            int mid = low + (high - low) / 2;\
            if (students[mid].rollNO == key) \{\
                return mid;\
            \} else if (students[mid].rollNO < key) \{\
                low = mid + 1;\
            \} else \{\
                high = mid - 1;\
            \}\
        \}\
        return -1;\
    \}\
\
    void disBinarySearch() \{\
        bubbleSort(); // Ensure the array is sorted before binary search\
        int key;\
        cout << "Enter the Roll Number to be Searched: ";\
        cin >> key;\
        int found = binSearch(key);\
        if (found != -1) \{\
            cout << "Student Found\\nStudents Details...\\n";\
            cout << "Name: " << students[found].name << endl;\
            cout << "Roll Number: " << students[found].rollNO << endl;\
            cout << "SGPA: " << students[found].sgpa << endl;\
            cout << "Grade: " << students[found].grade << endl;\
        \} else \{\
            cout << "ERROR! Student Not Found." << endl;\
        \}\
    \}\
\
    void bubbleSort() \{\
        for (int i = 0; i < n - 1; i++) \{\
            for (int j = 0; j < n - 1 - i; j++) \{\
                if (students[j].rollNO > students[j + 1].rollNO) \{\
                    Student temp = students[j];\
                    students[j] = students[j + 1];\
                    students[j + 1] = temp;\
                \}\
            \}\
        \}\
    \}\
\
    void insertionSort() \{\
        for (int i = 1; i < n; i++) \{\
            Student key = students[i];\
            int j = i - 1;\
            while (j >= 0 && students[j].name > key.name) \{\
                students[j + 1] = students[j];\
                j--;\
            \}\
            students[j + 1] = key;\
        \}\
    \}\
\
    void quickSort() \{\
        quickSortRecursive(0, n - 1);\
    \}\
\
    void quickSortRecursive(int low, int high) \{\
        if (low < high) \{\
            int pi = partition(low, high);\
            quickSortRecursive(low, pi - 1);\
            quickSortRecursive(pi + 1, high);\
        \}\
    \}\
\
    int partition(int low, int high) \{\
        float pivot = students[high].sgpa;\
        int i = low - 1;\
        for (int j = low; j <= high - 1; j++) \{\
            if (students[j].sgpa > pivot) \{\
                i++;\
                Student temp = students[i];\
                students[i] = students[j];\
                students[j] = temp;\
            \}\
        \}\
        Student temp = students[i + 1];\
        students[i + 1] = students[high];\
        students[high] = temp;\
        return i + 1;\
    \}\
\};\
\
int main() \{\
    SEIT database;\
    char choice;\
    database.input();\
    do \{\
        int method;\
        cout << "Choose the Method you want to USE:\\n";\
        cout << "1. Sequential Search\\n2. Bubble Sort\\n3. Insertion Sort\\n4. Binary Search\\n5. Quick Sort\\n";\
        cin >> method;\
        switch (method) \{\
        case 1:\
            database.seqSearch();\
            break;\
        case 2:\
            database.bubbleSort();\
            database.display();\
            break;\
        case 3:\
            database.insertionSort();\
            database.display();\
            break;\
        case 4:\
            database.disBinarySearch();\
            break;\
        case 5:\
            database.quickSort();\
            database.display();\
            break;\
        default:\
            cout << "Enter Correct Choice\\n";\
            return 1;\
        \}\
        cout << "Do You Wish To Continue? (y/n): ";\
        cin >> choice;\
    \} while (choice == 'y' || choice == 'Y');\
    cout << "EXITING..." << endl;\
    return 0;\
\}\
}