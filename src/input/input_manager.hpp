#pragma once
#include "GLFW/glfw3.h"
#include "action.hpp"
#include <unordered_map>
#include <unordered_set>

class InputManager {
public:
    explicit InputManager(GLFWwindow* window);

    void bindKey(int key, Action action);
    void unbindKey(int key);

    bool consume(Action action);

    void clear();

private:
    static void keyCallback(
        GLFWwindow* window,
        int key,
        int scancode,
        int action,
        int mods
    );

    void handleKeyPress(int key);

    void setupDefaultBindings();

private:
    GLFWwindow* window = nullptr;
    
    std::unordered_map<int, Action> keyBindings;
    std::unordered_set<Action> pressedActions;
};
