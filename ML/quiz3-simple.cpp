#include <iostream>
#include <string>
#include <cctype>

class WFFParser {
public:
    explicit WFFParser(const std::string& input) : input(input), pos(0) {}

    bool parse() {
        return parseFormula() && pos == input.size();  // 解析公式并确保整个输入被解析完
    }

private:
    std::string input;
    size_t pos;

    // 跳过空格
    void skipWhitespace() {
        while (pos < input.size() && std::isspace(input[pos])) {
            ++pos;
        }
    }

    // 解析公式（Formula）
    bool parseFormula() {
        skipWhitespace();
        if (pos >= input.size()) return false;

        // 1. 检查变量（原子公式）：字母（如 P, Q, R）
        if (std::isalpha(input[pos])) {
            ++pos;
            return true;
        }

        // 2. 检查否定公式：¬ <formula>
        if (input[pos] == '¬') {
            ++pos;
            return parseFormula();
        }

        // 3. 检查二元公式：（<formula> op <formula>），op 可以是 ∧, ∨, →, ↔
        if (input[pos] == '(') {
            ++pos;  // 跳过 '('
            bool left = parseFormula();  // 解析左侧公式
            skipWhitespace();
            if (!left || !parseOperator()) return false;  // 确保有操作符
            bool right = parseFormula();  // 解析右侧公式
            skipWhitespace();
            if (pos < input.size() && input[pos] == ')') {
                ++pos;  // 跳过 ')'
                return left && right;
            }
            return false;
        }

        return false;  // 以上都不符合时返回 false
    }

    // 解析操作符（∧, ∨, →, ↔）
    bool parseOperator() {
        skipWhitespace();
        if (pos >= input.size()) return false;

        if (input[pos] == '∧' || input[pos] == '∨' || input[pos] == '→' || input[pos] == '↔') {
            ++pos;
            return true;
        }

        return false;
    }
};

int main() {
    std::string input;
    std::cout << "请输入一个逻辑公式：" << std::endl;
    std::getline(std::cin, input);

    WFFParser parser(input);
    if (parser.parse()) {
        std::cout << "输入的是一个 well-formed formula！" << std::endl;
    } else {
        std::cout << "输入不是一个 well-formed formula。" << std::endl;
    }

    return 0;
}
