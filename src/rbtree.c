#include "rbtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

node_t* head_node;
int node_count;

void* head_node_to_t_root(rbtree* t)
{
    t->root = head_node->left;
}

//rbtree_to_array�� ��µ� �迭�� �����ϱ� ���� �Լ�

static int comp(const void* p1, const void* p2)
{
    const key_t* e1 = (const key_t*)p1;
    const key_t* e2 = (const key_t*)p2;
    if (*e1 < *e2)
    {
        return -1;
    }
    else if (*e1 > *e2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};


rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree), 1);
  // TODO: initialize struct if needed
  return p;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
    node_t* rbtree_insert(rbtree * t, const key_t key)
    {
        // TODO: implement insert

        // ù ����
        if (t->root == NULL)
        {
            // ��Ʈ �����:
            node_t* temp;
            temp = malloc(sizeof(node_t));
            t->root = temp;
            t->root->key = key;
            t->root->color = RBTREE_BLACK;
            t->root->left = t->root->right = t->root->parent = NULL;
            node_count = 1;

            //headnode ����
            head_node = malloc(sizeof(node_t));
            head_node->left = t->root;
            head_node->right = head_node->parent = NULL;
            head_node->color = RBTREE_BLACK;
            // t->root->parent = head_node;

            return t->root;
        }

        //�ι�°+ ����
        // n�� ���� ��带 ��Ī.
        node_t* n, * p, * gp, * ggp;
        ggp = gp = p = (node_t*)head_node;
        n = head_node->left;

        while (n)
        {

            // �ߺ� ������ ����
            if (key == n->key)
            {
                head_node_to_t_root(t);
                return 0;
            }

            // ���� ����ȯ ������ ��Ȳ, �ڽ� ��� �ΰ��� �����̰� ���� �����϶�
            if (n->left && n->right && n->left->color == RBTREE_RED && n->right->color == RBTREE_RED)
            {

                n->color = RBTREE_RED;
                n->left->color = n->right->color = RBTREE_BLACK;

                // �� ��ȯ ������ ��쿡�� ��Ģ ���� ��Ȳ�� �߻���. �̸� �ؼ��ϱ� ���� ȸ���� �ʿ����� üũ.

                // ������ ���ӵǱ⿡ ȸ�� �ʿ�
                if (p->color == RBTREE_RED)
                {

                    gp->color = RBTREE_RED;

                    //���� ȸ���� �ʿ��� ���
                    if ((key > gp->key) != (key > p->key))
                        p = _Rotate(key, gp, t);
                    n = _Rotate(key, ggp, t);
                    n->color = RBTREE_BLACK;
                }

                // ��Ʈ�� ������ ����
                head_node->left->color = RBTREE_BLACK;
            }

            //gp, p ��� ������Ʈ
            ggp = gp;
            gp = p;
            p = n;

            // �����Ϸ��� key ���� ���� Ʈ�� �¿� ����
            if (key > n->key)
                n = n->right;
            else
                n = n->left;
        }

        // while���� Ż�� �� ���, NULL leaf�� �����ߴٴ� ��

        // key ���� ������ ��� ���� �� ����
        node_t* temp;
        temp = malloc(sizeof(node_t));
        temp->key = key;
        temp->left = temp->right = NULL;
        temp->parent = p;
        temp->color = RBTREE_RED;
        node_count++;

        //�θ� ���� ����
        if (key > p->key && p != head_node)
            p->right = temp;
        else
            p->left = temp;

        //�θ� �����̸� �ѹ� �� ȸ�� / ���� ���� �����̱� ����;
        if (p->color == RBTREE_RED)
        {

            gp->color = RBTREE_RED;
            if ((key > gp->key) != (key > p->key))
                p = _Rotate(key, gp, t);
            temp = _Rotate(key, ggp, t);
            temp->color = RBTREE_BLACK;

        }

        //�Ѹ��� ��������
        head_node->left->color = RBTREE_BLACK;

        head_node_to_t_root(t);
        return head_node->left;
    }
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
