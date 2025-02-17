
#include <iostream>
#include <queue>
#include <stack>

template <class  T>

class Tree {

public:
    class Node {
    public:
        Node(T value) : value(value) {
            R = nullptr;
            L = nullptr;
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

    void printLevelOrder() {    //BFS
        std::queue<Node*> q;
        q.push(root);
        Node* temp;
        while (q.size() > 0) {
            temp = q.front();
            
            if (temp->L) {
                q.push(temp->L);
            }
            if (temp->R) {
                q.push(temp->R);
            }
            std::cout << temp->value << " ";
            q.pop();
        }
        std::cout << std::endl;

    }
    void printPreOrder() {    //DFS

        std::stack<Node*> stack;
        stack.push(root);

        while (!stack.empty()) {
            Node* temp = stack.top();
            stack.pop();

            if (temp->R) stack.push(temp->R);
            if (temp->L) stack.push(temp->L);

            std::cout << temp->value << " ";

        }
        std::cout << std::endl;


    }
 
private:
    


    Node* root = nullptr;

    


};

int main()
{
    Tree<int> tree;

    tree.insertCyclik(10);
    tree.insertCyclik(5);
    tree.insertCyclik(6);
    tree.insertCyclik(15);
    tree.insertCyclik(100);
    tree.insertCyclik(12);
    tree.insertCyclik(4);


    tree.printLevelOrder();
    tree.printPreOrder();

}
