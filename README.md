# Diplomatic Attendance Sorter

A C++ console application for recording and organising attendance at diplomatic events.

The program allows users to enter attendee information including name, diplomatic position, and country. It then automatically sorts attendees according to a predefined diplomatic hierarchy and country order before displaying a structured attendance report.

## Features

- Add multiple attendees
- Record each attendee's:
  - Name
  - Diplomatic position
  - Country
- Select diplomatic positions from a predefined list
- Validate position selections
- Standardise country names regardless of letter case
- Automatically sort attendees by diplomatic position
- Apply a predefined country order within each position
- Display a structured final attendance report

## Diplomatic Positions

The application supports the following positions:

- Ambassador
- Charge d'Affaires
- First Secretary
- Second Secretary
- Third Secretary
- First Counsellor
- Second Counsellor
- Political Advisor

## How It Works

1. The user selects the attendee's diplomatic position.
2. The user enters the attendee's country.
3. The user enters the attendee's name.
4. Additional attendees can be entered as required.
5. Once data entry is complete, the program sorts the attendees.
6. The sorted attendance report is displayed in the console.

The sorting system first compares diplomatic positions according to the predefined hierarchy and then uses the predefined country order for attendees holding the same position.

## Example Output

```text
Sorted Report:
----------------------------------------
Ambassador | Jordan | Example Name
Ambassador | Egypt | Example Name
First Secretary | Qatar | Example Name
----------------------------------------
```

## Technologies Used

- C++
- Standard Template Library (STL)
- `std::vector`
- `std::sort`
- Lambda expressions
- String processing
- Console input/output

## Programming Concepts Demonstrated

This project demonstrates:

- Structures (`struct`)
- Vectors
- Functions
- Input validation
- Custom sorting
- Lambda expressions
- String manipulation
- Iteration and conditional logic

## File Structure

```text
Diplomatic-Attendance-Sorter/
├── AttendanceSorter.cpp
└── README.md
```

## Purpose

This project was developed as a practical C++ application for organising attendance information at diplomatic events while demonstrating data structures, input validation, custom sorting logic, and use of the C++ Standard Template Library.

## Author

Enas Odeh
