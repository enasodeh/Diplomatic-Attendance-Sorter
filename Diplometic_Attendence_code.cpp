#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

struct Attendee {
    std::string name;
    std::string position;
    std::string country;
};

std::vector<std::string> positionOrder = {
    "Ambassador",
    "Charge d'Affaires",
    "First Secretary",
    "Second Secretary",
    "Third Secretary",
    "First Counsellor",
    "Second Counsellor",
    "Political Advisor"
};

std::vector<std::string> countryOrder = {
    "UAE", "Palestine", "Libya", "Syria", "Tunis", "Jordan", "Qatar",
    "Saudi", "Egypt", "Algeria", "Mauritania", "Sudan",
    "Lebanon","Somalia", "Comoros", "Yemen", "Oman", "Morocco", "Iraq", "Kuwait"
};

std::string toLower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return text;
}

int getPositionIndex(const std::string& position) {
    auto it = std::find(positionOrder.begin(), positionOrder.end(), position);
    if (it != positionOrder.end()) {
        return std::distance(positionOrder.begin(), it);
    }
    return positionOrder.size();
}

int getCountryIndex(const std::string& country) {
    auto it = std::find(countryOrder.begin(), countryOrder.end(), country);
    if (it != countryOrder.end()) {
        return std::distance(countryOrder.begin(), it);
    }
    return countryOrder.size();
}

int selectPosition() {
    int choice;

    std::cout << "\nSelect position:\n";
    for (size_t i = 0; i < positionOrder.size(); ++i) {
        std::cout << i + 1 << ". " << positionOrder[i] << "\n";
    }

    std::cout << "Enter choice: ";
    std::cin >> choice;

    while (std::cin.fail() || choice < 1 || choice > positionOrder.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid choice. Please enter a number from 1 to "
                  << positionOrder.size() << ": ";
        std::cin >> choice;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

std::string standardizeCountry(std::string country) {
    std::string countryLower = toLower(country);

    for (const auto& c : countryOrder) {
        if (toLower(c) == countryLower) {
            return c;
        }
    }

    return country;
}

int main() {
    std::vector<Attendee> attendees;
    char more = 'y';

    while (more == 'y' || more == 'Y') {
        int posNum = selectPosition();
        std::string position = positionOrder[posNum - 1];

        std::cout << "Enter country: ";
        std::string country;
        std::getline(std::cin, country);
        country = standardizeCountry(country);

        std::cout << "Enter name: ";
        std::string name;
        std::getline(std::cin, name);

        attendees.push_back({name, position, country});

        std::cout << "Add another attendee? (y/n): ";
        std::cin >> more;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::sort(attendees.begin(), attendees.end(),
              [](const Attendee& a, const Attendee& b) {
                  int posA = getPositionIndex(a.position);
                  int posB = getPositionIndex(b.position);

                  if (posA != posB) {
                      return posA < posB;
                  }

                  int countryA = getCountryIndex(a.country);
                  int countryB = getCountryIndex(b.country);

                  return countryA < countryB;
              });

    std::cout << "\nSorted Report:\n";
    std::cout << "----------------------------------------\n";

    for (const auto& attendee : attendees) {
        std::cout << attendee.position << " | "
                  << attendee.country << " | "
                  << attendee.name << "\n";
    }

    std::cout << "----------------------------------------\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}