#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "dbNode.hpp"

    class DoubleList
    {
        private:
            DbNode* m_head;
        public:
            DoubleList(); // Կանստրուկտռ
            ~DoubleList(); // Դեստրուկտռ
            void pushFront(const int&); // Ավելացնում ա սկզբից
            void pushBack(const int&);  // Ավելացնում ա վերջից
            void popFront(); // Ջնջում ա սկզբից
            void popBack();  // Ջնջում ա վերջից
            void printForvard(); // Տպում ա սկզբից մինչև վերջ
            void printBackward(); // Տպում ա վերջից մինչև սկիզբ
            DbNode* find(const int&) const; // Փնտրում ա ըստ ներմուծված արժեքի և եթե գտնում ա վերադարձնում ա հասցեն հակառակ դեպքում nullptr
            bool contains(const int&) const; // Փնտրում ա ներմուծված արժեքով և եթե գտնում ա վերադարձնում ա true հակառակ դեպքում false
            int size() const; // Վեարդարձնում ա լիստի երկարությունը 
            bool empty() const; // եթե դատարկա ա վերադարձնում ա true հակարակ դեպքում false
            void clear(); // մաքրում ա ամբողջ լիստի պարունակությունը
    };

#endif