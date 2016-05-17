# fadapter
An adapter to simplify the use of Unix Named Pipes (FIFOs) in multi-process setups.

It reads from a fifo, whose name is the program's argument.
Unlike most programs, it reopens the fifo and continues reading
    when a program closes the writing end of the fifo.
It writes to its standard out.
You can use it as an adapter between fifos and programs that don't
    behave very well reading from fifos normally.
