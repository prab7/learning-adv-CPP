
def calss(x, y):
    x, y = y, x;
    return x, y    # not golang - returns tuple

x = calss(1, 2)    # returns a tuple
print(x, end=' ');

x, y = calss(1,2)
print(x, y)       # it's the tuple trick