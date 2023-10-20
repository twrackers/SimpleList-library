# SimpleList-library #

A (very) lightweight template class to support lists of objects.  NOT a drop-in replacement for the C++ STL (Standard Template Library) `list` class.

The `SimpleList` class implements a *unidirectional linked list*, with a *head* position (address of the first object in the list), a *tail*  position (address of the last object in the list), and a current position between the head and tail positions inclusive.  This class lets the addresses of the objects be fetched in head-to-tail sequence.

This class uses an `add` method to populate the list, and `rewind`, `hasNext`, `current`, and `next` methods for accessing the list contents.

- The `add` method adds an object reference after the tail position, then the added object's address becomes the new tail position.
- The `rewind` method sets the current list position to the head, the beginning of the list.
- The `hasNext` method returns `true` if there is a list item **after** the current list position.  If the list is pointing to the tail, then `hasNext` will return `false`.
- The `current` method returns an object reference to the list item at the current list position.  DO NOT call this method if the list is pointing to the tail (`hasNext` would return `false`).
- The `next` method returns an object reference to the list item at the current list position, and advances the list position to the next item.  DO NOT call this method if the list is pointing to the tail (`hasNext` would return `false`).

### Note ###

On an Arduino processor, "dynamic" memory is not truly dynamic.  Memory can be allocated using the C++ `new` keyword, but `delete` does not free that memory.  This is especially an issue considering Arduino processors have a very limited amount of RAM available; the Uno has only 2K bytes and the Mega 2560 only 8K, for example.

The expected usage of the `SimpleList` class is to create a linked list which is created once and then repeatedly read as the program loops.

### Example sketches ###

- `SimpleListExample` generates a linked list of the first 15 powers of 2 as `unsigned int` values, then repeatedly prints the list.
- `SimpleListStringExample` works like `SimpleListExample` except it creates a list of [`String` objects](https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/) instead of `unsigned int` data.
