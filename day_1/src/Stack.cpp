#pragma once

#include <Stack.hpp>

namespace design_pattern::delegate {
    void Stack::push(task_type task){

        m_tasks.push_front(task);
    }
    task_type& Stack::peek() {
        return m_tasks.front();
    }
    const task_type& Stack::peek() const{
        return m_tasks.front();
    }
    task_type Stack::pop(){
        task_type front = peek();
        m_tasks.pop_front();

        return front;
    }
}

namespace design_pattern::derived {
    void Stack::push(task_type task) {
        push_front(task);
    }
    task_type& Stack::peek() {
        return front();
    }
    const task_type& Stack::peek() const {
        return front();
    }
    task_type Stack::pop() {
        task_type front = peek();
        pop_front();

        return front;
    }
}
