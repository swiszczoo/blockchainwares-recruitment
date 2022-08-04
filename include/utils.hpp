#pragma once
#include <initializer_list>

struct utils {
    template <class Container, typename... Args>
    static void push_back_all(Container& container, Args&&... args)
    {
        (container.push_back(std::forward<Args>(args)), ...);
    }
};
