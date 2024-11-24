#pragma once

#include <list>

namespace design_pattern{
    using task_type=double;
}

namespace design_pattern::delegate{
    class Stack {
        public:
            void push(task_type task);
            task_type& peek();
            const task_type& peek() const;
            task_type pop();
            size_t size() const { return m_tasks.size(); }

        private:
            std::list<task_type> m_tasks{};
    };

}

namespace design_pattern::derived{
    class Stack : protected std::list<task_type> {
        public:
            void push(task_type task);
            task_type& peek();
            const task_type& peek() const;
            task_type pop();
            size_t size() const { return std::list<task_type>::size(); }
    };

}
