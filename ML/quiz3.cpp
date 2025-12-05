#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
// #include <iostream>
// #include <string>
#include <bits/stdc++.h>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
using std::string;
// 定义一个模板解析器，支持基本命题逻辑公式
// template <typename Iterator>
struct wffParser : qi::grammar<std::string::const_iterator, ascii::space_type>
{
    qi::rule<std::string::const_iterator, ascii::space_type> formula;
    qi::rule<std::string::const_iterator, ascii::space_type> variable;
    qi::rule<std::string::const_iterator, ascii::space_type> binary_operator;
    wffParser() : wffParser::base_type(formula)
    {
        using qi::lit;
        using qi::lexeme;
        using qi::char_;
        using ascii::alpha;

        // 命题变量：这里只匹配一个字母（可以是大写或小写）
        variable = lexeme[alpha];

        // 定义公式：
        // 公式可以是：1. 一个变量；2. 否定公式；3. 括号包围的二元公式
        // formula = variable
        //         // | ('(' > lit("¬") > formula > ')')
        //         | (lit("¬") > formula)
        //         | ('(' > formula > binary_operator > formula > ')');
        formula = 
            variable
            | (lit("¬") > formula)
            | ('(' > formula > binary_operator > formula > ')');

        // 定义二元逻辑操作符：∧, ∨, →, ↔
        binary_operator = lit("∧") | lit("∨") | lit("→") | lit("↔");
    }


};

int main()
{ 
    typedef std::string::const_iterator iterator_type;
    // typedef wffParser parser;

    wffParser g;  // 构造解析器实例
    std::string S;

    // std::cout << "请输入一个逻辑公式:" << std::endl;
    std::getline(std::cin, S);

    iterator_type iter = S.begin();
    iterator_type end = S.end();
    // try{
    //     bool res = qi::phrase_parse(S.begin(), S.end(), g, ascii::space);
    //     printf("%s\n", res && S.begin() == S.end() ? "It's a wff." : "It's not a wff.");
    // } catch (const boost::wrapexcept<boost::spirit::qi::expectation_failure<string::const_iterator>>& e) {
    //     std::cerr << "Parsing failed: " << e.what() << std::endl;
    //     std::cout << "It's not a wff." << std::endl;
    // }
    // 使用 phrase_parse 解析输入（自动跳过空白字符）
    bool result = qi::phrase_parse(iter, end, g, ascii::space);
    printf("%s\n", result && S.begin() == S.end() ? "It's a wff." : "It's not a wff.");
    // if(result && iter == end)
    //     std::cout << "输入的是一个 well-formed formula!" << std::endl;
    // else
    //     std::cout << "输入不是一个 well-formed formula." << std::endl;

    return 0;
}