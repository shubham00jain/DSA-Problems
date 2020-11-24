One of the queues will be used to store the elements and the other to hold them temporarily
during the pop and top methods. The push method would enqueue the given element onto the
storage queue. The top method would transfer all but the last element from the storage queue onto
the temporary queue, save the front element of the storage queue to be returned, transfer the last
element to the temporary queue, then transfer all elements back to the storage queue. The pop
method would do the same as top, except instead of transferring the last element onto the
temporary queue after saving it for return, that last element would be discarded. Let Q1 and Q2 be
the two queues to be used in the implementation of stack. All we have to do is to define the push
and pop operations for the stack.
