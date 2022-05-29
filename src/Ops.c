#include <SNN/Ops.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Vector *vec_init(size_t n){
	assert(n>0);
	Vector *v = calloc(1, sizeof(Vector));
	if(v==NULL){
		return NULL;
	}
	v->n = n;
	v->data = calloc(n, sizeof(SNNTYPE));
	if(v->data == NULL){
		free(v);
		return NULL;
	}
	return v;
}

Vector *vec_arr_init(size_t n, const SNNTYPE a[n]){
	assert(n>0);
	Vector *v = vec_init(n);
	if(v==NULL){
		return NULL;
	}
	memcpy(v->data, a, n*sizeof(SNNTYPE));
	return v;
}

Vector *vec_const_init(size_t n, const SNNTYPE a){
	assert(n>0);
	Vector *v = vec_init(n);
	if(v==NULL){
		return NULL;
	}
	for(size_t i=0;i<n;i++){
		v->data[i] = a;
	}
	return v;
}

Vector *vec_copy(const Vector *a){
	if(a==NULL){
		return NULL;
	}
	Vector *v = vec_arr_init(a->n, a->data);
	if(v==NULL){
		return NULL;
	}
	return v;
}

void vec_show(const Vector *a){
	if(a==NULL){
		return;
	}
	for(size_t i=0;i<a->n;i++){
		printf("%lf ", a->data[i]);
	}
	printf("\n");
	return;
}

void vec_destroy(Vector *a){
	if(a==NULL){
		return;
	}
	if(a->data==NULL){
		free(a);
		a = NULL;
		return;
	}
	free(a->data);
	free(a);
	a = NULL;
	return;
}

Matrix *mat_init(size_t h, size_t w){
	assert(h>0 && w>0);
	Matrix *m = calloc(1, sizeof(Matrix));
	if(m==NULL){
		return NULL;
	}
	m->w = w;
	m->h = h;
	m->data = calloc(h, sizeof(Vector*));
	if(m->data==NULL){
		free(m);
		return NULL;
	}
	for(size_t i=0;i<h;i++){
		m->data[i] = vec_init(w);
		if(m->data[i]==NULL){
			for(size_t j=i;j!=0;j--){
				vec_destroy(m->data[j]);
			}
			free(m->data);
			free(m);
			return NULL;
		}
	}
	return m;
}

Matrix* mat_arr_init(size_t h, size_t w, const SNNTYPE a[h][w]){
	assert(h>0 && w>0);
	Matrix *m = calloc(1, sizeof(Matrix));
	if(m==NULL){
		return NULL;
	}
	m->h = h;
	m->w = w;
	m->data = calloc(h, sizeof(Vector*));
	for(size_t i=0;i<h;i++){
		m->data[i] = vec_arr_init(w, a[i]);
		if(m->data[i]==NULL){
			for(size_t j=i;j!=0;j--){
				vec_destroy(m->data[j]);
			}
			free(m->data);
			free(m);
			return NULL;
		}
	}
	return m;
}

Matrix *mat_const_init(size_t h, size_t w, const SNNTYPE a){
	assert(h>0 && w>0);
	Matrix *m = calloc(1, sizeof(Matrix));
	if(m==NULL){
		return NULL;
	}
	m->h = h;
	m->w = w;
	m->data = calloc(h, sizeof(Vector*));
	for(size_t i=0;i<h;i++){
		m->data[i] = vec_const_init(w, a);
		if(m->data[i]==NULL){
			for(size_t j=i;j!=0;j--){
				vec_destroy(m->data[j]);
			}
			free(m->data);
			free(m);
			return NULL;
		}
	}
	return m;
}

Matrix *mat_copy(const Matrix *a){
	assert(a!=NULL);
	Matrix *m = calloc(1, sizeof(Matrix));
	if(m==NULL){
		return NULL;
	}
	m->h = a->h;
	m->w = a->w;
	m->data = calloc(a->h, sizeof(Vector*));
	for(size_t i=0;i<a->h;i++){
		m->data[i] = vec_copy(a->data[i]);
		if(m->data[i]==NULL){
			for(size_t j=i;j!=0;j--){
				vec_destroy(m->data[j]);
			}
			free(m->data);
			free(m);
			return NULL;
		}
	}
	return m;
}

void mat_show(const Matrix *a){
	if(a==NULL){
		return;
	}
	for(size_t i=0;i<a->h;i++){
		vec_show(a->data[i]);
	}
	return;
}

void mat_destroy(Matrix *m){
	if(m==NULL){
		return;
	}
	if(m->data==NULL){
		free(m);
		return;
	}
	for(size_t i=0;i<m->h;i++){
		vec_destroy(m->data[i]);
	}
	m=NULL;
	return;
}

Vector* scalarxvect(const SNNTYPE sc, const Vector* a){
	if(a==NULL){
		return NULL;
	}
	Vector *v = vec_init(a->n);
	if(v==NULL){
		return NULL;
	}
	for(size_t i=0;i<a->n;i++){
		v->data[i] = a->data[i] * sc;
	}
	return v;
}

SNNTYPE vecxvecdot(const Vector* a, const Vector* b){
	assert(a!=NULL && b!=NULL);
	assert(a->n==b->n);
	SNNTYPE c = 0;
	for(size_t i=0;i<a->n;i++){
		c += a->data[i]*b->data[i];
	}
	return c;
}

Vector* vecxmatdot(const Vector* a, const Matrix* b){
	assert(a!=NULL && b!=NULL);
	assert(a->n==b->w);
	Vector *v = vec_init(b->h);
	for(size_t i=0;i<b->h;i++){
		v->data[i] = vecxvecdot(a, b->data[i]);
	}
	return v;
}