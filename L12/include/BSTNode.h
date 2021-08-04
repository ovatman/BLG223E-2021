class BSTNode{
    private:
        int data;
        BSTNode* left;
        BSTNode* right;
    
    public:
        BSTNode(int);
        void set_left(BSTNode*);
        void set_right(BSTNode*);
        void set_data(int);

        void add(int);
        bool contains(int);
        void remove(int);

        BSTNode* get_left();
        BSTNode* get_right();
        BSTNode** get_left_addr();
        BSTNode** get_right_addr();
        int get_data();
};
