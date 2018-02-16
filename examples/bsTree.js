/*
* bsTree.js
*
* @Author: Erick Rettozi
*/

const BST = new (require('sbinlignum')).BST();

BST.search(7, [1,2,5,7,9,10], (result) => {
	console.log(result);
});
