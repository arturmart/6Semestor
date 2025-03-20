

// AVLTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
#include <string>


std::string getSpaceStr(int size) {
    std::string str = "";
    for (int i = 0; i < size; i++) str += " ";
    return str;

}


template <typename T>
class AVLTree {


private:
    struct Node {

        Node(T newValue):height(1) { value = newValue; }
        //Node() : value(NULL){}

        T value;
        Node* left = nullptr;
        Node* right = nullptr;

        int height;


    };

    Node* root = nullptr;



    Node* insert(T insertValue, Node* node) {
        if (node == nullptr) return new Node(insertValue);

        if (insertValue > node->value)
            node->right = insert(insertValue, node->right);
        else
            node->left = insert(insertValue, node->left);

        return node;

    }
    Node* insertAVL(T insertValue, Node* node) {
        if (node == nullptr) return new Node(insertValue);

        if (insertValue > node->value)
            node->right = insert(insertValue, node->right);
        else
            node->left = insert(insertValue, node->left);

        int balance = getBalance(node);

        // Left Left Case 
        if (balance > 1 && insertValue < node->left->value)
            return rightRotate(node);
        // Right Right Case 
        if (balance < -1 && insertValue > node->right->value)
            return leftRotate(node);

        // Left Right Case 
        if (balance > 1 && insertValue > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case 
        if (balance < -1 && insertValue < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }



        return node;

    }

    int getH(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getH(node->left) - getH(node->right);
    }

    void printPreOrder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->value << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
    void printTree(Node* root, int space = 0, int count = 5) {
        if (root == nullptr) return;

        space += count; // Увеличиваем отступ

        // Сначала печатаем правый поддерево
        printTree(root->right, space);

        // Печатаем текущий узел
        std::cout << std::endl;
        for (int i = count; i < space; i++)
            std::cout << " ";
        std::cout << root->value;

#define HGT false
#define BLC true

#if HGT || BLC
        std::cout << '(';
#if HGT
        std::cout << getH(root);
#endif
#if HGT && BLC
        std::cout << ',';
#endif
#if BLC
        std::cout << getBalance(root);
#endif
        std::cout << ')';
#endif
        std::cout<<"\n";

        // Затем печатаем левый поддерево
        printTree(root->left, space);
    }


    Node* rightRotate(Node* z) {
    
        Node* y = z->left;
        Node* t2 = y->right;

        y->right = z;
        z->left = t2;

        z->height = std::max(getH(z->left), getH(z->right)) + 1;
        y->height = std::max(getH(y->left), getH(y->right)) + 1;

        return y;

    }

    Node* leftRotate(Node* z) {
 
        Node* y = z->right;
        Node* t2 = y->left;

        y->left = z;
        z->right = t2;

        z->height = std::max(getH(z->left), getH(z->right)) + 1;
        y->height = std::max(getH(y->left), getH(y->right)) + 1;

        return y;

    }
public:
    AVLTree(std::initializer_list<int> initList) {
        for (const auto& val : initList) {
            insertAVL(val);
        }

    }
    AVLTree() {}

    void insert(T insertValue) {
        root = insert(insertValue, root);
    }
    void insertAVL(T insertValue) {
        root = insertAVL(insertValue, root);
    }
    void printPreOrder() {
        printPreOrder(root);
        std::cout << std::endl;
    }

    void printTree() {
        printTree(root, 0, 4);
    }





};


int main()
{
    //AVLTree<int> myTree({40,20,60,10,30,50,70,5,15,25,35,45,55,65,75});

    AVLTree<int> myTree({ 30,20,40,10,5,4,2,60,80,90,45});



    //myTree.printPreOrder();
    myTree.printTree();
}
