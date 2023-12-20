#include <iostream>
#include "queue"
#include "vector"

struct Tree {
    int data;
    Tree *left;
    Tree *right;

    void printLNR() {
        if ((*this).left != nullptr) {
            (*this).left->printLNR();
        }
        std::cout << data << ' ';
        if ((*this).right != nullptr) {
            (*this).right->printLNR();
        }
    }

    void printBFS() {
        std::queue<Tree *> desc;
        desc.push(&(*this));
        while (!desc.empty()) {
            std::cout << desc.front()->data << ' ';
            if (desc.front()->left != nullptr) {
                desc.push(desc.front()->left);
            }
            if (desc.front()->right != nullptr) {
                desc.push(desc.front()->right);
            }
            desc.pop();
        }
    }
};

bool SymmetricCheck(Tree *bt, int null) {
    ///Нужна проверка, чтобы отсекать такие случаи
    ///        1                1               1
    ///     2     2          2     2         2     2
    ///    3 6   3          3 3             3
    ///Для этого при отсутствии потомков будем заполнять вектор нулем
    ///        1                1               1
    ///     2     2          2     2         2     2
    ///    3 6   3 0        3 3   0 0       0 3   0 0
    ///Но возможен случай, даже когда при заполнении нулями несимметричное дерево будет считаться симметричным
    ///        1                   1
    ///     2     2     =>      2     2
    ///    0 0                 0 0   0 0
    ///Для таких ситуаций будем второй раз проверять дерево, но заполняя его уже другим числом - 1
    ///Если дерево не проходит хотя бы одну из проверок - оно несимметричное
    std::vector<Tree *> v1;
    std::vector<Tree *> v2;
    if (bt->left == nullptr) {
        Tree *empty = new Tree;
        empty->data = null;
        empty->left = nullptr;
        empty->right = nullptr;
        v1.push_back(empty);
    } else {
        v1.push_back(bt->left);
    }
    if (bt->right == nullptr) {
        Tree *empty = new Tree;
        empty->data = null;
        empty->left = nullptr;
        empty->right = nullptr;
        v1.push_back(empty);
    } else {
        v1.push_back(bt->right);
    }
    while (!v1.empty()) {
        bool fl = true;
        auto right_ptr = v1.end();
        right_ptr--;
        for (auto left_ptr = v1.begin(); left_ptr < right_ptr; left_ptr++) {
            if ((*left_ptr)->data != (*right_ptr)->data) {
                return false;
            }
            if ((*left_ptr)->left != nullptr) {
                v2.push_back((*left_ptr)->left);
                fl = false;
            } else {
                Tree *empty = new Tree;
                empty->data = null;
                empty->left = nullptr;
                empty->right = nullptr;
                v2.push_back(empty);
            }
            if ((*left_ptr)->right != nullptr) {
                v2.push_back((*left_ptr)->right);
                fl = false;
            } else {
                Tree *empty = new Tree;
                empty->data = null;
                empty->left = nullptr;
                empty->right = nullptr;
                v2.push_back(empty);
            }

            if ((*right_ptr)->left != nullptr) {
                v2.push_back((*right_ptr)->left);
                fl = false;
            } else {
                Tree *empty = new Tree;
                empty->data = null;
                empty->left = nullptr;
                empty->right = nullptr;
                v2.push_back(empty);
            }
            if ((*right_ptr)->right != nullptr) {
                v2.push_back((*right_ptr)->right);
                fl = false;
            } else {
                Tree *empty = new Tree;
                empty->data = null;
                empty->left = nullptr;
                empty->right = nullptr;
                v2.push_back(empty);
            }
            right_ptr--;
        }
        v1 = v2;
        if (fl) {
            break;
        }
    }
    return true;
}

bool isSymmetricBFS(Tree *bt) {
    return (SymmetricCheck(bt, 0) && SymmetricCheck(bt, 1));
}

int main() {
    {
        Tree *t1 = new Tree;
        ///    1
        ///  2   2
        /// 3     3
        t1->data = 1;
        Tree *tmp_l = new Tree;
        tmp_l->data = 2;
        tmp_l->left = nullptr;
        tmp_l->right = nullptr;
        Tree *tmp_r = new Tree;
        tmp_r->data = 2;
        tmp_r->left = nullptr;
        tmp_r->right = nullptr;
        Tree *tmp_ll = new Tree;
        tmp_ll->data = 3;
        tmp_ll->left = nullptr;
        tmp_ll->right = nullptr;
        Tree *tmp_rr = new Tree;
        tmp_rr->data = 3;
        tmp_rr->left = nullptr;
        tmp_rr->right = nullptr;
        t1->left = tmp_l;
        t1->left->left = tmp_ll;
        t1->right = tmp_r;
        t1->right->right = tmp_rr;
//    t1->printBFS();
        std::cout << "1: " << isSymmetricBFS(t1) << std::endl;
    }

    {
        Tree *t2 = new Tree;
        ///    1
        ///  2   2
        /// 0 0
        t2->data = 1;
        Tree *tmp_l = new Tree;
        tmp_l->data = 2;
        tmp_l->left = nullptr;
        tmp_l->right = nullptr;
        Tree *tmp_r = new Tree;
        tmp_r->data = 2;
        tmp_r->left = nullptr;
        tmp_r->right = nullptr;
        Tree *tmp_ll = new Tree;
        tmp_ll->data = 0;
        tmp_ll->left = nullptr;
        tmp_ll->right = nullptr;
        Tree *tmp_lr = new Tree;
        tmp_lr->data = 0;
        tmp_lr->left = nullptr;
        tmp_lr->right = nullptr;
        t2->left = tmp_l;
        t2->right = tmp_r;
        t2->left->left = tmp_ll;
        t2->left->right = tmp_lr;
        std::cout << "2: " << isSymmetricBFS(t2) << std::endl;
    }
    {
        Tree *t3 = new Tree;
        ///    1
        ///  1
        ///   0
        t3->data = 1;
        Tree *tmp_l = new Tree;
        tmp_l->data = 1;
        tmp_l->left = nullptr;
        tmp_l->right = nullptr;
        Tree *tmp_lr = new Tree;
        tmp_lr->data = 0;
        tmp_lr->left = nullptr;
        tmp_lr->right = nullptr;
        t3->left = tmp_l;
        t3->right = nullptr;
        t3->left->right = tmp_lr;
        std::cout << "3: " << isSymmetricBFS(t3) << std::endl;
        ///Кстати, симметричность результата обхода по LNR тоже не является достаточным условием симметричности дерева
        std::cout << "LNR: ";
        t3->printLNR();
    }
    return 0;
}
