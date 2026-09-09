import java.util.ArrayList;
import java.util.Stack;
class MinStack {
    ArrayList<Integer> stack = new ArrayList<Integer>();
    Stack<Integer> sMin = new Stack<Integer>();
    public MinStack() {
        
    }
    
    public void push(int val) {
        stack.add(val);
        if(sMin.isEmpty() || val <= sMin.peek())
            sMin.push(val);
        
    }
    
    public void pop() {
        int x = stack.removeLast();
        if(sMin.peek() == x)
            sMin.pop();
    }
    
    public int top() {
        return stack.getLast();
    }
    
    public int getMin() {
        return sMin.peek();
    }
}

/**
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */