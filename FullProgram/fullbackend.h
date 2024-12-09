#ifndef fullBackend_H
#define fullBackend_H

#include <string>
#include <vector>
#include "tokenizeExpression.h"
#include "allIncludes.h"

class Backend {
public:
    double backendEvaluate(const std::string &input, std::vector<std::string> &output);
};

#endif