#include <boost/spirit/include/qi.hpp>
#include <bits/stdc++.h>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template < typename Iterator >
class wffParser : qi::grammar < Iterator, ascii::space_type > {
    qi::rule < Iterator, ascii::space_type > formula;
    qi::rule < Iterator, ascii::space_type > variable;
    qi::rule < Iterator, ascii::space_type > operator;

    wffParser() : wffParser::base_type(formula) {
        using qi::lit;
        using qi::lexeme;
        using qi::char_;
        using ascii::alpha;
        
        variable = lexeme[alpha];
    }
};