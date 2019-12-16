

node* heapify(root){
	int temp_data;
	int	temp_index;
	if(root->right != NULL){
		root->right = heapify(root->right);
		if(root->right->data > root->data){

			// Swapp
			arr[root->right->index] = root->data;
			arr[root->index] = root->right->data;

			// Data is Handled
			temp_data = root->right->data;
			root->right->data = root->data;
			root->data = temp_data;

			// Indexes for node is handled
			temp_index = root->right->index;
			root->right->index = root->index;
			root->index = temp_index;

		}

	}

	if(root->left != NULL){
		root->left = heapify(root->left);
		if(root->left->data > root->data){
			
			// Swapp
			arr[root->left->index] = root->data;
			arr[root->index] = root->left->data;

			// Data is Handled
			temp_data = root->left->data;
			root->left->data = root->data;
			root->data = temp_data;

			// Indexes for node is handled
			temp_index = root->left->index;
			root->left->index = root->index;
			root->index = temp_index;

		}

	}

	return root;

}