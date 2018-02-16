/****************************************************
* bst.cpp
*
* Constructors and Methods sbinlignum Class
*
* Node.js Addons C/C++
*
* Deps: v8, libuv
*
* (C) 2018 Erick Rettozi
*
* MIT LICENCE
****************************************************/

#include <node.h>
#include "bst.hpp"

using namespace std;
using namespace v8;

using v8::Exception;
using v8::Function;
using v8::FunctionTemplate;
using v8::HandleScope;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::String;
using v8::Value;
using v8::Array;

/*
* @Globals
*/
Persistent<Function> BST::constructor;

/*
* Struct
*/
struct ntree {
        int data;
        ntree *left;
        ntree *right;
};

/*
* createNewNodeTree
*
* @Private
*/
ntree* createNewNodeTree(int data) {
        ntree *newntree = new ntree;
        newntree->data = data;
        newntree->left = NULL;
        newntree->right = NULL;

        return newntree;
}

/*
* createBSTree
*
* @Private
*/
ntree* createBSTree(ntree* root, int data) {
        ntree *tmpntree = createNewNodeTree(data);
        ntree *tree = new ntree;
        tree = root;

        if(root != NULL)
                while(tree != NULL) {
                        if(tree->data < data ) {
                                if(tree->right == NULL) {
                                        tree->right = tmpntree;
                                        break;
                                }

                                tree = tree->right;
                        }
                        else if(tree->data > data) {
                                if(tree->left == NULL) {
                                        tree->left = tmpntree;
                                        break;
                                }
                                tree = tree->left;
                        }
                }
        else
        	root = tmpntree;

        return root;
}

/*
* Binary search tree
*
* @Private
*/
int bsTree(ntree *root, int data) {
        int depth = 0;
        ntree *tmpntree = new ntree;
        tmpntree = root;

        while(tmpntree != NULL) {
                depth++;
                if(tmpntree->data == data)
                        return depth;
                else if(tmpntree->data > data)
                        tmpntree = tmpntree->left;
                else
                        tmpntree = tmpntree->right;
        }

        return 0;
}

/*
* DESTRUCTOR()
*
* @Private
*/
BST::~BST() {
	//...
}

/*
* CONSTRUCTOR()
*
* @Public
*/
BST::BST() {
	//...
}

/*
* Init methods
*
* @Public
*/
void BST::Init(Local<Object> exports) {
	Isolate* isolate = exports->GetIsolate();

	Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, NULL);
	tpl->SetClassName(String::NewFromUtf8(isolate, "BST"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Set method search
	NODE_SET_PROTOTYPE_METHOD(tpl, "search", search);

	constructor.Reset(isolate, tpl->GetFunction());
	exports->Set(String::NewFromUtf8(isolate, "BST"),tpl->GetFunction());
}

/*
* search
*
* @Public
*/
void BST::search(const FunctionCallbackInfo<Value>& args) {

        Isolate* isolate = args.GetIsolate();

        if(args.Length() < 2) {
        	isolate->ThrowException(Exception::TypeError(
                		String::NewFromUtf8(isolate, "Use: search((int)<search for an element>,(int)Array,callback)"))
			);
                return;
        }

	Local<Number> value = Local<Number>::Cast(args[0]);
	int elem = value->NumberValue();

	Local<Array> array = Local<Array>::Cast(args[1]);
	unsigned int sizeInputArray = array->Length();
	int inputArray[sizeInputArray];

	for (unsigned int i = 0; i < sizeInputArray; i++) {
		Local<Number> value = Local<Number>::Cast(array->Get(i)); 
                inputArray[i] = value->NumberValue();
	}

	ntree *root = new ntree;
        root = NULL;

        for(unsigned i = 0; i < sizeInputArray; i++)
                root = createBSTree(root, inputArray[i]);

	// Binary search tree
	int number = bsTree(root,elem);

	Local<Value> result[1] = { v8::Number::New(isolate, number) };

    	HandleScope scope(isolate);
	Local<Function> cb = Local<Function>::Cast(args[2]);
        cb->Call(isolate->GetCurrentContext()->Global(), 1, result);
}
