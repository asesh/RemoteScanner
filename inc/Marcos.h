#pragma once

// Dynamic memory deallocators
#define DELETEPTR(X) {delete X;}
#define DELETEPTR_FREE(X) {if(X) {delete X; X = nullptr;}}
#define SAFE_DELETEPTR_FREE(X) {delete X; X = nullptr;}

// Singleton destroyers
#define DESTROY_SINGLETON(X) {if(X) X->destroy();}
#define SAFE_DESTROY_SINGLETON(X) {X->destroy();}