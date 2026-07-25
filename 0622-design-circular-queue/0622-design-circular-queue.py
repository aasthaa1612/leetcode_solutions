class MyCircularQueue(object):

    def __init__(self, k):
        """
        :type k: int
        """
        self.q = [0] * k
        self.k = k
        self.front = 0
        self.rear = -1
        self.count = 0

    def enQueue(self, value):
        """
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False

        self.rear = (self.rear + 1) % self.k
        self.q[self.rear] = value
        self.count += 1
        return True

    def deQueue(self):
        """
        :rtype: bool
        """
        if self.isEmpty():
            return False

        self.front = (self.front + 1) % self.k
        self.count -= 1
        return True

    def Front(self):
        """
        :rtype: int
        """
        if self.isEmpty():
            return -1
        return self.q[self.front]

    def Rear(self):
        """
        :rtype: int
        """
        if self.isEmpty():
            return -1
        return self.q[self.rear]

    def isEmpty(self):
        """
        :rtype: bool
        """
        return self.count == 0

    def isFull(self):
        """
        :rtype: bool
        """
        return self.count == self.k


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()