/****************************************************
* bst.hpp
*
* @Class: sbinlignum
*
* Node.js Addons C/C++
*
* Deps: v8, libuv
*
* (C) 2018 Erick Rettozi 
*
* MIT LICENCE
****************************************************/


#ifndef BST_HPP
#define BST_HPP

#include <node.h>
#include <node_object_wrap.h>

using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Value;

using namespace node;
using namespace v8;

class BST : public node::ObjectWrap {

	public:
	    static void Init(v8::Local<v8::Object> exports);
	    explicit BST();
            static void search(const FunctionCallbackInfo<Value>& args);

	private:
	    ~BST();

            static v8::Persistent<v8::Function> constructor;
};

#endif
