# List library API #

## List (template base class) ##

### *List()* ###

The constructor creates an empty instance of a `List` object.

### *virtual ~List()* ###

The destructor removes all of the data items which were added to the `List` object by the `add()` method.  On the Arduino platform, the  data items as well as the `List` object itself will *not* be deleted from memory.  So the destructor on an Arduino effectively only clears the references to the data items from the `List`.

### *void add(const T& item)* ###

Creates a reference to a data item of type `T` and appends it to the `List` object.

#### Arguments ####

- *const T& item*: Constant reference to a data item of type `T`, which is appended to the current contents of the `List` object.

### *byte size() const* ###

Returns the current count of items that have been added to the `List` object.

#### Returns ####

- *byte*: Returns current item count.

### *void rewind()* ###

Sets the state of the object to either turning-on or turning-off.

### *T& next()* ###

Returns a reference to the *next* item in the `List` object.

#### Returns ####

- *T&*: Reference to next data item.

### *bool hasNext() const* ###

Returns whether there are any data items after the one most recently fetched by `next()`.

#### Returns ####

- *bool*: `true` if there are any data items after the most recently accessed one, `false` if the most recent one is at the end of the list.