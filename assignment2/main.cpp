/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

std::string kYourName = "Vincent Morgan"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream read(filename);
  if (!read.is_open()) {
    std::cerr << "can open " << filename << '\n';
  }

  std::set<std::string> result;
  std::string line;
  while (std::getline(read, line)) {
    if (!line.empty()) {
      result.insert(line);
    }
  }
  read.close();

  return result;
}



bool shareInitials(const std::string& string1, const std::string& string2) {
  std::stringstream ss1(string1);
  std::stringstream ss2(string2);

  std::string first1, last1;
  std::string first2, last2;

  ss1 >> first1 >> last1;
  ss2 >> first2 >> last2;

  return first1.front() == first2.front() && last1.front() == last2.front();
}

// bool sameInitials(const std::string& a, const std::string& b) {
//     auto spaceA = a.find(' ');
//     auto spaceB = b.find(' ');

//     return a.front() == b.front() &&
//            a[spaceA + 1] == b[spaceB + 1];
// }
/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> result;
  if (name == "") {
    return result;
  }
  for (const auto& elem : students) {
    if (shareInitials(name, elem)) {
      result.push(&elem);
    }
  }
  return result;


}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }
  return *(matches.back());
  //return "";
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
