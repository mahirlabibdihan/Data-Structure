        } while (w != this->root);

        this->root = NULL;
        for (int i = 0; i < max_degree; i++)
        {
            if (A[i] != NULL)
            {
                A[i]->setLeft(A[i]);
                A[i]->setRight(A[i]);
                if (this->root == NULL)
                {
                    this->root = A[i];
                }
                else
                {
                    insertIntoList(A[i], this->root);
                    if (A[i]->key() < this->root->key())
                    {
                        this->root = A[i];
                    }
         