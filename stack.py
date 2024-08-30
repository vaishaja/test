class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)
        print(f"Pushed {item} onto the stack.")

    def pop(self):
        if not self.is_empty():
            item = self.stack.pop()
            print(f"Popped {item} from the stack.")
            return item
        else:
            print("Stack is empty. Nothing to pop.")
            return None

    def peek(self):
        if not self.is_empty():
            print(f"Top of the stack is {self.stack[-1]}.")
            return self.stack[-1]
        else:
            print("Stack is empty. No top element.")
            return None

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        print(f"Stack size is {len(self.stack)}.")
        return len(self.stack)

    def display(self):
        print(f"Stack contents: {self.stack}")

# Example usage
stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)
stack.display()
stack.peek()
stack.pop()
stack.display()
stack.size()
