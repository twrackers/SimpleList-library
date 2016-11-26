#ifndef _LIST__H_
#define _LIST__H_

template <class T>
class List
{
  class ListItem
  {
  private:
    T m_item;
    ListItem* m_next;

  public:
    ListItem(T item) : m_item(item), m_next(NULL)
    {
    }
    
    void setNext(ListItem* item)
    {
      m_next = item;
    }

    ListItem* getNext() const
    {
      return m_next;
    }

    T& getItem()
    {
      return m_item;
    }
  };
  
private:
  byte m_count;
  ListItem* m_head;
  ListItem* m_tail;
  ListItem* m_curr;
  
public:
  List() : m_count(0), m_head(NULL), m_tail(NULL), m_curr(NULL)
  {
  }
  
  virtual ~List()
  {
    rewind();
    while (m_curr != NULL) {
      m_curr = m_curr->getNext();
      delete m_head;
      m_head = m_curr;
    }
  }
  
  void add(const T& item)
  {
    ListItem* li = new ListItem(item);
    if (m_head == NULL) {
      m_head = m_tail = m_curr = li;
    } else {
      m_tail->setNext(li);
      m_tail = li;
    }
    ++m_count;
  }
  
  byte size() const
  {
    return m_count;
  }

  void rewind()
  {
    m_curr = m_head;
  }

  T& next()
  {
    ListItem* curr = m_curr;
    m_curr = m_curr->getNext();
    return curr->getItem();
  }

  bool hasNext() const
  {
    return (m_curr != NULL);
  }
};

#endif
