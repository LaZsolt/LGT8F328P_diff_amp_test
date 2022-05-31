# LGT8F328P_diff_amp_test
LGT8F328P differential amplifier and analog reference test

It is a test for check how differential amplifier works with different refrence voltages and gain.
For the test two voltage divider connected to the MCU. One to A3 input, which produce a lower voltage (eg. 0.8V) and the other divider connected to A7 input, which produce a bit higher voltage (eg 0.9V).


The program output looks like this:

```
Power Supply: 5011 mV
Ref: 1.024V
A7: 912 mV
A3: 843 mV

Ref: 2.048V
A7: 912 mV
A3: 838 mV

Ref: 4.096V
A7: 889 mV
A3: 825 mV 

Ref: DEFAULT
A7: 737
A3: 676
-----------
Ref: 1,024V 
 A7-A3 = 100 mV 
-----------
Ref: 2,048V 
 A7-A3 = 95 mV 
-----------
Ref: 4,096V 
 A7-A3 = 90 mV 
-----------
Ref: VCC 
 A7-A3 = 71
-----------
Ref: 2,048V 
 (A7-A3) * 1 = 199
-----------
Ref: 2,048V 
 (A7-A3) * 8 = 1268
-----------
Ref: 2,048V 
 (A7-A3) *16 = 2393
-----------
Ref: 2,048V 
 (A7-A3) *32 = 4064
-----------
```
