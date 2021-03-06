#ifndef TSP_COLLECTIONS
#define TSP_COLLECTIONS

#include <cstdlib>
#include <vector>
#include <functional>

template <typename T>
class Collection {

    private:

        std::vector<T> items;

    public:

        Collection() {}
        ~Collection() {}

        void add(T item) {
            items.push_back(item);
        }

        size_t count() {
            return items.size();
        }

        // Collection* filter(std::function<bool(T)> fn) {
        //     Collection<T> *result = new Collection<T>();
        //     for (size_t i = 0; i < items.size(); ++i) {
        //         T item = items.at(i);
        //         if (fn(item)) {
        //             result->add(item);
        //         }
        //     }
        //     return result;
        // }

        T firstOrDefault() {
            if (items.size() == 0) {
                return NULL;
            }

            return items.at(0);
        }

        T first() {
            return items.at(0);
        }

        T& at(int index) {
            return items.at(index);
        }

};

#endif