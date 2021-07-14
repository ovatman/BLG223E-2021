const int MAX_STACK_SIZE=10;


class MyStack{
    private:
        int arr[MAX_STACK_SIZE];
        int top;

    public:
        MyStack();
        bool push(int);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
        void clear();

};

