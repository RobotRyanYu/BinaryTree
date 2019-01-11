class Node:
    def __init__(self):
        self.val = 0
        self.next = None

class LinkList:
    def __init__(self):
        self.head = Node()
        self.tail = Node()
        self.cur_node = self.head
        self.num_of_node = 0
    
    def InsertNode(self, val):
        if self.num_of_node == 0:
            self.head.val = val
        else:
            new_node = Node()
            new_node.val = val
            self.cur_node.next = new_node
            self.cur_node = self.cur_node.next
            self.tail = new_node
        self.num_of_node += 1
    
    def PrintLinkList(self):
        new_node = self.head
        for i in range(self.num_of_node):
            val = new_node.val
            print(val)
            new_node = new_node.next
    
def main():

    link_list = LinkList()

    link_list.InsertNode(1)
    link_list.InsertNode(2)
    link_list.InsertNode(3)
    link_list.InsertNode(4)
    link_list.InsertNode(5)
    link_list.PrintLinkList()

    print("head: ", link_list.head.val)
    print("tail: ", link_list.tail.val)

if __name__ == '__main__':
    main()


