class Solution
{
public:
    void push(int node) {
        if(stack1.empty())
        {
            return;
        }
        stack1.push(node);               
            
    }

    int pop() {
        if(stack2.empty() && stack1.empty())
        {
            return 0;
        }
        if(!stack2.empty())
        {
            stack2.pop();
            return 1;
        }
        if(!stack1.empty())
        {
            stack2.push(stack1.pop());
            stack2.pop();
            return 1;
        }
            
    }

private:
        stack<int> stack1;
        stack<int> stack2;

};
