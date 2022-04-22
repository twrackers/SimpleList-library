# List-library #

A (very) lightweight template class to support lists of objects.  NOT a drop-in replacement for the C++ STL (Standard Template Library) `list` class.

The `List` class implements a *unidirectional linked list*, with a *head* position (address of the first object in the list), a *tail*  position (address of the last object in the list), and a current position between the head and tail positions inclusive.  This class lets the addresses of the objects be fetched in head-to-tail sequence.

This class uses an `add` method to populate the list, and `rewind`, `hasNext`,  and `next` methods for accessing the list contents.

- The `add` method adds an object reference after the tail position, then the added object's address becomes the new tail position.
- The `rewind` method sets the current list position to the head, the beginning of the list.
- The `hasNext` method returns `true` if there is a list item **after** the most recently accessed item.  If the most recent item is at the tail, then `hasNext` will return `false`.
- The `next` method returns an object reference to the object **after** the most recently accessed item.  If the most recent item is at the tail, then `next` will return `NULL`.

### Sample use case ###

    // Create empty List object.
    my_list = new List;

    // Create data items and add them to the list.
    const size_t NUM_ITEMS = 5;
    for (size_t i = 0; i < NUM_ITEMS; ++i) {
    	int* ptr_randval = new int;
    	*ptr_randval = rand(100);
		my_list.add(ptr_randval);
    }

    // Print list contents in order.
    // First, rewind to head of list.  'Next' item will be the
    // first list item.
    my_list.rewind();
    // Now step through list as long as there's a 'next' item.
    while (my_list.hasNext()) {
    	// Fetch the current item, then advance to next item.
    	std::cout << my_list.next() << std::endl;
    }