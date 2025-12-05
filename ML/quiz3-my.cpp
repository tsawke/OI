#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <bits/stdc++.h>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

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

        binaryOperator = lit("∧") | lit("∨") | lit("→") | lit("↔");

        formula = 
            variable
            | ('(' > ((formula > binaryOperator > formula) | (lit("¬") > formula)) > ')');
    }
};

int main() {
    wffParser parser;
    string S;
    std::getline(std::cin, S);
    bool res(false);
    
    try{
        std::string::const_iterator s = S.begin(), t = S.end();
        res = qi::phrase_parse(s, t, parser, ascii::space);
        printf("%s\n", res && s == t ? "It's a wff." : "It's not a wff.");
    }catch (const boost::wrapexcept<boost::spirit::qi::expectation_failure<string::const_iterator>>& e) {
        // std::cerr << e.what() << std::endl;
        printf("It's not a wff.\n");
    }

    return 0;
}