class TreeNode{
    private:
        char data;
        TreeNode* left;
        TreeNode* right;
    
    
    public:
        TreeNode(char);
        void set_data(char);
        char get_data();
        void set_left(TreeNode*);
        TreeNode* get_left();
        void set_right(TreeNode*);
        TreeNode* get_right();
        
};