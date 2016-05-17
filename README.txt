An adapter to simplify the use of Unix Named Pipes (FIFOs) in multi-process setups

to use
  install wherever you like, however you like
  fadapter <infifo> > <outfifo>

  where the outfifo is attached to a listening process that would usually have trouble listening out of a fifo when multiple programs act on the fifo in sequence
