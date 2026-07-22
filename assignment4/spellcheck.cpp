#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>
#include <set>


template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  Corpus result;
  auto spacePointer = find_all(source.begin(), source.end(), ::isspace);

  std::transform(
      spacePointer.begin(), spacePointer.end() - 1,  // first1, last1
      spacePointer.begin() + 1,                       // first2
      std::inserter(result, result.end()),            // d_first
      [&source](auto it1, auto it2) {                 // binary_op
        return Token{source, it1, it2};
      });

  //remove the empty token.
  std::erase_if(result, [](const Token& token) {
    return token.content.empty();
  });

  return result;
}

std::set<Misspelling> spellcheck(const Corpus& source,
                                 const Dictionary& dictionary) {
    namespace rv = std::ranges::views;

    auto view =
        source

        // Step 1: Keep only incorrectly spelled tokens.
        | rv::filter([&dictionary](const Token& token) {
              return !dictionary.contains(token.content);
          })

        // Step 2: Convert each Token into a Misspelling.
        | rv::transform([&dictionary](const Token& token) {
              auto suggestionView =
                  dictionary | rv::filter([&token](const std::string& word) {
                      return levenshtein(token.content, word) == 1;
                  });

              std::set<std::string> suggestions(
                  suggestionView.begin(),
                  suggestionView.end()
              );

              return Misspelling{token, suggestions};
          })

        // Step 3: Remove misspellings with no suggestions.
        | rv::filter([](const Misspelling& misspelling) {
              return !misspelling.suggestions.empty();
          });

    return std::set<Misspelling>(view.begin(), view.end());
}

/* Helper methods */

#include "utils.cpp"