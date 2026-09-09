import java.util.LinkedList;
import java.util.Queue;

class MyStack {
    Queue<Integer> q1 = new LinkedList<Integer>();
    Queue<Integer> q2 = new LinkedList<Integer>();
    boolean st = true; // decides which is the main (true --> q1 , false --> q2)

    public MyStack() {

    }

    public void push(int x) {
        if (st)
            q1.offer(x);
        else
            q2.offer(x);

    }

    public int pop() {
        int x = 0;
        if (st) {
            int q1Size = q1.size();
            for (int i = 0; i < q1Size -1 ; i++)
                q2.offer(q1.poll());
            x = q1.poll();
            st = !st;
        }

        else {
             int q2Size = q2.size();
            for (int i = 0; i < q2Size -1 ; i++)
                q1.offer(q2.poll());
            x = q2.poll();
            st = !st;
        }
        return x;

    }

    public int top() {
        int x = 0;
        if (st) {
            int q1Size = q1.size();
            for (int i = 0; i < q1Size - 1; i++)
                q2.offer(q1.poll());
            x = q1.poll();
            q2.offer(x);
            st = !st;
        }

        else {
            int q2Size = q2.size();
            for (int i = 0; i < q2Size - 1; i++)
                q1.offer(q2.poll());
            x = q2.poll();
            q1.offer(x);
            st = !st;
        }
        return x;

    }

    public boolean empty() {
        if((st && q1.isEmpty()) || (!st && q2.isEmpty()) )
            return true ;
        return false;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */