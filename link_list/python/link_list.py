class Node:
    def __init__(self):
        self.val = 0
        self.next = None
        self.parent = None

class DoubleLinkList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.cur = None
        self.num_of_node = 0
        
    def PushBack(self, val):
        if self.head == None:
            self.head = Node()
            self.tail = Node()
            self.head.val = val
            self.tail = self.head
        elif self.head.next == None:
            new_node = Node()
            new_node.val = val
            new_node.parent = self.head

            self.tail = new_node
            self.head.next = self.tail
        else:
            new_node = Node()
            new_node.val = val
            new_node.parent = self.tail

            self.tail.next = new_node
            self.tail = new_node
        
        self.num_of_node += 1

    def PushFront(self, value):
        if self.head == None:
            head = Node()
            head.val = value
        else:
            new_node = Node()
            new_node.val = value
            new_node.next = self.head
            self.head = new_node
        self.num_of_node += 1

    def PushNode(self, index, value):
        if index > self.num_of_node - 1:
            return None

        new_node = Node()
        new_node.val = value
        if (index == 0):
            new_node.next = self.head
            new_node.parent = None
            self.head = new_node
        else:
            self.cur = self.head        
            for i in range(index - 1):
                self.cur = self.cur.next
            new_node.next = self.cur.next
            new_node.parent = self.cur
            self.cur.next = new_node    
        self.num_of_node += 1
    
    def PopFront(self):
        node = self.head
        self.head = self.head.next
        self.num_of_node -= 1
        return node    
             
    def PopBack(self):
        node = self.tail.parent
        node.next = None
        self.tail = node
        self.num_of_node -= 1
        return node     
    
    def PopNode(self, index):
        if index > self.num_of_node - 1:
            return None

        node = None
        if index == 0:
            PopFront()
        elif index == self.num_of_node - 1:
            PopBack()
        else:
            self.cur = self.head
            for i in range(index):
                self.cur = self.cur.next
            node = self.cur
            self.cur.parent.next = self.cur.next
            self.cur.next.parent = self.cur.parent.next
        self.num_of_node -= 1

        return node
        
    def FindNode(self, index):
        if index > self.num_of_node - 1:
            return None

        self.cur = self.head   
        if (index > 0):
            while self.cur.next != None:
                self.cur = self.cur.next
        
        return self.cur

    def PrintLinkList(self):
        self.cur = self.head
        while self.cur != None:
            val = self.cur.val
            print(val)
            self.cur = self.cur.next
    
    def DeleteLink(self):
        self.head = None
        self.tail = None
        self.cur = None
        self.num_of_node = 0

def main():

    link_list = DoubleLinkList()

    link_list.PushBack(1)
    link_list.PushBack(2)
    link_list.PushBack(3)
    link_list.PushBack(4)
    link_list.PushBack(5)
    link_list.PrintLinkList()
    print("num of node: ", link_list.num_of_node)

    print("")

    link_list.PopFront()
    link_list.PopBack()
    link_list.PrintLinkList()
    print("num of node: ", link_list.num_of_node)

    print("")

    link_list.PushFront(1)
    link_list.PushBack(5)
    link_list.PrintLinkList()
    print("num of node: ", link_list.num_of_node)

    print("")

    link_list.PopNode(3)
    link_list.PrintLinkList()
    print("num of node: ", link_list.num_of_node)

    print("")

    link_list.PushNode(3, 4)
    link_list.PrintLinkList()
    print("num of node: ", link_list.num_of_node)

    print("")

    link_list.PushNode(0, 2)
    link_list.PrintLinkList()
    print("num of node: ", link_list.num_of_node)

    print("")

    link_list.DeleteLink()
    link_list.PrintLinkList()
    print("num of node: ", link_list.num_of_node)

if __name__ == '__main__':
    main()


