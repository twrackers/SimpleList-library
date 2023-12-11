#ifndef _LIST__H_
#define _LIST__H_

template<class T>
class SimpleList
{
  class SimpleListItem
  {
  private:
    T m_item;
    SimpleListItem* m_next;

  public:
    SimpleListItem(T item) : m_item(item), m_next(NULL)
    {
    }
    
    void setNext(SimpleListItem* item)
    {
      m_next = item;
    }

    SimpleListItem* getNext() const
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
  SimpleListItem* m_head;
  SimpleListItem* m_tail;
  SimpleListItem* m_curr;
  
public:
  SimpleList() : m_count(0), m_head(NULL), m_tail(NULL), m_curr(NULL)
  {
  }
  
  virtual ~SimpleList()
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
    SimpleListItem* li = new SimpleListItem(item);
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

  T& current()
  {
    return m_curr->getItem();
  }

  T& next()
  {
    SimpleListItem* curr = m_curr;
    m_curr = m_curr->getNext();
    return curr->getItem();
  }

  bool hasNext() const
  {
    return (m_curr != NULL);
  }
};

#endif
