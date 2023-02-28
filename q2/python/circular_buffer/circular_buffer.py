# -*- coding: utf-8 -*-

__author__      = "Lucas Matana Luza"
__copyright__   = "Copyright (C) None"
__license__     = "None"
__version__     = "0.0.1"
__maintainer__  = "Lucas Matana Luza"
__email__       = "lluza@live.com"
__status__      = "Development"


class CircularBuffer():
    """CircularBuffer implements a circular buffer with a LIFO (Last-In, First-Out) structure"""


    def __init__(self, size):
        """Inits the CircularBuffer with a max size of 'size'
        
        Args:
        - size : max number of elements for the buffer
        """
        self.max_size = size
        self.data = []

    def get_max_size(self):
        """Return the max defined size for the buffer"""
        return self.max_size
    
    def peek_all(self):
        """Return a list with all elements stored in the buffer"""
        return self.data
    
    def size(self):
        """Return the number of elements stored in the buffer"""
        return len(self.data)
    
    def push(self, value):
        """Add an element to the end of the buffer
        
        Args:
        - value : the element to be added to the buffer
        """
        if len(self.data) >= self.max_size:
            del self.data[0]
        self.data.append(value)
    
    def pop(self):
        """Return the last element of the buffer, and then remove it"""
        if len(self.data):
            value = self.data[-1]
            self.data.pop()
        else:
            value = self.data
        return value