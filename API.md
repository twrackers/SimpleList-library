# SimpleList library API #

## SimpleList (template base class) ##

### *SimpleList()* ###

The constructor creates an empty instance of a `SimpleList` object.

### *virtual ~SimpleList()* ###

The destructor removes all of the data items which were added to the `SimpleList` object by the `add()` method.  On the Arduino platform, the  data items as well as the `SimpleList` object itself will *not* be deleted from memory.  So the destructor on an Arduino effectively only clears the references to the data items from the `SimpleList`.

### *void add(const T& item)* ###

Creates a reference to a data item of type `T` and appends it to the `SimpleList` object.

#### Arguments ####

- *const T& item*: Constant reference to a data item of type `T`, which is appended to the current contents of the `SimpleList` object.

### *byte size() const* ###

Returns the current count of items that have been added to the `SimpleList` object.

#### Returns ####

- *byte*: Returns current item count.

### *void rewind()* ###

Sets list to access first item upon next call to `next()`.

### *T& next()* ###

Returns a reference to the *next* item in the `SimpleList` object.

#### Returns ####

- *T&*: Reference to next data item.

### *bool hasNext() const* ###

Returns whether there are any data items after the one most recently fetched by `next()`.

#### Returns ####

- *bool*: `true` if there are any data items after the most recently accessed one, `false` if the most recent one is at the end of the list.
