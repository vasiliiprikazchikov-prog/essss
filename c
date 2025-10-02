Бинарная куча (min-heap)
import heapq

class BinaryHeap:
    def __init__(self):
        self.heap = []
    
    def push(self, val):
        heapq.heappush(self.heap, val)
    
    def pop(self):
        return heapq.heappop(self.heap) if self.heap else None
    
    def peek(self):
        return self.heap[0] if self.heap else None
    
    def __str__(self):
        return str(self.heap)

# Демонстрация
print("=== Бинарная куча ===")
bh = BinaryHeap()
for num in [8, 3, 5, 1, 6, 2]:
    bh.push(num)

print("Куча:", bh)
print("Минимум:", bh.peek())
print("Извлечение:", bh.pop())
print("После извлечения:", bh)

Биномиальная куча
class BinomialNode:
    def __init__(self, key):
        self.key = key
        self.children = []
        self.degree = 0

class BinomialHeap:
    def __init__(self):
        self.trees = []
    
    def insert(self, key):
        new_heap = BinomialHeap()
        new_heap.trees.append(BinomialNode(key))
        self.merge(new_heap)
    
    def merge(self, other):
        self.trees.extend(other.trees)
        self.trees.sort(key=lambda node: node.degree)
    
    def get_min(self):
        if not self.trees:
            return None
        return min((tree.key for tree in self.trees))
    
    def __str__(self):
        return " | ".join(f"(root={t.key}, degree={t.degree})" for t in self.trees)

# Демонстрация
print("\n=== Биномиальная куча ===")
bh = BinomialHeap()
for x in [10, 2, 8, 15, 3]:
    bh.insert(x)

print("Куча:", bh)
print("Минимум:", bh.get_min())

  
Куча Фибоначчи
class FibNode:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.child = None
        self.left = self
        self.right = self
        self.degree = 0

class FibonacciHeap:
    def __init__(self):
        self.min_node = None
        self.count = 0
    
    def insert(self, key):
        node = FibNode(key)
        if self.min_node is None:
            self.min_node = node
        else:
            node.right = self.min_node.right
            self.min_node.right.left = node
            self.min_node.right = node
            node.left = self.min_node
            if node.key < self.min_node.key:
                self.min_node = node
        self.count += 1
    
    def get_min(self):
        return self.min_node.key if self.min_node else None
    
    def __len__(self):
        return self.count

# Демонстрация
print("\n=== Куча Фибоначчи ===")
fh = FibonacciHeap()
for x in [7, 3, 18, 52, 24]:
    fh.insert(x)

print("Минимум:", fh.get_min())
print("Размер:", len(fh))


  Хеш-таблица
class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]
    
    def _hash(self, key):
        return hash(key) % self.size
    
    def put(self, key, value):
        index = self._hash(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                self.table[index][i] = (key, value)
                return
        self.table[index].append((key, value))
    
    def get(self, key):
        index = self._hash(key)
        for k, v in self.table[index]:
            if k == key:
                return v
        return None
    
    def remove(self, key):
        index = self._hash(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                return
    
    def __str__(self):
        return str(self.table)

# Демонстрация
print("\n=== Хеш-таблица ===")
ht = HashTable()
ht.put("apple", 5)
ht.put("banana", 3)
ht.put("orange", 7)
print("Таблица:", ht)
print("Значение для 'apple':", ht.get("apple"))
ht.remove("banana")
print("После удаления 'banana':", ht)
спорта.

