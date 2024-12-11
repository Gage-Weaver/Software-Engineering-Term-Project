#ifndef UIINTERACTION_H
#define UIINTERACTION_H

#include <string>
class UIInteraction{
public:
    void startupMessage();
    std::string inputPrompt();
    void showResult(float result);
    void showError(std::string error);
};

#endif


