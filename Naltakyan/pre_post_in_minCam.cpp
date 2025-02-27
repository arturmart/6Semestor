
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include <iomanip>
#include <string>

template <class  T>

class Tree {

public:
    class Node {
    public:
        Node(T value) : value(value) {
            R = nullptr;
            L = nullptr;
        }
        Node(T value, Node* L, Node* R) : value(value), L(L), R(R) {
        }

        Node* R;
        Node* L;
        T value;
    private:
    };

    Tree() {};



    void insertCyclik(int value) {
        if (!root) {
            root = new Node(value);
        }
        else {
            Node* crr = root;
            while (true) {
     
                if (value >= crr->value) {
                    if (!(crr->R)) {
                        crr->R = new Node(value);
                        break;
                    }
                    else {
                        crr = crr->R;
                        continue;
                    }

                }
                else {
                    if (!(crr->L)) {
                        crr->L = new Node(value);
                        break;
                    }
                    else {
                        crr = crr->L;
                        continue;
                    }
                }
            } 
            
        }

    }

    std::vector<T> inorderTraversal() {
        return inorderTraversal(root);
    }
    std::vector<T> preorderTraversal() {
        return preorderTraversal(root);
    }
    std::vector<T> postorderTraversal() {
        return postorderTraversal(root);
    }
    int camMinTraversal() {
        
        int cnt = 0;
        int value = camMinTraversal(root, cnt);
        return cnt + (value == 2 ? 1 : 0);
    }

    Node* getRoot() {
        return root;
    }



private:

    std::vector<T> inorderTraversal(Node* node) {
        std::vector<T> temp;

        if (node != nullptr) {

            for (auto i : inorderTraversal(node->L)) {
                temp.push_back(i);
            }
            temp.push_back(node->value);
            for (auto i : inorderTraversal(node->R)) {
                temp.push_back(i);
            }
        }

        return temp;
    }

    std::vector<T> preorderTraversal(Node* node) {
        std::vector<T> temp;

        if (node != nullptr) {

            temp.push_back(node->value);
            for (auto i : preorderTraversal(node->L)) {
                temp.push_back(i);
            }

            for (auto i : preorderTraversal(node->R)) {
                temp.push_back(i);
            }
        }

        return temp;
    }

    std::vector<T> postorderTraversal(Node* node) {
        std::vector<T> temp;

        if (node != nullptr) {

            
            for (auto i : postorderTraversal(node->L)) {
                temp.push_back(i);
            }

            for (auto i : postorderTraversal(node->R)) {
                temp.push_back(i);
            }
            temp.push_back(node->value);
        }

        return temp;
    }

    int camMinTraversal(Node* node, int& cnt) {
      

        if (node == nullptr) {
            return 1;
        }

        int L = camMinTraversal(node->L, cnt);
        int R = camMinTraversal(node->R, cnt);

        if (L == 1 && R == 1) return 2;
        if (L == 2 || R == 2) {
            cnt++;
            return 3;
        }



        return 1;
    }

    
 

    


    Node* root = nullptr;

    


};


template <class  T>

void printVector(std::vector<T> vec) {

    for (auto i : vec) {
        std::cout << i<<" ";
    }
    std::cout << std::endl;

}

template <class T>
void printTree(typename Tree<T>::Node* root, std::string prefix = "", bool isLeft = true) {
    if (root == nullptr) return;

    std::cout << prefix << (isLeft ? "|--- " : "+--- ") << root->value << std::endl;

    std::string newPrefix = prefix + (isLeft ? "|    " : "    ");

    if (root->L || root->R) {  // Prevent printing unnecessary structure
        printTree<T>(root->L, newPrefix, true);
        printTree<T>(root->R, newPrefix, false);
    }
}

int main()
{

    std::vector<int> treeVec = {10,5,6,15,100,12,4};

    Tree<int> tree;

    for (auto i : treeVec) {
        tree.insertCyclik(i);
    }

    printVector(treeVec);

    std::cout << std::endl;
    printTree<int>(tree.getRoot());
    std::cout << std::endl;

    printVector(tree.inorderTraversal());
    printVector(tree.preorderTraversal());
    printVector(tree.postorderTraversal());

    std::cout << tree.camMinTraversal() << std::endl;


    std::cout << "-------------" << std::endl;


    std::vector<int> treeVec2 = { 10,9,7,8};

    Tree<int> tree2;
    for (auto i : treeVec2) {
        tree2.insertCyclik(i);
    }
    printVector(treeVec2);

    std::cout << std::endl;
    printTree<int>(tree2.getRoot());
    std::cout << std::endl;

    std::cout << tree2.camMinTraversal()<< std::endl;


  

}
