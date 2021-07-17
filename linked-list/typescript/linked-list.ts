
/**
 * Represents a node in the linked list.
 * @public
 */
class LinkedListNode {
  /**
   * The data held by the node.
   * @readonly
   */
  private _value: any = null

  /**
   * The next node in the linked list.
   */
  private _nextNode: LinkedListNode | null = null

  /**
   * Creates a linked list node.
   * @param value - The node value.
   * @param nextNode - Next next node in the Linked List.
   */
  constructor(value: any, nextNode: LinkedListNode = null) {
    this._value = value
    this._nextNode = nextNode
  }

  /**
   * Get the node value.
   * @returns The node value.
   */
  public get value(): any {
    return this._value
  }

  /**
   * Get the next node.
   * @returns The next node.
   */
  public get nextNode(): LinkedListNode {
    return this._nextNode
  }

  /**
   * Set the next node.
   */
  public set nextNode(nextNode: LinkedListNode) {
    this._nextNode = nextNode
  }
}

/**
 * Represents a linked list.
 * @public
 */
class LinkedList {
  /**
   * The first node in the linked list.
   */
  private _headNode: LinkedListNode | null

  /**
   * Creates a linked list.
   * @param headNode - Node to be set as the first node in the linked list.
   */
  constructor(node?: LinkedListNode) {
    if (node) {
      this.headNode = node
    }
  }

  /**
   * Find a node by testing function.
   * 
   * @remarks
   * The find() method returns the first node in the 
   * linked list that satisfies the provided testing function.
   * 
   * If no nodes satisfy the testing function, undefined is returned.
   * 
   * @param test - Testing function.
   * @returns Node that matches the testing function.
   */
  private find(
    test: (node: LinkedListNode, index: number) => boolean
  ): LinkedListNode | undefined {
    let currentNode = this.headNode
    let currentIndex = 0

    while (currentNode) {
      if (test(currentNode, currentIndex)) {
        return currentNode
      }

      currentIndex = currentIndex + 1
      currentNode = currentNode.nextNode
    }
  }

  /**
   * Converts linked list values into a single output value
   * 
   * @remarks
   * The reduce() method executes a reducer function (that you provide)
   * on each node of the linked list, resulting in a single output value.
   * 
   * @param reducer - Reducer function.
   * @returns Single output defined by reducer function.
   */
  private reduce(
    reducer: (accumulator: any, value: any, index: number) => any,
    initialValue: any
  ): any {
    let currentNode = this.headNode
    let currentIndex = 0
    let accumulator = initialValue

    while (currentNode) {
      accumulator = reducer(accumulator, currentNode.value, currentIndex)
      currentIndex = currentIndex + 1
      currentNode = currentNode.nextNode
    }

    return accumulator
  }

  /**
   * Get the head node.
   * @returns The head node.
   */
   public get headNode(): LinkedListNode | null {
    return this._headNode
  }

  /**
   * Set a new head node.
   * @param node - The new head node.
   * @internal
   */
  public set headNode(node: LinkedListNode) {
    this._headNode = node
  }

  /**
   * Get the tail node.
   * @returns The tail node.
   */
  public getTailNode(): LinkedListNode {
    return this.find((node) => {
      return !node.nextNode
    })
  }

  /**
   * Get node by stored value.
   * @param value - value to match node stored value.
   * @returns matching node
   */
  public getNodeByValue(value: any): LinkedListNode {
    return this.find((node) => {
      return node.value == value
    })
  }

  /**
   * Get node by index in linked list.
   * @param index - index to match node index.
   * @returns matching node
   */
  public getNodeByIndex(index: number): LinkedListNode | undefined {
    return this.find((node, i) => {
      return i == index
    })
  }

  /**
   * Add new node to the head of the linked list.
   * @param value - value of new head node.
   */
  public addNodeToHead(value: any): void {
    this.headNode = new LinkedListNode(value, this.headNode)
  }

  /**
   * Add new node to the tail of the linked list.
   * @param value - value of new tail node.
   */
  public addNodeToTail(value: any): void {
    this.getTailNode().nextNode = new LinkedListNode(value)
  }

  /**
   * Add new node at specific index of linked list.
   * @param value - value of new node.
   * @param index - index to add node at.
   */
  public addNodeByIndex(value: any, index: number): void {
    if (index === 0) {
      this.addNodeToHead(value)
    } else {
      const node = this.getNodeByIndex(index - 1)
      node.nextNode = new LinkedListNode(value, node.nextNode)
    }
  }

  /**
   * Remove head node.
   */
  public removeHeadNode(): void {
    const newHead = this.headNode.nextNode
    this.headNode.nextNode = null
    this.headNode = newHead
  }

  /**
   * Remove tail node.
   * 
   * @remarks
   * Gets the node before the tail node and removes the link to the tail node.
   * The old tail node will be naturally cleaned up via garbage collection
   */
  public removeTailNode(): void {
    const node = this.find((node) => {
      return !node.nextNode.nextNode
    })

    node.nextNode = null
  }

  /**
   * Remove node by value.
   * 
   * @remarks
   * Gets the node before the matching node and removes the link to the matching node.
   * The matching node will be naturally cleaned up via garbage collection
   * 
   * @param value - Value of node to remove.
   */
  public removeNodeByValue(value: any): void {
    if (headNode.value === value) {
      return this.removeHeadNode()
    }

    const node = this.find((node) => {
      return node.nextNode.value === value
    })

    if (node) {
      node.nextNode = node.nextNode.nextNode
    }
  }

  /**
   * Remove node by index.
   * 
   * @remarks
   * Gets the node before the matching node and removes the link to the matching node.
   * The matching node will be naturally cleaned up via garbage collection
   * 
   * @param index - Index of node to remove.
   */
  public removeNodeByIndex(index: number): void {
    if (index === 0) {
      return this.removeHeadNode()
    }

    const node = this.find((node, i) => {
      return i === index - 1
    })

    if (node) {
      node.nextNode = node.nextNode.nextNode
    }
  }

  /**
   * Transform linked list values into a stringified list, comma separated.
   * @returns Stringified list of node values.
   */
  public toString(separator: string = ", "): string {
    return this.reduce((accumulator, value) => {
      return [...accumulator, value]
    }, []).join(separator)
  }
}

// Tests

// Create link list and add values
const headNode = new LinkedListNode(4)
const ll = new LinkedList(headNode)
ll.addNodeToTail(8)
ll.addNodeToTail(16)
ll.addNodeToTail(32)
ll.addNodeToTail(64)
ll.addNodeToTail(128)

// Should return 4, 8, 16, 32, 64, 128
console.log(ll.toString())

// Should remove 4
ll.removeHeadNode()

// Should return 8, 16, 32, 64, 128
console.log(ll.toString())

// Should remove 128
ll.removeTailNode()

// Should return 8, 16, 32, 64
console.log(ll.toString())

// Should return 16
console.log(ll.getNodeByIndex(1).value)

// Should remove 16
ll.removeNodeByIndex(1)

// Should return 8, 32, 64
console.log(ll.toString())

// Should add 24 at index 1
ll.addNodeByIndex(24, 1)

// Should return 8, 24, 32, 64
console.log(ll.toString())

// Should return 32
console.log(ll.getNodeByValue(32).value)

// Should remove 32 from the linked list
ll.removeNodeByValue(32)

// Should return 8, 24, 64
console.log(ll.toString())