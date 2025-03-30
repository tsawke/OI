#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <bits/stdc++.h>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

// using namespace std;
using std::string;

struct wffParser : qi::grammar <string::const_iterator, ascii::space_type> {
    qi::rule <string::const_iterator, ascii::space_type> formula;
    qi::rule <string::const_iterator, ascii::space_type> variable;
    qi::rule <string::const_iterator, ascii::space_type> binaryOperator;

    wffParser() : wffParser::base_type(formula) {
        using qi::lit;
        using qi::lexeme;
        using qi::char_;
        using ascii::alpha;
        
        variable = lexeme[alpha];

        

        formula = 
            variable
            | ('(' > lit("¬") > formula > ')')
            | ('(' > formula > binaryOperator > formula > ')');
87      binaryOperator = lit("∧") | lit("∨") | lit("→") | lit("↔");

    }
};

int main() {
    wffParser parser;
    string S;
    std::getline(std::cin, S);
    bool res = qi::phrase_parse(S.begin(), S.end(), parser, ascii::space);

    printf("%s\n", res ? "It's a wff." : "It's not a wff.");

}