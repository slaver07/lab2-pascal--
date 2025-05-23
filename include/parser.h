#pragma once
#include "hierarchical_list.h"
#include "lexer.h"
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

#include <functional>

using namespace std;

class Parser {
private:
    vector<Lexeme> lexemes;
    size_t pos = 0;

    HLNode* current = nullptr;
    HLNode* root = nullptr;

    Lexeme& currentLex();
    bool match(LexemeType type);
    bool matchKeyword(const string& kw);

    void advance();

    HLNode* createNode(NodeType type, const vector<Lexeme>& expr = {});

    vector<Lexeme> collectUntil(const function<bool()>& predicate);

    void parseStatement(HLNode* parent);
    HLNode* parseIf();
    void parseBlock(HLNode* parent);

public:
    HLNode* BuildHList(vector<Lexeme>& input);
};

std::string HLNodeToString(const HLNode* node, int level);

const char* NodeTypeToString(NodeType type);
