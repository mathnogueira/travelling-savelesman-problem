#pragma once

template <typename T>
class GraphNode {

    private:
        T *content;

    public:
        GraphNode(T *content) {
            this->content = content;
        }

        T* getContent() {
            return content;
        }
};