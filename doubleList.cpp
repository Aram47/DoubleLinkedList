#include <iostream>
#include "doubleList.hpp"

DoubleList::DoubleList() : m_head(nullptr) {} // Կանստրուկտռ

DoubleList::~DoubleList() // Դեստրուկտռ
{
    DoubleList::clear();
}

void DoubleList::pushFront(const int& val)
{
    if (!m_head)
    {
        m_head = new DbNode();
        m_head->m_val = val;
    } else {
        DbNode* tmp = m_head;
        while (tmp)
        {
            if (!(tmp->m_next))
            {
                tmp->m_next = new DbNode();
                tmp->m_next->m_val = val;
                tmp->m_next->m_prev = tmp;
                tmp = tmp->m_next;
            }
            tmp = tmp->m_next;
        }
    }  
}

void DoubleList::pushBack(const int& val)
{
    if (!m_head)
    {
        m_head = new DbNode();
        m_head->m_val = val;
    } else {
        DbNode* tmp = m_head;
        while (tmp)
        {
            if (!(tmp->m_prev))
            {
                tmp->m_prev = new DbNode();
                tmp->m_prev->m_val = val;
                tmp->m_prev->m_next = tmp;
                m_head = tmp->m_prev;
                tmp = tmp->m_prev;
            }
            tmp = tmp->m_prev;
        }
    }
}

void DoubleList::popFront()
{
    if (!m_head)
        return;
    if (!(m_head->m_next))
    {
        delete m_head;
        m_head = nullptr;
        return;
    }
    DbNode* tmp = m_head;
    while (tmp)
    {
        if (!(tmp->m_next))
        {
            tmp = tmp->m_prev;
            delete tmp->m_next;
            tmp->m_next = nullptr;
        }
        tmp = tmp->m_next;
    }
}

void DoubleList::popBack()
{
    if (!m_head)
        return;
    if (!(m_head->m_next))
    {
        delete m_head;
        m_head = nullptr;
        return;
    }
    m_head = m_head->m_next;
    delete m_head->m_prev;
    m_head->m_prev = nullptr;
}

void DoubleList::printForvard()
{
    if (!m_head)
        return;
    DbNode* tmp = m_head;
    while (tmp)
    {
        std::cout << tmp->m_val << std::endl;
        tmp = tmp->m_next;
    }
}

void DoubleList::printBackward()
{
    if (!m_head)
        return;
    DbNode* tmp = m_head;
    while (tmp)
    {
        if (!(tmp->m_next))
            break;
        tmp = tmp->m_next;
    }

    while (tmp)
    {
        std::cout << tmp->m_val << std::endl;
        tmp = tmp->m_prev;
    }
}

DbNode* DoubleList::find(const int& val) const
{
    DbNode* tmp = m_head;
    while (tmp)
    {
        if (tmp->m_val == val)
            return tmp;
        tmp = tmp->m_next;
    }
    return tmp;
}

bool DoubleList::contains(const int& val) const
{
    DbNode* tmp = m_head;
    while (tmp)
    {
        if (tmp->m_val == val)
            return true;
        tmp = tmp->m_next;
    }
    return false;
}

int DoubleList::size() const
{
    int countNods = 0;
    DbNode* tmp = m_head;
    while (tmp)
    {
        ++countNods;
        tmp = tmp->m_next;
    }
    return countNods;
}

bool DoubleList::empty() const
{
    if (!m_head)
        return true;
    return false;
}

void DoubleList::clear()
{
    while (m_head) DoubleList::popBack();
}
