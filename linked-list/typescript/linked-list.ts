
class _Node {
  value: any = null;
  next_node: _Node = null;

  public constructor(value: any, next_node: _Node = null) {
    this.value = value
    this.next_node = next_node
  }

  public get_value(): any {
    return this.value
  }

  public get_next_node(): _Node {
    return this.next_node
  }

  public set_next_node(next_node: _Node): void {
    this.next_node = next_node
  }
}

class LinkedList {
  head_node: _Node;

  public constructor(value: any) {
    const head_node = new _Node(value)
    this.head_node = head_node
  }

  private set_head_node(head_node: _Node): void {
    this.head_node = head_node
  }

  public get_head_node(): _Node {
    return this.head_node
  }

  public get_tail_node(): _Node {
    let current_node = this.get_head_node()

    while (current_node) {
      if (!current_node.get_next_node()) {
        return current_node
      }

      current_node = current_node.get_next_node()
    }
  }

  public get_node_by_value(value: any): _Node {
    let current_node = this.get_head_node()

    while (current_node) {
      if (current_node.get_value() == value) {
        return current_node
      }

      current_node = current_node.get_next_node()
    }
  }

  public get_node_by_index(index: number): _Node | undefined {
    let current_node = this.get_head_node()
    let current_index = 0

    while (current_node) {
      if (current_node) {
        if (current_index === index) {
          return current_node
        }
      }
      current_index = current_index + 1
      current_node = current_node.get_next_node()
    }
  }

  public add_node_to_head(new_value: any): void {
    const new_node = new _Node(new_value, this.get_head_node())
    this.set_head_node(new_node)
  }

  public add_node_to_tail(new_value: any): void {
    const new_node = new _Node(new_value)
    const tail_node = this.get_tail_node()
    tail_node.set_next_node(new_node)
  }

  public add_node_by_index(new_value: any, index: number): void {
    let current_node = this.get_head_node()
    let current_index = 0

    if (index === current_index) {
      this.add_node_to_head(new_value)
    } else {
      while (current_node) {
        const next_index = current_index + 1
        const next_node = current_node.get_next_node()

        if (next_node) {
          if (index === next_index) {
            const new_node = new _Node(new_value, next_node)
            current_node.set_next_node(new_node)
          }
        }

        current_index = current_index + 1
        current_node = next_node
      }
    }
  }

  public remove_head_node(): void {
    const new_head = this.get_head_node().get_next_node()
    this.get_head_node().set_next_node(undefined)
    this.head_node = new_head
  }

  public remove_tail_node(): void {
    let current_node = this.get_head_node()

    while (current_node) {
      const next_node = current_node.get_next_node()

      if (next_node) {
        if (!next_node.get_next_node()) {
          current_node.set_next_node(undefined)
        }
      }

      current_node = next_node
    }
  }

  public remove_node_by_value(value: any): void {
    let current_node = this.get_head_node()

    if (current_node.get_value() === value) {
      this.remove_head_node()
    } else {
      while (current_node) {
        const next_node = current_node.get_next_node()

        if (next_node) {
          if (next_node.get_value() === value) {
            current_node.set_next_node(next_node.get_next_node())
          }
        }

        current_node = next_node
      }
    }
  }

  public remove_node_by_index(index: number): void {
    let current_node = this.get_head_node()
    let current_index = 0

    if (current_index === index) {
      this.remove_head_node()
    } else {
      while (current_node) {
        const next_index = current_index + 1
        const next_node = current_node.get_next_node()

        if (next_node) {
          if (next_index === index) {
            current_node.set_next_node(next_node.get_next_node())
          }
        }

        current_index = current_index + 1
        current_node = next_node
      }
    }
  }

  public stringify_list(): string {
    let current_node = this.get_head_node()
    let stringified_value = ''

    while (current_node) {
      const value = current_node.get_value()
      const next_node = current_node.get_next_node()

      if (value) {
        stringified_value += value.toString()
      }

      if (next_node) {
        if (next_node.get_value()) {
          stringified_value += ", "
        }
      }

      current_node = next_node
    }

    return stringified_value
  }
}

// Tests

// Create link list and add values
const ll = new LinkedList(4)
ll.add_node_to_tail(8)
ll.add_node_to_tail(16)
ll.add_node_to_tail(32)
ll.add_node_to_tail(64)
ll.add_node_to_tail(128)

// Should remove 4
ll.remove_head_node()

// Should remove 128
ll.remove_tail_node()

// Should return 16
console.log(ll.get_node_by_index(1).get_value())

// Should remove 16
ll.remove_node_by_index(1)

// Should add 24 at index 1
ll.add_node_by_index(24, 1)

// Should return 32
console.log(ll.get_node_by_value(32).get_value())

// Should remove 32 from the linked list
ll.remove_node_by_value(32)

// Should return 8, 24, 64
console.log(ll.stringify_list())