#include <iostream>

template <class type>
class BinarySearchTree {
    private:
        struct Pair {
            std::string key;
            type value;
        };

        struct Root {
            Pair data;
            Root *small = nullptr;
            Root *big = nullptr;
            Root(std::string key, type value) {
                data = {key, value};
            };
        };

        void rInsert(Root *root, std::string key, type value) {
            if (!root) {
                root = new Root(key, value);
            }
            else {
                int compare = root->data.key.compare(key);
                if (compare == 0) {
                    root->data.value = value;
                }
                else if (compare > 0) {
                    rInsert(root->big, key, value);
                }
                else {
                    rInsert(root->small, key, value);
                }
            }
        }

        void rPrint(Root *root) {
            if (!root) {
                return;
            }
            rPrint(root->big);
            std::cout << "Key: " << root->data.key << ", Value: " << root->data.value << std::endl;
            rPrint(root->small);
        }

    public:
        int size = 0;
        Root *root;

        void insert(std::string key, type value) {
            if (size == 0) {
                root = new Root(key, value);
            }
            else {
                rInsert(root, key, value);
            }
            size++;
        }

        void print() {
            rPrint(root);
        }
};

int main() {
    BinarySearchTree<int> bst;
    bst.insert("b", 8);
    bst.insert("a", 5);
    bst.insert("c", 9);
    bst.print();
}