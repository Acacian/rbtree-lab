#include "rbtree.h"

#include <stdlib.h>

rbtree* new_rbtree(void) {
	rbtree* p = (rbtree*)calloc(1, sizeof(rbtree)); // 포인터 배열을 할당, 원래 있던거
	// TODO: initialize struct if needed
	node_t* nilNode = (node_t*)malloc(sizeof(node_t)); // node_t에 배열할당, 이것도 h파일에 이미 있음.

	nilNode->color = RBTREE_BLACK; //nilNode를 검은색으로 할당

	p->nil = nilNode; //nilnode를 할당하는 포인터
	p->root = nilNode; // root를 할당하는 포인터

	return p;
}

void delete_rbtree(rbtree* t) {
	// TODO: reclaim the tree nodes's memory
	// 노드를 하나씩 찾아 가면서 삭제함.
	free(t);
}

node_t* rbtree_insert(rbtree* t, const key_t key) {
	// TODO: implement insert
	return t->root;
}

node_t* rbtree_find(const rbtree* t, const key_t key) {
	// TODO: implement find
	return t->root;
}

node_t* rbtree_min(const rbtree* t) {
	// TODO: implement find
	return t->root;
}

node_t* rbtree_max(const rbtree* t) {
	// TODO: implement find
	return t->root;
}

int rbtree_erase(rbtree* t, node_t* p) {
	// TODO: implement erase
	return 0;
}

int rbtree_to_array(const rbtree* t, key_t* arr, const size_t n) {
	// TODO: implement to_array
	return 0;
}