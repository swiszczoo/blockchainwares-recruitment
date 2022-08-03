#pragma once
#include <initializer_list>

struct utils
{

    template <class _Container, typename... Args>
    static void push_back_all(_Container &container, Args&&... args)
    {
        (container.push_back(std::forward<Args>(args)), ...);
    }

};
