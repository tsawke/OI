#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <iostream>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

// 定义一个模板解析器，支持基本命题逻辑公式
template <typename Iterator>
struct wff_parser : qi::grammar<Iterator, ascii::space_type>
{
    wff_parser() : wff_parser::base_type(formula)
    {
        using qi::lit;
        using qi::lexeme;
        using qi::char_;
        using ascii::alpha;

        // 命题变量：这里只匹配一个字母（可以是大写或小写）
        variable = lexeme[alpha];

        // 定义公式：
        // 公式可以是：1. 一个变量；2. 否定公式；3. 括号包围的二元公式
        formula = variable
                | (lit('¬') > formula)
                | ('(' > formula > binary_operator > formula > ')');

        // 定义二元逻辑操作符：∧, ∨, →, ↔
        binary_operator = lit("∧") | lit("∨") | lit("→") | lit("↔");
    }

    qi::rule<Iterator, ascii::space_type> formula;
    qi::rule<Iterator, ascii::space_type> variable;
    qi::rule<Iterator, ascii::space_type> binary_operator;
};

int main()
{
    typedef std::string::const_iterator iterator_type;
    typedef wff_parser<iterator_type> parser;

    parser g;  // 构造解析器实例
    std::string input;

    std::cout << "请输入一个逻辑公式:" << std::endl;
    std::getline(std::cin, input);

    iterator_type iter = input.begin();
    iterator_type end = input.end();

    // 使用 phrase_parse 解析输入（自动跳过空白字符）
    bool result = qi::phrase_parse(iter, end, g, ascii::space);

    if(result && iter == end)
        std::cout << "输入的是一个 well-formed formula!" << std::endl;
    else
        std::cout << "输入不是一个 well-formed formula." << std::endl;

    return 0;
}