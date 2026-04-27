    int postorder[] = {-1, -1, 2, -1, -1, 3, 1}; // example
    int n = sizeof(postorder)/sizeof(postorder[0]);
    int index = n - 1;

    Node* root = buildTreePost(postorder, &index);
