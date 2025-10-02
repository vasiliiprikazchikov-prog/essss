Биномиальная куча (Java)
import java.util.ArrayList;
import java.util.List;

class BinomialNode {
    int key;
    int degree;
    BinomialNode parent;
    BinomialNode child;
    BinomialNode sibling;

    public BinomialNode(int key) {
        this.key = key;
        this.degree = 0;
    }
}

class BinomialHeap {
    private BinomialNode head;

    public void insert(int key) {
        BinomialHeap temp = new BinomialHeap();
        temp.head = new BinomialNode(key);
        this.union(temp);
    }

    public int getMin() {
        if (head == null) return -1;
        BinomialNode minNode = head;
        BinomialNode curr = head;
        while (curr != null) {
            if (curr.key < minNode.key) {
                minNode = curr;
            }
            curr = curr.sibling;
        }
        return minNode.key;
    }

    private void union(BinomialHeap other) {
        merge(other);
        if (head == null) return;

        BinomialNode prev = null;
        BinomialNode curr = head;
        BinomialNode next = head.sibling;

        while (next != null) {
            if (curr.degree != next.degree ||
                (next.sibling != null && next.sibling.degree == curr.degree)) {
                prev = curr;
                curr = next;
            } else if (curr.key <= next.key) {
                curr.sibling = next.sibling;
                link(next, curr);
            } else {
                if (prev == null) {
                    head = next;
                } else {
                    prev.sibling = next;
                }
                link(curr, next);
                curr = next;
            }
            next = curr.sibling;
        }
    }

    private void merge(BinomialHeap other) {
        BinomialNode h1 = this.head;
        BinomialNode h2 = other.head;
        BinomialNode newHead = null, tail = null;

        while (h1 != null && h2 != null) {
            BinomialNode min;
            if (h1.degree <= h2.degree) {
                min = h1;
                h1 = h1.sibling;
            } else {
                min = h2;
                h2 = h2.sibling;
            }

            if (newHead == null) {
                newHead = min;
                tail = min;
            } else {
                tail.sibling = min;
                tail = min;
            }
        }

        while (h1 != null) {
            tail.sibling = h1;
            tail = h1;
            h1 = h1.sibling;
        }

        while (h2 != null) {
            tail.sibling = h2;
            tail = h2;
            h2 = h2.sibling;
        }

        head = newHead;
    }

    private void link(BinomialNode y, BinomialNode z) {
        y.parent = z;
        y.sibling = z.child;
        z.child = y;
        z.degree++;
    }
}

public class BinomialHeapDemo {
    public static void main(String[] args) {
        System.out.println("=== Биномиальная куча на Java ===");
        BinomialHeap heap = new BinomialHeap();
        heap.insert(10);
        heap.insert(3);
        heap.insert(7);
        heap.insert(1);
        heap.insert(8);

        System.out.println("Минимальный элемент: " + heap.getMin());
    }
}




Куча Фибоначчи 
import java.util.ArrayList;
import java.util.List;

class FibNode {
    int key;
    FibNode parent, child, left, right;
    int degree;
    boolean marked;

    public FibNode(int key) {
        this.key = key;
        this.degree = 0;
        this.marked = false;
        this.parent = null;
        this.child = null;
        this.left = this;
        this.right = this;
    }
}

class FibonacciHeap {
    private FibNode minNode;
    private int count;

    public FibonacciHeap() {
        minNode = null;
        count = 0;
    }

    public void insert(int key) {
        FibNode node = new FibNode(key);
        if (minNode == null) {
            minNode = node;
        } else {
            // Добавляем в корневой список
            node.right = minNode.right;
            node.left = minNode;
            minNode.right.left = node;
            minNode.right = node;
            if (key < minNode.key) {
                minNode = node;
            }
        }
        count++;
    }

    public int getMin() {
        return minNode == null ? -1 : minNode.key;
    }

    public int size() {
        return count;
    }
}

public class FibonacciHeapDemo {
    public static void main(String[] args) {
        System.out.println("=== Куча Фибоначчи на Java ===");
        FibonacciHeap heap = new FibonacciHeap();
        heap.insert(5);
        heap.insert(2);
        heap.insert(9);
        heap.insert(1);

        System.out.println("Минимальный элемент: " + heap.getMin());
        System.out.println("Размер кучи: " + heap.size());
    }
}
