#ifndef DBNODE_H
#define DBNODE_H

    struct DbNode
    {
        int m_val;
        DbNode* m_next;
        DbNode* m_prev;
    };

#endif