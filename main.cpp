/**********************************************************************
* main.cpp
*
* Binary Search Tree
*
* Node.js Addons C/C++
*
* Deps: v8
*
* (C) 2018 Erick Rettozi 
*
* MIT LICENCE
**********************************************************************/

#include <node.h>
#include "include/bst.hpp"

using v8::Local;
using v8::Object;

void initAll (Local<Object> exports) {
	BST::Init(exports);
}

NODE_MODULE(addon, initAll);
