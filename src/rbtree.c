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

//rbtree_to_array로 출력된 배열을 정렬하기 위한 함수

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

        // 첫 삽입
        if (t->root == NULL)
        {
            // 루트 만들기:
            node_t* temp;
            temp = malloc(sizeof(node_t));
            t->root = temp;
            t->root->key = key;
            t->root->color = RBTREE_BLACK;
            t->root->left = t->root->right = t->root->parent = NULL;
            node_count = 1;

            //headnode 생성
            head_node = malloc(sizeof(node_t));
            head_node->left = t->root;
            head_node->right = head_node->parent = NULL;
            head_node->color = RBTREE_BLACK;
            // t->root->parent = head_node;

            return t->root;
        }

        //두번째+ 삽입
        // n이 현재 노드를 지칭.
        node_t* n, * p, * gp, * ggp;
        ggp = gp = p = (node_t*)head_node;
        n = head_node->left;

        while (n)
        {

            // 중복 방지를 위해
            if (key == n->key)
            {
                head_node_to_t_root(t);
                return 0;
            }

            // 상향 색변환 가능한 상황, 자식 노드 두개가 빨강이고 나는 검정일때
            if (n->left && n->right && n->left->color == RBTREE_RED && n->right->color == RBTREE_RED)
            {

                n->color = RBTREE_RED;
                n->left->color = n->right->color = RBTREE_BLACK;

                // 색 변환 이후의 경우에만 원칙 위배 상황이 발생함. 이를 해소하기 위해 회전이 필요한지 체크.

                // 빨강이 연속되기에 회전 필요
                if (p->color == RBTREE_RED)
                {

                    gp->color = RBTREE_RED;

                    //이중 회전이 필요한 경우
                    if ((key > gp->key) != (key > p->key))
                        p = _Rotate(key, gp, t);
                    n = _Rotate(key, ggp, t);
                    n->color = RBTREE_BLACK;
                }

                // 루트는 언제나 검정
                head_node->left->color = RBTREE_BLACK;
            }

            //gp, p 등등 업데이트
            ggp = gp;
            gp = p;
            p = n;

            // 삽입하려는 key 값에 따라 트리 좌우 결정
            if (key > n->key)
                n = n->right;
            else
                n = n->left;
        }

        // while문을 탈출 할 경우, NULL leaf에 도달했다는 뜻

        // key 값을 배정할 노드 생성 후 배정
        node_t* temp;
        temp = malloc(sizeof(node_t));
        temp->key = key;
        temp->left = temp->right = NULL;
        temp->parent = p;
        temp->color = RBTREE_RED;
        node_count++;

        //부모 노드와 연결
        if (key > p->key && p != head_node)
            p->right = temp;
        else
            p->left = temp;

        //부모가 빨강이면 한번 더 회전 / 삽입 노드는 빨강이기 때문;
        if (p->color == RBTREE_RED)
        {

            gp->color = RBTREE_RED;
            if ((key > gp->key) != (key > p->key))
                p = _Rotate(key, gp, t);
            temp = _Rotate(key, ggp, t);
            temp->color = RBTREE_BLACK;

        }

        //뿌리는 검정으로
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
