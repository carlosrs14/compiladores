#include <string>
#include <vector>
#include <string.h>
using namespace std;
class Token {
    private:
        int ascii;
        string token;
        string symbol;
    public:
        Token(int ascii, string token, string symbol) {
            this->ascii = ascii;
            this->token = token;
            this->symbol = symbol;
        }
        int getAscii() {
            return ascii;
        }
        string getToken() {
            return token;
        }
        string getSymbol() {
            return symbol;
        }
        string toString() {
            return getToken() + " -> [" + getSymbol() + "]";
        }
        ~Token(){
            //destructor de token
        }
};
class ListaTokens {
    public:
    vector<Token> list;
    void addToken(Token t) {
        list.push_back(t);
    }
    bool contains(Token t) {
        for(int i = 0; i < (int)list.size(); i++) {
            if (list.at(i).getSymbol() == t.getSymbol()) {
               return true;
            }
        }
        return false;
    }
    int nToken() {
        return (int) list.size();
    }
    void llenarTokens() {
        //addToken(Token(0,"ID", ""));
        addToken(Token(0, "NONE", "none"));
        addToken(Token(0, "TRY", "try"));
        addToken(Token(0, "CATCH", "catch"));
        addToken(Token(0, "PROTECTED", "protected"));
        addToken(Token(0, "SHORT", "short"));
        addToken(Token(0, "NEW", "new"));
        addToken(Token(0, "STATIC", "static"));
        addToken(Token(0, "INT",  "int"));
        addToken(Token(0, "VOID",  "void"));
        addToken(Token(0, "MAIN",  "main"));
        addToken(Token(0, "BREAK",  "break"));
        addToken(Token(0, "DO",  "do"));
        addToken(Token(0, "WHILE",  "while"));
        addToken(Token(0, "ELSE",  "else"));
        addToken(Token(0, "IF",  "if"));
        addToken(Token(0, "RETURN",  "return"));
        addToken(Token(0, "SCANF",  "scanf"));
        addToken(Token(0, "PRINTF",  "printf"));
        addToken(Token(0, "FOR",  "for"));
        addToken(Token(0, "BOOL",  "bool"));
        addToken(Token(0, "SWITCH",  "switch"));
        addToken(Token(0, "STRUCT",  "struct"));
        addToken(Token(0, "TYPEDEF",  "typedef"));
        addToken(Token(0, "CLASS",  "class"));
        addToken(Token(0, "PRIVATE",  "private"));
        addToken(Token(0, "PUBLIC",  "public"));
        addToken(Token(0, "USING",  "using"));
        addToken(Token(0, "NAMESPACE",  "namespace"));
        addToken(Token(0, "CASE",  "case"));
        addToken(Token(0, "CHAR",  "char"));
        addToken(Token(0, "FLOAT",  "float"));
        addToken(Token(0, "DOUBLE",  "double"));
        addToken(Token(0, "LONG",  "long"));
        addToken(Token(0, "CONST",  "const"));
        addToken(Token(0, "DEFAULT",  "default"));
        addToken(Token(0, "AUTO",  "auto"));
        addToken(Token(0, "GOTO",  "goto"));
        addToken(Token(0, "SIZEOF",  "sizeof"));
        addToken(Token(0, "TRUE",  "true"));
        addToken(Token(0, "FALSE",  "false"));
        addToken(Token(0, "NULL",  "null"));
        addToken(Token(0, "ENUM",  "enum"));
        addToken(Token(0, "REGISTER",  "register"));
        addToken(Token(0, "EXTERN",  "extern"));
        addToken(Token(0, "UNION",  "union"));
        addToken(Token(0, "UNSIGNED",  "usigned"));
        addToken(Token(0, "SIGNED",  "signed"));
        addToken(Token(0, "VOLATILE",  "volatile"));
        addToken(Token(0, "DELETE",  "delete"));
        //DIRECTRICES DE PREPROCESAMIENTO
        addToken(Token(0, "DEFINE",  "define"));
        addToken(Token(0, "ELIF",  "elif"));
        addToken(Token(0, "ELSE",  "else"));
        addToken(Token(0, "ENDIF",  "endif"));
        addToken(Token(0, "ERROR",  "error"));
        addToken(Token(0, "IF",  "if"));
        addToken(Token(0, "IFDEF",  "ifdef"));
        addToken(Token(0, "IFNDEF",  "ifndef"));
        addToken(Token(0, "INCLUDE",  "include"));
        addToken(Token(0, "MESSAGE",  "message"));
        addToken(Token(0, "UNDEF",  "undef"));
        //OPERADORES LÓGICO
        addToken(Token(123, "LBRACE",  "{"));
        addToken(Token(125, "RBRACE",  "}"));
        addToken(Token(91, "LSQUARE",  "["));
        addToken(Token(93, "RSQUARE",  "]"));
        addToken(Token(40, "LPAR",  "("));
        addToken(Token(41, "RPAR",  ")"));
        addToken(Token(59, "SEMI",  ";"));
        addToken(Token(43, "PLUS",  "+"));
        addToken(Token(37, "MOD_OP",  "%"));
        addToken(Token(45, "MINUS",  "-"));
        addToken(Token(42, "MUL_OP",  "*"));
        addToken(Token(38, "DIV_OP",  "/"));
        addToken(Token(47, "AND_OP",  "&"));
        addToken(Token(124, "OR_OP",  "|"));
        addToken(Token(33, "NOT_OP",  "!"));
        addToken(Token(61, "ASSIGN",  "="));
        addToken(Token(60, "LT",  "<"));
        addToken(Token(62, "GT",  ">"));
        addToken(Token(0, "HASHTAG", "#"));
        //tokens.addToken(Token(174, "",  "<<")); los que tienen más de dos caracteres se retonarán por separados
        addToken(Token(44, "COMMA",  ","));
        addToken(Token(94, "POW_OP",  "^"));
        addToken(Token(46, "POINT",  "."));
        addToken(Token(39, "COMILLA_SIMPLE",  "'"));
        addToken(Token(34, "COMILLA_DOBLE",  "\""));//falta
        addToken(Token(0, "", "\n"));
        addToken(Token(0, "", "\0"));
        addToken(Token(0, "", "\r"));
        addToken(Token(0, "", "\f"));
        addToken(Token(0, "", "\b"));
        addToken(Token(0, "", "\t"));
        addToken(Token(0, "", "\\"));
        addToken(Token(0, "", "\a"));
        //addToken(Token(0, "", "\""));
        addToken(Token(126, "NEG",  "~"));
        addToken(Token(36, "SIGNO_DOLLAR",  "$"));
    }
};