/*
* bsTree.js
*
* @Author: Erick Rettozi
*/

const BST = new (require('sbinlignum')).BST();

BST.search(7, [13, 3, 4, 12, 14, 10, 5, 1, 8, 2, 7, 9, 11, 6, 18], (result) => {
	console.log(result);
});
