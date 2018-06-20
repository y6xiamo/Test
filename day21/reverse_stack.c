class reverse{

　public int getAndRemoveLastElement(Stack<Integer> stack) { //得到栈底元素并它移除，并且其它元素压回栈
     int result = stack.pop();
     if (stack.isEmpty()) {
     return result;
         
 } else {
                int last = getAndRemoveLastElement(stack);
                stack.push(result); //回溯，将其它元素重新压回栈
                return last; //返回栈底元素
                
 }
     }
     
     public void reverse(Stack<Integer> stack) {
             if (stack.isEmpty()) {
                    return;
            
    }
             int i = getAndRemoveLastElement(stack); //得到栈底元素
             reverse(stack); //递归，所以i依次为1，2，3
             stack.push(i);  //回溯，依次压入3，2，1
     
}
};
