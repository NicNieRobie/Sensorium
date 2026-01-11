#include "input_manager.hpp"
#include "GLFW/glfw3.h"

InputManager::InputManager(GLFWwindow* window)
    : window(window) {
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, keyCallback);
    setupDefaultBindings();
}

void InputManager::keyCallback(
    GLFWwindow* window,
    int key,
    int scancode,
    int action,
    int mods
) {
    InputManager* inputManager = static_cast<InputManager*>(glfwGetWindowUserPointer(window));

    if (!inputManager) {
        return;
    }

    if (action == GLFW_PRESS) {
        inputManager->handleKeyPress(key);
    }
}

void InputManager::handleKeyPress(int key) {
    auto it = keyBindings.find(key);
    if (it != keyBindings.end()) {
        pressedActions.insert(it->second);
    }
}

bool InputManager::consume(Action action) {
    return pressedActions.erase(action) > 0;
}

void InputManager::clear() {
    pressedActions.clear();
}

void InputManager::bindKey(int key, Action action) {
    keyBindings[key] = action;
}

void InputManager::unbindKey(int key) {
    keyBindings.erase(key);
}

void InputManager::setupDefaultBindings() {
    bindKey(GLFW_KEY_ESCAPE, Action::QUIT);
}
