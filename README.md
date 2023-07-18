# samd21_unique_id_test

Test retrieving unique serial number from SAMD21 memory per
datasheet. It includes:

> ### 10.3.3. Serial Number
> Each device has a unique 128-bit serial number which is a concatenation of four 32-bit words contained
at the following addresses:\
> Word 0: 0x0080A00C\
> Word 1: 0x0080A040\
> Word 2: 0x0080A044\
> Word 3: 0x0080A048

Output should look something like:

```
Unique ID: 0457CD6E54315451202020321B090FFF
Unique ID: 0457CD6E54315451202020321B090FFF
Unique ID: 0457CD6E54315451202020321B090FFF
Unique ID: 0457CD6E54315451202020321B090FFF
...
```
